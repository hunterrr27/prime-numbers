// purpose is to draw things on the screen using raylib
// draws the cartesian grid, draws the points, draws lines/shapes/colors, applies zoom and pan, draws other UI elements as needed
// this file should NOT have UI logic, mode logic, or input handling
// it takes app data from AppState state and performs raylib Draw() functions

#include "render.h"
#include "raylib.h"
#include "raygui.h"
#include <stdlib.h>
#include "ui.h"

void render_points(const AppState *state)
{
    // for loop from 0 to pointCount
    // set point x coordinate to be points[i].x + offsetX * the zoom and scale factor
    for (int i = 0; i < state->pointCount; i++) {
        state->points[i].x = (state->points[i].x + state->offsetX) * state->zoom;
        state->points[i].y = (state->points[i].y + state->offsetY) * state->zoom;
    }

}

void render_grid(const AppState *state)
{
    // draw x and y axis
    // x axis 
    DrawLine(50, state->screenHeight - 50, state->screenWidth - 50, state->screenWidth - 50, BLACK);
    // y axis DrawLine(50, 50, 50, GetScreenHeight() - 50);
    DrawLine(50, 50, 50, state->screenHeight - 50, BLACK);

}

void render_ui(const AppState *state)
{
    // draw N text input box
    Rectangle box = {GetScreenWidth() / 2 - 200, GetScreenHeight() / 2 - 60, 400, 120};
    GuiTextInputBox(box, "Enter N", "Type a new value for N", "OK", state->inputBuffer, sizeof(state->inputBuffer), false);
    
    // draw plot mode dropdown box
    GuiDropdownBox(box, "MODE_LINEAR;MODE_STEP;MODE_POLAR;MODE_ULAM;MODE_COUNT", state->dropdownActive, state->dropdownEditMode);

    
    // draw mouse (x,y) coordinates in bottom left of screen 
    Vector2 mouse = GetMousePosition();
    DrawText(TextFormat("(%d,%d)", mouse.x, mouse.y), 50, GetScreenHeight() - 50, 10, RED); 

    // draw FPS counter in bottom left near mouse coordinates
    DrawFPS(50, state->screenHeight - 40);

}

void render(const AppState *state) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    render_grid(state);
    render_points(state);
    render_ui(state);

    EndDrawing();
}
