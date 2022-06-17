#include <iostream>

double add(double left, double right){
    return left + right;
}


double multiply(double left, double right){
    return left * right;
}

double binary_op(double left, double right, double (*f)(double, double)) {
    return (*f)(left, right);
}

int main() {
    double a = 5.0;
    double b = 10.0;

    std::cout << "Add: " << binary_op(a,b,add) << std::endl;
    std::cout << "Multiply: " << binary_op(a,b,multiply) << std::endl;
}

/*
1. Function pointers are inefficient when compared with functors (discussed below). 
   The compiler will often pass them as raw pointers and as such the compiler will struggle to inline the code.
2. Function pointers by themselves are not particularly flexible at storing state. 
   (can lead to race conditions if using static variables inside)
3. Function pointers do not play too well with templates if there are multiple signatures of the function in your code.
   (casting gives dificult syntax)
4. Function pointers have fixed parameter types and quantities.
   (poor flexibility if wrapped with hard-coded parameters)
SO BETTER USE FUNCTORS (FUNCTION OBJECTS)! 
*/



