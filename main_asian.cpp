#include <iostream>
#include "payoff.h"
#include "asian.h"
#include "path_generation.h"
 
int main() {
    unsigned num_sims = 100000;
    unsigned num_intervals = 250;
    double S = 30.0;
    double K = 29.0;
    double r = 0.08;
    double v = 0.3;
    double T = 1.0;
    std::vector<double> spot_prices(num_intervals, S);

    PayOff* pay_off_call = new PayOffCall(K);
    PayOff* pay_off_put = new PayOffPut(K);
    AsianOptionArithmetic asian(pay_off_put);
    // AsianOptionGeometric asian(pay_off_call);

    double pay_off_sum = 0.0;
    for (int i = 0; i < num_sims; i++)
    {
        calc_path_spot_prices(spot_prices, r, v, T);
        pay_off_sum += asian.pay_off_price(spot_prices);
    }
    double discount_payoff_avg = (pay_off_sum/static_cast<double>(num_sims))*exp(-r*T);
    delete pay_off_call;
    
    std::cout << "Number of Paths: " << num_sims << std::endl;
    std::cout << "Asian price:     " << discount_payoff_avg << std::endl;
}