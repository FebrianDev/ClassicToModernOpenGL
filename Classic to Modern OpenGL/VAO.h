#pragma once
#include "VBO.h"
class VAO
{
private:
	unsigned int ID;

public:
	VAO() = default;
	VAO(VBO& VBO, unsigned int layout);
	void Bind();
	void Unbind();
	void Delete();

	unsigned int GetID();
};

