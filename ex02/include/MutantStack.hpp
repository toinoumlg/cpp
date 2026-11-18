#pragma once
#include <stack>
#include <vector>

template <class T> class MutantStack : public std::stack<T> {
public:
  // Constructor / destructor / copy
  MutantStack();
  MutantStack(const MutantStack &);
  MutantStack(const std::stack<T> &);
  MutantStack &operator=(const MutantStack &);
  template <typename Container> MutantStack(const Container &);
  ~MutantStack();

  // Iterators
  typedef typename std::stack<T>::container_type::iterator iterator;
  typedef typename std::stack<T>::container_type::const_iterator const_iterator;
  typedef
      typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
  typedef typename std::stack<T>::container_type::const_reverse_iterator
      const_reverse_iterator;

  iterator begin();
  iterator end();

  const_iterator begin() const;
  const_iterator end() const;

  reverse_iterator rbegin();
  reverse_iterator rend();

  const_reverse_iterator rbegin() const;
  const_reverse_iterator rend() const;
};
