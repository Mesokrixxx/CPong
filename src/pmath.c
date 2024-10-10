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

// MATRICES //

