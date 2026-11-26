#include "PmergeMe.hpp"

#include <cassert>
#include <cerrno>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

PmergeMe::PmergeMe() : _vec_time(0.0f), _deq_time(0.0f) {}

PmergeMe::PmergeMe(const PmergeMe& other)
    : _vec(other._vec),
      _vec_time(other._vec_time),
      _deq(other._deq),
      _deq_time(other._deq_time) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		_vec = other._vec;
		_vec_time = other._vec_time;
		_deq = other._deq;
		_deq_time = other._deq_time;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::before(char** args) {
	std::stringstream out;
	out << "Before:";
	while (*args) {
		char* end = NULL;
		errno = 0;
		const unsigned long value = std::strtoul(*args, &end, 10);
		if (!**args || !std::isdigit(static_cast<unsigned char>(**args)) ||
		    errno || *end != '\0' || value <= 0 || value > INT_MAX)
			throw std::exception();
		out << " " << value;
		args++;
	}
	std::cout << out.str() << std::endl;
}
void PmergeMe::after() const {
	std::cout << "After:";
	for (std::size_t i = 0; i < _vec.size() && i < _deq.size(); ++i) {
		std::cout << " " << _vec[i];
		assert(_vec[i] == _deq[i]);
	}
	std::cout << std::endl
	          << std::fixed << std::setprecision(5)
	          << "Time to process a range of " << _vec.size()
	          << " elements with std::vector in : " << _vec_time << " us"
	          << std::endl
	          << "Time to process a range of " << _deq.size()
	          << " elements with std::deque in : " << _deq_time << " us"
	          << std::endl;
}

void PmergeMe::mergeVec(char** args) {
	const std::clock_t start = std::clock();
	while (*args)
		_vec.push_back(std::strtoul(*args++, NULL, 10));

	sortVec(1);
	_vec_time =
	    static_cast<double>(std::clock() - start) * 1000000.0 / CLOCKS_PER_SEC;
}

static unsigned int jacobsthal(const unsigned int n) {
	return (std::pow(2, n) - std::pow(-1, n)) / 3;
}

void PmergeMe::swapVec(const std::size_t elem_size, const std::size_t pair_size,
                       const std::size_t nb_pairs) {
	for (std::size_t i = 0; i < nb_pairs; ++i) {
		const std::size_t left_start = i * pair_size;
		const std::size_t right_start = left_start + elem_size;

		const std::size_t left_end = right_start - 1;
		const std::size_t right_end = left_start + pair_size - 1;

		if (_vec[right_end] < _vec[left_end])
			std::swap_ranges(_vec.begin() + left_start,
			                 _vec.begin() + right_start,
			                 _vec.begin() + right_start);
	}
}

void PmergeMe::insertVec(const std::size_t elem_size,
                         const std::size_t pair_size,
                         const std::size_t nb_pairs) {
	std::vector<unsigned int> main;
	std::vector<unsigned int> pend;
	const std::size_t odd_size = _vec.size() % pair_size;

	for (std::size_t i = 0; i < nb_pairs; ++i) {
		const std::size_t left_start = i * pair_size;
		const std::size_t right_start = left_start + elem_size;
		const std::size_t pair_end = left_start + pair_size;

		if (i == 0)
			main.insert(main.end(), _vec.begin() + left_start,
			            _vec.begin() + right_start);
		else
			pend.insert(pend.end(), _vec.begin() + left_start,
			            _vec.begin() + right_start);

		main.insert(main.end(), _vec.begin() + right_start,
		            _vec.begin() + pair_end);
	}

	if (odd_size >= elem_size) {
		const std::size_t odd_start = nb_pairs * pair_size;
		pend.insert(pend.end(), _vec.begin() + odd_start,
		            _vec.begin() + odd_start + elem_size);
	}

	const std::size_t pend_blocks = pend.size() / elem_size;
	std::size_t inserted = 0;
	for (unsigned int k = 3; jacobsthal(k - 1) < pend_blocks + 1; ++k) {
		const std::size_t lower = jacobsthal(k - 1);
		std::size_t upper =
		    jacobsthal(k) > pend_blocks + 1 ? pend_blocks + 1 : jacobsthal(k);

		while (upper > lower) {
			const std::size_t pend_start = (upper - 2) * elem_size;
			const std::size_t pend_end = pend_start + elem_size;
			const unsigned int pend_high = pend[pend_end - 1];
			std::size_t left_main = 0;
			std::size_t right_main = upper + inserted > main.size() / elem_size
			                             ? main.size() / elem_size
			                             : upper + inserted;

			while (left_main < right_main) {
				const std::size_t mid =
				    left_main + (right_main - left_main) / 2;
				if (main[(mid + 1) * elem_size - 1] < pend_high)
					left_main = mid + 1;
				else
					right_main = mid;
			}

			main.insert(main.begin() + left_main * elem_size,
			            pend.begin() + pend_start, pend.begin() + pend_end);

			inserted++;
			upper--;
		}
	}
	std::copy(main.begin(), main.end(), _vec.begin());
}

void PmergeMe::sortVec(const std::size_t elem_size) {
	const std::size_t pair_size = 2 * elem_size;
	const std::size_t nb_pairs = _vec.size() / pair_size;

	if (nb_pairs == 0)
		return;

	swapVec(elem_size, pair_size, nb_pairs);

	sortVec(pair_size);

	insertVec(elem_size, pair_size, nb_pairs);
}

void PmergeMe::mergeDeq(char** args) {
	const std::clock_t start = std::clock();

	while (*args)
		_deq.push_back(std::strtoul(*args++, NULL, 10));

	sortDeq(1);
	_deq_time =
	    static_cast<double>(std::clock() - start) * 1000000.0 / CLOCKS_PER_SEC;
}

void PmergeMe::swapDeq(const std::size_t elem_size, const std::size_t pair_size,
                       const std::size_t nb_pairs) {
	for (std::size_t i = 0; i < nb_pairs; ++i) {
		const std::size_t left_start = i * pair_size;
		const std::size_t right_start = left_start + elem_size;

		const std::size_t left_end = right_start - 1;
		const std::size_t right_end = left_start + pair_size - 1;

		if (_deq[right_end] < _deq[left_end])
			std::swap_ranges(_deq.begin() + left_start,
			                 _deq.begin() + right_start,
			                 _deq.begin() + right_start);
	}
}

void PmergeMe::insertDeq(const std::size_t elem_size,
                         const std::size_t pair_size,
                         const std::size_t nb_pairs) {
	std::deque<unsigned int> main;
	std::deque<unsigned int> pend;

	const std::size_t odd_size = _deq.size() % pair_size;

	for (std::size_t i = 0; i < nb_pairs; ++i) {
		const std::size_t left_start = i * pair_size;
		const std::size_t right_start = left_start + elem_size;
		const std::size_t pair_end = left_start + pair_size;

		if (i == 0)
			main.insert(main.end(), _deq.begin() + left_start,
			            _deq.begin() + right_start);
		else
			pend.insert(pend.end(), _deq.begin() + left_start,
			            _deq.begin() + right_start);

		main.insert(main.end(), _deq.begin() + right_start,
		            _deq.begin() + pair_end);
	}

	if (odd_size >= elem_size) {
		const std::size_t odd_start = nb_pairs * pair_size;
		pend.insert(pend.end(), _deq.begin() + odd_start,
		            _deq.begin() + odd_start + elem_size);
	}

	const std::size_t pend_blocks = pend.size() / elem_size;
	std::size_t inserted = 0;
	for (unsigned int k = 3; jacobsthal(k - 1) < pend_blocks + 1; ++k) {
		const std::size_t lower = jacobsthal(k - 1);
		std::size_t upper =
		    jacobsthal(k) > pend_blocks + 1 ? pend_blocks + 1 : jacobsthal(k);

		while (upper > lower) {
			const std::size_t pend_start = (upper - 2) * elem_size;
			const std::size_t pend_end = pend_start + elem_size;
			const unsigned int pend_high = pend[pend_end - 1];
			std::size_t left_main = 0;
			std::size_t right_main = upper + inserted > main.size() / elem_size
			                             ? main.size() / elem_size
			                             : upper + inserted;

			while (left_main < right_main) {
				const std::size_t mid =
				    left_main + (right_main - left_main) / 2;
				if (main[(mid + 1) * elem_size - 1] < pend_high)
					left_main = mid + 1;
				else
					right_main = mid;
			}
			main.insert(main.begin() + left_main * elem_size,
			            pend.begin() + pend_start, pend.begin() + pend_end);
			inserted++;
			upper--;
		}
	}
	std::copy(main.begin(), main.end(), _deq.begin());
}

void PmergeMe::sortDeq(const std::size_t elem_size) {
	const std::size_t pair_size = 2 * elem_size;
	const std::size_t nb_pairs = _deq.size() / pair_size;

	if (nb_pairs == 0)
		return;

	swapDeq(elem_size, pair_size, nb_pairs);

	sortDeq(pair_size);

	insertDeq(elem_size, pair_size, nb_pairs);
}