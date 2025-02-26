#include "euler_method.hpp"
#include <cmath>

mpz_class euler_method(const mpz_class &F, const unsigned long long& n) 
{   
    mpz_class two_p_nplusone = 2;
    mpz_pow_ui(two_p_nplusone.get_mpz_t(), two_p_nplusone.get_mpz_t(), n + 1);

    mpz_class q = 1 + two_p_nplusone, N;

    mpz_sqrt(N.get_mpz_t(), F.get_mpz_t());

    while (q < N)
    {
        if ((F % q) == 0)
            return q;

        q += two_p_nplusone;
    }
    
    return F;
}