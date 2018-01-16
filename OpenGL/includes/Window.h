#ifndef _WINDOW_H_
#define _WINDOW_H_

#include "GL.h"
#include <string>

using namespace std;

class Window
{
public:
	GLFWwindow* handle;
	int width, height;
	string title;
	GLFWmonitor* monitor;
	GLFWwindow* share;

	int CreateWindow(int width, int height,
		string title,
		GLFWmonitor* monitor,
		GLFWwindow* share);

	void FocusWindow();
	void EnableVSync();

	bool IsOpen();
	void RefreshViewport();
	void End();
};

#endif