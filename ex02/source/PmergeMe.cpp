#include "PmergeMe.hpp"

#include <assert.h>

#include <iomanip>
#include <iostream>

PmergeMe::PmergeMe() : _vec_time(0.0f), _deq_time(0.0f), _size(0) {}

PmergeMe::PmergeMe(const PmergeMe& other)
    : _vec(other._vec),
      _vec_time(other._vec_time),
      _deq(other._deq),
      _deq_time(other._deq_time),
      _size(other._size) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		_vec = other._vec;
		_vec_time = other._vec_time;
		_deq = other._deq;
		_deq_time = other._deq_time;
		_size = other._size;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::before(char** args) {
	std::cout << "Before:";
	_size = 0;
	while (*args) {
		char* end = NULL;
		const unsigned long value = std::strtoul(*args, &end, 10);
		if (!**args || !std::isdigit(**args) || *end != '\0')
			throw std::exception();
		std::cout << " " << value;
		args++;
		_size++;
	}
	std::cout << std::endl;
}
void PmergeMe::after() const {
	std::cout << "After:";
	for (std::size_t i = 0; i < _size; ++i) {
		std::cout << " " << _vec[i];
		assert(_vec[i] == _deq[i]);
	}
	std::cout << std::endl
	          << std::fixed << std::setprecision(5)
	          << "Time to process a range of " << _size
	          << " elements with std::vector in : " << _vec_time << " us"
	          << std::endl
	          << "Time to process a range of " << _size
	          << " elements with std::deque in : " << _deq_time << " us"
	          << std::endl;
}

void PmergeMe::mergeVec(char** args) {
	const std::clock_t start = std::clock();
	while (*args)
		_vec.push_back(std::strtoul(*args++, NULL, 10));

	sortVec(1);
	_vec_time = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC;
}

void PmergeMe::sortVec(const std::size_t elem_size) {
	const std::size_t pair_size = 2 * elem_size;
	const std::size_t num_pairs = _vec.size() / pair_size;

	if (num_pairs == 0)
		return;

	for (std::size_t i = 0; i < num_pairs; ++i) {
		const std::size_t left_start = i * pair_size;
		const std::size_t right_start = left_start + elem_size;

		const std::size_t left_end = right_start - 1;
		const std::size_t right_end = left_start + pair_size - 1;

		if (_vec[right_end] < _vec[left_end])
			std::swap_ranges(_vec.begin() + left_start,
			                 _vec.begin() + right_start,
			                 _vec.begin() + right_start);
	}

	sortVec(pair_size);

	std::vector<unsigned int> main;
	std::vector<unsigned int> pend;
	const std::size_t odd_size = _vec.size() % pair_size;

	for (std::size_t i = 0; i < num_pairs; ++i) {
		const std::size_t left_start = i * pair_size;
		const std::size_t right_start = left_start + elem_size;
		const std::size_t pair_end = left_start + pair_size;

		if (!i)
			main.insert(main.end(), _vec.begin() + left_start,
			            _vec.begin() + right_start);
		else
			pend.insert(pend.end(), _vec.begin() + left_start,
			            _vec.begin() + right_start);

		main.insert(main.end(), _vec.begin() + right_start,
		            _vec.begin() + pair_end);
	}

	if (odd_size >= elem_size) {
		const std::size_t odd_start = num_pairs * pair_size;
		pend.insert(pend.end(), _vec.begin() + odd_start,
		            _vec.begin() + odd_start + elem_size);
	}
	while (!pend.empty()) {
	}
}

void PmergeMe::mergeDeq(char** args) {
	const std::clock_t start = std::clock();

	while (*args)
		_deq.push_back(std::strtoul(*args++, NULL, 10));

	sortDeq(1);
	_deq_time = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC;
}

void PmergeMe::sortDeq(const std::size_t elem_size) {
	const std::size_t pair_size = 2 * elem_size;
	const std::size_t num_pairs = _deq.size() / pair_size;

	if (num_pairs == 0)
		return;

	for (std::size_t i = 0; i < num_pairs; ++i) {
		const std::size_t left_start = i * pair_size;
		const std::size_t right_start = left_start + elem_size;

		const std::size_t left_end = right_start - 1;
		const std::size_t right_end = left_start + pair_size - 1;

		if (_deq[right_end] < _deq[left_end])
			std::swap_ranges(_deq.begin() + left_start,
			                 _deq.begin() + right_start,
			                 _deq.begin() + right_start);
	}

	sortDeq(pair_size);
}