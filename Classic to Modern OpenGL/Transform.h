#pragma once
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include <glew.h>
#include <glfw3.h>

#include "Shader.h"

using namespace glm;

class Transform
{
private:
	mat4 transform;
	Shader* shader;
	void execute();
public:
	Transform();
	Transform(Shader* shader);
	void translate(const vec3& vec);
	void scale(const vec3& vec);
	void rotate(const vec3& vec, const float& angle);
};

