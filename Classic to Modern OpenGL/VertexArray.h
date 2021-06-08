#pragma once
#include <glew.h>
#include <iostream>

class VertexArray
{
private:
	unsigned int vbo, vao;
public:	
	void compile(const float* vertices ,unsigned int count,  GLsizeiptr size);
	void bind() const;
};

