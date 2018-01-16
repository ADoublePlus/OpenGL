#include "Triangle.h"

void Triangle::Start()
{
	glGenBuffers(1, &vertBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

void Triangle::Update()
{
	M = rotate<float>(glfwGetTime() * 20, vec3(0, 0, 1));
	// Camera view goes here (V = ...)
	P = ortho<float>(-1, 1, 1, -1);
	MVP = P * M; // P * V * M
}

void Triangle::Draw(GLuint program)
{
	// Get the shader locations of all the Uniforms and Attributes
	mvpLocation = glGetUniformLocation(program, "MVP");
	vPosLocation = glGetAttribLocation(program, "vPos");
	vColLocation = glGetAttribLocation(program, "vCol");

	// Enable the shader values
	glEnableVertexAttribArray(vPosLocation);
	glEnableVertexAttribArray(vColLocation);

	// Send the information of our vertices over to the graphics card
	glVertexAttribPointer(vPosLocation, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)0);
	glVertexAttribPointer(vColLocation, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)(sizeof(float) * 2));

	// Give the graphics card the matrix
	glUniformMatrix4fv(mvpLocation, 1, GL_FALSE, (const GLfloat*)&MVP);

	// FINALLY TELL THE GRAPHICS CARD TO DRAW IT!
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
