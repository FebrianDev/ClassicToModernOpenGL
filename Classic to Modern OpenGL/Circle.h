#pragma once
#include "Object.h"
#include "Transform.h"
#include<vector>
#include <iostream>

class Circle : public Object
{
private:
	Shader* shader;
	unsigned int VBO, VAO, EBO;
	Transform* transform;

	float radius;

public:
	Circle();
	//constructor persegi
	Circle(const float& x, const float& y, const float& radius);

	void setRadius(const float& radius);
	float getRadius() const;
	
	//override dari fungsi draw
	void draw() override;
	void build() override;
	void translate(const vec3& vec) override;
	void rotate(const vec3& vec,const float& angle) override;
	void scale(const vec3& vec) override;
};

