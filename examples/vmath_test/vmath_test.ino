#include <Arduino.h>
#include <vmath.h>
#include <Wire.h>
#define p(x) Serial.print(x)
#define pln(x) Serial.println(x)
#define pv(v) p(v.x); p(", "); pln(v.y);

void setup() {
	Serial.begin(115200);
	Serial.println("Vector math test");
	test_add();
	test_sub();
	test_len();
	test_scale();
	test_operator_plus();
	test_operator_minus();
	test_operator_star();

	test_intersect1();
	test_intersect2();
}

void loop() {}

void test_add() {
	pln("Addition");
	vec2 a;
	vec2 b(1,3);
	p("a: "); pv(a);
	p("b: "); pv(b);
	a.add(b);
	p("a.add(b): "); pv(a);
}

void test_sub() {
	pln("Subtraction");
	vec2 a(1, 2);
	vec2 b(2, 3);
	p("a: "); pv(a);
	p("b: "); pv(b);
	a.sub(b);
	p("a.sub(b): "); pv(a);
}

void test_len() {
	pln("Length");
	vec2 a(0, 5);
	vec2 b(2, -2);
	p("a: "); pv(a);
	p("b: "); pv(b);
	p("a.len(): "); pln(a.len());
	p("b.len(): "); pln(b.len());
}

void test_scale() {
	pln("Scale");
	vec2 a(0, 5);
	vec2 b(2, -2);
	p("a: "); pv(a);
	p("b: "); pv(b);
	a.scale(3);
	b.scale(4.5);
	p("a.scale(3): "); pv(a);
	p("b.scale(4.5): "); pv(b);
}

void test_operator_plus() {
	pln("Op: +");
	vec2 a(0, 5);
	vec2 b(2, -2);
	p("a: "); pv(a);
	p("b: "); pv(b);
	p("a+b = "); pv((a + b));
}

void test_operator_minus() {
	pln("Op: -");
	vec2 a(0, 5);
	vec2 b(2, -2);
	p("a: "); pv(a);
	p("b: "); pv(b);
	p("a-b = "); pv((a - b));
}

void test_operator_star() {
	pln("Op: *");
	vec2 a(1, 5);
	float s = 2.5;
	p("a: "); pv(a);
	p("s: "); pln(s);
	p("a*s = "); pv((a * s));
}

void test_intersect1() {
	pln("Test intesecion 1");
	vec2 a(0, 0);
	vec2 b(0, 2);
	vec2 c(0,0);
	vec2 d(2,0);
	vec2 out;
	bool success = lineSegmentIntersection(a, b, c, d, out);
	if (success) {
		p("lineSegmentIntersection expected=(0,0) was="); pv(out);
	} else {
		pln("lineSegmentIntersection failed!");
	}

	success = lineIntersection(a, b, c, d, out);
	if (success) {
		p("lineIntersection expected=(0,0) was="); pv(out);
	} else {
		pln("lineIntersection failed!");
	}
}

void test_intersect2() {
	pln("Test intesecion 2");
	vec2 a(-2, -2);
	vec2 b(4, 4);
	vec2 c(0, 2);
	vec2 d(2, 0);
	vec2 out;
	bool success = lineSegmentIntersection(a, b, c, d, out);
	if (success) {
		p("lineSegmentIntersection expected=(1,1) was="); pv(out);
	} else {
		pln("lineSegmentIntersection failed!");
	}

	success = lineIntersection(a, b, c, d, out);
	if (success) {
		p("lineIntersection expected=(1,1) was="); pv(out);
	} else {
		pln("lineIntersection failed!");
	}
}