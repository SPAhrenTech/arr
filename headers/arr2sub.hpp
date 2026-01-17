//sub arrays (m x n) - P. Ahrenkiel

#ifndef _ARR2SUB_
#define _ARR2SUB_

namespace arr {

    template<class data_type>
    class arr2;

    template<class data_type>
    class arr2sub {
    private:

    protected:
        arr2<data_type> *_a;
        std::size_t _iRow, _iCol;
        std::size_t _nRows, _nCols;

    public:
        arr2sub(arr2<data_type> *a, const std::size_t iRow, const std::size_t iCol, const std::size_t nRows,
                const std::size_t nCols);

        void operator=(const arr2sub<data_type> &A);

        void operator=(const arr2<data_type> &A);

        arr2sub(const arr2sub<data_type> &A);

        ~arr2sub();

        std::size_t index(const std::size_t i) const;

        std::size_t size(const std::size_t i) const;

        data_type &at(const std::size_t i, const std::size_t j);
        data_type const &at(const std::size_t i, const std::size_t j) const;

        data_type &operator()(const std::size_t i, const std::size_t j);
        data_type const &operator()(const std::size_t i, const std::size_t j) const;

				arr2<data_type> *data();
       	arr2<data_type> const *data() const;

        void operator=(const data_type &x);
    };

}

#include "arr2sub.tem"

#endif
