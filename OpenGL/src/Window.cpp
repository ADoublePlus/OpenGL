#include "Window.h"

int Window::CreateWindow(int width, int height,
	string title,
	GLFWmonitor* monitor,
	GLFWwindow* share)
{
	// Open a new window
	handle = glfwCreateWindow(width, height, title.c_str(), monitor, share);
	if (!handle)
	{
		glfwTerminate();
		return -1;
	}
	return 0;
}

void Window::FocusWindow()
{
	glfwMakeContextCurrent(handle);
}

void Window::EnableVSync()
{
	glfwSwapInterval(1);
}

bool Window::IsOpen()
{
	return !glfwWindowShouldClose(handle);
}

void Window::RefreshViewport()
{
	float ratio;
	int width, height;
	glfwGetFramebufferSize(handle, &width, &height);
	ratio = width / (float)height;
	glViewport(0, 0, width, height);
}

void Window::End()
{
	glfwSwapBuffers(handle);
	glfwPollEvents();
}
