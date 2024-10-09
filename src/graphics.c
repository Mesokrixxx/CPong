# include "include/graphics.h"
# include <stdio.h>

GLFWwindow* setupWindow()
{
	glfwInit();
	
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	// Create window
	GLFWwindow* window = glfwCreateWindow(800, 600, "CPong", NULL, NULL);
	if (window == NULL)
	{
		printf("Failed to create a window\n");
		glfwTerminate();
		return NULL;
	}
	glfwMakeContextCurrent(window);

	// Initialize GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
	    printf("Failed to load GLAD\n");
	    glfwTerminate();
	    return NULL;
	}  

	glViewport(0, 0, 800, 600);

	glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);  

	return window;
}

void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}  