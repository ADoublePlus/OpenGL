#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "GL.h"
#include <GLM\mat4x4.hpp>

using namespace glm;

class Triangle
{
public:
	GLuint mvpLocation, vPosLocation, vColLocation;
	GLuint vertBuffer;
	mat4 M, P, MVP;
	Vertex vertices[3] =
	{ 
		{ -0.6f, -0.4f, 1.0f, 0.0f, 0.0f },
		{ 0.6f, -0.4f, 0.0f, 1.0f, 0.0f },
		{ 0.f, 0.6f, 0.0f, 0.0f, 1.0f }
	};

	void Start();
	void Update();

	void Draw(GLuint program);
};

#endif