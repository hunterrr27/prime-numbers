// prime number explorer
// by hunter freeman

#include "state.h"
#include "render.h"
#include "ui.h"
#include "prime_gen.h"
#include "modes.h"

#include "raylib.h"
#include "raygui.h"

int main(void)
{
    Appstate state = init_state();
    InitWindow(1200, 800, "Prime Number Explorer");

    while (!WindowShouldClose()) {
        handle_input(&state);
        
        if (state.needs_recompute) {
            regenerate_primes(&state);
            regenerate_points(&state);
            state.needs_recompute = false;
        }
        
        BeginDrawing();
        
        ClearBackground(RAYWHITE);
        render_grid(&state);
        render_point(&state);
        draw_ui(&state);
        
        EndDrawing();
        
    cleanup_state(&state);
    CloseWindow();
        
    return 0;
}
