# include "include/pmath.h"
# include <math.h>

// BASE //
float pSquaredf(float x)
{ 
	return x * x;
}

double pSquared(double x)
{ 
	return x * x;
}

float radToDeg(float rad)
{ 
	return (rad * 180) / PI;
}

float degToRad (float deg)
{ 
	return (deg * PI) / 180;
}

// VECTORS //
// Vec2
Vec2 vec2(float x, float y)
{
	Vec2 vec = {x, y};
	return vec;
}

Vec2 addVec2s(Vec2 vecA, Vec2 vecB)
{ 
	return vec2(vecA.x + vecB.x, vecA.y + vecB.y);
}

Vec2 subVec2s(Vec2 vecA, Vec2 vecB)
{ 
	return vec2(vecA.x - vecB.x, vecA.y - vecB.y);
}

Vec2 scaleVec2(Vec2 vec, float x)
{ 
	return vec2(vec.x * x, vec.y * x);
}

float dotVec2s(Vec2 vecA, Vec2 vecB)
{ 
	return ((vecA.x * vecB.x) + (vecA.y * vecB.y));
}

Vec2 normalizeVec2(Vec2 vec)
{
	float lenVec = lenVec2(vec);
	return vec2(vec.x / lenVec, vec.y / lenVec);
}

float lenVec2(Vec2 vec)
{
	return sqrtf(pSquaredf(vec.x) + pSquaredf(vec.y));
}

// Vec3
Vec3 vec3(float x, float y, float z)
{
	Vec3 vec = {x, y, z};
	return vec;
}

Vec3 vec3FromVec2(Vec2 src, float z)
{
	return vec3(src.x, src.y, z);
}

Vec3 addVec3s(Vec3 vecA, Vec3 vecB)
{
	return vec3(vecA.x + vecB.x, vecA.y + vecB.y, vecA.z + vecB.z);
}

Vec3 subVec3s(Vec3 vecA, Vec3 vecB)
{
	return vec3(vecA.x - vecB.x, vecA.y - vecB.y, vecA.z - vecB.z);
}

Vec3 scaleVec3(Vec3 vec, float x)
{
	return vec3(vec.x * x, vec.y * x, vec.z * x);
}

float dotVec3s(Vec3 vecA, Vec3 vecB)
{
	return ((vecA.x * vecB.x) + (vecA.y * vecB.y) + (vecA.z * vecB.z));
}

Vec3 crossVec3s(Vec3 vecA, Vec3 vecB)
{
	return vec3(((vecA.y * vecB.z) - (vecA.z * vecB.y)), ((vecA.z * vecB.x) - (vecA.x * vecB.z)), ((vecA.x * vecB.y) - (vecA.y * vecB.x)));
}

Vec3 normalizeVec3(Vec3 vec)
{
	float lenVec = lenVec3(vec);
	return vec3(vec.x / lenVec, vec.y / lenVec, vec.z / lenVec);
}

float lenVec3(Vec3 vec)
{
	return sqrtf(pSquaredf(vec.x) + pSquaredf(vec.y) + pSquaredf(vec.z));
}

// Vec4
Vec4 vec4(float x, float y, float z, float w)
{
	Vec4 vec = {x, y, z, w};
	return vec;
}

Vec4 vec4FromVec3(Vec3 src, float w)
{
	return vec4(src.x, src.y, src.z, w);
}

Vec4 addVec4s(Vec4 vecA, Vec4 vecB)
{
	return vec4(vecA.x + vecB.x, vecA.y + vecB.y, vecA.z + vecB.z, vecA.w + vecB.w);
}

Vec4 subVec4s(Vec4 vecA, Vec4 vecB)
{
	return vec4(vecA.x - vecB.x, vecA.y - vecB.y, vecA.z - vecB.z, vecA.w - vecB.w);
}

Vec4 scaleVec4(Vec4 vec, float x)
{
	return vec4(vec.x * x, vec.y * x, vec.z * x, vec.w * x);
}

float dotVec4s(Vec4 vecA, Vec4 vecB)
{
	return ((vecA.x * vecB.x) + (vecA.y * vecB.y) + (vecA.z * vecB.z) + (vecA.w * vecB.w));
}

Vec4 normalizeVec4(Vec4 vec)
{
	float lenVec = lenVec4(vec);
	return vec4(vec.x / lenVec, vec.y / lenVec, vec.z / lenVec, vec.w / lenVec);
}

float lenVec4(Vec4 vec)
{
	return sqrtf(pSquaredf(vec.x) + pSquaredf(vec.y) + pSquaredf(vec.z) + pSquaredf(vec.w));
}

// MATRICES //
// Mat4
Mat4 mat4Zero()
{
	Mat4 mat = {0};
	return mat;
}

Mat4 mat4(float x)
{
	Mat4 mat = mat4Zero();

	for (int i = 0; i < 4; i++)
		mat.m[i][i] = x;

	return mat;
}

Mat4 translateMat4(Mat4 mat, Vec3 vec)
{
	Mat4 out = mat4(1.0f);

	out.m[0][3] = vec.x;
	out.m[1][3] = vec.y;
	out.m[2][3] = vec.z;

	return mulMat4s(mat, out);
}

Mat4 scaleMat4(Mat4 mat, Vec3 vec)
{
	Mat4 out = mat4(1.0f);

	out.m[0][0] = vec.x;
	out.m[1][1] = vec.y;
	out.m[2][2] = vec.z;

	return mulMat4s(mat, out);
}

Mat4 rotateMat4(Mat4 mat, float angle, Vec3 axis)
{
	Mat4 rotationMat4 = mat4Zero();

	rotationMat4.m[0][0] = cosf(angle) + pSquaredf(axis.x) * (1 - cosf(angle));
	rotationMat4.m[0][1] = axis.x * axis.y * (1 - cosf(angle)) - axis.z * sinf(angle);
	rotationMat4.m[0][2] = axis.x * axis.z * (1 - cosf(angle)) + axis.y * sinf(angle);

	rotationMat4.m[1][0] = axis.y * axis.x * (1 - cosf(angle)) + axis.z * sinf(angle);
	rotationMat4.m[1][1] = cosf(angle) + pSquaredf(axis.y) * (1 - cosf(angle));
	rotationMat4.m[1][2] = axis.y * axis.z * (1 - cosf(angle)) - axis.x * sinf(angle);

	rotationMat4.m[2][0] = axis.z * axis.x * (1 - cosf(angle)) - axis.y * sinf(angle);
	rotationMat4.m[2][1] = axis.z * axis.y * (1 - cosf(angle)) + axis.x * sinf(angle);
	rotationMat4.m[2][2] = cosf(angle) + pSquaredf(axis.z) * (1 - cosf(angle));

	rotationMat4.m[3][3] = 1;

	return mulMat4s(mat, rotationMat4);
}

Mat4 mulMat4s(Mat4 matA, Mat4 matB)
{
	Mat4 out;

	for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            out.m[i][j] = 0;
            for (int k = 0; k < 4; k++)
                out.m[i][j] += matA.m[i][k] * matB.m[k][j];
        }
    }

	return out;
}

// Mix of Vectors and Matrices
Vec4 mulMat4Vec4(Mat4 mat, Vec4 vec)
{
	Vec4 out;

	out.x = mat.m[0][0] * vec.x + mat.m[0][1] * vec.y + mat.m[0][2] * vec.z + mat.m[0][3] * vec.w;
	out.y = mat.m[1][0] * vec.x + mat.m[1][1] * vec.y + mat.m[1][2] * vec.z + mat.m[1][3] * vec.w;
	out.z = mat.m[2][0] * vec.x + mat.m[2][1] * vec.y + mat.m[2][2] * vec.z + mat.m[2][3] * vec.w;
	out.w = mat.m[3][0] * vec.x + mat.m[3][1] * vec.y + mat.m[3][2] * vec.z + mat.m[3][3] * vec.w;

	return out;
}