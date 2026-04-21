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
  // parse inputbuffer for N
  if (strlen(state->inputBuffer) > 0) {
    state->N = atoi(state->inputBuffer);
    state->needsRecompute = true;
    memset(state->inputBuffer, 0, sizeof(state->inputBuffer));
  }
  
  // handle input for plot mode dropdown box 

  // handle input for N text box

  // handle input for zoom and pan

  // handle input for mouse hovering over points to display coordinates

  
}


