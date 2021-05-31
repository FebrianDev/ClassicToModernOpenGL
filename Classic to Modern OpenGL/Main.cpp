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

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	switch (key) {
		case GLFW_KEY_A:
			rectangle.rotate(vec3(0.0f, 0.0f, 1.0f), -1.0f);
			rectangle2.rotate(vec3(0.0f, 0.0f, 1.0f), -1.0f);
			//circle.rotate(vec3(0.0f, 0.0f, 1.0f), 1.0f);
			break;
		case GLFW_KEY_D:
			rectangle.rotate(vec3(0.0f, 0.0f, 1.0f), 1.0f);
			rectangle2.rotate(vec3(0.0f, 0.0f, 1.0f), 1.0f);
			break;
		case GLFW_KEY_LEFT:
			rectangle.translate(vec3(glfwGetTime() * -0.01f, 0.0f,0.0f));
			rectangle2.translate(vec3(glfwGetTime() * -0.01f, 0.0f, 0.0f));
			break;
		case GLFW_KEY_RIGHT:
			rectangle.translate(vec3(glfwGetTime() * 0.01f, 0.0f, 0.0f));
			rectangle2.translate(vec3(glfwGetTime() * 0.01f, 0.0f, 0.0f));
			break;
		case GLFW_KEY_UP:
			rectangle.translate(vec3(0.0f, glfwGetTime() * 0.01f, 0.0f));
			rectangle2.translate(vec3(0.0f, glfwGetTime() * 0.01f, 0.0f));
			break;
		case GLFW_KEY_DOWN:
			rectangle.translate(vec3(0.0f, glfwGetTime() * -0.01f, 0.0f));
			rectangle2.translate(vec3(0.0f, glfwGetTime() * -0.01f, 0.0f));
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

	rectangle = Rectangle(-0.5f, -0.5f, 0.5f, 0.5f);
	rectangle.build();
	//rectangle.setColor(1.0f, 0.0f, 1.0f,1.0f);
	
	rectangle2 = Rectangle(0.5f, 0.5f, 0.5f, 0.5f);
	rectangle2.build();
//	rectangle2.setColor(0.0f, 1.0f, 0.0f, 1.0f);

	circle = Circle(0.0f,0.0f,0.2f);
	circle.build();
	
	while(!window.close())
	{
		window.clear();

		circle.draw();
		rectangle.draw();
		rectangle2.draw();
		
		glfwSetKeyCallback(window.getWindow(), key_callback);
		
		window.update();
	}

}