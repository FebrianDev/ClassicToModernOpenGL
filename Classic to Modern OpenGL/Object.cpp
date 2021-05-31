#include "Object.h"

Object::Object() {
	x = 0;
	y = 0;
}

//setter getter origin
void Object::setX(float ix) {
	x = ix;
}
void Object::setY(float iy) {
	y = iy;
}

float Object::getX() {
	return x;
}

float Object::getY() {
	return y;
}

//setter color
void Object::setColor(float r, float g, float b, float a) {
	red = r;
	green = g;
	blue = b;
	alpha = a;
}