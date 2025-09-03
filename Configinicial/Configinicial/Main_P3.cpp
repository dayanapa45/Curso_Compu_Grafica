// Dayana Plata Alvarez grupo 7
// Práctica 3
// Fecha de entrega: 31/08/25
// No. de cuenta: 319209608

#include <iostream>

//#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Shaders
#include "Shader.h"

const GLint WIDTH = 800, HEIGHT = 600;

int main() {
    glfwInit();

    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Práctica 3 - Dayana Plata Alvarez (grupo 7)", nullptr, nullptr);

    int screenWidth, screenHeight;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

    if (nullptr == window) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;

    if (GLEW_OK != glewInit()) {
        std::cout << "Failed to initialise GLEW" << std::endl;
        return EXIT_FAILURE;
    }

    glViewport(0, 0, screenWidth, screenHeight);

    // OpenGL states
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Programa de shaders
    Shader ourShader("Shader/core.vs", "Shader/core.frag");

    // --- Vértices de un cubo (36 vértices)
    float vertices[] = {
        // Posición          // Color
        // Front (+Z) - ROJO
        -0.5f,-0.5f, 0.5f, 1.0f,0.0f,0.0f,
         0.5f,-0.5f, 0.5f, 1.0f,0.0f,0.0f,
         0.5f, 0.5f, 0.5f, 1.0f,0.0f,0.0f,
         0.5f, 0.5f, 0.5f, 1.0f,0.0f,0.0f,
        -0.5f, 0.5f, 0.5f, 1.0f,0.0f,0.0f,
        -0.5f,-0.5f, 0.5f, 1.0f,0.0f,0.0f,

        // Back (-Z) - VERDE
        -0.5f,-0.5f,-0.5f, 0.0f,1.0f,0.0f,
         0.5f,-0.5f,-0.5f, 0.0f,1.0f,0.0f,
         0.5f, 0.5f,-0.5f, 0.0f,1.0f,0.0f,
         0.5f, 0.5f,-0.5f, 0.0f,1.0f,0.0f,
        -0.5f, 0.5f,-0.5f, 0.0f,1.0f,0.0f,
        -0.5f,-0.5f,-0.5f, 0.0f,1.0f,0.0f,

        // Right (+X) - AZUL
         0.5f,-0.5f, 0.5f, 0.0f,0.0f,1.0f,
         0.5f,-0.5f,-0.5f, 0.0f,0.0f,1.0f,
         0.5f, 0.5f,-0.5f, 0.0f,0.0f,1.0f,
         0.5f, 0.5f,-0.5f, 0.0f,0.0f,1.0f,
         0.5f, 0.5f, 0.5f, 0.0f,0.0f,1.0f,
         0.5f,-0.5f, 0.5f, 0.0f,0.0f,1.0f,

         // Left (-X) - AMARILLO
         -0.5f, 0.5f, 0.5f, 1.0f,1.0f,0.0f,
         -0.5f, 0.5f,-0.5f, 1.0f,1.0f,0.0f,
         -0.5f,-0.5f,-0.5f, 1.0f,1.0f,0.0f,
         -0.5f,-0.5f,-0.5f, 1.0f,1.0f,0.0f,
         -0.5f,-0.5f, 0.5f, 1.0f,1.0f,0.0f,
         -0.5f, 0.5f, 0.5f, 1.0f,1.0f,0.0f,

         // Bottom (-Y) - CIAN
         -0.5f,-0.5f,-0.5f, 0.0f,1.0f,1.0f,
          0.5f,-0.5f,-0.5f, 0.0f,1.0f,1.0f,
          0.5f,-0.5f, 0.5f, 0.0f,1.0f,1.0f,
          0.5f,-0.5f, 0.5f, 0.0f,1.0f,1.0f,
         -0.5f,-0.5f, 0.5f, 0.0f,1.0f,1.0f,
         -0.5f,-0.5f,-0.5f,  0.0f,1.0f,1.0f,

         // Top (+Y) - MAGENTA
         -0.5f, 0.5f,-0.5f, 1.0f,0.2f,0.5f,
          0.5f, 0.5f,-0.5f, 1.0f,0.2f,0.5f,
          0.5f, 0.5f, 0.5f, 1.0f,0.2f,0.5f,
          0.5f, 0.5f, 0.5f, 1.0f,0.2f,0.5f,
         -0.5f, 0.5f, 0.5f, 1.0f,0.2f,0.5f,
         -0.5f, 0.5f,-0.5f, 1.0f,0.2f,0.5f,
    };

    GLuint VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Atributos
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);               // posición
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat))); // color
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // Proyección en perspectiva
    glm::mat4 projection = glm::mat4(1.0f);
    projection = glm::perspective(glm::radians(45.0f),
        (GLfloat)screenWidth / (GLfloat)screenHeight,
        0.1f, 100.0f);

    // Parámetros
    const float cubeScale = 2.2f;                 // tamaño del cubo
    const float sep = cubeScale * 1.05f;         // separación horizontal
    const float h = cubeScale * 1.05f;         // separación vertical
    const float yaw = 3.14159265f - glm::radians(45.0f); // frente (π) inclinado 45° a la izquierda

    // POSICIONES 3–2–1: base (3), intermedia (2), arriba (1)
    glm::vec3 positions[6] = {
        // Base (3 cubos) - z = 0.0
        glm::vec3(-sep, 0.0f,  0.0f),
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(sep, 0.0f,  0.0f),

        // Intermedia (2 cubos) - y = h, z algo más al fondo
        glm::vec3(-sep * 0.5f, h, -0.4f * sep),
        glm::vec3(sep * 0.5f, h, -0.4f * sep),

        // Arriba (1 cubo) - y = 2h, z más al fondo
        glm::vec3(0.0f, 2.0f * h, -0.8f * sep)
    };

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        ourShader.Use();

        // Cámara: centrada y un poco más lejos para encuadrar los 6 cubos
        glm::mat4 view(1.0f);
        view = glm::translate(view, glm::vec3(0.0f, -1.5f, -16.5f));

        GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
        GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
        GLint projLoc = glGetUniformLocation(ourShader.Program, "projection");

        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

        glBindVertexArray(VAO);

        // --- DIBUJAR 6 CUBOS ---
        for (int i = 0; i < 6; ++i) {
            glm::mat4 model(1.0f);
            model = glm::translate(model, positions[i]);
            model = glm::rotate(model, yaw, glm::vec3(0.0f, 1.0f, 0.0f)); // 45° a la izquierda
            model = glm::scale(model, glm::vec3(cubeScale));

            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }

        glBindVertexArray(0);

        glfwSwapBuffers(window);
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    glfwTerminate();
    return EXIT_SUCCESS;
}
