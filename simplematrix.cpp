#ifndef _SIMPLE_MATRIX_CPP
#define _SIMPLE_MATRIX_CPP

#include "simplematrix.hpp"
#include <vector>
#include <iostream>
using namespace std;

template <typename Type>
SimpleMatrix<Type>::SimpleMatrix() {
    // No need for implementation , as the vector ”mat”
    // will create the necessary storage
}

template <typename Type>
SimpleMatrix<Type>::SimpleMatrix(const int& rows, const int& cols, const Type& val){
    for (int i=0; i<rows; i++){
        std::vector<Type> col_vec (cols, val);
        mat.push_back(col_vec);
    }
}

template <typename Type>
SimpleMatrix<Type>:: SimpleMatrix(const SimpleMatrix<Type>& _rhs) {
    mat = _rhs.get_mat();
}


template <typename Type>
SimpleMatrix<Type>& SimpleMatrix<Type>::operator= (const SimpleMatrix<Type>& _rhs) {
    if (this == &_rhs) return *this;
    mat = _rhs.get_mat();
    return *this;
}

template <typename Type>
SimpleMatrix<Type>::~SimpleMatrix(){
    // No need for implementation , as there is no
    // manual dynamic memory allocation
}

template <typename Type>
vector<vector<Type> > SimpleMatrix<Type>::get_mat() const {
    return mat;
}

template <typename Type>
Type& SimpleMatrix<Type>::value(const int& row, const int& col) {
    return mat[row][col];
}
#endif

int main() {
    SimpleMatrix<double> my_mat(2,2,4.0);
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            cout << my_mat.value(i,j) << " "s;
        }
        cout << endl;
    }
}