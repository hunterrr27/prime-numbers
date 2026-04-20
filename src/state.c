#include "state.h"

void init_state(AppState *state)
{
  state->N = 313;
  state->primes = NULL;
  state->primeCount = 0;

  state->points = NULL;
  state->pointCount = 0;

  state->zoom = 1.0f;
  state->offsetX = 0.0f;
  state->offsetY = 0.0f;

  state->showInputBox = false;
  memset(state->inputBuffer, 0, sizeof(state->inputBuffer));
  state->inputResult = 0;

  state->mode = MODE_SCATTER;
  state->needsRecompute = true;
}

void cleanup_state(Appstate *state)
{
  free(state->primes);
  free(state->points);
}
