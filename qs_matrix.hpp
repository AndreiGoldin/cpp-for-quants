#ifndef __QS_MATRIX_H
#define __QS_MATRIX_H

#include <vector>

template <typename T> class QSMatrix {
    private:
        std::vector<std::vector<T> > mat;
        unsigned rows;
        unsigned cols;
    
    public:
        QSMatrix(unsigned _rows, unsigned _cols, const T& _initial);
        QSMatrix(const QSMatrix<T>& rhs);
        virtual ~QSMatrix();

        QSMatrix<T>& operator=(const QSMatrix<T>& rhs);
        QSMatrix<T> operator+(const QSMatrix<T>& rhs);
        QSMatrix<T>& operator+=(const QSMatrix<T>& rhs);
        QSMatrix<T> operator-(const QSMatrix<T>& rhs);
        QSMatrix<T>& operator-=(const QSMatrix<T>& rhs);
        QSMatrix<T> operator*(const QSMatrix<T>& rhs);
        QSMatrix<T>& operator*=(const QSMatrix<T>& rhs);
        QSMatrix<T> transpose();

        QSMatrix<T> operator+(const T& rhs);
        QSMatrix<T> operator-(const T& rhs);
        QSMatrix<T> operator*(const T& rhs);
        QSMatrix<T> operator/(const T& rhs);

        std::vector<T> operator*(const std::vector<T>& rhs);
        std::vector<T> diag_vec();

        T& operator()(const unsigned& row, const unsigned& col);
        const T& operator()(const unsigned& row, const unsigned& col) const;
        
        unsigned get_rows() const;
        unsigned get_cols() const;
};

// Necessary while working with template classes
#include "qs_matrix.cpp"
#endif