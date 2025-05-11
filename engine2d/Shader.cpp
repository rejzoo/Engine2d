#include "Shader.h"

Shader::Shader()
{
	CreateFromFiles(m_vShader, m_fShader);
}

Shader::~Shader()
{
	ClearShader();
}

void Shader::CreateFromFiles(const char* vertexPath, const char* fragmentPath)
{
	std::string vertexCode = ReadFile(vertexPath);
	std::string fragmentCode = ReadFile(fragmentPath);

	CompileShader(vertexCode.c_str(), fragmentCode.c_str());
}

std::string Shader::ReadFile(const char* filePath)
{
	std::string content;
	std::ifstream fileStream(filePath, std::ios::in);

	if (!fileStream.is_open())
	{
		Logger::Log(LogType::ERROR, "Failed to read " + std::string(filePath));
		return "";
	}

	std::string line;

	while (!fileStream.eof())
	{
		std::getline(fileStream, line);
		content.append(line + "\n"); // \n easier debug
	}

	return content;
}

void Shader::UseShader()
{
	glUseProgram(m_shaderID);
}

void Shader::ClearShader()
{
	if (m_shaderID != 0)
	{
		glDeleteProgram(m_shaderID);
		m_shaderID = 0;
	}
}

void Shader::SetMat4(const std::string& name, glm::mat4 matrix) const
{
	GLuint uniform = glGetUniformLocation(m_shaderID, name.c_str());
	glUniformMatrix4fv(uniform, 1, GL_FALSE, glm::value_ptr(matrix));
}

void Shader::SetVec4(const std::string& name, glm::vec4 vector) const
{
	GLuint uniform = glGetUniformLocation(m_shaderID, name.c_str());
	glUniform4fv(uniform, 1, &vector[0]);
}

void Shader::CompileShader(const char* vertexCode, const char* fragmentCode)
{
	m_shaderID = glCreateProgram();
	GLuint m_vertHandle, m_fragHandle;

	if (!m_shaderID)
	{
		Logger::Log(LogType::ERROR, "Shader program not created.");
		return;
	}

	AddShader(m_shaderID, vertexCode, GL_VERTEX_SHADER, m_vertHandle);
	AddShader(m_shaderID, fragmentCode, GL_FRAGMENT_SHADER, m_fragHandle);

	GLint result = 0;
	GLchar log[1024]{};

	glLinkProgram(m_shaderID);
	glGetProgramiv(m_shaderID, GL_LINK_STATUS, &result);

	if (!result)
	{
		glGetProgramInfoLog(m_shaderID, sizeof(log), NULL, log);
		Logger::Log(LogType::ERROR, "ERROR LINK: " + std::string(log));
		return;
	}

	glValidateProgram(m_shaderID);
	glGetProgramiv(m_shaderID, GL_VALIDATE_STATUS, &result);

	if (!result)
	{
		glGetProgramInfoLog(m_shaderID, sizeof(log), NULL, log);
		Logger::Log(LogType::ERROR, "ERROR VALIDATE: " + std::string(log));
		return;
	}

	// NO NEED ?
	glDetachShader(m_shaderID, m_vertHandle);
	glDeleteShader(m_vertHandle);
	glDetachShader(m_shaderID, m_fragHandle);
	glDeleteShader(m_fragHandle);
}

void Shader::AddShader(GLuint program, const char* shaderCode, GLenum shaderType, GLuint& handle)
{
	handle = glCreateShader(shaderType);

	const GLchar* code[1];
	code[0] = shaderCode;

	GLint length[1];
	length[0] = strlen(shaderCode);

	glShaderSource(handle, 1, code, length);
	glCompileShader(handle);
	GLint result = 0;
	GLchar log[1024]{};

	glGetShaderiv(handle, GL_COMPILE_STATUS, &result);

	if (!result)
	{
		glGetShaderInfoLog(handle, sizeof(log), NULL, log);
		Logger::Log(LogType::ERROR, "ERROR COMPILE: " + std::string(log) + std::to_string(shaderType));
		return;
	}

	glAttachShader(program, handle);
}
