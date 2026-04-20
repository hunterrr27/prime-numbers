#include "modes.h"

void compute_points_linear(AppState *state)
{
  state->pointCount = state->primeCount;
  state->points = realloc(state->points, sizeof(Point) * state->pointCount);

  for (int i = 0; i < state->primeCount; i++) {
    state->points[i].x = (float)i;
    state->points[i].y = (float)state->primes[i];
  }
}

void compute_points_step(AppState *state);
void compute_points_ulam(AppState *state);
void compute_points_polar(AppState *state);
