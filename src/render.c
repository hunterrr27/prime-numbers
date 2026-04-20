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


}

void render_ui(const AppState *state)
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
