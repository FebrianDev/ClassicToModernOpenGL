#include "Circle.h"

Circle::Circle() {
    x = 0;
    y = 0;
    this->radius = 0.0f;
}

Circle::Circle(const float& x, const float& y, const float& radius)
{
    this->x = x;
    this->y = y;
    this->radius = radius;
}

void Circle::build()
{
    shader = new Shader("circleVertexShader.vs", "circleFragmentShader.fs");

    transform = new Transform(shader);

    float PI = 3.14;
    int size = 60;
    float vertices[60];

    for (int i = 0; i < size; i++) {
        float x = radius * cos(2 * PI * i / size); // rumus untuk mencari banyaknya titik lingkaran berdasarkan sumbu x
        float y = radius * sin(2 * PI * i / size); // rumus untuk mencari banyaknya titik lingkaran berdasarkan sumbu y

        if (i % 2 == 0)
        {
            vertices[i] = x;
        }else
        {
            vertices[i] = y;
        }
    }
	
    // set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
}


void Circle::draw() {

    scale(vec3(1.0f, 1.0f, 1.0f));
    shader->use();

    glBindVertexArray(VAO);
    glDrawArrays(GL_POLYGON, 0,60 );
}

void Circle::translate(const vec3& vec)
{
    transform->translate(vec);
}

void Circle::rotate(const vec3& vec, const float& angle)
{
    transform->rotate(vec, angle);
}

void Circle::scale(const vec3& vec)
{
    transform->scale(vec);
}
