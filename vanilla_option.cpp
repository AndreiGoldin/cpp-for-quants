#ifndef VANILLA_OPTION_CPP 
#define VANILLA_OPTION_CPP

#include "vanilla_option.h"
#include <cmath>
#include <iostream>

// Cumulative distribution function of the normal distribution
double N(double x)
{
  double L, K, w ;
  double Pi = 3.141592653589793238462643;
  /* constants */
  double const a1 = 0.31938153, a2 = -0.356563782, a3 = 1.781477937;
  double const a4 = -1.821255978, a5 = 1.330274429;

  L = fabs(x);
  K = 1.0 / (1.0 + 0.2316419 * L);
  w = 1.0 - 1.0 / sqrt(2 * Pi) * exp(-L *L / 2) * (a1 * K + a2 * K *K + a3 * pow(K,3) + a4 * pow(K,4) + a5 * pow(K,5));

  if (x < 0 ){
    w= 1.0 - w;
  }
  return w;
}

void VanillaOption::init(){
    K = 100.0;
    r = 0.05; // 5% interest rate
    T = 1.0; // One year until maturity
    S = 100.0; // Option is ”at the money” as spot equals the strike .
    sigma = 0.2; // Volatility is 20%
}

void VanillaOption::copy(const VanillaOption& rhs){
    K = rhs.getK();
    r = rhs.getr();
    T = rhs.getT();
    S = rhs.getS();
    sigma = rhs.getsigma();
}


VanillaOption::VanillaOption() { init(); }
VanillaOption::VanillaOption(const double& _K, const double& _r, 
                const double& _T, const double& _S, 
                const double& _sigma) {
                    K=_K;
                    r=_r;
                    T=_T;
                    S=_S;
                    sigma=_sigma;
                }
// Copy constructor
VanillaOption::VanillaOption(const VanillaOption& rhs) {
    copy(rhs);
}
// Assignment operator
VanillaOption& VanillaOption::operator=(const VanillaOption& rhs) {
    if (this == &rhs) return *this;
    copy(rhs);   
    return *this;
}
// Destructor
VanillaOption::~VanillaOption() {
    // Empty, , as the compiler does the work of cleaning up the simple types for us
}

 // Public access for the member data
double VanillaOption::getK() const { return K; }
double VanillaOption::getr() const { return r; }
double VanillaOption::getT() const { return T; }
double VanillaOption::getS() const { return S; }
double VanillaOption::getsigma() const { return sigma; }

double VanillaOption::calc_call_price() const {
    double sigma_sqrt_T = sigma*sqrt(T);
    double d_1 = ( log(S/K) + (r+sigma*sigma*0.5)*T)/sigma_sqrt_T;
    double d_2 = d_1 - sigma_sqrt_T;
    return S*N(d_1) - K*exp(-r*T) * N(d_2);
}

double VanillaOption::calc_put_price() const {
    double sigma_sqrt_T = sigma*sqrt(T);
    double d_1 = ( log(S/K) + (r+sigma*sigma*0.5)*T)/sigma_sqrt_T;
    double d_2 = d_1 - sigma_sqrt_T;
    return - S*N(-d_1) + K*exp(-r*T) * N(-d_2);
}
#endif

int main(){
    VanillaOption default_call;
    double default_price;
    VanillaOption another_call(105.0, 0.05, 1.0, 100.0, 0.2);
    double another_price;
    default_price = default_call.calc_call_price();
    another_price = another_call.calc_call_price();
    std::cout << "Default call price: " << default_price << std::endl;
    std::cout << "Non-default call price: " << another_price << std::endl;
}