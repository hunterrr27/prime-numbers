// purpose is to draw things on the screen using raylib
// draws the cartesian grid, draws the points, draws lines/shapes/colors, applies zoom and pan, draws other UI elements as needed
// this file should NOT have UI logic, mode logic, or input handling
// it takes app data from AppState state and performs raylib Draw() functions

#include "render.h"
#include "raylib.h"

void render_points(const Appstate *state)
{


}

void render_grid(const Appstate *state)
{


}

void render_ui(const Appstate *state)
{


}

void render(const AppState *state) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    render_grid(state);
    render_points(state);
    render_ui(state);

    EndDrawing();
}
