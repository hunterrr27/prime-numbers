// handles the math & data logic
// generates the list of prime numbers from 2 to N
// runs isPrime(), allocates and fills primes[] array, stores primeCount
#include "prime_gen.h"
#include <math.h>
#include <stdlib.h>

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

void regenerate_primes(AppState *state)
{
    int countPrimes = 0;
    state->primes = malloc(sizeof(int) * state->N);
    for (int i = 2; i < state->N; i++) {
        if (isPrime(i)) {
            state->primes[countPrimes++] = i;
        }
    }
    state->primeCount = countPrimes;
}
