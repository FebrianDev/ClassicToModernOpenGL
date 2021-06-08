#pragma once
#include <glew.h>
#include <glfw3.h>
#include "Shader.h"
#include "glm.hpp"
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

class Object {
	
protected:
	//titik origin objek
	float x;
	float y;
	
	//parameter warna objek
	float red;
	float green;
	float blue;
	float alpha;

public:
	virtual ~Object() = default;
	//constructor
	Object();

	//setter getter origin objek
	void setX(float ix);
	void setY(float iy);

	float getX();
	float getY();
	
	//setter warna objek
	void setColor(float r, float g, float b, float alpha);
	
	//gambar
	virtual void draw() = 0;
	virtual void build() = 0;
	virtual void translate(const glm::vec3& vec) = 0;
	virtual void rotate(const glm::vec3& vec, const float& angle) = 0;
	virtual void scale(const glm::vec3& vec = glm::vec3(1.0f,1.0f,1.0f)) = 0;
	virtual glm::vec4 position() = 0;
	
};

