# ifndef PONG_MATH_H
# define PONG_MATH_H
# include <math.h>

# define PI M_PI

// BASE //
float pSquaredf(float x);
int pSquared(int x);
float radToDef(float rad);
float degToRad(float deg);

// VECTORS //
typedef float Vec2[2];
typedef float Vec3[3];
typedef float Vec4[4];

// Vectors 2 - float
float initVec2(Vec2 vec, float x, float y);
float initUnitVec2(Vec2 vec, float n);
float scaleVec2(Vec2 vec, float x);
float negateVec2(Vec2 vec);
float addVec2s(Vec2 vecA, Vec2 vecB, Vec2 dest);
float subVec2s(Vec2 vecA, Vec2 vecB, Vec2 dest);
float normalizeVec2(Vec2 vec, Vec2 dest);
float lenVec2(Vec2 vec);
float dotVec2s(Vec2 vecA, Vec2 vecB);
float getRadAngleOfVec2s(Vec2 vecA, Vec2 vecB);
float getDegAngleOfVec2s(Vec2 vecA, Vec2 vecB);

// Vectors 3 - float
float initVec3(Vec3 vec, float x, float y, float z);
float initUnitVec3(Vec3 vec, float n);
float initVec3FromVec2(Vec3 dest, Vec2 src, float z);
float scaleVec3(Vec3 vec, float x);
float negateVec3(Vec3 vec);
float addVec3s(Vec3 vecA, Vec3 vecB, Vec3 dest);
float subVec3s(Vec3 vecA, Vec3 vecB, Vec3 dest);
float normalizeVec3(Vec3 vec, Vec3 dest);
float lenVec3(Vec3 vec);
float dotVec3s(Vec3 vecA, Vec3 vecB);
float getRadAngleOfVec3s(Vec3 vecA, Vec3 vecB);
float getDegAngleOfVec3s(Vec3 vecA, Vec3 vecB);
float crossVec3s(Vec3 vecA, Vec3 vecB, Vec3 dest);

// Vectors 4 - float
float initVec4(Vec4 vec, float x, float y, float z, float w);
float initUnitVec4(Vec4 vec, float n);
float initVec4FromVec3(Vec4 dest, Vec3 src, float w);
float scaleVec4(Vec4 vec, float x);
float negateVec4(Vec4 vec);
float addVec4s(Vec4 vecA, Vec4 vecB, Vec4 dest);
float subVec4s(Vec4 vecA, Vec4 vecB, Vec4 dest);
float normalizeVec4(Vec4 vec, Vec4 dest);
float lenVec4(Vec4 vec);
float dotVec4s(Vec4 vecA, Vec4 vecB);
float getRadAngleOfVec4s(Vec4 vecA, Vec4 vecB);
float getDegAngleOfVec4s(Vec4 vecA, Vec4 vecB);

// MATRICES //

# endif