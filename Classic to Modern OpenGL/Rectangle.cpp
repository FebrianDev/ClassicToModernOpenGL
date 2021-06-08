#include "Rectangle.h"

float* Rectangle::setVertices(const float& x, const float& y, const float& width, const float& height)
{
     float vertices[] = {
      x        , y         , 0.0f,
      x + width, y         , 0.0f,
      x + width, y + height, 0.0f,
      x        , y + height, 0.0f,
    };

     return vertices;
}

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
    shader = new Shader("vertexShader.vs", "fragmentShader.fs");
    transform = new Transform(shader);
  
    float vertices[] = {
     x        , y         , 0.0f,   
     x + width, y         , 0.0f,   
     x + width, y + height, 0.0f,   
     x        , y + height, 0.0f,
    };
    transform->setPosition(vec4(-1.0f, -.5f, 0.0f, 1.0f));
    compile(vertices,3, sizeof(vertices));
}


void Rectangle::draw() {
    scale(vec3(1.0f, 1.0f, 1.0f));
	
    shader->use();
    shader->setVec4("color", red, green, blue,alpha);

    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);
  
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -1.0f));
    projection = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);

	shader->setMat4("view", view);
    shader->setMat4("projection", projection);
    transform->setPosition(vec4(x, y, 0.0f, 1.0f));
	bind();

	glDrawArrays(GL_POLYGON, 0, 4);
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

vec4 Rectangle::position()
{
    return transform->GetPosition();
}

// bool Rectangle::onCollisionWith(Circle circle)
// {
//     return this->getX() < circle.getX() && this->getY() < circle.getY();
// }
