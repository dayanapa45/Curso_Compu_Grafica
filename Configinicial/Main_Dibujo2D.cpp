#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cmath>

#include "Shader.h" // tu clase Shader

// Función de callback
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

// Captura de entrada
void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// Genera los vértices de un corazón usando su ecuación paramétrica
std::vector<float> generateHeartVertices(float scale, float r, float g, float b) {
    std::vector<float> vertices;

    // Punto central para el TRIANGLE_FAN
    vertices.push_back(0.0f);
    vertices.push_back(0.0f);
    vertices.push_back(r);
    vertices.push_back(g);
    vertices.push_back(b);

    // Aproximamos la curva con muchos puntos
    int n = 200;
    for (int i = 0; i <= n; i++) {
        float t = (i / (float)n) * 2 * M_PI;
        float x = 16 * pow(sin(t), 3);
        float y = 13 * cos(t) - 5 * cos(2 * t) - 2 * cos(3 * t) - cos(4 * t);

        x *= 0.05f * scale; // normalización + escala
        y *= 0.05f * scale;

        vertices.push_back(x);
        vertices.push_back(y);
        vertices.push_back(r);
        vertices.push_back(g);
        vertices.push_back(b);
    }

    return vertices;
}

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 800, "Corazon con borde", NULL, NULL);
    if (window == NULL) {
        std::cout << "Error al crear ventana GLFW" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Error al inicializar GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, 800, 800);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    Shader ourShader("Shader/core.vs", "Shader/core.frag");

    // --- Generar corazón negro (borde) ---
    std::vector<float> heartBorder = generateHeartVertices(1.1f, 0.0f, 0.0f, 0.0f); // negro
    unsigned int VBO_border, VAO_border;
    glGenVertexArrays(1, &VAO_border);
    glGenBuffers(1, &VBO_border);

    glBindVertexArray(VAO_border);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_border);
    glBufferData(GL_ARRAY_BUFFER, heartBorder.size() * sizeof(float), heartBorder.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // --- Generar corazón rojo (relleno) ---
    std::vector<float> heartFill = generateHeartVertices(1.0f, 1.0f, 0.0f, 0.0f); // rojo
    unsigned int VBO_fill, VAO_fill;
    glGenVertexArrays(1, &VAO_fill);
    glGenBuffers(1, &VBO_fill);

    glBindVertexArray(VAO_fill);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_fill);
    glBufferData(GL_ARRAY_BUFFER, heartFill.size() * sizeof(float), heartFill.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // --- Loop de renderizado ---
    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // fondo blanco
        glClear(GL_COLOR_BUFFER_BIT);

        ourShader.use();

        // Dibujar borde primero
        glBindVertexArray(VAO_border);
        glDrawArrays(GL_TRIANGLE_FAN, 0, heartBorder.size() / 5);

        // Dibujar relleno encima
        glBindVertexArray(VAO_fill);
        glDrawArrays(GL_TRIANGLE_FAN, 0, heartFill.size() / 5);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Liberar memoria
    glDeleteVertexArrays(1, &VAO_border);
    glDeleteBuffers(1, &VBO_border);
    glDeleteVertexArrays(1, &VAO_fill);
    glDeleteBuffers(1, &VBO_fill);

    glfwTerminate();
    return 0;
}
