#ifndef STATE_H
#define STATE_H

#include <stdbool.h>

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
    bool dropdownEditMode;

    // Recompute flags
    bool needsRecompute;

    // extras i defined that i might not need
    int screenHeight;
    int screenWidth;

} AppState;

typedef struct Point {
    float x, y;
} Point;

// State management
void init_state(AppState *state);
void cleanup_state(AppState *state);

#endif
