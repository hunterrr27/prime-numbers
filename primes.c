// primeexplorer.c
// prime number explorer
// by hunter freeman

#define RAYGUI_IMPLEMENTATION

#include "primes.h"

typedef enum {
    LINEAR = 0,
    STEP,
    POLAR,
    ULAM
} PlotType;

bool isPrime(int number)
{
    if (number < 2) return false;

    int limit = sqrt(number);
    for (int i = 2; i <= limit; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

void drawPrimeGraph(int *primes, int countPrimes, int N)
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Prime Number Explorer");
    SetTargetFPS(60);

    int plotTypeActive = LINEAR; 
    bool plotTypeEditMode = false;

    // this is mathematical origin since top left 0,0 regarded
    int originX = 50;
    int originY = screenHeight - 50;

    while (!WindowShouldClose())
    {
        //scale
        float xScale = (float)(screenWidth - 100) / countPrimes;
        float yScale = (float)(screenHeight - 100) / countPrimes;

        // linear plot 
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawLine(originX, originY, screenWidth - 50, originY, BLACK);
            DrawLine(originX, originY, originX, 50, BLACK);

            // input textbox and dropdown for plotting function
            GuiLabel((Rectangle){ 12, 62, 140, 24 }, TextFormat("Enter max value: "));
            GuiLabel((Rectangle){ 12, 10, 140, 24 }, "Plot type:");
            GuiDropdownBox((Rectangle){ 12, 8 + 24, 140, 28 }, "LINEAR;STEP;POLAR;ULAR", &plotTypeActive, plotTypeEditMode);

            for (int i = 0; i < countPrimes; i++) {
                float plotX = originX + (i * xScale);
                float plotY = originY - (i * yScale);
                DrawCircle(plotX, plotY, 3, RED);
                // draw small vertical line across x axis where point is at
                DrawLine(plotX, originY + 10, plotX, originY - 10, BLACK);
                // draw small horizontal line on y axis where point is at
                DrawLine(originX + 10, plotY, originX - 10, plotY, BLACK);
            }
        EndDrawing();

        // number theory w step function
        // Inside the while (!WindowShouldClose()) loop
        /* BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawLine(originX, originY, screenWidth - 50, originY, BLACK);
            DrawLine(originX, originY, originX, 50, BLACK);
            for (int i = 0; i < countPrimes - 1; i++) {
                // Current Prime (Step Start)
                float x1 = originX + (primes[i] * xScale);
                float y1 = originY - (i * yScale);

                // Next Prime (Step End)
                float x2 = originX + (primes[i+1] * xScale);
                float y2 = originY - ((i + 1) * yScale);

                // 1. Draw horizontal line to the next prime's X position
                DrawLine(x1, y1, x2, y1, BLUE);

                // 2. Draw vertical line "step up" at the next prime
                DrawLine(x2, y1, x2, y2, RED);
                
                // Optional: Draw a small dot at the jump point
                DrawCircle(x2, y2, 2, DARKGRAY);
            }
        EndDrawing(); */

        // ulam spiral
        /* BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawLine(originX, originY, screenWidth - 50, originY, BLACK);
            DrawLine(originX, originY, originX, 50, BLACK);

            for (int i = 0; i < countPrimes; i++) {
                float plotX = originX + (i * xScale);
                float plotY = originY - (i * yScale);
                DrawCircle(plotX, plotY, 3, RED);
                // draw small vertical line across x axis where point is at
                DrawLine(plotX, originY + 10, plotX, originY - 10, BLACK);
                // draw small horizontal line on y axis where point is at
                DrawLine(originX + 10, plotY, originX - 10, plotY, BLACK);
            }
        EndDrawing(); */


        // polar plot
        /* BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawLine(originX, originY, screenWidth - 50, originY, BLACK);
            DrawLine(originX, originY, originX, 50, BLACK);

            for (int i = 0; i < countPrimes; i++) {
                float plotX = originX + (i * xScale);
                float plotY = originY - (i * yScale);
                DrawCircle(plotX, plotY, 3, RED);
                // draw small vertical line across x axis where point is at
                DrawLine(plotX, originY + 10, plotX, originY - 10, BLACK);
                // draw small horizontal line on y axis where point is at
                DrawLine(originX + 10, plotY, originX - 10, plotY, BLACK);
            }
        EndDrawing(); */


    }
    CloseWindow();
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s N\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    if (N < 2) {
        printf("N must be >= 2\n");
        return 1;
    }

    // Allocate max possible space on the heap
    int *tmp = malloc(N * sizeof(int));
    if (!tmp) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    // Fill with primes
    int countPrimes = 0;
    for (int i = 2; i <= N; i++) {
        if (isPrime(i)) {
            tmp[countPrimes++] = i;
        }
    }

    // Shrink to exact size
    int *primes = realloc(tmp, countPrimes * sizeof(int));
    if (!primes) {
        // If realloc fails, tmp is still valid
        primes = tmp;
    }

    // Print primes (for debugging)
    for (int i = 0; i < countPrimes; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    // Call Raylib graphing function
    drawPrimeGraph(primes, countPrimes, N);

    // Cleanup
    free(primes);

    return 0;
}
