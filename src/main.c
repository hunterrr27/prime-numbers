// primeexplorer.c
// prime number explorer
// by hunter freeman

#define RAYGUI_IMPLEMENTATION

#include "primes.h"



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
        render_grid(Appstate *state);
        render_point(Appstate *state);
        draw_ui(&state);
        
        EndDrawing();
        
    cleanup_state(&state);
    CloseWindow();
        
    return 0;
}
