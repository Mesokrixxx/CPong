# ifndef PONG_MAIN_H
# define PONG_MAIN_H
# include "graphics.h"
# include "pmath.h"
# include <stdio.h>
# include <SDL2/SDL.h>

// Debug
# define ASSERT(_c, ...) if (!(_c)) { fprintf(stderr, __VA_ARGS__); exit(1); }

// Variables
# define WindowWidth 1280
# define WindowHeight 720

# define MapWidth 384
# define MapHeight 216

# endif