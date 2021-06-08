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
	vec3 vec;
public:
	Transform();
	Transform(Shader* shader);
	void translate(const vec3& vec);
	void scale(const vec3& vec);
	void rotate(const vec3& vec, const float& angle);

	void setPosition(const vec4& vec);
	vec4 GetPosition() const;
};

