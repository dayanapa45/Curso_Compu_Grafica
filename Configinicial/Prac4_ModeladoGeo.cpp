// Plata Alvarez Dayana
// Practica 4
// Fecha de entrega: 2/09/25
// No. de cuenta: 318300764

#include <iostream>

//#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Shaders
#include "Shader.h"

void Inputs(GLFWwindow* window);

const GLint WIDTH = 800, HEIGHT = 600;
float movX = 0.0f;
float movY = 0.0f;
float movZ = -8.0f;
float rot = 15.0f;

// --- Helper: dibuja un cubo con transform y color ---
static inline void drawBox(GLint modelLoc,
    const glm::vec3& scale,
    const glm::vec3& translate,
    const glm::vec3& color) {
    glm::mat4 model(1.0f);
    model = glm::translate(model, translate);
    model = glm::scale(model, scale);
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

    glVertexAttrib3f(1, color.r, color.g, color.b);
    glDrawArrays(GL_TRIANGLES, 0, 36);
}

int main() {
    glfwInit();
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Unicornio Voxel", nullptr, nullptr);

    int screenWidth, screenHeight;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

    if (nullptr == window) {
        std::cout << "Failed to create GLFW window\n";
        glfwTerminate();
        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if (GLEW_OK != glewInit()) {
        std::cout << "Failed to initialise GLEW\n";
        return EXIT_FAILURE;
    }

    glViewport(0, 0, screenWidth, screenHeight);
    glEnable(GL_DEPTH_TEST);

    Shader ourShader("Shader/core.vs", "Shader/core.frag");

    // Cubo base
    float vertices[] = {
        -0.5f,-0.5f, 0.5f, 1,0,0,  0.5f,-0.5f, 0.5f, 1,0,0,  0.5f, 0.5f, 0.5f, 1,0,0,
         0.5f, 0.5f, 0.5f, 1,0,0, -0.5f, 0.5f, 0.5f, 1,0,0, -0.5f,-0.5f, 0.5f, 1,0,0,

        -0.5f,-0.5f,-0.5f, 0,1,0,  0.5f,-0.5f,-0.5f, 0,1,0,  0.5f, 0.5f,-0.5f, 0,1,0,
         0.5f, 0.5f,-0.5f, 0,1,0, -0.5f, 0.5f,-0.5f, 0,1,0, -0.5f,-0.5f,-0.5f, 0,1,0,

         0.5f,-0.5f, 0.5f, 0,0,1,  0.5f,-0.5f,-0.5f, 0,0,1,  0.5f, 0.5f,-0.5f, 0,0,1,
         0.5f, 0.5f,-0.5f, 0,0,1,  0.5f, 0.5f, 0.5f, 0,0,1,  0.5f,-0.5f, 0.5f, 0,0,1,

        -0.5f, 0.5f, 0.5f, 1,1,0, -0.5f, 0.5f,-0.5f, 1,1,0, -0.5f,-0.5f,-0.5f, 1,1,0,
        -0.5f,-0.5f,-0.5f, 1,1,0, -0.5f,-0.5f, 0.5f, 1,1,0, -0.5f, 0.5f, 0.5f, 1,1,0,

        -0.5f,-0.5f,-0.5f, 0,1,1,  0.5f,-0.5f,-0.5f, 0,1,1,  0.5f,-0.5f, 0.5f, 0,1,1,
         0.5f,-0.5f, 0.5f, 0,1,1, -0.5f,-0.5f, 0.5f, 0,1,1, -0.5f,-0.5f,-0.5f, 0,1,1,

        -0.5f, 0.5f,-0.5f, 1,0.2f,0.5f, 0.5f, 0.5f,-0.5f, 1,0.2f,0.5f, 0.5f, 0.5f, 0.5f, 1,0.2f,0.5f,
         0.5f, 0.5f, 0.5f, 1,0.2f,0.5f, -0.5f, 0.5f, 0.5f, 1,0.2f,0.5f, -0.5f, 0.5f,-0.5f, 1,0.2f,0.5f
    };

    GLuint VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    glm::mat4 projection(1.0f);
    projection = glm::perspective(glm::radians(45.0f),
        (GLfloat)screenWidth / (GLfloat)screenHeight,
        0.1f, 100.0f);

    // Colores
    const glm::vec3 pink(1.00f, 0.82f, 0.90f);
    const glm::vec3 pinkLight(1.00f, 0.88f, 0.95f);
    const glm::vec3 hoof(0.69f, 0.53f, 0.56f);
    const glm::vec3 magenta(0.95f, 0.10f, 0.80f);
    const glm::vec3 black(0.05f, 0.05f, 0.05f);
    const glm::vec3 red(1.00f, 0.25f, 0.25f);
    const glm::vec3 orange(1.00f, 0.60f, 0.20f);
    const glm::vec3 yellow(1.00f, 0.90f, 0.20f);
    const glm::vec3 green(0.25f, 0.85f, 0.45f);
    const glm::vec3 cyan(0.25f, 0.85f, 0.95f);
    const glm::vec3 blue(0.25f, 0.50f, 1.00f);
    const glm::vec3 purple(0.75f, 0.30f, 1.00f);

    while (!glfwWindowShouldClose(window)) {
        Inputs(window);
        glfwPollEvents();

        glClearColor(0.93f, 0.88f, 0.97f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        ourShader.Use();

        glm::mat4 view(1.0f);
        view = glm::translate(view, glm::vec3(movX, movY, movZ));
        view = glm::rotate(view, glm::radians(rot), glm::vec3(0.0f, 1.0f, 0.0f));

        GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
        GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
        GLint projLoc = glGetUniformLocation(ourShader.Program, "projection");

        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

        glBindVertexArray(VAO);
        glDisableVertexAttribArray(1);

        // --- UNICORNIO ---

        // Cuerpo
        drawBox(modelLoc, { 3.6f, 2.0f, 2.2f }, { 0.0f, 0.8f, 0.0f }, pink);

        // Patas
        glm::vec3 legScale(0.7f, 1.3f, 0.7f);
        drawBox(modelLoc, legScale, { 1.9f,-0.3f, 1.4f }, pink);
        drawBox(modelLoc, legScale, { -1.9f,-0.3f, 1.4f }, pink);
        drawBox(modelLoc, legScale, { -1.9f,-0.3f,-1.4f }, pink);
        drawBox(modelLoc, legScale, { 1.9f,-0.3f,-1.4f }, pink);

        // Pezuñas
        glm::vec3 hoofScale(0.7f, 0.45f, 0.7f);
        drawBox(modelLoc, hoofScale, { 1.9f,-1.2f, 1.4f }, hoof);
        drawBox(modelLoc, hoofScale, { -1.9f,-1.2f, 1.4f }, hoof);
        drawBox(modelLoc, hoofScale, { -1.9f,-1.2f,-1.4f }, hoof);
        drawBox(modelLoc, hoofScale, { 1.9f,-1.2f,-1.4f }, hoof);

        // Cabeza
        drawBox(modelLoc, { 1.5f, 1.5f, 1.5f }, { 2.6f, 1.7f, 0.0f }, pinkLight);

        // Hocico
        drawBox(modelLoc, { 0.9f, 0.9f, 1.0f }, { 3.6f, 1.3f, 0.0f }, pink);

        // Oreja
        drawBox(modelLoc, { 0.35f, 0.55f, 0.35f }, { 2.3f, 2.6f,-0.5f }, pinkLight);

        // Cuerno
        drawBox(modelLoc, { 0.35f, 1.1f, 0.35f }, { 2.8f, 2.8f, 0.2f }, magenta);

        // OJOS (más grandes, cubos negros)
        drawBox(modelLoc, { 0.45f, 0.45f, 0.45f }, { 3.30f, 1.55f,  0.38f }, black);
        drawBox(modelLoc, { 0.45f, 0.45f, 0.45f }, { 3.30f, 1.55f, -0.38f }, black);


        // Melena arcoíris
        float mx = -0.6f;
        drawBox(modelLoc, { 0.60f,0.35f,0.60f }, { mx + 0.0f, 2.1f, 0.0f }, red);
        drawBox(modelLoc, { 0.60f,0.35f,0.60f }, { mx + 0.6f, 2.25f, 0.0f }, orange);
        drawBox(modelLoc, { 0.60f,0.35f,0.60f }, { mx + 1.2f, 2.40f, 0.0f }, yellow);
        drawBox(modelLoc, { 0.60f,0.35f,0.60f }, { mx + 1.8f, 2.55f, 0.0f }, green);
        drawBox(modelLoc, { 0.60f,0.35f,0.60f }, { mx + 2.4f, 2.70f, 0.0f }, cyan);
        drawBox(modelLoc, { 0.60f,0.35f,0.60f }, { mx + 3.0f, 2.85f, 0.0f }, blue);
        drawBox(modelLoc, { 0.60f,0.35f,0.60f }, { mx + 3.6f, 3.00f, 0.0f }, purple);

        // COLA ARCOÍRIS(7 bloquecitos conectados al cuerpo)
        {
            float ax = -1.85f;   // borde trasero del cuerpo
            float ay = 1.40f;    // altura para conectarla al cuerpo
            float az = 0.0f;
            glm::vec3 tScale(0.45f, 0.45f, 0.45f);

            drawBox(modelLoc, tScale, { ax - 0.10f, ay + 0.00f, az }, red);
            drawBox(modelLoc, tScale, { ax - 0.55f, ay - 0.15f, az }, orange);
            drawBox(modelLoc, tScale, { ax - 1.00f, ay - 0.30f, az }, yellow);
            drawBox(modelLoc, tScale, { ax - 1.45f, ay - 0.45f, az }, green);
            drawBox(modelLoc, tScale, { ax - 1.90f, ay - 0.60f, az }, cyan);
            drawBox(modelLoc, tScale, { ax - 2.35f, ay - 0.75f, az }, blue);
            drawBox(modelLoc, tScale, { ax - 2.80f, ay - 0.90f, az }, purple);
        }


        glBindVertexArray(0);
        glfwSwapBuffers(window);
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glfwTerminate();
    return EXIT_SUCCESS;
}

void Inputs(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) movX += 0.08f;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) movX -= 0.08f;
    if (glfwGetKey(window, GLFW_KEY_PAGE_UP) == GLFW_PRESS) movY += 0.08f;
    if (glfwGetKey(window, GLFW_KEY_PAGE_DOWN) == GLFW_PRESS) movY -= 0.08f;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) movZ -= 0.08f;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) movZ += 0.08f;
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) rot += 0.4f;
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) rot -= 0.4f;
}
