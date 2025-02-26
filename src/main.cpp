#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "euler_method.hpp"
#include "fermat_number.hpp"

using namespace std;

void usage() {
    std::cout << "Usage: ./mersenne_primality_test -i [N] [-m METHOD] [-n]\n"
            << "  -m Mode - Mode e for euler factorization of the Fermat Number e or mode f for looking for a Fermat number that has a prime factor k*2^l + 1\n"
            << "  -i index - Index of the Mersenne number to be tested (e.g., 5 for M_5 = 2^5 - 1)\n"
            << "  -k the k part of the prime factor k*2^l + 1\n"
            << "  -l the l part of the prime factor k*2^l + 1\n"
            << "  -n Prints the corresponding Mersenne number\n";
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        usage();
        return 1;
    }

    unsigned long long n = 0, k = 0, l = 0; // Inicializa o índice
    bool show = false;
    std::string method = "e"; // Método padrão
    int opt;

    while ((opt = getopt(argc, argv, "i:m:k:l:n")) != -1) {
        switch (opt) {
            case 'i':
                n = atoll(optarg); // Armazena o índice do número de Mersenne
                break;
            case 'm':
                method = optarg;
                break;
            case 'n':
                show = true;
                break;
            case 'k':
                k = atoll(optarg);
                break;
            case 'l':
                l = atoll(optarg);
                break;
            default:
                usage();
                return 1;
        }

        
    }

    mpz_class F;

    if (method == "e" && n == 0 || method == "f" && (l == 0 || k == 0)) {
        usage();
        return 1;
    }

    else if (method == "e")
    {
        F = n_fermat_number(n);

        cout << "2^(2^" << n << ") + 1 ";

        mpz_class factor = euler_method(F, n);

        if (factor == F)
            cout << "is a prime number\n";

        else
            cout << "is not a prime number\nThe smallest factor is " << factor << '\n';

        if (show)
        {
            F = n_fermat_number(n);    
            cout << "2^(2^" << n << ") + 1 = " <<  F << '\n';
        }
    }

    else if (method == "f")
    {
        cout << k << "*2^" << l << " + 1 ";

        if (show)
        {
            mpz_class q ;
            mpz_set_ui(q.get_mpz_t(), k);
            q = (q << l) + 1;

            cout << "= " << q << ' ';
        }
            

        vector<unsigned long long> fnumbers = find_fermat_number(k, l);

        if (fnumbers.empty())
            cout << "is not a factor of a Fermat number\n";

        else
            for (unsigned long long f : fnumbers)
            {
                cout << "is a factor of 2^(2^" << f << ") + 1\n";

    
                if (show)
                {
                    F = n_fermat_number(f);    
                    cout << "2^(2^" << f << ") + 1 = " <<  F << '\n';
                }
            }
    }

    return 0;
}