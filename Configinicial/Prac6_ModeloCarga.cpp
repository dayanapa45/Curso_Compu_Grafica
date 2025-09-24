// Dayana Plata Alvarez
// Practica 6 Carga de Modelos
// Fecha de entrega: 9/21/2025
// No. cuenta: 318300764

// Std. Includes
#include <iostream>
#include <string>

// GLEW
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// GL includes
#include "Shader.h"
#include "Camera.h"
#include "Model.h"

// GLM Mathematics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Other Libs
#include "SOIL2/SOIL2.h"
#include "stb_image.h"

// Properties
const GLuint WIDTH = 800, HEIGHT = 600;
int SCREEN_WIDTH, SCREEN_HEIGHT;

// Function prototypes
void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
void MouseCallback(GLFWwindow* window, double xPos, double yPos);
void DoMovement();

// Camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
bool    keys[1024] = { false };
GLfloat lastX = 400.0f;
GLfloat lastY = 300.0f;
bool    firstMouse = true;

GLfloat deltaTime = 0.0f;
GLfloat lastFrame = 0.0f;

int main()
{
    // Init GLFW
    if (!glfwInit()) {
        std::cout << "Failed to init GLFW\n";
        return EXIT_FAILURE;
    }

    // Set all the required options for GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // Create window
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Carga de modelos y camara sintetica", nullptr, nullptr);
    if (!window) {
        std::cout << "Failed to create GLFW window\n";
        glfwTerminate();
        return EXIT_FAILURE;
    }
    glfwMakeContextCurrent(window);

    glfwGetFramebufferSize(window, &SCREEN_WIDTH, &SCREEN_HEIGHT);

    // Callbacks
    glfwSetKeyCallback(window, KeyCallback);
    glfwSetCursorPosCallback(window, MouseCallback);
    // glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); // opcional

    // GLEW
    glewExperimental = GL_TRUE;
    if (GLEW_OK != glewInit()) {
        std::cout << "Failed to initialize GLEW\n";
        return EXIT_FAILURE;
    }

    // Viewport
    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    // OpenGL options
    glEnable(GL_DEPTH_TEST);

    // Shaders
    Shader shader("Shader/modelLoading.vs", "Shader/modelLoading.frag");

    // Load models (ajusta rutas según tu estructura)
    Model dog((char*)"Models/RedDog/RedDog.obj");
    Model planta((char*)"Models/Planta/planta.obj");

    // Matrices de cámara/proyección (puedes recalcular si cambias tamaño)
    glm::mat4 projection = glm::perspective(
        glm::radians(camera.GetZoom()),
        static_cast<float>(SCREEN_WIDTH) / static_cast<float>(SCREEN_HEIGHT),
        0.1f, 100.0f
    );

    // Game loop
    while (!glfwWindowShouldClose(window))
    {
        // Time
        GLfloat currentFrame = static_cast<GLfloat>(glfwGetTime()); // glfwGetTime() es double
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // Input
        glfwPollEvents();
        DoMovement();

        // Clear
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Use shader y set uniforms
        shader.Use();

        glm::mat4 view = camera.GetViewMatrix();

        GLint uProj = glGetUniformLocation(shader.Program, "projection");
        GLint uView = glGetUniformLocation(shader.Program, "view");
        GLint uModel = glGetUniformLocation(shader.Program, "model");

        glUniformMatrix4fv(uProj, 1, GL_FALSE, glm::value_ptr(projection));
        glUniformMatrix4fv(uView, 1, GL_FALSE, glm::value_ptr(view));

        // --- Perro (dog) ---
        glm::mat4 modelDog = glm::mat4(1.0f);
        modelDog = glm::translate(modelDog, glm::vec3(0.0f, 0.0f, 0.0f));
        modelDog = glm::scale(modelDog, glm::vec3(1.0f));
        glUniformMatrix4fv(uModel, 1, GL_FALSE, glm::value_ptr(modelDog));
        dog.Draw(shader);

        // --- Planta ---
        glm::mat4 modelPlanta = glm::mat4(1.0f);
        modelPlanta = glm::translate(modelPlanta, glm::vec3(3.0f, 0.0f, 0.0f));
        modelPlanta = glm::scale(modelPlanta, glm::vec3(2.0f));
        glUniformMatrix4fv(uModel, 1, GL_FALSE, glm::value_ptr(modelPlanta));
        Planta.Draw(shader);

        // (opcional) Duplicar el perro en otra posición
        glm::mat4 modelDog2 = glm::mat4(1.0f);
        modelDog2 = glm::translate(modelDog2, glm::vec3(-2.0f, 0.0f, 0.0f));
        glUniformMatrix4fv(uModel, 1, GL_FALSE, glm::value_ptr(modelDog2));
        dog.Draw(shader);

        // Swap
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}

// Moves/alters the camera positions based on user input
void DoMovement()
{
    if (keys[GLFW_KEY_W] || keys[GLFW_KEY_UP])
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (keys[GLFW_KEY_S] || keys[GLFW_KEY_DOWN])
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (keys[GLFW_KEY_A] || keys[GLFW_KEY_LEFT])
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (keys[GLFW_KEY_D] || keys[GLFW_KEY_RIGHT])
        camera.ProcessKeyboard(RIGHT, deltaTime);
}

// Is called whenever a key is pressed/released via GLFW
void KeyCallback(GLFWwindow* window, int key, int, int action, int)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

    if (key >= 0 && key < 1024) {
        if (action == GLFW_PRESS)  keys[key] = true;
        if (action == GLFW_RELEASE) keys[key] = false;
    }
}

void MouseCallback(GLFWwindow* window, double xPos, double yPos)
{
    (void)window; // evita warning si no lo usas

    if (firstMouse) {
        lastX = static_cast<GLfloat>(xPos);
        lastY = static_cast<GLfloat>(yPos);
        firstMouse = false;
    }

    GLfloat xOffset = static_cast<GLfloat>(xPos) - lastX;
    GLfloat yOffset = lastY - static_cast<GLfloat>(yPos); // invertido por convención

    lastX = static_cast<GLfloat>(xPos);
    lastY = static_cast<GLfloat>(yPos);

    camera.ProcessMouseMovement(xOffset, yOffset);
}


