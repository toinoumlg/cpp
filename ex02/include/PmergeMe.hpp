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

	void before(char** args);
	void after() const;

	void mergeVec(char** args);
	void mergeDeq(char** args);
	void sortDeq(std::size_t elem_size);

   private:
	void sortVec(std::size_t elem_size);
	static int _elem_size;
	std::vector<unsigned int> _vec;
	double _vec_time;

	std::deque<unsigned int> _deq;
	double _deq_time;

	std::size_t _size;
};

#endif
