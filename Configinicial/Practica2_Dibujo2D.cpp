// Practica 2: Dibujo de Primitivas en 2D 
// Laboratorio de computacion grafica
// GPO: 07 
// Dayana Plata Alvarez 
// No. cuenta: 318300764 
// Fecha de entrega: Agosto/24/2025 

#include<iostream>

//#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Shaders
#include "Shader.h"

void resize(GLFWwindow* window, int width, int height);

const GLint WIDTH = 800, HEIGHT = 600;

int main() {
    glfwInit();

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
    // VÉRTICES DEL CORAZÓN
    // ========================
    // Cada fila y columna simula una “celda” del corazón pixelado
    // Cada vértice es un punto coloreado (r,g,b)
    // Coordenadas ajustadas para que se vea centrado (-0.5 a 0.5 aprox)

   // 
    float vertices[] = {
        // x,     y,     z,    r, g, b
        // ================= Borde superior (negro) =================
        -0.40f,  0.42f, 0.0f,  0,0,0,
        -0.30f,  0.46f, 0.0f,  0,0,0,
        -0.20f,  0.48f, 0.0f,  0,0,0,
         0.20f,  0.48f, 0.0f,  0,0,0,
         0.30f,  0.46f, 0.0f,  0,0,0,
         0.40f,  0.42f, 0.0f,  0,0,0,

         // ================= Brillos blancos (lóbulo izq.) =================
         -0.32f,  0.28f, 0.0f,  1,1,1,
         -0.24f,  0.28f, 0.0f,  1,1,1,
         -0.32f,  0.18f, 0.0f,  1,1,1,

         // ================= Relleno rojo: scanlines (de arriba a abajo) =================
         // Fila 1
         -0.36f,  0.36f, 0.0f,  1,0,0,   -0.28f, 0.36f, 0.0f, 1,0,0,   -0.20f, 0.36f, 0.0f, 1,0,0,
         -0.12f,  0.36f, 0.0f,  1,0,0,    0.00f, 0.36f, 0.0f, 1,0,0,    0.12f, 0.36f, 0.0f, 1,0,0,
          0.20f,  0.36f, 0.0f,  1,0,0,    0.28f, 0.36f, 0.0f, 1,0,0,    0.36f, 0.36f, 0.0f, 1,0,0,

          // Fila 2
          -0.40f,  0.28f, 0.0f,  1,0,0,   -0.28f, 0.28f, 0.0f, 1,0,0,   -0.20f, 0.28f, 0.0f, 1,0,0,
          -0.12f,  0.28f, 0.0f,  1,0,0,    0.00f, 0.28f, 0.0f, 1,0,0,    0.12f, 0.28f, 0.0f, 1,0,0,
           0.20f,  0.28f, 0.0f,  1,0,0,    0.28f, 0.28f, 0.0f, 1,0,0,    0.40f, 0.28f, 0.0f, 1,0,0,

           // Fila 3
           -0.44f,  0.20f, 0.0f,  1,0,0,   -0.32f, 0.20f, 0.0f, 1,0,0,   -0.24f, 0.20f, 0.0f, 1,0,0,
           -0.16f,  0.20f, 0.0f,  1,0,0,   -0.08f, 0.20f, 0.0f, 1,0,0,    0.00f, 0.20f, 0.0f, 1,0,0,
            0.08f,  0.20f, 0.0f,  1,0,0,    0.16f, 0.20f, 0.0f, 1,0,0,    0.24f, 0.20f, 0.0f, 1,0,0,
            0.32f,  0.20f, 0.0f,  1,0,0,    0.44f, 0.20f, 0.0f, 1,0,0,

            // Fila 4
            -0.44f,  0.12f, 0.0f,  1,0,0,   -0.32f, 0.12f, 0.0f, 1,0,0,   -0.24f, 0.12f, 0.0f, 1,0,0,
            -0.16f,  0.12f, 0.0f,  1,0,0,   -0.08f, 0.12f, 0.0f, 1,0,0,    0.00f, 0.12f, 0.0f, 1,0,0,
             0.08f,  0.12f, 0.0f,  1,0,0,    0.16f, 0.12f, 0.0f, 1,0,0,    0.24f, 0.12f, 0.0f, 1,0,0,
             0.32f,  0.12f, 0.0f,  1,0,0,    0.44f, 0.12f, 0.0f, 1,0,0,

             // Fila 5
             -0.36f,  0.04f, 0.0f,  1,0,0,   -0.28f, 0.04f, 0.0f, 1,0,0,   -0.20f, 0.04f, 0.0f, 1,0,0,
             -0.12f,  0.04f, 0.0f,  1,0,0,   -0.04f, 0.04f, 0.0f, 1,0,0,    0.04f, 0.04f, 0.0f, 1,0,0,
              0.12f,  0.04f, 0.0f,  1,0,0,    0.20f, 0.04f, 0.0f, 1,0,0,    0.28f, 0.04f, 0.0f, 1,0,0,
              0.36f,  0.04f, 0.0f,  1,0,0,

              // Fila 6
              -0.28f, -0.04f, 0.0f,  1,0,0,   -0.20f, -0.04f, 0.0f, 1,0,0,  -0.12f, -0.04f, 0.0f, 1,0,0,
              -0.04f, -0.04f, 0.0f,  1,0,0,    0.04f, -0.04f, 0.0f, 1,0,0,   0.12f, -0.04f, 0.0f, 1,0,0,
               0.20f, -0.04f, 0.0f,  1,0,0,    0.28f, -0.04f, 0.0f, 1,0,0,

               // Fila 7
               -0.20f, -0.12f, 0.0f,  1,0,0,   -0.12f, -0.12f, 0.0f, 1,0,0,  -0.04f, -0.12f, 0.0f, 1,0,0,
                0.04f, -0.12f, 0.0f,  1,0,0,    0.12f, -0.12f, 0.0f, 1,0,0,   0.20f, -0.12f, 0.0f, 1,0,0,

                // ================= Borde inferior (negro) =================
                -0.12f, -0.20f, 0.0f,  0,0,0,
                 0.00f, -0.24f, 0.0f,  0,0,0,
                 0.12f, -0.20f, 0.0f,  0,0,0,
                 0.00f, -0.36f, 0.0f,  0,0,0  // punta
    };


    unsigned int indices[] = { 0,1,2 }; // No lo usamos realmente, pero lo dejamos por estructura

    GLuint VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        ourShader.Use();
        glBindVertexArray(VAO);

        glPointSize(35);  // tamaño de los “pixeles”
        glDrawArrays(GL_POINTS, 0, 26); // dibuja todos los puntos

        glBindVertexArray(0);
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return EXIT_SUCCESS;
}

void resize(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}
