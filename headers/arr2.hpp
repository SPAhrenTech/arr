// arrays (m x n) - P. Ahrenkiel

#ifndef _ARR2_
#define _ARR2_

#include <vector>

namespace arr {

template <class data_type>
class arr1;

template <class data_type>
class arr2slice;

template <class data_type>
class arr2sub;

template <class data_type>
class arr2
{
private:

protected:
	std::vector<data_type> _v;
	std::size_t _nRows,_nCols;

public:
	arr2(const std::size_t nRows=0,const std::size_t nCols=0,const data_type* p=NULL);
	arr2(const std::size_t nRows,const std::size_t nCols,const std::vector<data_type> &v);
	arr2(const arr1<data_type>& A);
	arr2(const std::initializer_list<std::initializer_list<data_type>> A);
	arr2(const arr2<data_type>& A); // copy constructor
	arr2(const arr2slice<data_type>& A);
	arr2(const arr2sub<data_type>& A);
	~arr2();

	std::vector<data_type> operator()() const;
	arr2<data_type>& operator=(const data_type& x);
	arr2<data_type>& operator=(const arr2<data_type>& A);

	//using std::vector<data_type>::at;
	data_type& at(const std::size_t i);
	data_type const& at(const std::size_t i) const;
		
	std::size_t size() const { return _nRows * _nCols; }
	std::size_t size(std::size_t d) const;
	void resize(const size_t nRows, const size_t nCols);

	bool operator==(const arr2<data_type>& A) const;
	bool operator!=(const arr2<data_type>& A) const;

	bool isSquare() const { return _nRows==_nCols; }

	arr2<data_type> minor(const std::size_t m, const std::size_t n) const;
	arr1<data_type> operator()(const std::size_t i) const;
	arr2<data_type> T() const;

	arr2slice<data_type> slice(const std::size_t iDim, const std::size_t iIndex);
	arr2slice<data_type> col(const std::size_t iIndex);
	arr2slice<data_type> row(const std::size_t iIndex);
	arr2sub<data_type> sub(const std::size_t iRow,
												 const std::size_t iCol,
												 const std::size_t nRows,
												 const std::size_t nCols);

	arr2sub<data_type> operator()(const std::size_t iRow,
																const std::size_t iCol,
																const std::size_t nRows,
																const std::size_t nCols);

	arr2<std::size_t> icol() const;
	arr2<std::size_t> irow() const;

	arr2<data_type> operator()(const arr2<std::size_t> A, const std::size_t Bi);
	arr2<data_type> operator()(const std::size_t Ai, const arr2<std::size_t> B);
	arr2<data_type> operator()(const arr2<std::size_t> A, const arr2<std::size_t> B);

	bool swapRows(const std::size_t iRow1, const std::size_t iRow2);
	bool swapCols(const std::size_t iCol1, const std::size_t iCol2);
	
	data_type& at(const std::size_t i0, const std::size_t i1);
	data_type const& at(const std::size_t i0, const std::size_t i1) const;
	
	data_type& operator()(const std::size_t i, const std::size_t j);
	data_type const& operator()(const std::size_t i, const std::size_t j) const;

	data_type* data();
	data_type const* data() const;
};

template <class data_type>
std::ostream& operator<<(std::ostream& os, const arr2<data_type>& A);

} // namespace arr

#include "arr2.tem"

#endif
