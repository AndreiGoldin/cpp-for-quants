/* The main benefit of using function objects is that 
they are objects and hence can contain state, either statically 
across all instances of the function objects or individually 
on a particular instance. This is a major improvement comperad to
simply function pointers. */

#include <iostream>

//Abstract base class
class BinaryFunction {
    public:
        BinaryFunction() {};
        virtual double operator() (double left, double right) = 0;

};

// Add two doubles
class Add : public BinaryFunction {
    public:
        Add () {};
        virtual double operator() (double left, double right) {
            return left + right;
        }
};

// Multiply two doubles
class Multiply : public BinaryFunction {
    public:
        Multiply () {};
        virtual double operator() (double left, double right) {
            return left * right;
        }
};

double binary_op(double left, double right, BinaryFunction* bin_func) {
    /* Since BinaryFunction is an abstract class, it cannot be instantiated.
     Hence we need to make use of POINTERS to pass in pAdd and pMultiply 
     to the binary_op function. */
    return (*bin_func)(left, right);
}

int main() {
    double a = 5.0;
    double b = 10.0;

    BinaryFunction* pAdd = new Add();
    BinaryFunction* pMultiply = new Multiply();

    std::cout << "Add: " << binary_op(a, b, pAdd) << std::endl;
    std::cout << "Multiply: " << binary_op(a, b, pMultiply) << std::endl;

    delete pAdd; 
    delete pMultiply;

    return 0;
}
