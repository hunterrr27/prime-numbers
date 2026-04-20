#include "prime_gen.c"

bool isPrime(Appstate *state)
{
    if (number < 2) return false;

    int limit = sqrt(number);
    for (int i = 2; i <= limit; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int *generate_primes(Appstate *state)
{

}
