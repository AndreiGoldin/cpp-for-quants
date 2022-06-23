#ifndef PAYOFF_H
#define PAYOFF_H

#include <algorithm>

class PayOff {
    public:
        PayOff() {}; // Default constructor
        virtual ~PayOff() {}; // Virtual destructor

        // Overloading () turns the PayOff into 
        // an abstract function object
        virtual double operator() (const double& S) const = 0; // Pure virtual method
};

class PayOffCall : public PayOff {
    private:
        double K;
    public:
        PayOffCall(const double& _K); // No default constructor
        virtual ~PayOffCall(); // Virtual destructor

        virtual double operator() (const double& S) const;
};

class PayOffPut : public PayOff {
    private:
        double K;
    public:
        PayOffPut(const double& K_); // No default constructor
        virtual ~PayOffPut(); // Virtual destructor

        virtual double operator() (const double& S) const;
};

class PayOffDoubleDigital : public PayOff {
    private:
        double U; //Upper strike price
        double D; //Lower strike price
    public:
        PayOffDoubleDigital(const double U_, const double D_);
        virtual ~PayOffDoubleDigital();
        virtual double operator() (const double& S) const;
};

#endif