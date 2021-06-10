#include<iostream>
#include <glew.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include"Circle.h"
#include "Rectangle.h"
#include <stb_image.h>
#include"Window.h"
using namespace std;

Rectangle rectangle,rectangle2;
Circle circle;

 bool collisionDetection(Rectangle& rect, Circle& circle) {
 	
	 float circleDistancex = abs(circle.getX() - rect.getX());
	 float circleDistancey = abs(circle.getY() - rect.getY());

	 if (circleDistancex > (rect.getWidth() / 2 + circle.getRadius())) { return false; }
	 if (circleDistancey > (rect.getHeight() / 2 + circle.getRadius())) { return false; }

	 if (circleDistancex <= (rect.getWidth() / 2)) { return true; }
	 if (circleDistancey <= (rect.getHeight() / 2)) { return true; }

	 float cornerDistance_sq = (circleDistancex - rect.getWidth()/ 2)  * (circleDistancex - rect.getWidth() / 2) + (circleDistancey - rect.getHeight() / 2) * (circleDistancey - rect.getHeight() / 2);

	 return (cornerDistance_sq <= (circle.getRadius() * circle.getRadius()));
 }

bool Collision(Rectangle& rect1, Rectangle& rect2)
 {
	if (rect1.getX() < rect2.getWidth() && rect2.getX() < rect1.getWidth()
		&& rect1.getY() < rect2.getHeight() && rect2.getY() < rect1.getHeight()) {
		if (rect1.getX() < rect2.getX()) {
			rect1.setX(rect2.getX());
		}
		if (rect1.getY() < rect2.getY()) {
			rect1.setY(rect2.getY());
		}
		if (rect1.getWidth() > rect2.getWidth()) {
			rect1.setWidth(rect2.getWidth());
		}
		if (rect1.getHeight() > rect2.getHeight()) {
			rect1.setHeight(rect1.getHeight());
		}
		
		return true;
	}else
	{
		return false;
	}
 	
 }

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	switch (key) {
		case GLFW_KEY_A:
			rectangle.rotate(vec3(0.0f, 0.0f, 1.0f), -1.0f);
		//	rectangle2.rotate(vec3(0.0f, 0.0f, 1.0f), -1.0f);
			break;
		case GLFW_KEY_D:
			rectangle.rotate(vec3(0.0f, 0.0f, 1.0f), 1.0f);
		//	rectangle2.rotate(vec3(0.0f, 0.0f, 1.0f), 1.0f);
			break;
		case GLFW_KEY_LEFT:
			rectangle.translate(vec3(glfwGetTime() * -0.01f, 0.0f,0.0f));
		//	rectangle2.translate(vec3(glfwGetTime() * -0.01f, 0.0f, 0.0f));
			break;
		case GLFW_KEY_RIGHT:
			rectangle.translate(vec3(glfwGetTime() * 0.01f, 0.0f, 0.0f));
		///	rectangle2.translate(vec3(glfwGetTime() * 0.01f, 0.0f, 0.0f));
			break;
		case GLFW_KEY_UP:
			rectangle.translate(vec3(0.0f, glfwGetTime() * 0.01f, 0.0f));
		//	rectangle2.translate(vec3(0.0f, glfwGetTime() * 0.01f, 0.0f));
			break;
		case GLFW_KEY_DOWN:
			rectangle.translate(vec3(0.0f, glfwGetTime() * -0.01f, 0.0f));
			//rectangle2.translate(vec3(0.0f, glfwGetTime() * -0.01f, 0.0f));
			break;
		case GLFW_KEY_P:
			rectangle.setColor(0.0f,0.0f,1.0f,1.0f);
			break;
		case GLFW_KEY_Q:
			rectangle.setColor(1.0f, 0.0f, 1.0f, 1.0f);
			break;
		default: ;
	}
}

int main()
{

	Window window = Window(480, 480, "OpenGL Modern");

	rectangle = Rectangle(-1.0f, -0.5f, 0.5f, 0.5f);
	rectangle.build();
	rectangle.setColor(0.0f, 0.0f, 1.0f,.1f);
	
	rectangle2 = Rectangle(0.5f, 0.5f, 0.5f, 0.5f);
	rectangle2.build();
	rectangle2.setColor(0.0f, 1.0f, 0.0f, 0.0f);

	// circle = Circle(0.0f,0.0f,0.2f);
	// circle.build();
	// circle.setColor(1.0f, 0.0f, 1.0f, 1.0f);
	
	while(!window.close())
	{
		window.clear();
		
		//circle.draw();

		rectangle2.draw();
		rectangle.draw();
		

		glfwSetKeyCallback(window.getWindow(), key_callback);
		
		window.update();
	}

}