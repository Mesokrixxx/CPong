# ifndef PONG_MAIN_H
# define PONG_MAIN_H
# include <stdint.h> 
#include <stdio.h>
# include <SDL2/SDL.h>

typedef float    f32;
typedef double   f64;
typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t   i8;
typedef int16_t  i16;
typedef int32_t  i32;
typedef int64_t  i64;

// Boolean
typedef enum { false = 0, true = 1 } Bool;

// Vector2
typedef struct Vec2_s { f32 x, y; } Vec2;
typedef struct Vec2i_s { i32 x, y; } Vec2i;

// Math
# define min(a, b) ({ __typeof__(a) _a = (a), _b = (b); (__typeof__(a)) (_a < _b ? _a : _b); })
# define max(a, b) ({ __typeof__(a) _a = (a), _b = (b); (__typeof__(a)) (_a > _b ? _a : _b); })

// Debug
# define ASSERT(_c, ...) if (!(_c)) { fprintf(stderr, __VA_ARGS__); exit(1); }

// Variables
# define WindowWidth 1280
# define WindowHeight 720

# define MapWidth 384
# define MapHeight 216

# endif