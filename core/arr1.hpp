// arrays (n) - P. Ahrenkiel

#ifndef _ARR1_
#define _ARR1_

#include <iterator> // Provides iterator and forward_iterator_tag
#include <cstdio>
#include <iostream>
#include <vector>

namespace arr {

template <class data_type>
class arr2slice;

template <class data_type>
class arr1
 {
private:

protected:
	std::vector<data_type> _v;
	
public:
	arr1(const std::size_t n=0, const data_type* p=NULL);
	
	arr1(const arr1<data_type>& A); // copy constructor
	arr1(const std::vector<data_type>& A);
	arr1(std::initializer_list<data_type> A);
	arr1(const arr2slice<data_type>& A);
	~arr1();
		
	std::vector<data_type> operator()() const;
	arr1<data_type> operator()(const arr1<std::size_t> A);
	arr1 operator=(const data_type& x);
	arr1& operator=(const arr1<data_type>& A);
	arr1<data_type>& operator=(const arr2slice<data_type>& A);
	
	void append(const data_type ai);

	void resize(const std::size_t n);

	void clear();
	std::size_t size() const;

	bool operator==(const arr1& A) const;
	bool operator!=(const arr1& A) const;

	data_type& at(const std::size_t i);
	data_type const& at(const std::size_t i) const;

	data_type& operator()(const std::size_t i);
	data_type const& operator()(const std::size_t i) const;
	
	data_type* data();
	data_type const* data() const;
		 
	data_type& cyc(const std::size_t i);
	data_type const& cyc(const std::size_t i) const;
	
	void copy(data_type* ap) const;
	
	arr1<std::size_t> iindex() const;
	
	arr1<data_type> reverse();
};

template <class data_type>
std::ostream& operator<<(std::ostream& os, const arr1<data_type>& A);

} // namespace arr

#include "arr1.tem"

#endif
