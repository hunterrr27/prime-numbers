#include "primes.h"

typedef struct Appstate {
  int N;
  int *primes;
  int prime_count;
  plot_mode mode;
  float zoom;
  float offsetX;
  float offsetY;
  bool show_input_box;
  char input_buffer[32];
  int input_result;
  bool needs_recompute;
} Appstate;
