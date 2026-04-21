// purpose is to draw things on the screen using raylib
// draws the cartesian grid, draws the points, draws lines/shapes/colors, applies zoom and pan, draws other UI elements as needed
// this file should NOT have UI logic, mode logic, or input handling
// it takes app data from AppState state and performs raylib Draw() functions

#include "render.h"
#include "raylib.h"
#include "raygui.h"
#include <stdlib.h>
#include "ui.h"
#include "state.h"

void render_points(AppState *state)
{
    // set scale and inverse y
    // screenY = screenHeight - (worldY * scale)
    // for loop from 0 to pointCount
    // set point x coordinate to be points[i].x + offsetX * the zoom and scale factor
    // loop from 0 to number of points (same as number of primes, calculated from modes.c)
    Vector2 mouse = GetMousePosition();
    for (int i = 0; i < state->pointCount; i++) {

        // create new float x and set it = to points.x
        float x = (state->points[i].x * state->scaleX) + state->offsetX;

        // set new float y = points.y
        float y = state->screenHeight - (state->points[i].y * state->scaleY) - state->offsetY;

        //draw a circle at x,y 
        DrawCircle(x, y, 3, BLUE);

        // draw grid lines at each point
        DrawLine(x, 40, x, 60, BLACK);
        DrawLine(40, y, 60, y, BLACK);

        // check mouse collision to show coords when hovering
        Vector2 center = {x, y};
        if (CheckCollisionPointCircle(mouse, center, 10)) {
            DrawText(TextFormat("%.0f,%.0f", state->points[i].x, state->points[i].y), x + 20, y - 20, 20, RED);
        }

        
    }

}

void render_grid(AppState *state)
{
    // draw x and y axis
    // x axis 
    DrawLine(50, state->screenHeight - 50, state->screenWidth - 50, state->screenHeight - 50, BLACK);

    // y axis DrawLine(50, 50, 50, GetScreenHeight() - 50);
    DrawLine(50, 50, 50, state->screenHeight - 50, BLACK);

    
}

void render_ui(AppState *state)
{
    // draw N text input box
    Rectangle textBox = {950, 50, 200, 50};

    // guitextinputbox returns 1 if OK is clicked
    if(GuiTextBox(textBox, state->inputBuffer, sizeof(state->inputBuffer), state->inputEditMode)) {
        // toggle edit mode off when finished
        state->inputEditMode = !state->inputEditMode;

        if (IsKeyPressed(KEY_ENTER)) {
            // convert entered N value to int and update state
            int newValue = atoi(state->inputBuffer);
            if (newValue > 2) {
                state->N = newValue;
                state->needsRecompute = true;
                state->inputEditMode = false;
            }
        }
    }
    
    // draw plot mode dropdown box
    // Rectangle dropdownBox = {600, 200, 400, 100};
    // GuiDropdownBox(dropdownBox, "MODE_LINEAR;MODE_STEP;MODE_POLAR;MODE_ULAM;MODE_COUNT", state->dropdownActive, state->dropdownEditMode);

    
    // draw mouse (x,y) coordinates in bottom left of screen 
    DrawText(TextFormat("(%d,%d)", GetMouseX(), GetMouseY()), 50, GetScreenHeight() - 50, 10, RED); 

    // draw FPS counter in bottom left near mouse coordinates
    DrawFPS(50, state->screenHeight - 40);

}

void render(AppState *state) {

    render_grid(state);
    render_points(state);
    render_ui(state);

}
