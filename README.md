# icoptr-gui
A little GUI program for my 0x0 instance

# Building
## Requirements
- C++ compiler (g++ or clang)
- GNU Make
- GLFW3

## Compiling

### OpenGL3
```bash
make -j$(nproc) BACKEND=OPENGL3
```

### OpenGL2
```bash
make -j$(nproc) BACKEND=OPENGL2
```
