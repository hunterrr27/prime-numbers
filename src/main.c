// primeexplorer.c
// prime number explorer
// by hunter freeman

#define RAYGUI_IMPLEMENTATION

#include "primes.h"



int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s N\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    if (N < 2) {
        printf("N must be >= 2\n");
        return 1;
    }

    // Allocate max possible space on the heap
    int *tmp = malloc(N * sizeof(int));
    if (!tmp) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    // Fill with primes
    int countPrimes = 0;
    for (int i = 2; i <= N; i++) {
        if (isPrime(i)) {
            tmp[countPrimes++] = i;
        }
    }

    // Shrink to exact size
    int *primes = realloc(tmp, countPrimes * sizeof(int));
    if (!primes) {
        // If realloc fails, tmp is still valid
        primes = tmp;
    }

    // Print primes (for debugging)
    for (int i = 0; i < countPrimes; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    // Call Raylib graphing function
    drawPrimeGraph(primes, countPrimes, N);

    // Cleanup
    free(primes);

    return 0;
}
