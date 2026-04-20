#ifndef MODES_H
#define MODES_H

#include "state.h"

void compute_points_linear(AppState *state);
void compute_points_step(AppState *state);
void compute_points_ulam(AppState *state);
void compute_points_polar(AppState *state);

void regenerate_points(AppState *state);

#endif
