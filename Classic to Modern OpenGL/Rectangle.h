#pragma once
#include "Object.h"
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include "Circle.h"
#include "Transform.h"

class Rectangle : public Object {

private:
	Shader* shader;
	unsigned int VBO, VAO, EBO;
	Transform* transform;

	//tinggi (h) dan lebar objek(w)
	float width;
	float height;
	
public:
	Rectangle();
	//constructor persegi
	Rectangle(const float& x, const float& y, const float& width, const float& height);

	//setter getter tinggi dan lebar objek
	void setWidth(const float& width);
	void setHeight(const float& height);

	float getWidth() const;
	float getHeight() const;

	//override dari fungsi draw
	void draw() override;
	void build() override;
	void translate(const vec3& vec) override;
	void rotate(const vec3& vec, const float& angle) override;
	void scale(const vec3& vec) override;

	bool onCollisionWith(Circle circle);

};


