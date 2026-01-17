// arrays (m x n) - P. Ahrenkiel

#ifndef _ARR3_
#define _ARR3_

#include "arr2.hpp"

#include <vector>

namespace arr {
//
template <class data_type>
class arr3
{
private:

protected:
	std::vector<data_type> _v;
	std::size_t _n0, _n1, _n2;

public:
	arr3(const std::size_t n0 = 0,
			 const std::size_t n1 = 0,
			 const std::size_t n2 = 0,
			 const data_type* a = NULL);

	arr3(const arr3<data_type>& A); // copy constructor
	~arr3();

	arr3<data_type>& operator=(const data_type& x);

	arr3<data_type>& operator=(const arr3<data_type>& A);

	std::vector<data_type> operator()() const;

	std::size_t size() const;
	std::size_t size(std::size_t d) const;

	void resize(const size_t n0, const size_t n1, const size_t n2);

	bool operator==(const arr3<data_type>& A) const;

	bool operator!=(const arr3<data_type>& A) const;

	bool isCube() const;
	
	data_type& at(const std::size_t i0, const std::size_t i1, const std::size_t i2);
	data_type const& at(const std::size_t i0, const std::size_t i1, const std::size_t i2) const;

	data_type& operator()(const std::size_t i, const std::size_t j, const std::size_t k);
	data_type const& operator()(const std::size_t i, const std::size_t j, const std::size_t k) const;
	
	data_type* data();
	data_type const* data() const;
};

} // namespace arr

#include "arr3.tem"

#endif
