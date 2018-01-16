#include "GL.h"

GL::GL()
{
	glfwSetErrorCallback(ErrorCallBack);
}

int GL::Initialize()
{
	/* Initialize the library! */
	if (!glfwInit())
	{
		return -1;
	}
	return 0;
}