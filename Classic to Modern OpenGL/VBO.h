#pragma once
#include <glew.h>
class VBO
{
private:
	unsigned int ID;
public:
	VBO() = default;
	VBO(float* vertices, unsigned int size);
	~VBO() = delete;
	
	void Bind();
	void Unbind();
	void Delete();

	unsigned int GetID();
};

