# ifndef PONG_MATH_H
# define PONG_MATH_H

# define PI 3.14159265359

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

Vec2 vec2(float x, float y);
Vec2 addVec2s(Vec2 vecA, Vec2 vecB);
Vec2 subVec2s(Vec2 vecA, Vec2 vecB);
Vec2 scaleVec2(Vec2 vec, float x);
float dotVec2s(Vec2 vecA, Vec2 vecB);
Vec2 normalizeVec2(Vec2 vec);
float lenVec2(Vec2 vec);

// Vec3
typedef struct {
	float x, y, z;
} Vec3;

Vec3 vec3(float x, float y, float z);
Vec3 vec3FromVec2(Vec2 src, float z);
Vec3 addVec3s(Vec3 vecA, Vec3 vecB);
Vec3 subVec3s(Vec3 vecA, Vec3 vecB);
Vec3 scaleVec3(Vec3 vec, float x);
float dotVec3s(Vec3 vecA, Vec3 vecB);
Vec3 crossVec3s(Vec3 vecA, Vec3 vecB);
Vec3 normalizeVec3(Vec3 vec);
float lenVec3(Vec3 vec);

// Vec4
typedef struct {
	float x, y, z, w;
} Vec4;

Vec4 vec4(float x, float y, float z, float w);
Vec4 vec4FromVec3(Vec3 src, float w);
Vec4 addVec4s(Vec4 vecA, Vec4 vecB);
Vec4 subVec4s(Vec4 vecA, Vec4 vecB);
Vec4 scaleVec4(Vec4 vec, float x);
float dotVec4s(Vec4 vecA, Vec4 vecB);
Vec4 normalizeVec4(Vec4 vec);
float lenVec4(Vec4 vec);

// MATRICES //
// Mat4
typedef struct {
	float m[4][4];
} Mat4;

Mat4 mat4Zero();
Mat4 mat4(float x);
Mat4 translateMat4(Mat4 mat, Vec3 vec);
Mat4 scaleMat4(Mat4 mat, Vec3 vec);
Mat4 rotateMat4(Mat4 mat, float angle, Vec3 axis);

// Mix of Vectors and Matrices
Vec4 mulMat4Vec4(Mat4 mat, Vec4 vec);

# endif