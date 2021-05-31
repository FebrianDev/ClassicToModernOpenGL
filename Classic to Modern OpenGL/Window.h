#include <glew.h>
#include <glfw3.h>
#include <iostream>
#pragma once

class Window
{
private:
    int width;
    int height;
    const char* title;
    GLFWwindow* window;

    void init();

public:
    Window();
    Window(int width, int height, const char* title);
    ~Window();
    int getWidth() const;
    void setWidth(int width);
    int getHeight() const;
    void setHeight(int height);
    const char* getTitle() const;
    void setTitle(const char* title);
    GLFWwindow* getWindow() const;

    bool close();
    void update();
    void make();
    void clear();
};

