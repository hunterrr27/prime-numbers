#ifndef RENDER_H
#define RENDER_H

#include "state.h"

void render_grid(const AppState *state);
void render_points(const AppState *state);
void render_ui(const AppState *state);

void render(const AppState *state);

#endif

