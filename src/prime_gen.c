#include "prime_gen.c"

bool isPrime(int n)
{
    if (n < 2) return false;

    int limit = sqrt(n);
    for (int i = 2; i <= limit; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void regenerate_primes(Appstate *state)
{

}
