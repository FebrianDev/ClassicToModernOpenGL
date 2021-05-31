#include "Rectangle.h"

Rectangle::Rectangle() {
	x = 0;
	y = 0;
	width= 1.0f;
	height = 1.0f;
}

Rectangle::Rectangle(const float& x, const float& y, const float& width, const float& height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

void Rectangle::build()
{
    shader = new Shader("circleVertexShader.vs", "circleFragmentShader.fs");

    transform = new Transform(shader);
	
    // set up vertex data (and buffer(s)) and configure vertex attributes
  // ------------------------------------------------------------------
    float vertices[] = {
         x        , y         , 0.0f,  
         x + width, y         , 0.0f,  
         x + width, y + height, 0.0f,  
         x        , y + height, 0.0f,  
    };
    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
   // glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    //glEnableVertexAttribArray(1);
}


void Rectangle::draw() {
    scale(vec3(1.0f, 1.0f, 1.0f));
    this->shader->setVec3("color", red, green, blue);

    this->shader->use();
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}


void Rectangle::setWidth(const float& width) {

    this->width = width;
}

void Rectangle::setHeight(const float& height) {

    this->height = height;
}

float Rectangle::getWidth() const {
    return width;
}
float Rectangle::getHeight() const {
    return height;
}

void Rectangle::translate(const vec3& vec)
{
    transform->translate(vec);
}

void Rectangle::rotate(const vec3& vec, const float& angle)
{
    transform->rotate(vec, angle);
}

void Rectangle::scale(const vec3& vec)
{
    transform->scale(vec);
}

bool Rectangle::onCollisionWith(Circle circle)
{
    return this->getX() < circle.getX() && this->getY() < circle.getY();
}
