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

    Texture2D title_texture = LoadTexture("assets/title.png");    

    // this is mathematical origin since top left 0,0 regarded
    int originX = 50;
    int originY = screenHeight - 50;

    while (!WindowShouldClose())
    {
        //scale
        float xScale = (float)(screenWidth - 100) / countPrimes;
        float yScale = (float)(screenHeight - 100) / countPrimes;

        // get mouse position
        Vector2 mouse = GetMousePosition();

        // linear plot 
        BeginDrawing();
            // set bg color
            ClearBackground(RAYWHITE);

            //draw imported picture title.png
            DrawTexture(title_texture, 200, 0, RAYWHITE);

            // draw x and y axes
            DrawLine(originX, originY, screenWidth - 50, originY, BLACK);
            DrawLine(originX, originY, originX, 50, BLACK);

            //draw mouse pointer
            DrawCircleV(mouse, 3, RED);

            // input textbox and dropdown for plotting function
            

            for (int i = 0; i < countPrimes; i++) {
                float plotX = originX + (primes[i] * xScale);
                float plotY = originY - (primes[i] * yScale);
                DrawCircle(plotX, plotY, 3, RED);
                // draw small vertical line across x axis where point is at
                DrawLine(plotX, originY + 10, plotX, originY - 10, BLACK);
                // x axis labels
                DrawText(TextFormat("%d", primes[i]), plotX + 5, originY + 5, 10, BLACK);
                // draw small horizontal line on y axis where point is at
                DrawLine(originX + 10, plotY, originX - 10, plotY, BLACK);
                // y axis labels
                DrawText(TextFormat("%d", primes[i]), originX - 10, plotY + 5, 10, BLACK);

                // check for mouse collisions
                // highlight point (x, y) when hovering 
                if (CheckCollisionPointCircle(mouse, (Vector2){plotX, plotY}, 20)) {
                    DrawText(TextFormat("(%d, %d)", primes[i], primes[i]), mouse.x + 10, mouse.y - 20, 20, RED);
                }
            }

        EndDrawing();
    }
    UnloadTexture(title_texture);
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
