# Prime Number Explorer
## by Hunter Freeman
 
*A modular, interactive prime number visualization tool built in C with Raylib.*

Prime Explorer is a graphical application for exploring the structure and beauty of prime numbers through multiple visualization modes. It is designed with a clean, scalable architecture so new modes, UI features, and rendering techniques can be added easily.

The project is intentionally structured like a small game engine or scientific visualization tool, with clear separation between:

- **State management**  
- **Prime generation**  
- **Visualization modes**  
- **Rendering**  
- **UI & input handling**  

---

# **Features**
- Interactive visualization of prime numbers  
- Multiple plotting modes (linear, step, Ulam spiral, polar, etc.)  
- Adjustable N (number of primes to compute)  
- Raygui‑based UI for input and mode switching  
- Zoom and pan controls  
- Clean modular architecture  
- Easy to extend with new visualization modes  

---

# **Project Structure**

```
prime_explorer/
│
├── src/
│   ├── main.c
│   ├── state.c
│   ├── state.h
│   ├── prime_gen.c
│   ├── prime_gen.h
│   ├── modes.c
│   ├── modes.h
│   ├── render.c
│   ├── render.h
│   ├── ui.c
│   ├── ui.h
│
├── assets/        (fonts, icons, etc)
├── Makefile
└── README.md
```

---

# **High‑Level Architecture**

Prime Explorer follows a simple but powerful loop:

```
UI → State → Prime Generation → Mode Computation → Rendering
```

### **UI**
Handles user input (mouse, keyboard, Raygui widgets).  
Updates the AppState (N, mode, zoom, pan, etc.).

### **State**
Stores all global program data in one struct (`AppState`).  
Controls when recomputation is needed.

### **Prime Generation**
Computes the list of primes up to N.  
Stores results in `state->primes`.

### **Modes**
Transforms primes into drawable points.  
Each mode has its own coordinate logic.

### **Rendering**
Draws the grid, points, and UI using Raylib.

---

# **Build Instructions**

### Requirements
- C compiler (gcc/clang/MSVC)
- Raylib
- Raygui
- Make

### Build
```
make
```

### Run
```
./prime_explorer
```

---

# **AppState Overview**

All global program data lives in one struct:

```c
typedef struct {
    int N;
    int *primes;
    int primeCount;

    Point *points;
    int pointCount;

    float zoom, offsetX, offsetY;

    bool showInputBox;
    char inputBuffer[32];
    int inputResult;

    PlotMode mode;
    bool needsRecompute;

    int screenWidth, screenHeight;
} AppState;
```

This makes the program modular and easy to extend.

---

# **Module‑by‑Module Explanation + Pseudocode**

Below is a clear explanation of what each `.c` file does and the pseudocode for its internal logic.

---

# **main.c — Program Entry Point**

### Responsibilities
- Initialize Raylib  
- Initialize AppState  
- Main loop  
- Call UI, prime generation, modes, and rendering  
- Cleanup  

### Pseudocode

```
init_state(state)
InitWindow()

while window open:
    handle_input(state)

    if state.needsRecompute:
        regenerate_primes(state)
        regenerate_points(state)
        state.needsRecompute = false

    render(state)

cleanup_state(state)
CloseWindow()
```

---

# **state.c — Global State Management**

### Responsibilities
- Initialize AppState with defaults  
- Allocate/free memory  
- Reset flags  

### Pseudocode

```
function init_state(state):
    state.N = 313
    state.zoom = 1.0
    state.offsetX = screenWidth/2
    state.offsetY = screenHeight/2
    state.mode = MODE_LINEAR
    state.needsRecompute = true
    allocate buffers (primes, points)

function cleanup_state(state):
    free(state.primes)
    free(state.points)
```

---

# **prime_gen.c — Prime Number Generation**

### Responsibilities
- Compute primes up to N  
- Store them in state  
- Provide is_prime() helper  

### Pseudocode

```
function is_prime(n):
    if n < 2: return false
    for i from 2 to sqrt(n):
        if n % i == 0: return false
    return true

function regenerate_primes(state):
    free old primes
    allocate new array
    for i from 2 to state.N:
        if is_prime(i):
            append to state.primes
    state.primeCount = count
```

Later you can replace this with a sieve.

---

# **modes.c — Visualization Modes**

### Responsibilities
- Convert primes → (x, y) points  
- One function per mode  
- A dispatcher function  

### Pseudocode

```
function compute_points_linear(state):
    for i in 0..primeCount:
        x = i
        y = primes[i]
        store point

function compute_points_step(state):
    ...

function compute_points_ulam(state):
    ...

function compute_points_polar(state):
    ...

function regenerate_points(state):
    switch state.mode:
        case LINEAR: compute_points_linear(state)
        case STEP: compute_points_step(state)
        case ULAM: compute_points_ulam(state)
        case POLAR: compute_points_polar(state)
```

---

# **render.c — Drawing**

### Responsibilities
- Draw grid  
- Draw points  
- Draw UI text  
- Handle world→screen transforms  

### Pseudocode

```
function world_to_screen(x, y, state):
    return (x * zoom + offsetX, y * zoom + offsetY)

function render_grid(state):
    draw vertical/horizontal lines

function render_points(state):
    for each point:
        screenPos = world_to_screen(point)
        DrawCircle(screenPos)

function render_ui(state):
    DrawText("Prime Explorer")
    DrawText("N = ...")
    DrawText("Mode = ...")

function render(state):
    BeginDrawing()
    ClearBackground()
    render_grid(state)
    render_points(state)
    render_ui(state)
    EndDrawing()
```

---

# **ui.c — Input Handling & Raygui**

### Responsibilities
- Mouse input  
- Keyboard input  
- Raygui text input box  
- Mode switching  
- Zoom/pan  

### Pseudocode

```
function handle_input(state):
    if mouse wheel moved:
        adjust zoom

    if right mouse drag:
        adjust offsetX/Y

    if user clicks "Set N" button:
        showInputBox = true

    if showInputBox:
        result = GuiTextInputBox(...)
        if OK pressed:
            state.N = atoi(inputBuffer)
            state.needsRecompute = true

    if user selects mode button:
        state.mode = newMode
        state.needsRecompute = true
```

---

# **Future Roadmap**

### Visualization
- Animated Ulam spiral  
- Prime gap heatmaps  
- 3D rendering  
- Shaders  

### UI
- Dropdown for modes  
- Sliders for zoom  
- Color themes  

### Performance
- Sieve of Eratosthenes  
- Segmented sieve  
- Multithreaded prime generation  


