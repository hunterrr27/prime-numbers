// purpose is to draw things on the screen using raylib
// draws the cartesian grid, draws the points, draws lines/shapes/colors, applies zoom and pan, draws other UI elements as needed
// this file should NOT have UI logic, mode logic, or input handling
// it takes app data from AppState state and performs raylib Draw() functions

#include "render.h"
#include "raylib.h"

void render_points(const AppState *state)
{
    // for loop from 0 to pointCount
    // set point x coordinate to be points[i].x + offsetX * the zoom and scale factor

}

void render_grid(const AppState *state)
{
    // draw x and y axis
    // x axis DrawLine(50, GetScreenHeight() - 50, GetScreenWidth() - 50, GetScreenHeight - 50);
    // y axis DrawLine(50, 50, 50, GetScreenHeight() - 50);

}

void render_ui(const AppState *state)
{
    // draw N text input box
    // Rectangle box = {GetScreenWidth() / 2 - 200, GetScreenHeight() / 2 - 60, 400, 120};
    // GUITextInputBox(Rectangle){box, "Enter N", "Type a new value for N", state.inputbuffer, sizeof(state.inputbuffer), true};
    
    // draw plot mode dropdown box
    // GUIDropdownBox(Rectangle){box, "Choose a plot mode", MODE_LINEAR;MODE_STEP;MODE_POLAR;MODE_ULAM;MODE_COUNT, state.inputbuffer, sizeof(state.inputbuffer), true};
    
    // draw mouse (x,y) coordinates in bottom left of screen 
    // Vector 2 mouse = GetMousePosition();
    // DrawText(FormatText("(%d,%d)", mouse.x, mouse.y), 50, GetScreenHeight() - 50, 10, RED); 

    // draw FPS counter in bottom left near mouse coordinates
    // DrawFPS();


}

void render(const AppState *state) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    render_grid(state);
    render_points(state);
    render_ui(state);

    EndDrawing();
}
