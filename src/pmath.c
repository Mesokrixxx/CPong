# include "include/pmath.h"

// BASE //
float pSquaredf(float x)
{ 
	return x * x;
}

int pSquared(int x)
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

