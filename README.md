# icoptr-gui
A little GUI program for my 0x0 instance

# Building
## Requirements
- C++ compiler (g++ or clang)
- GNU Make
- GLFW3
- CURL

### OpenGL3
```bash
git clone --recursive --shallow-submodules https://github.com/ico277/icoptr-gui
cd icoptr-gui/
make -j$(nproc) BACKEND=OPENGL3
```

### OpenGL2
```sh
git clone --recursive --shallow-submodules https://github.com/ico277/icoptr-gui
cd icoptr-gui/
make -j$(nproc) BACKEND=OPENGL2
```
