#ifndef _SHADER_H_
#define _SHADER_H_

#include "GL.h"

#include <fstream>
#include <iostream>

using namespace std;

enum ShaderType
{
	VERTEX,
	FRAGMENT
};

class Shader
{
public:
	char* shaderText;
	GLuint handle;
	ShaderType type;

	Shader(string fileName, ShaderType type);

	void Compile();
};

#endif
