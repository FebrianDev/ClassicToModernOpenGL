#include "Transform.h"

void Transform::execute()
{
	
}

Transform::Transform()
{
	transform = mat4(1.0f);
}

Transform::Transform(Shader* shader)
{
	transform = mat4(1.0f); // make sure to initialize matrix to identity matrix first
	this->shader = shader;
}

void Transform::translate(const vec3& vec)
{
	transform = glm::translate(transform,vec);
	shader->setMat4("transform", transform);
}

void Transform::scale(const vec3& vec)
{
	transform = glm::scale(transform,vec);
	shader->setMat4("transform", transform);
}

void Transform::rotate(const vec3& vec, const float& angle)
{
	transform = glm::rotate(transform, glm::radians(angle)  ,vec);
	shader->setMat4("transform", transform);
}
