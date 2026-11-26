#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <cstdlib>
#include <ctime>
#include <deque>
#include <vector>

class PmergeMe {
   public:
	PmergeMe();
	PmergeMe(const PmergeMe&);
	PmergeMe& operator=(const PmergeMe&);
	~PmergeMe();

	static void before(char** args);
	void after() const;

	void mergeVec(char** args);
	void mergeDeq(char** args);

   private:
	void sortVec(std::size_t elem_size);
	void swapVec(std::size_t elem_size, std::size_t pair_size,
	             std::size_t nb_pairs);
	void insertVec(std::size_t elem_size, std::size_t pair_size,
	               std::size_t nb_pairs);

	std::vector<unsigned int> _vec;
	double _vec_time;

	void sortDeq(std::size_t elem_size);
	void swapDeq(std::size_t elem_size, std::size_t pair_size,
	             std::size_t nb_pairs);
	void insertDeq(std::size_t elem_size, std::size_t pair_size,
	               std::size_t nb_pairs);

	std::deque<unsigned int> _deq;
	double _deq_time;
};

#endif
