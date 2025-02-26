#include "fermat_number.hpp"

mpz_class n_fermat_number(const unsigned long long& n)
{
    return (mpz_class(1) << (1 << n)) + 1;
}