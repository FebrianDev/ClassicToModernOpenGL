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

void Circle::setRadius(const float& radius)
{
    this->radius = radius;
}

float Circle::getRadius() const
{
    return radius;
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
	
    compile(vertices,2, sizeof(vertices));
}


void Circle::draw() {

    scale(vec3(1.0f, 1.0f, 1.0f));
    shader->use();
  //  shader->setVec4("color", red, green, blue, alpha);
    //glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
  //  glm::mat4 view = glm::mat4(1.0f);
    //glm::mat4 projection = glm::mat4(1.0f);
    //  model = glm::rotate(model, glm::radians((float)glfwGetTime()), glm::vec3(0.0f, 0.0f, 1.0f));
    //view = glm::translate(view, glm::vec3(0.0f, 0.0f, -1.0f));
    //projection = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
    //   shader->setMat4("model", model);
   // shader->setMat4("view", view);
 //   shader->setMat4("projection", projection);
    transform->setPosition(vec4(x, y,0.0f,1.0f));
    bind();
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

glm::vec4 Circle::position()
{
    return transform->GetPosition();
}
