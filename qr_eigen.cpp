#include <iostream>
#include <Eigen/Dense>

int main() {
    Eigen::MatrixXf p(3,3);
    p << 12, -51, 4,
         6, 167, -68,
         -4, 24, -41;
    std::cout << "Matrix P: \n" << p << std::endl;

    Eigen::HouseholderQR<Eigen::MatrixXf> qr(p);
    Eigen::MatrixXf q = qr.householderQ();
    std::cout << "Q Matrix: \n" << q << std::endl;
    std::cout << "QQ^T Matrix: \n" << q*q.transpose() << std::endl;
}

