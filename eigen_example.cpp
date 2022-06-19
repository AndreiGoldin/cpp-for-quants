#include <iostream>
#include <Eigen/Dense>
 
using Eigen::MatrixXd;
 
int main()
{
    MatrixXd m(2,2);
    m(0,0) = 3;
    m(1,0) = 2.5;
    m(0,1) = -1;
    m(1,1) = m(1,0) + m(0,1);
    std::cout << m << std::endl;

    // Define two matrices , both 3x3 
    Eigen::Matrix3d p ;
    Eigen::Matrix3d q ;
    // Define two three−dimensional vectors
    // The constructor provides initialisation 
    Eigen::Vector3d r(1 ,2 ,3);
    Eigen::Vector3d s(4 ,5 ,6);
    // Use the << operator to f i l l the matrices
    p << 1,2,3,4,5,6,7,8,9;
    q << 10, 11, 12, 13, 14, 15, 16, 17, 18;
    // Output arithmetic operations for matrices
    std::cout << "p+q=\n" << p + q << std::endl; 
    std::cout << "p-q=\n" << p - q << std::endl;
    // Output arithmetic operations for vectors
    std::cout << "r+s=\n" << r + s << std::endl;
    std::cout << "r-s=\n" << r - s << std::endl; 

    // Define a 3x3 matrix and two 3−dimensional vectors Eigen : : Matrix3d p ;
    p << 1,2,3,
         4,5,6,
         7,8,9;
    // Matrix/matrix multiplication
    std::cout << "p*p:\n" << p*p << std::endl;
    // Matrix/vector multiplication
    std::cout << "p*r:\n" << p*r << std::endl;
    std::cout << "r^T*p:\n" << r.transpose()*p << std::endl;
    // Vector/vector multiplication (inner product)
    std::cout << "r^T*s:\n" << r.transpose()*s << std::endl;

    std::cout << "p.sum(): " << p.sum() << std::endl;
    std::cout << "p.prod(): " << p.prod() << std::endl; 
    std::cout << "p.mean(): " << p.mean() << std::endl; 
    std::cout << "p.minCoeff(): " << p.minCoeff() << std::endl; std::cout << "p.maxCoeff(): " << p.maxCoeff() << std::endl; std::cout << "p.trace(): " << p.trace() << std::endl;
}