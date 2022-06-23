#ifndef PAYOFF_CPP 
#define PAYOFF_CPP

#include "payoff.h"
// #include <cmath>
#include <iostream>

PayOffCall::PayOffCall(const double& _K) { K=_K; }
PayOffCall::~PayOffCall() {}

// Over−ridden operator () method , which turns PayOffCall object into a function
double PayOffCall::operator() (const double& S) const {
    return std::max(S-K, 0.0);
}

PayOffPut::PayOffPut(const double& _K) { K=_K; }
PayOffPut::~PayOffPut() {}

// Over−ridden operator () method , which turns PayOffPut object into a function
double PayOffPut::operator() (const double& S) const {
    return std::max(K-S, 0.0);
}

PayOffDoubleDigital::PayOffDoubleDigital(const double _U, const double _D){
    U = _U; D = _D;
}
PayOffDoubleDigital::~PayOffDoubleDigital() {};

double PayOffDoubleDigital::operator() (const double& S) const {
    if (S>=D && S<=U){
        return 1.0;
    } else {
        return 0.0;
    }
}

#endif

/* int main (){
    PayOffCall default_call(100.0);
    double default_price;
    PayOffDoubleDigital another_call(110.0, 100.0);
    double another_price;
    default_price = default_call(120.0);
    another_price = another_call(105.0);
    std::cout << "Default call price: " << default_price << std::endl;
    std::cout << "Non-default call price: " << another_price << std::endl;
} */