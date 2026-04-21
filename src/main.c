// prime number explorer
// by hunter freeman

#include "state.h"
#include "render.h"
#include "ui.h"
#include "prime_gen.h"
#include "modes.h"
#include <stdlib.h>

#include "raylib.h"
#include "raygui.h"

int main(void)
{
    AppState state;
    init_state(&state);
    regenerate_primes(&state);
    state.needsRecompute = true;
    InitWindow(1200, 800, "Prime Number Explorer");
    SetTargetFPS(30);

    while (!WindowShouldClose()) {
        handle_input(&state);
        
        if (state.needsRecompute) {
            regenerate_primes(&state);
            compute_points_linear(&state);
            state.needsRecompute = false;
        }
        
        BeginDrawing();
        
        ClearBackground(RAYWHITE);
        render(&state);
        
        EndDrawing();
    }
    cleanup_state(&state);
    CloseWindow();
        
    return 0;
}
