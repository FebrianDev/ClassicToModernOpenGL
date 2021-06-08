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
#include "VertexArray.h"
#include "Texture.h"

class Rectangle : public Object, VertexArray {

private:
	Shader* shader;
	Transform* transform;
	Texture* texture;
	
	//tinggi (h) dan lebar objek(w)
	float width;
	float height;

	unsigned int ID;

	float* setVertices(const float& x, const float& y, const float& width, const float& height);
	
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
	vec4 position() override;

	//bool onCollisionWith(Circle circle);

};


