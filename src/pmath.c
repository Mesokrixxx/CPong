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
	return ((rad * 180) / PI);
}

float degToRad(float deg)
{
	return ((deg * PI) / 180);
}

// VECTORS //
// Vectors 2 - float
float initVec2(Vec2 vec, float x, float y)
{
	vec[0] = x;
	vec[1] = y;
}

float initUnitVec2(Vec2 vec, float n)
{
	return initVec2(vec, n, n);
}

float scaleVec2(Vec2 vec, float x)
{
	vec[0] += x;
	vec[1] += x;
}

float negateVec2(Vec2 vec)
{
	vec[0] *= -1;
	vec[1] *= -1;
}

float addVec2s(Vec2 vecA, Vec2 vecB, Vec2 dest)
{
	dest[0] = vecA[0] + vecB[0];
	dest[1] = vecA[1] + vecB[1];
}

float subVec2s(Vec2 vecA, Vec2 vecB, Vec2 dest)
{
	dest[0] = vecA[0] - vecB[0];
	dest[1] = vecA[1] - vecB[1];
}

float normalizeVec2(Vec2 vec, Vec2 dest)
{
	float lenVec = lenVec2(vec);
	return initVec2(dest, vec[0] / lenVec, vec[1] / lenVec);
}

float lenVec2(Vec2 vec)
{
	return (sqrtf(pSquaredf(vec[0]) + pSquaredf(vec[1])));
}

float dotVec2s(Vec2 vecA, Vec2 vecB)
{
	return ((vecA[0] * vecB[0]) + (vecA[1] * vecB[1]));
}

float getRadAngleOfVec2s(Vec2 vecA, Vec2 vecB)
{
	Vec2 normVecA;
	Vec2 normVecB;

	normalizeVec2(vecA, normVecA);
	normalizeVec2(vecB, normVecB);

	return (acos(dotVec2s(normVecA, normVecB)));
}

float getDegAngleOfVec2s(Vec2 vecA, Vec2 vecB)
{
	return (radToDeg(getRadAngleOfVec2s(vecA, vecB)));
}

// Vectors 3 - float
float initVec3(Vec3 vec, float x, float y, float z)
{
	vec[0] = x;
	vec[1] = y;
	vec[2] = z;
}

float initUnitVec3(Vec3 vec, float n)
{
	return initVec3(vec, n, n, n);
}

float initVec3FromVec2(Vec3 dest, Vec2 src, float z)
{
	return initVec3(dest, src[0], src[1], z);
}

float scaleVec3(Vec3 vec, float x)
{
	vec[0] += x;
	vec[1] += x;
	vec[2] += x;
}

float negateVec3(Vec3 vec)
{
	vec[0] *= -1;
	vec[1] *= -1;
	vec[2] *= -1;
}

float addVec3s(Vec3 vecA, Vec3 vecB, Vec3 dest)
{
	dest[0] = vecA[0] + vecB[0];
	dest[1] = vecA[1] + vecB[1];
	dest[2] = vecA[2] + vecB[2];
}

float subVec3s(Vec3 vecA, Vec3 vecB, Vec3 dest)
{
	dest[0] = vecA[0] - vecB[0];
	dest[1] = vecA[1] - vecB[1];
	dest[2] = vecA[2] - vecB[2];
}

float normalizeVec3(Vec3 vec, Vec3 dest)
{
	float lenVec = lenVec3(vec);
	return initVec3(dest, vec[0] / lenVec, vec[1] / lenVec, vec[2] / lenVec);
}

float lenVec3(Vec3 vec)
{
	return (sqrtf(pSquaredf(vec[0]) + pSquaredf(vec[1]) + pSquaredf(vec[2])));
}

float dotVec3s(Vec3 vecA, Vec3 vecB)
{
	return ((vecA[0] * vecB[0]) + (vecA[1] * vecB[1]) + (vecA[2] * vecB[2]));
}

float getRadAngleOfVec3s(Vec3 vecA, Vec3 vecB)
{
	Vec3 normVecA;
	Vec3 normVecB;

	normalizeVec3(vecA, normVecA);
	normalizeVec3(vecB, normVecB);

	return (acos(dotVec3s(normVecA, normVecB)));
}

float getDegAngleOfVec3s(Vec3 vecA, Vec3 vecB)
{
	return (radToDeg(getRadAngleOfVec3s(vecA, vecB)));
}

float crossVec3s(Vec3 vecA, Vec3 vecB, Vec3 dest)
{
	return (initVec3(dest, ((vecA[1] * vecB[2]) - (vecA[2] * vecB[1])), ((vecA[2] * vecB[0]) - (vecA[0] * vecB[2])), ((vecA[0] * vecB[1]) - (vecA[1] * vecB[0]))));
}

// Vectors 4 - float
float initVec4(Vec4 vec, float x, float y, float z, float w)
{
	vec[0] = x;
	vec[1] = y;
	vec[2] = z;
	vec[3] = w;
}

float initUnitVec4(Vec4 vec, float n)
{
	return initVec4(vec, n, n, n, n);
}

float initVec4FromVec3(Vec4 dest, Vec3 src, float z)
{
	return (initVec4(dest, src[0], src[1], src[2], z));
}

float scaleVec4(Vec4 vec, float x)
{
	vec[0] += x;
	vec[1] += x;
	vec[2] += x;
	vec[3] += x;
}

float negateVec4(Vec4 vec)
{
	vec[0] *= -1;
	vec[1] *= -1;
	vec[2] *= -1;
	vec[3] *= -1;
}

float addVec4s(Vec4 vecA, Vec4 vecB, Vec4 dest)
{
	dest[0] = vecA[0] + vecB[0];
	dest[1] = vecA[1] + vecB[1];
	dest[2] = vecA[2] + vecB[2];
	dest[3] = vecA[3] + vecB[3];
}

float subVec4s(Vec4 vecA, Vec4 vecB, Vec4 dest)
{
	dest[0] = vecA[0] - vecB[0];
	dest[1] = vecA[1] - vecB[1];
	dest[2] = vecA[2] - vecB[2];
	dest[3] = vecA[3] - vecB[3];
}

float normalizeVec4(Vec4 vec, Vec4 dest)
{
	float lenVec = lenVec4(vec);
	return initVec4(dest, vec[0] / lenVec, vec[1] / lenVec, vec[2] / lenVec, vec[3] / lenVec);
}

float lenVec4(Vec4 vec)
{
	return (sqrtf(pSquaredf(vec[0]) + pSquaredf(vec[1]) + pSquaredf(vec[2]) + pSquaredf(vec[4])));
}

float dotVec4s(Vec4 vecA, Vec4 vecB)
{
	return ((vecA[0] * vecB[0]) + (vecA[1] * vecB[1]) + (vecA[2] * vecB[2]) + (vecA[3] * vecB[3]));
}

float getRadAngleOfVec4s(Vec4 vecA, Vec4 vecB)
{
	Vec4 normVecA;
	Vec4 normVecB;

	normalizeVec4(vecA, normVecA);
	normalizeVec4(vecB, normVecB);

	return (acos(dotVec4s(normVecA, normVecB)));
}

float getDegAngleOfVec4s(Vec4 vecA, Vec4 vecB)
{
	return (radToDeg(getRadAngleOfVec4s(vecA, vecB)));
}

// MATRICES //
