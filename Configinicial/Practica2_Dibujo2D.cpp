// Practica 2: Dibujo de Primitivas en 2D 
// Laboratorio de computacion grafica
// GPO: 07 
// Dayana Plata Alvarez 
// No. cuenta: 318300764 
// Fecha de entrega: Agosto/24/2025 

#include <iostream>

//#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Shaders
#include "Shader.h"

void resize(GLFWwindow* window, int width, int height);

const GLint WIDTH = 800, HEIGHT = 600;

int main() {
    glfwInit();
    //glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Dibujo de Primitivas en 2D", NULL, NULL);
    glfwSetFramebufferSizeCallback(window, resize);

    if (window == NULL) {
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

    std::cout << "> Version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "> Vendor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "> Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "> SL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

    Shader ourShader("Shader/core.vs", "Shader/core.frag");

    // ========================
    //    VÉRTICES DEL CORAZÓN
    // ========================
    // Cada vértice: x, y, z, r, g, b
    // (corazón “pixelado” con dos brillos blancos; fondo negro)
    float vertices[] = {
        // ---------- BRILLOS (BLANCO) LÓBULO IZQUIERDO ----------
        -0.42f,  0.30f, 0.0f,   1.0f,1.0f,1.0f,
        -0.36f,  0.30f, 0.0f,   1.0f,1.0f,1.0f,

        // ---------- CUERPO (ROJO) FILAS SUPERIORES ----------
        // y = 0.36
        -0.48f,  0.36f, 0.0f,   1,0,0,
        -0.42f,  0.36f, 0.0f,   1,0,0,
        -0.36f,  0.36f, 0.0f,   1,0,0,
         0.24f,  0.36f, 0.0f,   1,0,0,
         0.30f,  0.36f, 0.0f,   1,0,0,
         0.36f,  0.36f, 0.0f,   1,0,0,

         // y = 0.30
         -0.48f,  0.30f, 0.0f,   1,0,0,
         -0.30f,  0.30f, 0.0f,   1,0,0,
         -0.24f,  0.30f, 0.0f,   1,0,0,
          0.12f,  0.30f, 0.0f,   1,0,0,
          0.18f,  0.30f, 0.0f,   1,0,0,
          0.24f,  0.30f, 0.0f,   1,0,0,
          0.30f,  0.30f, 0.0f,   1,0,0,
          0.36f,  0.30f, 0.0f,   1,0,0,

          // y = 0.24
          -0.42f,  0.24f, 0.0f,   1,0,0,
          -0.36f,  0.24f, 0.0f,   1,0,0,
          -0.30f,  0.24f, 0.0f,   1,0,0,
          -0.24f,  0.24f, 0.0f,   1,0,0,
          -0.18f,  0.24f, 0.0f,   1,0,0,
          -0.12f,  0.24f, 0.0f,   1,0,0,
          -0.06f,  0.24f, 0.0f,   1,0,0,
           0.00f,  0.24f, 0.0f,   1,0,0,
           0.06f,  0.24f, 0.0f,   1,0,0,
           0.12f,  0.24f, 0.0f,   1,0,0,
           0.18f,  0.24f, 0.0f,   1,0,0,
           0.24f,  0.24f, 0.0f,   1,0,0,
           0.30f,  0.24f, 0.0f,   1,0,0,

           // y = 0.18
           -0.30f,  0.18f, 0.0f,   1,0,0,
           -0.24f,  0.18f, 0.0f,   1,0,0,
           -0.18f,  0.18f, 0.0f,   1,0,0,
           -0.12f,  0.18f, 0.0f,   1,0,0,
           -0.06f,  0.18f, 0.0f,   1,0,0,
            0.00f,  0.18f, 0.0f,   1,0,0,
            0.06f,  0.18f, 0.0f,   1,0,0,
            0.12f,  0.18f, 0.0f,   1,0,0,
            0.18f,  0.18f, 0.0f,   1,0,0,
            0.24f,  0.18f, 0.0f,   1,0,0,
            0.30f,  0.18f, 0.0f,   1,0,0,

            // y = 0.12
            -0.24f,  0.12f, 0.0f,   1,0,0,
            -0.18f,  0.12f, 0.0f,   1,0,0,
            -0.12f,  0.12f, 0.0f,   1,0,0,
            -0.06f,  0.12f, 0.0f,   1,0,0,
             0.00f,  0.12f, 0.0f,   1,0,0,
             0.06f,  0.12f, 0.0f,   1,0,0,
             0.12f,  0.12f, 0.0f,   1,0,0,
             0.18f,  0.12f, 0.0f,   1,0,0,
             0.24f,  0.12f, 0.0f,   1,0,0,

             // y = 0.06
             -0.18f,  0.06f, 0.0f,   1,0,0,
             -0.12f,  0.06f, 0.0f,   1,0,0,
             -0.06f,  0.06f, 0.0f,   1,0,0,
              0.00f,  0.06f, 0.0f,   1,0,0,
              0.06f,  0.06f, 0.0f,   1,0,0,
              0.12f,  0.06f, 0.0f,   1,0,0,

              // y = 0.00
              -0.12f,  0.00f, 0.0f,   1,0,0,
              -0.06f,  0.00f, 0.0f,   1,0,0,
               0.00f,  0.00f, 0.0f,   1,0,0,
               0.06f,  0.00f, 0.0f,   1,0,0,

               // ---------- TALLO VERTICAL ROJO ----------
                0.00f, -0.06f, 0.0f,   1,0,0,
                0.00f, -0.12f, 0.0f,   1,0,0,
                0.00f, -0.18f, 0.0f,   1,0,0,
                0.00f, -0.24f, 0.0f,   1,0,0,
                0.00f, -0.30f, 0.0f,   1,0,0,
    };

    // Mantengo el EBO por estructura (no lo usamos aquí).
    unsigned int indices[] = { 0,1,2 };

    GLuint VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Posición
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    // Color
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        // Fondo negro como la referencia pequeña
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        ourShader.Use();
        glBindVertexArray(VAO);

        // “Pixeles” grandes para rellenar
        glPointSize(22.0f);
        GLint nverts = (GLint)(sizeof(vertices) / (6 * sizeof(float)));
        glDrawArrays(GL_POINTS, 0, nverts);

        // Si quieres evitar líneas/triángulos de tu demo, déjalos comentados:
        // glDrawArrays(GL_LINES,1,2);
        // glDrawArrays(GL_LINE_LOOP,0,4);
        // glDrawArrays(GL_TRIANGLES,0,3);
        // glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

        glBindVertexArray(0);
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return EXIT_SUCCESS;
}

void resize(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

