#include "Renderer2D.h"

Renderer2D::Renderer2D(Camera2D* camera)
{
    InitQuad();
    m_shader = new Shader();
    m_camera = camera;
}

Renderer2D::~Renderer2D()
{
    glDeleteVertexArrays(1, &m_qVAO);
    glDeleteBuffers(1, &m_qVBO);
    delete(m_shader);
}

void Renderer2D::Draw(glm::mat4 model, glm::vec4 color)
{
    m_shader->UseShader();

    glm::mat4 projection = m_camera->GetView();

    m_shader->SetMat4("model", model);
    m_shader->SetVec4("color", color);
    m_shader->SetMat4("projection", projection);

    glBindVertexArray(m_qVAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}

void Renderer2D::InitQuad()
{
    float vertices[] = {
        0.0f, 1.0f,
        1.0f, 0.0f,
        0.0f, 0.0f,

        0.0f, 1.0f,
        1.0f, 1.0f,
        1.0f, 0.0f
    };

    glGenVertexArrays(1, &m_qVAO);
    glGenBuffers(1, &m_qVBO);

    glBindVertexArray(m_qVAO);

    glBindBuffer(GL_ARRAY_BUFFER, m_qVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);

    glBindVertexArray(0);
}
