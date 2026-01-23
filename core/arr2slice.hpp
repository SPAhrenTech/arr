//array slices (n) - P. Ahrenkiel

#ifndef _ARR2SLICE_
#define _ARR2SLICE_

namespace arr {

template<class data_type>
class arr1;

template<class data_type>
class arr2;

template<class data_type>
class arr2slice {
private:

protected:
	arr2<data_type> *_a;
	std::size_t _iDim;
	std::size_t _iIndex;

public:
	arr2slice(arr2<data_type> *a, const std::size_t iDim, const std::size_t iIndex);
	arr2slice(const arr2slice<data_type> &A);
	~arr2slice();

	void operator=(const arr2slice<data_type> A);
	void operator=(const arr1<data_type> &A);

	std::size_t dim() const;
	std::size_t index() const;

	data_type &at(const std::size_t i);
	data_type const &at(const std::size_t i) const;

	data_type &operator()(const std::size_t i);
	data_type const& operator()(const std::size_t i) const;

	arr2<data_type>* data();
	arr2<data_type> const* data() const;
	
	std::size_t size() const;

	friend std::ostream &operator<<(std::ostream &os, const arr2slice<data_type> &A);
};
}

#include "arr2slice.tem"

#endif
