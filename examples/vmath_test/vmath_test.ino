#include <Arduino.h>
#include <vmath.h>
#include <Wire.h>
#define p(x) Serial.print(x)
#define pln(x) Serial.println(x)
#define pv(v) p(v.x); p(", "); pln(v.y);

void setup() {
	Serial.begin(115200);
	Serial.println("Vector math test");
}

void loop() {
	pln("Lets do math again...");
	test_add();
	test_sub();
	test_len();
	test_scale();
	test_operator_plus();
	test_operator_minus();
	test_operator_star();
	delay(5000);
}

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