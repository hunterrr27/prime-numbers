#include "state.h"

void init_state(Appstate *state)
{
  Appstate state = {
      .N = 313,
      .zoom = 1.0f,
      .offsetX = 0,
      .offsetY = 0,
      .mode = MODE_LINEAR,
      .needs_recompute = true
  }
}

void cleanup_state(Appstate *state)
{
  Appstate state = { 0 };
}
