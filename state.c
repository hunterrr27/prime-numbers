#include "state.h"

Appstate init_state(void)
{
  return Appstate state = {
      .N = 313,
      .zoom = 1.0f,
      .offsetX = 0,
      .offsetY = 0,
      .mode = MODE_LINEAR,
      .needs_recompute = true
  }
}
