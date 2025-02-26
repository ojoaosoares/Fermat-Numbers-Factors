#include "fermat_number.hpp"
// #include <iostream>

// using namespace std;

mpz_class n_fermat_number(const unsigned long long& n)
{
    return (mpz_class(1) << (1 << n)) + 1;
}

vector<unsigned long long> find_fermat_number(const unsigned long long k, const unsigned long long l)
{

    mpz_class q ;
    mpz_set_ui(q.get_mpz_t(), k);
    q = (q << l) + 1;

    vector<unsigned long long> ans;

    unsigned long long index = 0;
    
    mpz_class residue = 2 % q;

    while (index < l)
    {
        if (residue == q - 1)
            ans.push_back(index);

        residue = residue*residue % q;
        index++;
    }

    return ans;
}