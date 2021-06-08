#include "Transform.h"

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
	shader->setMat4("model", transform);
	this->vec = vec;
}

void Transform::scale(const vec3& vec)
{
	transform = glm::scale(transform,vec);
	shader->setMat4("model", transform);
	this->vec = vec;
}

void Transform::rotate(const vec3& vec, const float& angle)
{
	transform = glm::rotate(transform, glm::radians(angle)  ,vec);
	shader->setMat4("model", transform);
	this->vec = vec;
}

void Transform::setPosition(const vec4& vec)
{
	this->vec = vec;
}

vec4 Transform::GetPosition() const
{
	const vec4 newVector = transform * vec4(vec, 1.0);
	return newVector;
}