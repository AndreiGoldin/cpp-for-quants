#ifndef _SIMPLE_MATRIX_H
#define _SIMPLE_MATRIX_H

#include <vector>
using namespace std;

template <typename Type = double> class SimpleMatrix {
    private:
        vector<vector<Type> > mat;
    public:
        SimpleMatrix();
        SimpleMatrix(const int& rows, const int& cols, const Type& val);
        SimpleMatrix(const SimpleMatrix<Type>& _rhs);
        SimpleMatrix<Type>& operator= (const SimpleMatrix<Type>& _rhs);

        virtual ~SimpleMatrix();
        vector<vector<Type> > get_mat() const;
        Type& value(const int& row, const int& col);

};

#endif