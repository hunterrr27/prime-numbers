// purpose is to handle user interaction and update the AppState
// detects kbm i/o, handles raygui widgets, opens text input boxes, switches visualization modes, sets needsRecompute = true when needed, adjusts zoom and pan, etc
// ui.c does NOT draw points, do math, or generate prime numbers

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include "ui.h"
#include "state.h"
#include "raylib.h"

void handle_input(Appstate *state)
{
  // handle input for plot mode dropdown box and N text input box

}

void draw_ui(Appstate *state)
{
  // draw plot mode dropdown box and N text input box
  // Rectangle box = {GetScreenWidth() / 2 - 200, GetScreenHeight() / 2 - 60, 400, 120};
  // GUITextInputBox(Rectangle){box, "Enter N", "Type a new value for N", state.inputbuffer, sizeof(state.inputbuffer), true};
  
  // draw mouse (x,y) coordinates in bottom left of screen 
  // Vector 2 mouse = GetMousePosition();
  // DrawText(FormatText("(%d,%d)", mouse.x, mouse.y), 50, GetScreenHeight() - 50, 10, RED);

}

