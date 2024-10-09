# include "include/inputs.h"
# include "include/utils.h"

extern int DEBUG;
extern int DEBUG_VIEW;

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, TRUE);

	if (DEBUG)
	{
		static int isDebugKeyPressed = 0;

		if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS && !isDebugKeyPressed)
		{
			DEBUG_VIEW = !DEBUG_VIEW;
			viewMode();
			isDebugKeyPressed = 1;
		}

		if (glfwGetKey(window, GLFW_KEY_G) == GLFW_RELEASE)
			isDebugKeyPressed = 0;
	}
}

void viewMode()
{
	if (DEBUG_VIEW)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}