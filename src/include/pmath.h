# ifndef PONG_MATH_H
# define PONG_MATH_H
# include <math.h>

# define PI M_PI

// BASE //
float pSquaredf(float x);
int pSquared(int x);
float radToDeg(float rad);
float degToRad(float deg);

// VECTORS //
// Vec2
typedef struct {
	float x, y;
} Vec2;

// Vec3
typedef struct {
	float x, y, z;
} Vec3;

// Vec4
typedef struct {
	float x, y, z, w;
} Vec4;

// MATRICES //

# endif