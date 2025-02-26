#ifndef FERMAT_NUMBERS
#define FERMAT_NUMBERS

#include <gmpxx.h>
#include <vector>

using namespace std;

mpz_class n_fermat_number(const unsigned long long& n);

vector<unsigned long long> find_fermat_number(const unsigned long long k, const unsigned long long l);

#endif