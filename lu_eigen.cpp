#include <iostream>
#include <Eigen/Dense>
#include <Eigen/LU>

int main() {
    typedef Eigen::Matrix<double, 4, 4> Matrix4x4;

    Matrix4x4 p;
    p << 7, 3, -1, 2,
         3, 8, 1, -4,
         -1, 1, 4, -1,
         2, -4, -1, 6;
    std::cout << "Matrix P: \n" << p << std::endl;

    Eigen::PartialPivLU<Matrix4x4> lu(p);
    std::cout << "LU Matrix: \n" << lu.matrixLU() << std::endl;

    Matrix4x4 l = Eigen::MatrixXd::Identity(4,4);
    l.block<4,4>(0,0).triangularView<Eigen::StrictlyLower>() = lu.matrixLU();
    std::cout << "L Matrix: \n" << l << std::endl;
    
    Matrix4x4 u = lu.matrixLU().triangularView<Eigen::Upper>();
    std::cout << "R Matrix: \n" << u << std::endl;
}