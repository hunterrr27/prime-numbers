#include "state.h"
#include <stdlib.h>
#include <string.h>

void init_state(AppState *state)
{
  state->N = 313;
  state->primes = malloc(sizeof(int) * state->N);
  state->primeCount = 0;

  state->points = malloc(sizeof(Point) * state->N); // allocate enough space for worst case all numbers 2 to N are primes
  state->pointCount = 0;

  state->zoom = 1.0f;
  state->offsetX = 0.0f;
  state->offsetY = 0.0f;

  state->showInputBox = false;
  memset(state->inputBuffer, 0, sizeof(state->inputBuffer));
  state->inputResult = 0;

  state->dropdownEditMode = false;
  state->dropdownActive = 0;
  state->mode = MODE_LINEAR;
  state->needsRecompute = true;

  // my extras
  state->screenWidth = 1200;
  state->screenHeight = 800;
}

void cleanup_state(AppState *state)
{
  free(state->primes);
  free(state->points);
}
