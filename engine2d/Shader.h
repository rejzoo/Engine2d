#pragma once

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Logger.h"

class Shader
{
private:
	GLuint m_shaderID;
	const char* m_vShader = "Shaders/shader.vert";
	const char* m_fShader = "Shaders/shader.frag";

public:
	Shader();
	~Shader();

	void CreateFromFiles(const char* vertexPath, const char* fragmentPath);

	std::string ReadFile(const char* filePath);
	void UseShader();
	void ClearShader();

	void SetMat4(const std::string& name, glm::mat4 matrix) const;
	void SetVec4(const std::string& name, glm::vec4 vector) const;

private:
	void CompileShader(const char* vertexCode, const char* fragmentCode);
	void AddShader(GLuint program, const char* shaderCode, GLenum shaderType);
};
