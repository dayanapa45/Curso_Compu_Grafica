// Dayana Plata Alvarez
// Practica 5 Modelo Jerárquico
// Fecha de entrega: 9/14/2025
// No. cuenta: 318300764

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h> 
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.h"

void Inputs(GLFWwindow* window);

const GLint WIDTH = 1200, HEIGHT = 800;

// For Keyboard
float movX = 0.0f, movY = 0.0f, movZ = -5.0f, rot = 0.0f;

// For model (ángulos)
float hombro = 0.0f, codo = 0.0f, muneca = 0.0f;
// Usaremos estos dos para TODAS las falanges (proximal y distal)
float dedo1 = 0.0f, dedo2 = 0.0f;

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Modelado jerarquico", nullptr, nullptr);
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
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    Shader ourShader("Shader/core.vs", "Shader/core.frag");

    // Cubo unitario (36 vértices)
    float vertices[] = {
        -0.5f,-0.5f, 0.5f,  0.5f,-0.5f, 0.5f,  0.5f, 0.5f, 0.5f,
         0.5f, 0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f,-0.5f, 0.5f,

        -0.5f,-0.5f,-0.5f,  0.5f,-0.5f,-0.5f,  0.5f, 0.5f,-0.5f,
         0.5f, 0.5f,-0.5f, -0.5f, 0.5f,-0.5f, -0.5f,-0.5f,-0.5f,

         0.5f,-0.5f, 0.5f,  0.5f,-0.5f,-0.5f,  0.5f, 0.5f,-0.5f,
         0.5f, 0.5f,-0.5f,  0.5f, 0.5f, 0.5f,  0.5f,-0.5f, 0.5f,

        -0.5f, 0.5f, 0.5f, -0.5f, 0.5f,-0.5f, -0.5f,-0.5f,-0.5f,
        -0.5f,-0.5f,-0.5f, -0.5f,-0.5f, 0.5f, -0.5f, 0.5f, 0.5f,

        -0.5f,-0.5f,-0.5f,  0.5f,-0.5f,-0.5f,  0.5f,-0.5f, 0.5f,
         0.5f,-0.5f, 0.5f, -0.5f,-0.5f, 0.5f, -0.5f,-0.5f,-0.5f,

        -0.5f, 0.5f,-0.5f,  0.5f, 0.5f,-0.5f,  0.5f, 0.5f, 0.5f,
         0.5f, 0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f,-0.5f
    };

    GLuint VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    glm::mat4 projection = glm::perspective(glm::radians(45.0f),
        (GLfloat)screenWidth / (GLfloat)screenHeight, 0.1f, 100.0f);
    glm::vec3 color = glm::vec3(0.0f, 0.0f, 1.0f);

    while (!glfwWindowShouldClose(window)) {
        Inputs(window);
        glfwPollEvents();

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        ourShader.Use();
        glm::mat4 model = glm::mat4(1.0f);
        glm::mat4 view = glm::mat4(1.0f);
        glm::mat4 modelTemp = glm::mat4(1.0f);
        glm::mat4 modelTemp2 = glm::mat4(1.0f);

        // View
        view = glm::translate(view, glm::vec3(movX, movY, movZ));
        view = glm::rotate(view, glm::radians(rot), glm::vec3(0.0f, 1.0f, 0.0f));

        GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
        GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
        GLint projecLoc = glGetUniformLocation(ourShader.Program, "projection");
        GLint uniformColor = ourShader.uniformColor;

        glUniformMatrix4fv(projecLoc, 1, GL_FALSE, glm::value_ptr(projection));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

        glBindVertexArray(VAO);

        // Bíceps
        model = glm::rotate(model, glm::radians(hombro), glm::vec3(0.0f, 0.0, 1.0f));
        modelTemp = model = glm::translate(model, glm::vec3(1.5f, 0.0f, 0.0f));
        model = glm::scale(model, glm::vec3(3.0f, 1.0f, 1.0f));
        color = glm::vec3(0.0f, 1.0f, 0.0f);
        glUniform3fv(uniformColor, 1, glm::value_ptr(color));
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glDrawArrays(GL_TRIANGLES, 0, 36);

        // Antebrazo
        model = glm::translate(modelTemp, glm::vec3(1.5f, 0.0f, 0.0f));
        model = glm::rotate(model, glm::radians(codo), glm::vec3(0.0f, 1.0f, 0.0f));
        modelTemp = model = glm::translate(model, glm::vec3(1.0f, 0.0f, 0.0f));
        model = glm::scale(model, glm::vec3(2.0f, 1.0f, 1.0f));
        color = glm::vec3(1.0f, 0.0f, 0.0f);
        glUniform3fv(uniformColor, 1, glm::value_ptr(color));
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glDrawArrays(GL_TRIANGLES, 0, 36);

        // Palma
        model = glm::translate(modelTemp, glm::vec3(1.0f, 0.0f, 0.0f));
        model = glm::rotate(model, glm::radians(muneca), glm::vec3(1.0f, 0.0f, 0.0f));
        modelTemp2 = modelTemp = model = glm::translate(model, glm::vec3(0.25f, 0.0f, 0.0f));
        model = glm::scale(model, glm::vec3(0.5f, 1.0f, 1.0f));
        color = glm::vec3(1.0f, 1.0f, 1.0f);
        glUniform3fv(uniformColor, 1, glm::value_ptr(color));
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glDrawArrays(GL_TRIANGLES, 0, 36);

        // Guardamos un ancla estable de la palma para todos los dedos
        glm::mat4 palmBase = modelTemp2;

        auto drawFinger = [&](glm::vec3 baseOffset, float baseZRotateDeg = 0.0f) {
            glm::mat4 m = glm::translate(palmBase, baseOffset);            // Punto donde nace el dedo
            if (baseZRotateDeg != 0.0f)
                m = glm::rotate(m, glm::radians(baseZRotateDeg), glm::vec3(0.0f, 0.0f, 1.0f));

            // Falange proximal
            m = glm::rotate(m, glm::radians(dedo1), glm::vec3(0.0f, 0.0f, 1.0f));
            glm::mat4 joint = m = glm::translate(m, glm::vec3(0.5f, 0.0f, 0.0f));
            glm::mat4 seg = glm::scale(m, glm::vec3(1.0f, 0.28f, 0.25f));
            color = glm::vec3(0.0f, 1.0f, 1.0f);
            glUniform3fv(uniformColor, 1, glm::value_ptr(color));
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(seg));
            glDrawArrays(GL_TRIANGLES, 0, 36);

            // Falange distal
            m = glm::translate(joint, glm::vec3(0.5f, 0.0f, 0.0f));
            m = glm::rotate(m, glm::radians(dedo2), glm::vec3(0.0f, 0.0f, 1.0f));
            m = glm::translate(m, glm::vec3(0.5f, 0.0f, 0.0f));
            seg = glm::scale(m, glm::vec3(1.0f, 0.25f, 0.22f));
            color = glm::vec3(0.0f, 0.0f, 1.0f);
            glUniform3fv(uniformColor, 1, glm::value_ptr(color));
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(seg));
            glDrawArrays(GL_TRIANGLES, 0, 36);
            };

        // 4 dedos alineados (índice, medio, anular, meñique) — offsets en Z para no colisionar
        drawFinger(glm::vec3(0.25f, 0.35f, 0.375f)); // índice
        drawFinger(glm::vec3(0.25f, 0.35f, 0.125f)); // medio
        drawFinger(glm::vec3(0.25f, 0.35f, -0.125f)); // anular
        drawFinger(glm::vec3(0.25f, 0.35f, -0.375f)); // meñique

        // Pulgar (más abajo y con ligera rotación para alejarlo y evitar choques)
        drawFinger(glm::vec3(0.10f, -0.35f, 0.28f), -20.0f);

        glBindVertexArray(0);
        glfwSwapBuffers(window);
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glfwTerminate();
    return EXIT_SUCCESS;
}

void Inputs(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) movX += 0.008f;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) movX -= 0.008f;
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) movY += 0.008f;
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) movY -= 0.008f;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) movZ -= 0.008f;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) movZ += 0.008f;
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) rot += 0.18f;
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)  rot -= 0.18f;
    if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) hombro += 0.18f;
    if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS) hombro -= 0.18f;
    if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS) codo += 0.18f;
    if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS) codo -= 0.18f;
    if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS) muneca += 0.18f;
    if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS) muneca -= 0.18f;
    if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS) dedo1 += 0.18f; // proximal
    if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS) dedo1 -= 0.18f;
    if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS) dedo2 += 0.18f; // distal
    if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS) dedo2 -= 0.18f;
}

