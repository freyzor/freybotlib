#ifndef VMATH_H
#define VMATH_H

#include <math.h>

struct vec2 {
	float x;
	float y;
	vec2(): x(0), y(0) {};
	vec2(float xx, float yy): x(xx), y(yy) {};
	vec2(int xx, int yy): x(xx), y(yy) {};
	void add(const vec2 &v) {
		x += v.x;
		y += v.y;
	};
	void sub(const vec2 &v) {
		x -= v.x;
		y -= v.y;
	};
	void scale(float s) {
		x *= s;
		y *= s;
	};
	float lenSq() {
		return x*x + y*y;
	};
	float len() {
		return sqrt(lenSq());
	};
	vec2 operator+(const vec2& b) {
		vec2 a = *this;
		a.add(b);
		return a;
	};
	vec2 operator-(const vec2& b) {
		vec2 a = *this;
		a.sub(b);
		return a;
	};
	vec2 operator*(float s) {
		vec2 a = *this;
		a.scale(s);
		return a;
	};
	vec2 operator-() {
		vec2 a(-x, -y);
		return a;
	};
	vec2& operator+=(const vec2& b) {
		add(b);
		return *this;
	};
	vec2& operator-=(const vec2& b) {
		sub(b);
		return *this;
	};
};

struct vec3 {
	float x;
	float y;
	float z;
	vec3(): x(0), y(0), z(0) {};
	void add(vec3 &v) {
		x += v.x;
		y += v.y;
		z += v.z;
	}
	void sub(vec3 &v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
	}
	void scale(float s) {
		x *= s;
		y *= s;
		z *= s;
	}
};

bool lineSegmentIntersection(vec2 a, vec2 b, vec2 c, vec2 d, vec2 &out);
bool lineIntersection(vec2 a, vec2 b, vec2 c, vec2 d, vec2 &out);
#endif