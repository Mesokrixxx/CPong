# ifndef PONG_GRAPHICS_H
# define PONG_GRAPHICS_H
# include <glad/glad.h>
# include <GLFW/glfw3.h>

// Window
GLFWwindow* setupWindow();
void framebufferSizeCallback(GLFWwindow* window, int width, int height);  

# endif