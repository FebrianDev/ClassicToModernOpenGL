#include "VertexArray.h"

void VertexArray::compile(const float* vertices, unsigned int count, GLsizeiptr size)
{
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
   
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	
    glVertexAttribPointer(0, count, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);
}

void VertexArray::bind() const
{
    glBindVertexArray(vao);
}