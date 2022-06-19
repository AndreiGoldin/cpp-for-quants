#include <iostream>
#include <Eigen/Dense>

int main() {
    typedef Eigen::Matrix<double, 4, 4> Matrix4x4;

    Matrix4x4 p;
    p << 6, 3, 4, 8,
         3, 6, 5, 1,
         4, 5, 10, 7,
         8, 1, 7, 25;
    std::cout << "Matrix P: \n" << p << std::endl;

    Eigen::LLT<Matrix4x4> llt(p);

    Matrix4x4 l = llt.matrixL();
    std::cout << "L Matrix: \n" << l << std::endl;
    
    Matrix4x4 u = l.transpose();
    std::cout << "L^T Matrix: \n" << u << std::endl;
    
    std::cout << "LL^T Matrix: \n" << l*u << std::endl;
}
