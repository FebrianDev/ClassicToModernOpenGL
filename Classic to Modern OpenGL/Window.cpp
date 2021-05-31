#include "Window.h"
void Window::init()
{
    /* Initialize the library */
    if (!glfwInit()) {
        std::cout << "Init Failed";
        system("Pause");
    }

    glewInit();
}

bool Window::close()
{
    //if window not close
    return glfwWindowShouldClose(window);
}

void Window::update()
{
    /* Swap front and back buffers */
    glfwSwapBuffers(window);

    /* Poll for and process events */
    glfwPollEvents();

    //Resize
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
}

Window::Window() {
    width = 0;
    height = 0;
    title = "";

    make();
}

Window::Window(int width, int height, const char* title) {
    this->width = width;
    this->height = height;
    this->title = title;

    make();
}

Window::~Window()
{
    glfwTerminate();
}

int Window::getWidth() const {
    return width;
}

void Window::setWidth(int width) {
    this->width = width;
}

int Window::getHeight() const {
    return height;
}

void Window::setHeight(int height) {
    this->height = height;
}

const char* Window::getTitle() const {
    return title;
}

void Window::setTitle(const char* title) {
    this->title = title;
}

GLFWwindow* Window::getWindow() const {
    return window;
}

void Window::make()
{
    init();
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(width, height, title, NULL, NULL);

    if (!window) {
        std::cout << "Window NULL";
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
}

void Window::clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
