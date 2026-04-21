#include "modes.h"
#include <stdlib.h>

void compute_points_linear(AppState *state)
{
  // set pointCount = to primeCount (calcualted by prime_gen.c)
  state->pointCount = state->primeCount;

  // allocate memory for array of point structs
  state->points = realloc(state->points, sizeof(Point) * state->pointCount);

  // loop from 0 to # of primes
  for (int i = 0; i < state->primeCount; i++) {
    
    // set each point.x in the array to be i (so each points x value will be just indexes)
    state->points[i].x = (float)i;

    // set each point.y to be the corresponding primes value (primes and points arrays should be same length)
    state->points[i].y = (float)state->primes[i];
  }
}

//void compute_points_step(AppState *state);
//void compute_points_ulam(AppState *state);
//void compute_points_polar(AppState *state);
