// purpose is to handle user interaction and update the AppState
// detects kbm i/o, handles raygui widgets, opens text input boxes, switches visualization modes, sets needsRecompute = true when needed, adjusts zoom and pan, etc
// ui.c does NOT draw points, do math, or generate prime numbers

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include "ui.h"
#include "state.h"
#include "raylib.h"

void handle_input(AppState *state)
{
  int N = 313;
  // handle input for plot mode dropdown box 

  // handle input for N text box
  state->N = N;

  // handle input for zoom and pan

  // handle input for mouse hovering over points to display coordinates

  
}


