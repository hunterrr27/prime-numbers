#ifndef STATE_H
#define STATE_H

#include <stdbool.h>
#include "raylib.h"

typedef enum {
    MODE_LINEAR,
    MODE_STEP,
    MODE_ULAM,
    MODE_POLAR,
    MODE_COUNT
} PlotMode;

typedef struct {
    int N;
    int *primes;
    int primeCount;

    // Visualization points (computed by modes)
    struct Point *points;
    int pointCount;

    // Camera / view
    float zoom;
    float offsetX;
    float offsetY;

    // UI
    bool showInputBox;
    char inputBuffer[32];
    int inputResult;

    // Mode selection
    PlotMode mode;
    bool inputEditMode;
    int *inputActive;

    // Recompute flags
    bool needsRecompute;

    // extras i defined that i might not need
    int screenHeight;
    int screenWidth;
    Vector2 mouse;
    float scaleX;
    float scaleY;

} AppState;

typedef struct Point {
    float x, y;
} Point;

// State management
void init_state(AppState *state);
void cleanup_state(AppState *state);

#endif
