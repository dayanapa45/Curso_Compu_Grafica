// Practica 11: Animaciones Maquina de estados 
// Laboratorio de computacion grafica
// GPO: 07 
// Dayana Plata Alvarez 
// No. cuenta: 318300764 
// Fecha de entrega: 11/2/2025 
//#include <iostream>
//#include <cmath>
//
// GLEW
//#include <GL/glew.h>
//
// GLFW
//#include <GLFW/glfw3.h>
//
// Other Libs
//#include "stb_image.h"
//
// GLM Mathematics
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
//Load Models
//#include "SOIL2/SOIL2.h"
//
//
// Other includes
//#include "Shader.h"
//#include "Camera.h"
//#include "Model.h"
//
// Function prototypes
//void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mode);
//void MouseCallback(GLFWwindow *window, double xPos, double yPos);
//void DoMovement();
//void Animation();
//
// Window dimensions
//const GLuint WIDTH = 800, HEIGHT = 600;
//int SCREEN_WIDTH, SCREEN_HEIGHT;
//
// Camera
//Camera  camera(glm::vec3(0.0f, 0.0f, 3.0f));
//GLfloat lastX = WIDTH / 2.0;
//GLfloat lastY = HEIGHT / 2.0;
//bool keys[1024];
//bool firstMouse = true;
// Light attributes
//glm::vec3 lightPos(0.0f, 0.0f, 0.0f);
//bool active;
//
// Positions of the point lights
//glm::vec3 pointLightPositions[] = {
//	glm::vec3(0.0f,2.0f, 0.0f),
//	glm::vec3(0.0f,0.0f, 0.0f),
//	glm::vec3(0.0f,0.0f,  0.0f),
//	glm::vec3(0.0f,0.0f, 0.0f)
//};
//
//float vertices[] = {
//	 -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//	   -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//	   -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//
//	   -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//	   -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//	   -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//
//	   -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//	   -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//	   -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//	   -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//	   -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//	   -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//
//		0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//		0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//		0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//		0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//		0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//		0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//
//	   -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//		0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//		0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//		0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//	   -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//	   -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//
//	   -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//		0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//		0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//		0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//	   -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//	   -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
//};
//
//
//
//glm::vec3 Light1 = glm::vec3(0);
//Anim
//float rotBall = 0.0f;
//bool AnimBall = false;
//bool AnimDog = false;
//float rotDog = 0.0f;
//int dogAnim = 0;
//float FLegs = 0.0f;
//float RLegs = 0.0f;
//float head = 0.0f;
//float tail = 0.0f;
//glm::vec3 dogPos (0.0f,0.0f,0.0f);
//float dogRot = 0.0f;
//bool step = false;
//
//
//
// Deltatime
//GLfloat deltaTime = 0.0f;	// Time between current frame and last frame
//GLfloat lastFrame = 0.0f;  	// Time of last frame
//
//int main()
//{
//	 Init GLFW
//	glfwInit();
//	 Set all the required options for GLFW
//	/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);*/
//
//	 Create a GLFWwindow object that we can use for GLFW's functions
//	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Animacion maquina de estados", nullptr, nullptr);
//
//	if (nullptr == window)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//
//		return EXIT_FAILURE;
//	}
//
//	glfwMakeContextCurrent(window);
//
//	glfwGetFramebufferSize(window, &SCREEN_WIDTH, &SCREEN_HEIGHT);
//
//	 Set the required callback functions
//	glfwSetKeyCallback(window, KeyCallback);
//	glfwSetCursorPosCallback(window, MouseCallback);
//
//	 GLFW Options
//	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//
//	 Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
//	glewExperimental = GL_TRUE;
//	 Initialize GLEW to setup the OpenGL Function pointers
//	if (GLEW_OK != glewInit())
//	{
//		std::cout << "Failed to initialize GLEW" << std::endl;
//		return EXIT_FAILURE;
//	}
//
//	 Define the viewport dimensions
//	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
//
//
//
//	Shader lightingShader("Shader/lighting.vs", "Shader/lighting.frag");
//	Shader lampShader("Shader/lamp.vs", "Shader/lamp.frag");
//	
//	models
//	Model DogBody((char*)"Models/DogBody.obj");
//	Model HeadDog((char*)"Models/HeadDog.obj");
//	Model DogTail((char*)"Models/TailDog.obj");
//	Model F_RightLeg((char*)"Models/F_RightLegDog.obj");
//	Model F_LeftLeg((char*)"Models/F_LeftLegDog.obj");
//	Model B_RightLeg((char*)"Models/B_RightLegDog.obj");
//	Model B_LeftLeg((char*)"Models/B_LeftLegDog.obj");
//	Model Piso((char*)"Models/piso.obj");
//	Model Ball((char*)"Models/ball.obj");
//
//
//
//	 First, set the container's VAO (and VBO)
//	GLuint VBO, VAO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	 Position attribute
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//	 normal attribute
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//	 Set texture units
//	lightingShader.Use();
//	glUniform1i(glGetUniformLocation(lightingShader.Program, "Material.difuse"), 0);
//	glUniform1i(glGetUniformLocation(lightingShader.Program, "Material.specular"), 1);
//
//	glm::mat4 projection = glm::perspective(camera.GetZoom(), (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT, 0.1f, 100.0f);
//
//	 Game loop
//	while (!glfwWindowShouldClose(window))
//	{
//
//		 Calculate deltatime of current frame
//		GLfloat currentFrame = glfwGetTime();
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		 Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
//		glfwPollEvents();
//		DoMovement();
//		Animation();
//
//		 Clear the colorbuffer
//		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	   
//		 OpenGL options
//		glEnable(GL_DEPTH_TEST);
//
//		
//		glm::mat4 modelTemp = glm::mat4(1.0f); //Temp
//		
//	
//
//		 Use cooresponding shader when setting uniforms/drawing objects
//		lightingShader.Use();
//
//        glUniform1i(glGetUniformLocation(lightingShader.Program, "diffuse"), 0);
//		glUniform1i(glGetUniformLocation(lightingShader.Program, "specular"),1);
//
//		GLint viewPosLoc = glGetUniformLocation(lightingShader.Program, "viewPos");
//		glUniform3f(viewPosLoc, camera.GetPosition().x, camera.GetPosition().y, camera.GetPosition().z);
//
//
//		 Directional light
//		glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.direction"), -0.2f, -1.0f, -0.3f);
//		glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.ambient"),0.6f,0.6f,0.6f);
//		glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.diffuse"), 0.6f, 0.6f, 0.6f);
//		glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.specular"),0.3f, 0.3f, 0.3f);
//
//
//		 Point light 1
//	    glm::vec3 lightColor;
//		lightColor.x= abs(sin(glfwGetTime() *Light1.x));
//		lightColor.y= abs(sin(glfwGetTime() *Light1.y));
//		lightColor.z= sin(glfwGetTime() *Light1.z);
//
//		
//		glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].position"), pointLightPositions[0].x, pointLightPositions[0].y, pointLightPositions[0].z);
//		glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].ambient"), lightColor.x,lightColor.y, lightColor.z);
//		glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].diffuse"), lightColor.x,lightColor.y,lightColor.z);
//		glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].specular"), 1.0f, 0.2f, 0.2f);
//		glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[0].constant"), 1.0f);
//		glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[0].linear"), 0.045f);
//		glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[0].quadratic"),0.075f);
//
//
//		 SpotLight
//		glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.position"), camera.GetPosition().x, camera.GetPosition().y, camera.GetPosition().z);
//		glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.direction"), camera.GetFront().x, camera.GetFront().y, camera.GetFront().z);
//		glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.ambient"), 0.2f, 0.2f, 0.8f);
//		glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.diffuse"), 0.2f, 0.2f, 0.8f);
//		glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.specular"), 0.0f, 0.0f, 0.0f);
//		glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.constant"), 1.0f);
//		glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.linear"), 0.3f);
//		glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.quadratic"), 0.7f);
//		glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.cutOff"), glm::cos(glm::radians(12.0f)));
//		glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.outerCutOff"), glm::cos(glm::radians(18.0f)));
//		
//
//		 Set material properties
//		glUniform1f(glGetUniformLocation(lightingShader.Program, "material.shininess"), 5.0f);
//
//		 Create camera transformations
//		glm::mat4 view;
//		view = camera.GetViewMatrix();
//
//		 Get the uniform locations
//		GLint modelLoc = glGetUniformLocation(lightingShader.Program, "model");
//		GLint viewLoc = glGetUniformLocation(lightingShader.Program, "view");
//		GLint projLoc = glGetUniformLocation(lightingShader.Program, "projection");
//
//		 Pass the matrices to the shader
//		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
//
//
//		glm::mat4 model(1);
//
//	
//		
//		Carga de modelo 
//        view = camera.GetViewMatrix();	
//		model = glm::mat4(1);
//		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//		Piso.Draw(lightingShader);
//
//		model = glm::mat4(1);
//		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//		glUniform1i(glGetUniformLocation(lightingShader.Program, "transparency"), 0);
//		Body
//		modelTemp= model = glm::translate(model, dogPos);
//		modelTemp= model = glm::rotate(model, glm::radians(dogRot), glm::vec3(0.0f, 1.0f, 0.0f));
//		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//		DogBody.Draw(lightingShader);
//		Head
//		model = modelTemp;
//		model = glm::translate(model, glm::vec3(0.0f, 0.093f, 0.208f));
//		model = glm::rotate(model, glm::radians(head), glm::vec3(0.0f, 0.0f, 1.0f));
//		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//		HeadDog.Draw(lightingShader);
//		Tail 
//		model = modelTemp;
//		model = glm::translate(model, glm::vec3(0.0f, 0.026f, -0.288f));
//		model = glm::rotate(model, glm::radians(tail), glm::vec3(0.0f, 0.0f, -1.0f)); 
//		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model)); 
//		DogTail.Draw(lightingShader);
//		Front Left Leg
//		model = modelTemp;
//		model = glm::translate(model, glm::vec3(0.112f, -0.044f, 0.074f));
//		model = glm::rotate(model, glm::radians(FLegs), glm::vec3(-1.0f, 0.0f, 0.0f)); 
//		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//		F_LeftLeg.Draw(lightingShader);
//		Front Right Leg
//		model = modelTemp; 
//		model = glm::translate(model, glm::vec3(-0.111f, -0.055f, 0.074f));
//		model = glm::rotate(model, glm::radians(FLegs), glm::vec3(1.0f, 0.0f, 0.0f));
//		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//		F_RightLeg.Draw(lightingShader);
//		Back Left Leg
//		model = modelTemp; 
//		model = glm::translate(model, glm::vec3(0.082f, -0.046, -0.218)); 
//		model = glm::rotate(model, glm::radians(RLegs), glm::vec3(1.0f, 0.0f, 0.0f)); 
//		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model)); 
//		B_LeftLeg.Draw(lightingShader);
//		Back Right Leg
//		model = modelTemp; 
//		model = glm::translate(model, glm::vec3(-0.083f, -0.057f, -0.231f));
//		model = glm::rotate(model, glm::radians(RLegs), glm::vec3(-1.0f, 0.0f, 0.0f));
//		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//		B_RightLeg.Draw(lightingShader); 
//
//
//		model = glm::mat4(1);
//		glEnable(GL_BLEND);//Avtiva la funcionalidad para trabajar el canal alfa
//		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//		glUniform1i(glGetUniformLocation(lightingShader.Program, "transparency"), 1);
//		model = glm::rotate(model, glm::radians(rotBall), glm::vec3(0.0f, 1.0f, 0.0f));
//		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//	    Ball.Draw(lightingShader); 
//		glDisable(GL_BLEND);  //Desactiva el canal alfa 
//		glBindVertexArray(0);
//	
//
//		 Also draw the lamp object, again binding the appropriate shader
//		lampShader.Use();
//		 Get location objects for the matrices on the lamp shader (these could be different on a different shader)
//		modelLoc = glGetUniformLocation(lampShader.Program, "model");
//		viewLoc = glGetUniformLocation(lampShader.Program, "view");
//		projLoc = glGetUniformLocation(lampShader.Program, "projection");
//
//		 Set matrices
//		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
//		model = glm::mat4(1);
//		model = glm::translate(model, lightPos);
//		model = glm::scale(model, glm::vec3(0.2f)); // Make it a smaller cube
//		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//		 Draw the light object (using light's vertex attributes)
//		
//			model = glm::mat4(1);
//			model = glm::translate(model, pointLightPositions[0]);
//			model = glm::scale(model, glm::vec3(0.2f)); // Make it a smaller cube
//			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//			glBindVertexArray(VAO);
//			glDrawArrays(GL_TRIANGLES, 0, 36);
//		
//		glBindVertexArray(0);
//
//
//
//		 Swap the screen buffers
//		glfwSwapBuffers(window);
//	}
//
//
//	 Terminate GLFW, clearing any resources allocated by GLFW.
//	glfwTerminate();
//
//
//
//	return 0;
//}
//
// Moves/alters the camera positions based on user input
//void DoMovement()
//{
//
//	 Camera controls
//	if (keys[GLFW_KEY_W] || keys[GLFW_KEY_UP])
//	{
//		camera.ProcessKeyboard(FORWARD, deltaTime);
//
//	}
//
//	if (keys[GLFW_KEY_S] || keys[GLFW_KEY_DOWN])
//	{
//		camera.ProcessKeyboard(BACKWARD, deltaTime);
//
//
//	}
//
//	if (keys[GLFW_KEY_A] || keys[GLFW_KEY_LEFT])
//	{
//		camera.ProcessKeyboard(LEFT, deltaTime);
//
//
//	}
//
//	if (keys[GLFW_KEY_D] || keys[GLFW_KEY_RIGHT])
//	{
//		camera.ProcessKeyboard(RIGHT, deltaTime);
//
//
//	}
//
//	if (keys[GLFW_KEY_T])
//	{
//		pointLightPositions[0].x += 0.01f;
//	}
//	if (keys[GLFW_KEY_G])
//	{
//		pointLightPositions[0].x -= 0.01f;
//	}
//
//	if (keys[GLFW_KEY_Y])
//	{
//		pointLightPositions[0].y += 0.01f;
//	}
//
//	if (keys[GLFW_KEY_H])
//	{
//		pointLightPositions[0].y -= 0.01f;
//	}
//	if (keys[GLFW_KEY_U])
//	{
//		pointLightPositions[0].z -= 0.1f;
//	}
//	if (keys[GLFW_KEY_J])
//	{
//		pointLightPositions[0].z += 0.01f;
//	}
//	
//}
//
// Is called whenever a key is pressed/released via GLFW
//void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mode)
//{
//	if (GLFW_KEY_ESCAPE == key && GLFW_PRESS == action)
//	{
//		glfwSetWindowShouldClose(window, GL_TRUE);
//	}
//
//	if (key >= 0 && key < 1024)
//	{
//		if (action == GLFW_PRESS)
//		{
//			keys[key] = true;
//		}
//		else if (action == GLFW_RELEASE)
//		{
//			keys[key] = false;
//		}
//	}
//
//	if (keys[GLFW_KEY_SPACE])
//	{
//		active = !active;
//		if (active)
//		{
//			Light1 = glm::vec3(0.2f, 0.8f, 1.0f);
//			
//		}
//		else
//		{
//			Light1 = glm::vec3(0);//Cuado es solo un valor en los 3 vectores pueden dejar solo una componente
//		}
//	}
//	if (keys[GLFW_KEY_N])
//	{
//		AnimBall = !AnimBall;
//		
//	}
//	if (keys[GLFW_KEY_B])
//	{
//		dogAnim = 1;
//
//	}
//	
//}
//void Animation() {
//	if (AnimBall)
//	{
//		rotBall += 0.4f;
//		printf("/n%f", rotBall);
//	}
//	
//	if (AnimDog)
//	{
//		rotDog -= 0.6f;
//		printf("%f", rotBall);
//	}
//	if (dogAnim == 1) { //Walk Animation
//		if (!step) { // State 1 - step false 
//			RLegs += 0.3f;
//			FLegs += 0.3f;
//			head += 0.3f;
//			tail += 0.3f;
//			if (RLegs > 15.0f) // Condition 
//				step = true;
//
//		}
//		else
//		{
//			RLegs -= 0.3f; // Las variables tienen que ser negativas.
//			FLegs -= 0.3f;
//			head -= 0.3f;
//			tail -= 0.3f;
//			if (RLegs < -15.0f) // Condition 
//				step = false;
//		}
//
//
//		dogPos.z += 0.00005;
//		printf("/n%f", RLegs);
//
//	}
//	
//}
//
//void MouseCallback(GLFWwindow *window, double xPos, double yPos)
//{
//	if (firstMouse)
//	{
//		lastX = xPos;
//		lastY = yPos;
//		firstMouse = false;
//	}
//
//	GLfloat xOffset = xPos - lastX;
//	GLfloat yOffset = lastY - yPos;  // Reversed since y-coordinates go from bottom to left
//
//	lastX = xPos;
//	lastY = yPos;
//
//	camera.ProcessMouseMovement(xOffset, yOffset);
//}
// 
//
// 
// Practica 11: Animaciones Maquina de estados 
// Laboratorio de computacion grafica
// GPO: 07 
// Dayana Plata Alvarez 
// No. cuenta: 318300764 
// Fecha de entrega: 11/2/2025 
//#include <iostream>
//#include <cmath>
//
//// GLEW
//#include <GL/glew.h>
//
//// GLFW
//#include <GLFW/glfw3.h>
//
//// Other Libs
//#include "stb_image.h"
//
//// GLM Mathematics
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
////Load Models
//#include "SOIL2/SOIL2.h"
//
//// Other includes
//#include "Shader.h"
//#include "Camera.h"
//#include "Model.h"
//
//// Function prototypes
//void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
//void MouseCallback(GLFWwindow* window, double xPos, double yPos);
//void DoMovement();
//void Animation();
//
//// Window dimensions
//const GLuint WIDTH = 800, HEIGHT = 600;
//int SCREEN_WIDTH, SCREEN_HEIGHT;
//
//// Camera
//Camera  camera(glm::vec3(0.0f, 0.0f, 3.0f));
//GLfloat lastX = WIDTH / 2.0f;  // 2.0f para evitar C4244
//GLfloat lastY = HEIGHT / 2.0f; // 2.0f para evitar C4244
//bool keys[1024];
//bool firstMouse = true;
//// Light attributes
//glm::vec3 lightPos(0.0f, 0.0f, 0.0f);
//bool active;
//
//// Positions of the point lights
//glm::vec3 pointLightPositions[] = {
//    glm::vec3(0.0f,2.0f, 0.0f),
//    glm::vec3(0.0f,0.0f, 0.0f),
//    glm::vec3(0.0f,0.0f,  0.0f),
//    glm::vec3(0.0f,0.0f, 0.0f)
//};
//
//float vertices[] = {
//       -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//        0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//        0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//        0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//       -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//       -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//
//       -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//        0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//        0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//        0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//       -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//       -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//
//       -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//
//        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//        0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//        0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//        0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//
//       -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//        0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//        0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//        0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//       -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//       -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//
//       -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//        0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//        0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//        0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//       -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//       -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
//};
//
//glm::vec3 Light1 = glm::vec3(0);
////Anim
//float rotBall = 0.0f;
//bool AnimBall = false;
//bool AnimDog = false;
//float rotDog = 0.0f;
//int dogAnim = 0;
//float FLegs = 0.0f;
//float RLegs = 0.0f;
//float head = 0.0f;
//float tail = 0.0f;
//glm::vec3 dogPos(0.0f, 0.0f, 0.0f);
//float dogRot = 0.0f;
//bool step = false;
//
//// ------------------- AÑADIDO: límites del piso y máquina de estados -------------------
//// --- BORDES DEL PISO (ajústalos a tu modelo "Piso") ---
//const float FLOOR_MIN_X = -2.0f;
//const float FLOOR_MAX_X = 2.0f;
//const float FLOOR_MIN_Z = -2.0f;
//const float FLOOR_MAX_Z = 2.0f;
//const float SAFE_MARGIN = 0.15f; // qué tan "cerca" del borde quieres que se detenga
//
//// Velocidades (unidades/seg y grados/seg)
//const float DOG_WALK_SPEED = 0.6f;   // desplazamiento lineal
//const float DOG_TURN_SPEED = 90.0f; // grados/seg
//
//// Máquina de estados del perro
//enum DogState { IDLE = 0, WALK_FWD, TURN_RIGHT_1, WALK_RIGHT, TURN_RIGHT_2 };
//DogState dogState = IDLE;
//float dogTargetRot = 0.0f; // destino del giro en grados
//// --------------------------------------------------------------------------------------
//
//// Deltatime
//GLfloat deltaTime = 0.0f;  // Time between current frame and last frame
//GLfloat lastFrame = 0.0f;  // Time of last frame
//
//int main()
//{
//    // Init GLFW
//    glfwInit();
//
//    // Create a GLFWwindow object
//    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Animacion maquina de estados", nullptr, nullptr);
//    if (nullptr == window)
//    {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return EXIT_FAILURE;
//    }
//
//    glfwMakeContextCurrent(window);
//    glfwGetFramebufferSize(window, &SCREEN_WIDTH, &SCREEN_HEIGHT);
//
//    // Callbacks
//    glfwSetKeyCallback(window, KeyCallback);
//    glfwSetCursorPosCallback(window, MouseCallback);
//
//    // GLEW
//    glewExperimental = GL_TRUE;
//    if (GLEW_OK != glewInit())
//    {
//        std::cout << "Failed to initialize GLEW" << std::endl;
//        return EXIT_FAILURE;
//    }
//
//    // Viewport
//    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
//
//    Shader lightingShader("Shader/lighting.vs", "Shader/lighting.frag");
//    Shader lampShader("Shader/lamp.vs", "Shader/lamp.frag");
//
//    // Models
//    Model DogBody((char*)"Models/DogBody.obj");
//    Model HeadDog((char*)"Models/HeadDog.obj");
//    Model DogTail((char*)"Models/TailDog.obj");
//    Model F_RightLeg((char*)"Models/F_RightLegDog.obj");
//    Model F_LeftLeg((char*)"Models/F_LeftLegDog.obj");
//    Model B_RightLeg((char*)"Models/B_RightLegDog.obj");
//    Model B_LeftLeg((char*)"Models/B_LeftLegDog.obj");
//    Model Piso((char*)"Models/piso.obj");
//    Model Ball((char*)"Models/ball.obj");
//
//    // VAO/VBO
//    GLuint VBO, VAO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//    glBindVertexArray(VAO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//    // Position
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
//    glEnableVertexAttribArray(0);
//    // Normal
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//
//    // Set texture units
//    lightingShader.Use();
//    glUniform1i(glGetUniformLocation(lightingShader.Program, "Material.difuse"), 0);
//    glUniform1i(glGetUniformLocation(lightingShader.Program, "Material.specular"), 1);
//
//    glm::mat4 projection = glm::perspective(camera.GetZoom(),
//        (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT,
//        0.1f, 100.0f);
//
//    // Game loop
//    while (!glfwWindowShouldClose(window))
//    {
//        // Delta time (cast a float para evitar warnings C4244)
//        GLfloat currentFrame = static_cast<float>(glfwGetTime());
//        deltaTime = currentFrame - lastFrame;
//        lastFrame = currentFrame;
//
//        // Input y animación
//        glfwPollEvents();
//        DoMovement();
//        Animation();
//
//        // Clear
//        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        glEnable(GL_DEPTH_TEST);
//
//        // ==== DIBUJO ====
//        glm::mat4 model;
//        glm::mat4 view = camera.GetViewMatrix();
//        glm::mat4 modelTemp = glm::mat4(1.0f); // <<-- UNA sola declaración por frame
//
//        lightingShader.Use();
//
//        glUniform1i(glGetUniformLocation(lightingShader.Program, "diffuse"), 0);
//
//        GLint viewPosLoc = glGetUniformLocation(lightingShader.Program, "viewPos");
//        glUniform3f(viewPosLoc, camera.GetPosition().x, camera.GetPosition().y, camera.GetPosition().z);
//
//        // Directional light
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.direction"), -0.2f, -1.0f, -0.3f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.ambient"), 0.6f, 0.6f, 0.6f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.diffuse"), 0.6f, 0.6f, 0.6f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.specular"), 0.3f, 0.3f, 0.3f);
//
//        // Point light 1
//        glm::vec3 lightColor;
//        lightColor.x = fabsf(sinf(glfwGetTime() * Light1.x));
//        lightColor.y = fabsf(sinf(glfwGetTime() * Light1.y));
//        lightColor.z = sinf(glfwGetTime() * Light1.z);
//
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].position"),
//            pointLightPositions[0].x, pointLightPositions[0].y, pointLightPositions[0].z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].ambient"),
//            lightColor.x, lightColor.y, lightColor.z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].diffuse"),
//            lightColor.x, lightColor.y, lightColor.z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].specular"),
//            1.0f, 0.2f, 0.2f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[0].constant"), 1.0f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[0].linear"), 0.045f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[0].quadratic"), 0.075f);
//
//        // SpotLight
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.position"),
//            camera.GetPosition().x, camera.GetPosition().y, camera.GetPosition().z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.direction"),
//            camera.GetFront().x, camera.GetFront().y, camera.GetFront().z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.ambient"), 0.2f, 0.2f, 0.8f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.diffuse"), 0.2f, 0.2f, 0.8f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.specular"), 0.0f, 0.0f, 0.0f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.constant"), 1.0f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.linear"), 0.3f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.quadratic"), 0.7f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.cutOff"), glm::cos(glm::radians(12.0f)));
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.outerCutOff"), glm::cos(glm::radians(18.0f)));
//
//        // Material
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "material.shininess"), 5.0f);
//
//        // Uniforms de matrices
//        GLint modelLoc = glGetUniformLocation(lightingShader.Program, "model");
//        GLint viewLoc = glGetUniformLocation(lightingShader.Program, "view");
//        GLint projLoc = glGetUniformLocation(lightingShader.Program, "projection");
//        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
//
//        // --- Piso ---
//        model = glm::mat4(1.0f);
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        Piso.Draw(lightingShader);
//
//        // --- Perro ---
//        model = glm::mat4(1.0f);
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        glUniform1i(glGetUniformLocation(lightingShader.Program, "transparency"), 0);
//
//        // Body
//        model = glm::translate(model, dogPos);
//        model = glm::rotate(model, glm::radians(dogRot), glm::vec3(0.0f, 1.0f, 0.0f));
//        modelTemp = model; // usar como base para sub-partes
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        DogBody.Draw(lightingShader);
//
//        // Head
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(0.0f, 0.093f, 0.208f));
//        model = glm::rotate(model, glm::radians(head), glm::vec3(0.0f, 0.0f, 1.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        HeadDog.Draw(lightingShader);
//
//        // Tail 
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(0.0f, 0.026f, -0.288f));
//        model = glm::rotate(model, glm::radians(tail), glm::vec3(0.0f, 0.0f, -1.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        DogTail.Draw(lightingShader);
//
//        // Front Left Leg
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(0.112f, -0.044f, 0.074f));
//        model = glm::rotate(model, glm::radians(FLegs), glm::vec3(-1.0f, 0.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        F_LeftLeg.Draw(lightingShader);
//
//        // Front Right Leg
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(-0.111f, -0.055f, 0.074f));
//        model = glm::rotate(model, glm::radians(FLegs), glm::vec3(1.0f, 0.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        F_RightLeg.Draw(lightingShader);
//
//        // Back Left Leg
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(0.082f, -0.046f, -0.218f));
//        model = glm::rotate(model, glm::radians(RLegs), glm::vec3(1.0f, 0.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        B_LeftLeg.Draw(lightingShader);
//
//        // Back Right Leg
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(-0.083f, -0.057f, -0.231f));
//        model = glm::rotate(model, glm::radians(RLegs), glm::vec3(-1.0f, 0.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        B_RightLeg.Draw(lightingShader);
//
//        // --- Pelota ---
//        model = glm::mat4(1.0f);
//        glEnable(GL_BLEND);
//        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        glUniform1i(glGetUniformLocation(lightingShader.Program, "transparency"), 1);
//        model = glm::rotate(model, glm::radians(rotBall), glm::vec3(0.0f, 1.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        Ball.Draw(lightingShader);
//        glDisable(GL_BLEND);
//        glBindVertexArray(0);
//
//        // --- Lámpara ---
//        lampShader.Use();
//        modelLoc = glGetUniformLocation(lampShader.Program, "model");
//        GLint viewLoc2 = glGetUniformLocation(lampShader.Program, "view");
//        GLint projLoc2 = glGetUniformLocation(lampShader.Program, "projection");
//        glUniformMatrix4fv(viewLoc2, 1, GL_FALSE, glm::value_ptr(view));
//        glUniformMatrix4fv(projLoc2, 1, GL_FALSE, glm::value_ptr(projection));
//
//        model = glm::mat4(1.0f);
//        model = glm::translate(model, lightPos);
//        model = glm::scale(model, glm::vec3(0.2f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//
//        model = glm::mat4(1.0f);
//        model = glm::translate(model, pointLightPositions[0]);
//        model = glm::scale(model, glm::vec3(0.2f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        glBindVertexArray(VAO);
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//        glBindVertexArray(0);
//
//        // Swap
//        glfwSwapBuffers(window);
//    }
//
//    glfwTerminate();
//    return 0;
//}
//
//// Moves/alters the camera positions based on user input
//void DoMovement()
//{
//    if (keys[GLFW_KEY_W] || keys[GLFW_KEY_UP])    camera.ProcessKeyboard(FORWARD, deltaTime);
//    if (keys[GLFW_KEY_S] || keys[GLFW_KEY_DOWN])  camera.ProcessKeyboard(BACKWARD, deltaTime);
//    if (keys[GLFW_KEY_A] || keys[GLFW_KEY_LEFT])  camera.ProcessKeyboard(LEFT, deltaTime);
//    if (keys[GLFW_KEY_D] || keys[GLFW_KEY_RIGHT]) camera.ProcessKeyboard(RIGHT, deltaTime);
//
//    if (keys[GLFW_KEY_T]) { pointLightPositions[0].x += 0.01f; }
//    if (keys[GLFW_KEY_G]) { pointLightPositions[0].x -= 0.01f; }
//    if (keys[GLFW_KEY_Y]) { pointLightPositions[0].y += 0.01f; }
//    if (keys[GLFW_KEY_H]) { pointLightPositions[0].y -= 0.01f; }
//    if (keys[GLFW_KEY_U]) { pointLightPositions[0].z -= 0.1f; }
//    if (keys[GLFW_KEY_J]) { pointLightPositions[0].z += 0.01f; }
//}
//
//// Is called whenever a key is pressed/released via GLFW
//void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//    if (GLFW_KEY_ESCAPE == key && GLFW_PRESS == action) {
//        glfwSetWindowShouldClose(window, GL_TRUE);
//    }
//
//    if (key >= 0 && key < 1024) {
//        if (action == GLFW_PRESS)      keys[key] = true;
//        else if (action == GLFW_RELEASE) keys[key] = false;
//    }
//
//    if (keys[GLFW_KEY_SPACE]) {
//        active = !active;
//        Light1 = active ? glm::vec3(0.2f, 0.8f, 1.0f) : glm::vec3(0.0f);
//    }
//    if (keys[GLFW_KEY_N]) {
//        AnimBall = !AnimBall;
//    }
//    if (keys[GLFW_KEY_B]) {
//        dogAnim = 1;
//        dogState = WALK_FWD;   // comienza caminando hacia +Z
//    }
//}
//
//void Animation() {
//    // Bola
//    if (AnimBall) {
//        rotBall += 0.4f;
//    }
//
//    // Rotación libre del perro (si la usas)
//    if (AnimDog) {
//        rotDog -= 0.6f;
//    }
//
//    // Animación cíclica de patas / cabeza / cola
//    if (dogAnim == 1) {
//        if (!step) {
//            RLegs += 0.3f;
//            FLegs += 0.3f;
//            head += 0.3f;
//            tail += 0.3f;
//            if (RLegs > 15.0f) step = true;
//        }
//        else {
//            RLegs -= 0.3f;
//            FLegs -= 0.3f;
//            head -= 0.3f;
//            tail -= 0.3f;
//            if (RLegs < -15.0f) step = false;
//        }
//    }
//
//    // Movimiento con límites y giros
//    float moveStep = DOG_WALK_SPEED * deltaTime; // unidades/s
//    float turnStep = DOG_TURN_SPEED * deltaTime; // grados/s
//
//    switch (dogState) {
//    case IDLE:
//        break;
//
//    case WALK_FWD:
//        dogPos.z += moveStep; // hacia +Z
//        if (dogPos.z >= (FLOOR_MAX_Z - SAFE_MARGIN)) {
//            dogPos.z = (FLOOR_MAX_Z - SAFE_MARGIN);
//            dogState = TURN_RIGHT_1;
//            dogTargetRot = dogRot + 90.0f; // giro horario
//        }
//        break;
//
//    case TURN_RIGHT_1:
//        if (dogRot < dogTargetRot) {
//            dogRot += turnStep;
//            if (dogRot > dogTargetRot) dogRot = dogTargetRot;
//        }
//        if (dogRot == dogTargetRot) {
//            dogState = WALK_RIGHT; // caminar a +X
//        }
//        break;
//
//    case WALK_RIGHT:
//        dogPos.x += moveStep; // hacia +X
//        if (dogPos.x >= (FLOOR_MAX_X - SAFE_MARGIN)) {
//            dogPos.x = (FLOOR_MAX_X - SAFE_MARGIN);
//            dogState = TURN_RIGHT_2;
//            dogTargetRot = dogRot + 90.0f; // otro giro horario
//        }
//        break;
//
//    case TURN_RIGHT_2:
//        if (dogRot < dogTargetRot) {
//            dogRot += turnStep;
//            if (dogRot > dogTargetRot) dogRot = dogTargetRot;
//        }
//        if (dogRot == dogTargetRot) {
//            dogState = IDLE; // queda quieto
//        }
//        break;
//    }
//
//    // Clamp suave: no salir del piso
//    if (dogPos.x < FLOOR_MIN_X + SAFE_MARGIN) dogPos.x = FLOOR_MIN_X + SAFE_MARGIN;
//    if (dogPos.x > FLOOR_MAX_X - SAFE_MARGIN) dogPos.x = FLOOR_MAX_X - SAFE_MARGIN;
//    if (dogPos.z < FLOOR_MIN_Z + SAFE_MARGIN) dogPos.z = FLOOR_MIN_Z + SAFE_MARGIN;
//    if (dogPos.z > FLOOR_MAX_Z - SAFE_MARGIN) dogPos.z = FLOOR_MAX_Z - SAFE_MARGIN;
//
//    // Normaliza el ángulo
//    if (dogRot >= 360.0f) dogRot -= 360.0f;
//    if (dogRot < 0.0f)  dogRot += 360.0f;
//}
//
//void MouseCallback(GLFWwindow* window, double xPos, double yPos)
//{
//    if (firstMouse)
//    {
//        lastX = static_cast<float>(xPos);
//        lastY = static_cast<float>(yPos);
//        firstMouse = false;
//    }
//
//    GLfloat xOffset = static_cast<float>(xPos) - lastX;
//    GLfloat yOffset = lastY - static_cast<float>(yPos);
//
//    lastX = static_cast<float>(xPos);
//    lastY = static_cast<float>(yPos);
//
//    camera.ProcessMouseMovement(xOffset, yOffset);
//}
//
// 
// Practica 11: Animaciones Maquina de estados 
// Laboratorio de computacion grafica
// GPO: 07 
// Dayana Plata Alvarez 
// No. cuenta: 318300764 
// Fecha de entrega: 11/2/2025 
//#include <iostream>
//#include <cmath>
//
//// GLEW
//#include <GL/glew.h>
//
//// GLFW
//#include <GLFW/glfw3.h>
//
//// Other Libs
//#include "stb_image.h"
//
//// GLM Mathematics
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
////Load Models
//#include "SOIL2/SOIL2.h"
//
//// Other includes
//#include "Shader.h"
//#include "Camera.h"
//#include "Model.h"
//
//// Function prototypes
//void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
//void MouseCallback(GLFWwindow* window, double xPos, double yPos);
//void DoMovement();
//void Animation();
//
//// Window dimensions
//const GLuint WIDTH = 800, HEIGHT = 600;
//int SCREEN_WIDTH, SCREEN_HEIGHT;
//
//// Camera
//Camera  camera(glm::vec3(0.0f, 0.0f, 3.0f));
//GLfloat lastX = WIDTH / 2.0f;
//GLfloat lastY = HEIGHT / 2.0f;
//bool keys[1024];
//bool firstMouse = true;
//// Light attributes
//glm::vec3 lightPos(0.0f, 0.0f, 0.0f);
//bool active;
//
//// Positions of the point lights
//glm::vec3 pointLightPositions[] = {
//    glm::vec3(0.0f,2.0f, 0.0f),
//    glm::vec3(0.0f,0.0f, 0.0f),
//    glm::vec3(0.0f,0.0f,  0.0f),
//    glm::vec3(0.0f,0.0f, 0.0f)
//};
//
//float vertices[] = {
//       -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//        0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//        0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//        0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//       -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//       -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//
//       -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//        0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//        0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//        0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//       -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//       -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//
//       -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//
//        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//        0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//        0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//        0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//
//       -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//        0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//        0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//        0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//       -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//       -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//
//       -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//        0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//        0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//        0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//       -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//       -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
//};
//
//glm::vec3 Light1 = glm::vec3(0);
////Anim
//float rotBall = 0.0f;
//bool AnimBall = false;
//bool AnimDog = false;
//float rotDog = 0.0f;
//int dogAnim = 0;
//float FLegs = 0.0f;
//float RLegs = 0.0f;
//float head = 0.0f;
//float tail = 0.0f;
//glm::vec3 dogPos(0.0f, 0.0f, 0.0f);
//float dogRot = 0.0f;
//bool step = false;
//
//// ------------------- Límites del piso y máquina de estados -------------------
//const float FLOOR_MIN_X = -2.0f;
//const float FLOOR_MAX_X = 2.0f;
//const float FLOOR_MIN_Z = -2.0f;
//const float FLOOR_MAX_Z = 2.0f;
//const float SAFE_MARGIN = 0.15f;
//
//// Velocidades
//const float DOG_WALK_SPEED = 0.6f;   // unidades/seg
//const float DOG_TURN_SPEED = 90.0f;  // grados/seg
//
//// Máquina de estados del perro (extendida)
//enum DogState {
//    IDLE = 0,
//    WALK_FWD,        // +Z
//    TURN_RIGHT_1,    // +90° horario
//    WALK_RIGHT,      // +X
//    TURN_RIGHT_2,    // +90° horario
//    WALK_BACK,       // -Z
//    TURN_LEFT_CCW    // -90° antihorario
//};
//DogState dogState = IDLE;
//float dogTargetRot = 0.0f; // destino del giro en grados
//// -----------------------------------------------------------------------------
//
//
//// Deltatime
//GLfloat deltaTime = 0.0f;
//GLfloat lastFrame = 0.0f;
//
//int main()
//{
//    // Init GLFW
//    glfwInit();
//
//    // Window
//    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Animacion maquina de estados", nullptr, nullptr);
//    if (nullptr == window) {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return EXIT_FAILURE;
//    }
//    glfwMakeContextCurrent(window);
//    glfwGetFramebufferSize(window, &SCREEN_WIDTH, &SCREEN_HEIGHT);
//
//    // Callbacks
//    glfwSetKeyCallback(window, KeyCallback);
//    glfwSetCursorPosCallback(window, MouseCallback);
//
//    // GLEW
//    glewExperimental = GL_TRUE;
//    if (GLEW_OK != glewInit()) {
//        std::cout << "Failed to initialize GLEW" << std::endl;
//        return EXIT_FAILURE;
//    }
//
//    // Viewport
//    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
//
//    Shader lightingShader("Shader/lighting.vs", "Shader/lighting.frag");
//    Shader lampShader("Shader/lamp.vs", "Shader/lamp.frag");
//
//    // Models
//    Model DogBody((char*)"Models/DogBody.obj");
//    Model HeadDog((char*)"Models/HeadDog.obj");
//    Model DogTail((char*)"Models/TailDog.obj");
//    Model F_RightLeg((char*)"Models/F_RightLegDog.obj");
//    Model F_LeftLeg((char*)"Models/F_LeftLegDog.obj");
//    Model B_RightLeg((char*)"Models/B_RightLegDog.obj");
//    Model B_LeftLeg((char*)"Models/B_LeftLegDog.obj");
//    Model Piso((char*)"Models/piso.obj");
//    Model Ball((char*)"Models/ball.obj");
//
//    // VAO/VBO
//    GLuint VBO, VAO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//    glBindVertexArray(VAO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//    // Position
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
//    glEnableVertexAttribArray(0);
//    // Normal
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//
//    // Material samplers
//    lightingShader.Use();
//    glUniform1i(glGetUniformLocation(lightingShader.Program, "Material.difuse"), 0);
//    glUniform1i(glGetUniformLocation(lightingShader.Program, "Material.specular"), 1);
//
//    glm::mat4 projection = glm::perspective(
//        camera.GetZoom(),
//        (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT,
//        0.1f, 100.0f
//    );
//
//    // Game loop
//    while (!glfwWindowShouldClose(window))
//    {
//        // Delta time
//        GLfloat currentFrame = static_cast<float>(glfwGetTime());
//        deltaTime = currentFrame - lastFrame;
//        lastFrame = currentFrame;
//
//        // Input + anim
//        glfwPollEvents();
//        DoMovement();
//        Animation();
//
//        // Clear
//        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        glEnable(GL_DEPTH_TEST);
//
//        // ==== DRAW ====
//        glm::mat4 model;
//        glm::mat4 view = camera.GetViewMatrix();
//        glm::mat4 modelTemp = glm::mat4(1.0f); // una sola vez por frame
//
//        lightingShader.Use();
//
//        glUniform1i(glGetUniformLocation(lightingShader.Program, "diffuse"), 0);
//
//        GLint viewPosLoc = glGetUniformLocation(lightingShader.Program, "viewPos");
//        glUniform3f(viewPosLoc, camera.GetPosition().x, camera.GetPosition().y, camera.GetPosition().z);
//
//        // Dir light
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.direction"), -0.2f, -1.0f, -0.3f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.ambient"), 0.6f, 0.6f, 0.6f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.diffuse"), 0.6f, 0.6f, 0.6f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.specular"), 0.3f, 0.3f, 0.3f);
//
//        // Point light anim
//        glm::vec3 lightColor;
//        lightColor.x = fabsf(sinf(glfwGetTime() * Light1.x));
//        lightColor.y = fabsf(sinf(glfwGetTime() * Light1.y));
//        lightColor.z = sinf(glfwGetTime() * Light1.z);
//
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].position"),
//            pointLightPositions[0].x, pointLightPositions[0].y, pointLightPositions[0].z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].ambient"),
//            lightColor.x, lightColor.y, lightColor.z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].diffuse"),
//            lightColor.x, lightColor.y, lightColor.z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].specular"),
//            1.0f, 0.2f, 0.2f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[0].constant"), 1.0f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[0].linear"), 0.045f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[0].quadratic"), 0.075f);
//
//        // Spotlight (cámara)
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.position"),
//            camera.GetPosition().x, camera.GetPosition().y, camera.GetPosition().z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.direction"),
//            camera.GetFront().x, camera.GetFront().y, camera.GetFront().z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.ambient"), 0.2f, 0.2f, 0.8f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.diffuse"), 0.2f, 0.2f, 0.8f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.specular"), 0.0f, 0.0f, 0.0f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.constant"), 1.0f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.linear"), 0.3f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.quadratic"), 0.7f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.cutOff"), glm::cos(glm::radians(12.0f)));
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.outerCutOff"), glm::cos(glm::radians(18.0f)));
//
//        // Material
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "material.shininess"), 5.0f);
//
//        // Matrices
//        GLint modelLoc = glGetUniformLocation(lightingShader.Program, "model");
//        GLint viewLoc = glGetUniformLocation(lightingShader.Program, "view");
//        GLint projLoc = glGetUniformLocation(lightingShader.Program, "projection");
//        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
//
//        // --- Piso ---
//        model = glm::mat4(1.0f);
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        Piso.Draw(lightingShader);
//
//        // --- Perro ---
//        model = glm::mat4(1.0f);
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        glUniform1i(glGetUniformLocation(lightingShader.Program, "transparency"), 0);
//
//        // Body
//        model = glm::translate(model, dogPos);
//        model = glm::rotate(model, glm::radians(dogRot), glm::vec3(0.0f, 1.0f, 0.0f));
//        modelTemp = model; // base
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        DogBody.Draw(lightingShader);
//
//        // Head
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(0.0f, 0.093f, 0.208f));
//        model = glm::rotate(model, glm::radians(head), glm::vec3(0.0f, 0.0f, 1.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        HeadDog.Draw(lightingShader);
//
//        // Tail 
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(0.0f, 0.026f, -0.288f));
//        model = glm::rotate(model, glm::radians(tail), glm::vec3(0.0f, 0.0f, -1.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        DogTail.Draw(lightingShader);
//
//        // Front Left Leg
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(0.112f, -0.044f, 0.074f));
//        model = glm::rotate(model, glm::radians(FLegs), glm::vec3(-1.0f, 0.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        F_LeftLeg.Draw(lightingShader);
//
//        // Front Right Leg
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(-0.111f, -0.055f, 0.074f));
//        model = glm::rotate(model, glm::radians(FLegs), glm::vec3(1.0f, 0.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        F_RightLeg.Draw(lightingShader);
//
//        // Back Left Leg
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(0.082f, -0.046f, -0.218f));
//        model = glm::rotate(model, glm::radians(RLegs), glm::vec3(1.0f, 0.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        B_LeftLeg.Draw(lightingShader);
//
//        // Back Right Leg
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(-0.083f, -0.057f, -0.231f));
//        model = glm::rotate(model, glm::radians(RLegs), glm::vec3(-1.0f, 0.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        B_RightLeg.Draw(lightingShader);
//
//        // --- Pelota ---
//        model = glm::mat4(1.0f);
//        glEnable(GL_BLEND);
//        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        glUniform1i(glGetUniformLocation(lightingShader.Program, "transparency"), 1);
//        model = glm::rotate(model, glm::radians(rotBall), glm::vec3(0.0f, 1.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        Ball.Draw(lightingShader);
//        glDisable(GL_BLEND);
//        glBindVertexArray(0);
//
//        // --- Lámpara ---
//        lampShader.Use();
//        modelLoc = glGetUniformLocation(lampShader.Program, "model");
//        GLint viewLoc2 = glGetUniformLocation(lampShader.Program, "view");
//        GLint projLoc2 = glGetUniformLocation(lampShader.Program, "projection");
//        glUniformMatrix4fv(viewLoc2, 1, GL_FALSE, glm::value_ptr(view));
//        glUniformMatrix4fv(projLoc2, 1, GL_FALSE, glm::value_ptr(projection));
//
//        model = glm::mat4(1.0f);
//        model = glm::translate(model, lightPos);
//        model = glm::scale(model, glm::vec3(0.2f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//
//        model = glm::mat4(1.0f);
//        model = glm::translate(model, pointLightPositions[0]);
//        model = glm::scale(model, glm::vec3(0.2f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        glBindVertexArray(VAO);
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//        glBindVertexArray(0);
//
//        // Swap
//        glfwSwapBuffers(window);
//    }
//
//    glfwTerminate();
//    return 0;
//}
//
//// Moves/alters the camera positions based on user input
//void DoMovement()
//{
//    if (keys[GLFW_KEY_W] || keys[GLFW_KEY_UP])    camera.ProcessKeyboard(FORWARD, deltaTime);
//    if (keys[GLFW_KEY_S] || keys[GLFW_KEY_DOWN])  camera.ProcessKeyboard(BACKWARD, deltaTime);
//    if (keys[GLFW_KEY_A] || keys[GLFW_KEY_LEFT])  camera.ProcessKeyboard(LEFT, deltaTime);
//    if (keys[GLFW_KEY_D] || keys[GLFW_KEY_RIGHT]) camera.ProcessKeyboard(RIGHT, deltaTime);
//
//    if (keys[GLFW_KEY_T]) { pointLightPositions[0].x += 0.01f; }
//    if (keys[GLFW_KEY_G]) { pointLightPositions[0].x -= 0.01f; }
//    if (keys[GLFW_KEY_Y]) { pointLightPositions[0].y += 0.01f; }
//    if (keys[GLFW_KEY_H]) { pointLightPositions[0].y -= 0.01f; }
//    if (keys[GLFW_KEY_U]) { pointLightPositions[0].z -= 0.1f; }
//    if (keys[GLFW_KEY_J]) { pointLightPositions[0].z += 0.01f; }
//}
//
//// Is called whenever a key is pressed/released via GLFW
//void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//    if (GLFW_KEY_ESCAPE == key && GLFW_PRESS == action) {
//        glfwSetWindowShouldClose(window, GL_TRUE);
//    }
//
//    if (key >= 0 && key < 1024) {
//        if (action == GLFW_PRESS)      keys[key] = true;
//        else if (action == GLFW_RELEASE) keys[key] = false;
//    }
//
//    if (keys[GLFW_KEY_SPACE]) {
//        active = !active;
//        Light1 = active ? glm::vec3(0.2f, 0.8f, 1.0f) : glm::vec3(0.0f);
//    }
//    if (keys[GLFW_KEY_N]) {
//        AnimBall = !AnimBall;
//    }
//    if (keys[GLFW_KEY_B]) {
//        dogAnim = 1;
//        dogState = WALK_FWD;   // comienza caminando hacia +Z
//    }
//}
//
//void Animation() {
//    // Bola
//    if (AnimBall) {
//        rotBall += 0.4f;
//    }
//
//    // Rotación libre del perro (si la usas)
//    if (AnimDog) {
//        rotDog -= 0.6f;
//    }
//
//    // Animación cíclica de patas / cabeza / cola
//    if (dogAnim == 1) {
//        if (!step) {
//            RLegs += 0.3f; FLegs += 0.3f; head += 0.3f; tail += 0.3f;
//            if (RLegs > 15.0f) step = true;
//        }
//        else {
//            RLegs -= 0.3f; FLegs -= 0.3f; head -= 0.3f; tail -= 0.3f;
//            if (RLegs < -15.0f) step = false;
//        }
//    }
//
//    // Movimiento con límites y giros
//    float moveStep = DOG_WALK_SPEED * deltaTime; // unidades/s
//    float turnStep = DOG_TURN_SPEED * deltaTime; // grados/s
//
//    switch (dogState) {
//    case IDLE:
//        break;
//
//        // +Z hasta orilla frontal
//    case WALK_FWD:
//        dogPos.z += moveStep;
//        if (dogPos.z >= (FLOOR_MAX_Z - SAFE_MARGIN)) {
//            dogPos.z = (FLOOR_MAX_Z - SAFE_MARGIN);
//            dogState = TURN_RIGHT_1;
//            dogTargetRot = dogRot + 90.0f; // giro horario
//        }
//        break;
//
//        // Primer giro horario (+90)
//    case TURN_RIGHT_1:
//        if (dogRot < dogTargetRot) {
//            dogRot += turnStep;
//            if (dogRot > dogTargetRot) dogRot = dogTargetRot;
//        }
//        if (dogRot == dogTargetRot) {
//            dogState = WALK_RIGHT; // caminar a +X
//        }
//        break;
//
//        // +X hasta orilla derecha
//    case WALK_RIGHT:
//        dogPos.x += moveStep;
//        if (dogPos.x >= (FLOOR_MAX_X - SAFE_MARGIN)) {
//            dogPos.x = (FLOOR_MAX_X - SAFE_MARGIN);
//            dogState = TURN_RIGHT_2;
//            dogTargetRot = dogRot + 90.0f; // segundo giro horario
//        }
//        break;
//
//        // Segundo giro horario (+90) => queda apuntando a -Z
//    case TURN_RIGHT_2:
//        if (dogRot < dogTargetRot) {
//            dogRot += turnStep;
//            if (dogRot > dogTargetRot) dogRot = dogTargetRot;
//        }
//        if (dogRot == dogTargetRot) {
//            dogState = WALK_BACK; // seguir caminando hacia -Z
//        }
//        break;
//
//        // -Z hasta la orilla trasera
//    case WALK_BACK:
//        dogPos.z -= moveStep;
//        if (dogPos.z <= (FLOOR_MIN_Z + SAFE_MARGIN)) {
//            dogPos.z = (FLOOR_MIN_Z + SAFE_MARGIN);
//            dogState = TURN_LEFT_CCW;
//            dogTargetRot = dogRot - 90.0f; // giro ANTihorario
//        }
//        break;
//
//        // Giro antihorario (-90) en la esquina
//    case TURN_LEFT_CCW:
//        if (dogRot > dogTargetRot) {
//            dogRot -= turnStep;
//            if (dogRot < dogTargetRot) dogRot = dogTargetRot;
//        }
//        if (dogRot == dogTargetRot) {
//            dogState = IDLE; // detenerse tras el giro CCW
//            // Si quieres que siga a -X: dogState = WALK_LEFT; (y añade ese estado)
//        }
//        break;
//    }
//
//    // Clamp suave para no salir del piso
//    if (dogPos.x < FLOOR_MIN_X + SAFE_MARGIN) dogPos.x = FLOOR_MIN_X + SAFE_MARGIN;
//    if (dogPos.x > FLOOR_MAX_X - SAFE_MARGIN) dogPos.x = FLOOR_MAX_X - SAFE_MARGIN;
//    if (dogPos.z < FLOOR_MIN_Z + SAFE_MARGIN) dogPos.z = FLOOR_MIN_Z + SAFE_MARGIN;
//    if (dogPos.z > FLOOR_MAX_Z - SAFE_MARGIN) dogPos.z = FLOOR_MAX_Z - SAFE_MARGIN;
//
//    // Normaliza el ángulo
//    if (dogRot >= 360.0f) dogRot -= 360.0f;
//    if (dogRot < 0.0f)  dogRot += 360.0f;
//}
//
//void MouseCallback(GLFWwindow* window, double xPos, double yPos)
//{
//    if (firstMouse)
//    {
//        lastX = static_cast<float>(xPos);
//        lastY = static_cast<float>(yPos);
//        firstMouse = false;
//    }
//
//    GLfloat xOffset = static_cast<float>(xPos) - lastX;
//    GLfloat yOffset = lastY - static_cast<float>(yPos);
//
//    lastX = static_cast<float>(xPos);
//    lastY = static_cast<float>(yPos);
//
//    camera.ProcessMouseMovement(xOffset, yOffset);
//}

 /*Practica 11: Animaciones Maquina de estados  
 Laboratorio de computacion grafica
 GPO: 07 
 Dayana Plata Alvarez 
 No. cuenta: 318300764 
 Fecha de entrega: 11/2/2025 */
//#include <iostream>
//#include <cmath>
//
//// GLEW
//#include <GL/glew.h>
//
//// GLFW
//#include <GLFW/glfw3.h>
//
//// Other Libs
//#include "stb_image.h"
//
//// GLM Mathematics
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
////Load Models
//#include "SOIL2/SOIL2.h"
//
//// Other includes
//#include "Shader.h"
//#include "Camera.h"
//#include "Model.h"
//
//// Function prototypes
//void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
//void MouseCallback(GLFWwindow* window, double xPos, double yPos);
//void DoMovement();
//void Animation();
//
//// Window dimensions
//const GLuint WIDTH = 800, HEIGHT = 600;
//int SCREEN_WIDTH, SCREEN_HEIGHT;
//
//// Camera
//Camera  camera(glm::vec3(0.0f, 0.0f, 3.0f));
//GLfloat lastX = WIDTH / 2.0f;
//GLfloat lastY = HEIGHT / 2.0f;
//bool keys[1024];
//bool firstMouse = true;
//// Light attributes
//glm::vec3 lightPos(0.0f, 0.0f, 0.0f);
//bool active;
//
//// Positions of the point lights
//glm::vec3 pointLightPositions[] = {
//    glm::vec3(0.0f,2.0f, 0.0f),
//    glm::vec3(0.0f,0.0f, 0.0f),
//    glm::vec3(0.0f,0.0f,  0.0f),
//    glm::vec3(0.0f,0.0f, 0.0f)
//};
//
//float vertices[] = {
//       -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//        0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//        0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//        0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//       -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//       -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//
//       -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//        0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//        0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//        0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//       -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//       -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//
//       -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//
//        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//        0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//        0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//        0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//
//       -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//        0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//        0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//        0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//       -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//       -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//
//       -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//        0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//        0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//        0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//       -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//       -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
//};
//
//glm::vec3 Light1 = glm::vec3(0);
////Anim
//float rotBall = 0.0f;
//bool AnimBall = false;
//bool AnimDog = false;
//float rotDog = 0.0f;
//int dogAnim = 0;
//float FLegs = 0.0f;
//float RLegs = 0.0f;
//float head = 0.0f;
//float tail = 0.0f;
//glm::vec3 dogPos(0.0f, 0.0f, 0.0f);
//float dogRot = 0.0f;
//bool step = false;
//
//// ------------------- Límites del piso y máquina de estados -------------------
//const float FLOOR_MIN_X = -2.0f;
//const float FLOOR_MAX_X = 2.0f;
//const float FLOOR_MIN_Z = -2.0f;
//const float FLOOR_MAX_Z = 2.0f;
//const float SAFE_MARGIN = 0.15f;
//
//// Velocidades
//const float DOG_WALK_SPEED = 0.6f;   // unidades/seg
//const float DOG_TURN_SPEED = 90.0f;  // grados/seg
//
//// Máquina de estados del perro (extendida)
//enum DogState {
//    IDLE = 0,
//    WALK_FWD,        // +Z
//    TURN_RIGHT_1,    // +90° horario
//    WALK_RIGHT,      // +X
//    TURN_RIGHT_2,    // +90° horario
//    WALK_BACK,       // -Z
//    TURN_LEFT_CCW    // (modificado) último giro AHORA horario
//};
//DogState dogState = IDLE;
//float dogTargetRot = 0.0f; // destino del giro en grados
//// -----------------------------------------------------------------------------
//
//
//// Deltatime
//GLfloat deltaTime = 0.0f;
//GLfloat lastFrame = 0.0f;
//
//int main()
//{
//    // Init GLFW
//    glfwInit();
//
//    // Window
//    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Animacion maquina de estados", nullptr, nullptr);
//    if (nullptr == window) {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return EXIT_FAILURE;
//    }
//    glfwMakeContextCurrent(window);
//    glfwGetFramebufferSize(window, &SCREEN_WIDTH, &SCREEN_HEIGHT);
//
//    // Callbacks
//    glfwSetKeyCallback(window, KeyCallback);
//    glfwSetCursorPosCallback(window, MouseCallback);
//
//    // GLEW
//    glewExperimental = GL_TRUE;
//    if (GLEW_OK != glewInit()) {
//        std::cout << "Failed to initialize GLEW" << std::endl;
//        return EXIT_FAILURE;
//    }
//
//    // Viewport
//    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
//
//    Shader lightingShader("Shader/lighting.vs", "Shader/lighting.frag");
//    Shader lampShader("Shader/lamp.vs", "Shader/lamp.frag");
//
//    // Models
//    Model DogBody((char*)"Models/DogBody.obj");
//    Model HeadDog((char*)"Models/HeadDog.obj");
//    Model DogTail((char*)"Models/TailDog.obj");
//    Model F_RightLeg((char*)"Models/F_RightLegDog.obj");
//    Model F_LeftLeg((char*)"Models/F_LeftLegDog.obj");
//    Model B_RightLeg((char*)"Models/B_RightLegDog.obj");
//    Model B_LeftLeg((char*)"Models/B_LeftLegDog.obj");
//    Model Piso((char*)"Models/piso.obj");
//    Model Ball((char*)"Models/ball.obj");
//
//    // VAO/VBO
//    GLuint VBO, VAO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//    glBindVertexArray(VAO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//    // Position
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
//    glEnableVertexAttribArray(0);
//    // Normal
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//
//    // Material samplers
//    lightingShader.Use();
//    glUniform1i(glGetUniformLocation(lightingShader.Program, "Material.difuse"), 0);
//    glUniform1i(glGetUniformLocation(lightingShader.Program, "Material.specular"), 1);
//
//    glm::mat4 projection = glm::perspective(
//        camera.GetZoom(),
//        (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT,
//        0.1f, 100.0f
//    );
//
//    // Game loop
//    while (!glfwWindowShouldClose(window))
//    {
//        // Delta time
//        GLfloat currentFrame = static_cast<float>(glfwGetTime());
//        deltaTime = currentFrame - lastFrame;
//        lastFrame = currentFrame;
//
//        // Input + anim
//        glfwPollEvents();
//        DoMovement();
//        Animation();
//
//        // Clear
//        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        glEnable(GL_DEPTH_TEST);
//
//        // ==== DRAW ====
//        glm::mat4 model;
//        glm::mat4 view = camera.GetViewMatrix();
//        glm::mat4 modelTemp = glm::mat4(1.0f); // una sola vez por frame
//
//        lightingShader.Use();
//
//        glUniform1i(glGetUniformLocation(lightingShader.Program, "diffuse"), 0);
//
//        GLint viewPosLoc = glGetUniformLocation(lightingShader.Program, "viewPos");
//        glUniform3f(viewPosLoc, camera.GetPosition().x, camera.GetPosition().y, camera.GetPosition().z);
//
//        // Dir light
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.direction"), -0.2f, -1.0f, -0.3f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.ambient"), 0.6f, 0.6f, 0.6f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.diffuse"), 0.6f, 0.6f, 0.6f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.specular"), 0.3f, 0.3f, 0.3f);
//
//        // Point light anim
//        glm::vec3 lightColor;
//        lightColor.x = fabsf(sinf(glfwGetTime() * Light1.x));
//        lightColor.y = fabsf(sinf(glfwGetTime() * Light1.y));
//        lightColor.z = sinf(glfwGetTime() * Light1.z);
//
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].position"),
//            pointLightPositions[0].x, pointLightPositions[0].y, pointLightPositions[0].z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].ambient"),
//            lightColor.x, lightColor.y, lightColor.z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].diffuse"),
//            lightColor.x, lightColor.y, lightColor.z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].specular"),
//            1.0f, 0.2f, 0.2f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[0].constant"), 1.0f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[0].linear"), 0.045f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[0].quadratic"), 0.075f);
//
//        // Spotlight (cámara)
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.position"),
//            camera.GetPosition().x, camera.GetPosition().y, camera.GetPosition().z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.direction"),
//            camera.GetFront().x, camera.GetFront().y, camera.GetFront().z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.ambient"), 0.2f, 0.2f, 0.8f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.diffuse"), 0.2f, 0.2f, 0.8f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.specular"), 0.0f, 0.0f, 0.0f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.constant"), 1.0f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.linear"), 0.3f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.quadratic"), 0.7f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.cutOff"), glm::cos(glm::radians(12.0f)));
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.outerCutOff"), glm::cos(glm::radians(18.0f)));
//
//        // Material
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "material.shininess"), 5.0f);
//
//        // Matrices
//        GLint modelLoc = glGetUniformLocation(lightingShader.Program, "model");
//        GLint viewLoc = glGetUniformLocation(lightingShader.Program, "view");
//        GLint projLoc = glGetUniformLocation(lightingShader.Program, "projection");
//        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
//
//        // --- Piso ---
//        model = glm::mat4(1.0f);
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        Piso.Draw(lightingShader);
//
//        // --- Perro ---
//        model = glm::mat4(1.0f);
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        glUniform1i(glGetUniformLocation(lightingShader.Program, "transparency"), 0);
//
//        // Body
//        model = glm::translate(model, dogPos);
//        model = glm::rotate(model, glm::radians(dogRot), glm::vec3(0.0f, 1.0f, 0.0f));
//        modelTemp = model; // base
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        DogBody.Draw(lightingShader);
//
//        // Head
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(0.0f, 0.093f, 0.208f));
//        model = glm::rotate(model, glm::radians(head), glm::vec3(0.0f, 0.0f, 1.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        HeadDog.Draw(lightingShader);
//
//        // Tail 
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(0.0f, 0.026f, -0.288f));
//        model = glm::rotate(model, glm::radians(tail), glm::vec3(0.0f, 0.0f, -1.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        DogTail.Draw(lightingShader);
//
//        // Front Left Leg
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(0.112f, -0.044f, 0.074f));
//        model = glm::rotate(model, glm::radians(FLegs), glm::vec3(-1.0f, 0.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        F_LeftLeg.Draw(lightingShader);
//
//        // Front Right Leg
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(-0.111f, -0.055f, 0.074f));
//        model = glm::rotate(model, glm::radians(FLegs), glm::vec3(1.0f, 0.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        F_RightLeg.Draw(lightingShader);
//
//        // Back Left Leg
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(0.082f, -0.046f, -0.218f));
//        model = glm::rotate(model, glm::radians(RLegs), glm::vec3(1.0f, 0.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        B_LeftLeg.Draw(lightingShader);
//
//        // Back Right Leg
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(-0.083f, -0.057f, -0.231f));
//        model = glm::rotate(model, glm::radians(RLegs), glm::vec3(-1.0f, 0.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        B_RightLeg.Draw(lightingShader);
//
//        // --- Pelota ---
//        model = glm::mat4(1.0f);
//        glEnable(GL_BLEND);
//        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        glUniform1i(glGetUniformLocation(lightingShader.Program, "transparency"), 1);
//        model = glm::rotate(model, glm::radians(rotBall), glm::vec3(0.0f, 1.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        Ball.Draw(lightingShader);
//        glDisable(GL_BLEND);
//        glBindVertexArray(0);
//
//        // --- Lámpara ---
//        lampShader.Use();
//        modelLoc = glGetUniformLocation(lampShader.Program, "model");
//        GLint viewLoc2 = glGetUniformLocation(lampShader.Program, "view");
//        GLint projLoc2 = glGetUniformLocation(lampShader.Program, "projection");
//        glUniformMatrix4fv(viewLoc2, 1, GL_FALSE, glm::value_ptr(view));
//        glUniformMatrix4fv(projLoc2, 1, GL_FALSE, glm::value_ptr(projection));
//
//        model = glm::mat4(1.0f);
//        model = glm::translate(model, lightPos);
//        model = glm::scale(model, glm::vec3(0.2f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//
//        model = glm::mat4(1.0f);
//        model = glm::translate(model, pointLightPositions[0]);
//        model = glm::scale(model, glm::vec3(0.2f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        glBindVertexArray(VAO);
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//        glBindVertexArray(0);
//
//        // Swap
//        glfwSwapBuffers(window);
//    }
//
//    glfwTerminate();
//    return 0;
//}
//
//// Moves/alters the camera positions based on user input
//void DoMovement()
//{
//    if (keys[GLFW_KEY_W] || keys[GLFW_KEY_UP])    camera.ProcessKeyboard(FORWARD, deltaTime);
//    if (keys[GLFW_KEY_S] || keys[GLFW_KEY_DOWN])  camera.ProcessKeyboard(BACKWARD, deltaTime);
//    if (keys[GLFW_KEY_A] || keys[GLFW_KEY_LEFT])  camera.ProcessKeyboard(LEFT, deltaTime);
//    if (keys[GLFW_KEY_D] || keys[GLFW_KEY_RIGHT]) camera.ProcessKeyboard(RIGHT, deltaTime);
//
//    if (keys[GLFW_KEY_T]) { pointLightPositions[0].x += 0.01f; }
//    if (keys[GLFW_KEY_G]) { pointLightPositions[0].x -= 0.01f; }
//    if (keys[GLFW_KEY_Y]) { pointLightPositions[0].y += 0.01f; }
//    if (keys[GLFW_KEY_H]) { pointLightPositions[0].y -= 0.01f; }
//    if (keys[GLFW_KEY_U]) { pointLightPositions[0].z -= 0.1f; }
//    if (keys[GLFW_KEY_J]) { pointLightPositions[0].z += 0.01f; }
//}
//
//// Is called whenever a key is pressed/released via GLFW
//void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//    if (GLFW_KEY_ESCAPE == key && GLFW_PRESS == action) {
//        glfwSetWindowShouldClose(window, GL_TRUE);
//    }
//
//    if (key >= 0 && key < 1024) {
//        if (action == GLFW_PRESS)      keys[key] = true;
//        else if (action == GLFW_RELEASE) keys[key] = false;
//    }
//
//    if (keys[GLFW_KEY_SPACE]) {
//        active = !active;
//        Light1 = active ? glm::vec3(0.2f, 0.8f, 1.0f) : glm::vec3(0.0f);
//    }
//    if (keys[GLFW_KEY_N]) {
//        AnimBall = !AnimBall;
//    }
//    if (keys[GLFW_KEY_B]) {
//        dogAnim = 1;
//        dogState = WALK_FWD;   // comienza caminando hacia +Z
//    }
//}
//
//void Animation() {
//    // Bola
//    if (AnimBall) {
//        rotBall += 0.4f;
//    }
//
//    // Rotación libre del perro (si la usas)
//    if (AnimDog) {
//        rotDog -= 0.6f;
//    }
//
//    // Animación cíclica de patas / cabeza / cola
//    if (dogAnim == 1) {
//        if (!step) {
//            RLegs += 0.3f; FLegs += 0.3f; head += 0.3f; tail += 0.3f;
//            if (RLegs > 15.0f) step = true;
//        }
//        else {
//            RLegs -= 0.3f; FLegs -= 0.3f; head -= 0.3f; tail -= 0.3f;
//            if (RLegs < -15.0f) step = false;
//        }
//    }
//
//    // Movimiento con límites y giros
//    float moveStep = DOG_WALK_SPEED * deltaTime; // unidades/s
//    float turnStep = DOG_TURN_SPEED * deltaTime; // grados/s
//
//    switch (dogState) {
//    case IDLE:
//        break;
//
//        // +Z hasta orilla frontal
//    case WALK_FWD:
//        dogPos.z += moveStep;
//        if (dogPos.z >= (FLOOR_MAX_Z - SAFE_MARGIN)) {
//            dogPos.z = (FLOOR_MAX_Z - SAFE_MARGIN);
//            dogState = TURN_RIGHT_1;
//            dogTargetRot = dogRot + 90.0f; // giro horario
//        }
//        break;
//
//        // Primer giro horario (+90)
//    case TURN_RIGHT_1:
//        if (dogRot < dogTargetRot) {
//            dogRot += turnStep;
//            if (dogRot > dogTargetRot) dogRot = dogTargetRot;
//        }
//        if (dogRot == dogTargetRot) {
//            dogState = WALK_RIGHT; // caminar a +X
//        }
//        break;
//
//        // +X hasta orilla derecha
//    case WALK_RIGHT:
//        dogPos.x += moveStep;
//        if (dogPos.x >= (FLOOR_MAX_X - SAFE_MARGIN)) {
//            dogPos.x = (FLOOR_MAX_X - SAFE_MARGIN);
//            dogState = TURN_RIGHT_2;
//            dogTargetRot = dogRot + 90.0f; // segundo giro horario
//        }
//        break;
//
//        // Segundo giro horario (+90) => queda apuntando a -Z
//    case TURN_RIGHT_2:
//        if (dogRot < dogTargetRot) {
//            dogRot += turnStep;
//            if (dogRot > dogTargetRot) dogRot = dogTargetRot;
//        }
//        if (dogRot == dogTargetRot) {
//            dogState = WALK_BACK; // seguir caminando hacia -Z
//        }
//        break;
//
//        // -Z hasta la orilla trasera
//    case WALK_BACK:
//        dogPos.z -= moveStep;
//        if (dogPos.z <= (FLOOR_MIN_Z + SAFE_MARGIN)) {
//            dogPos.z = (FLOOR_MIN_Z + SAFE_MARGIN);
//            dogState = TURN_LEFT_CCW;
//            // *** CAMBIO SOLICITADO: último giro AHORA HORARIO (+90°) ***
//            dogTargetRot = dogRot + 90.0f; // giro horario en la última esquina
//        }
//        break;
//
//        // *** Último giro: horario (+90) ***
//    case TURN_LEFT_CCW:
//        if (dogRot < dogTargetRot) {
//            dogRot += turnStep;
//            if (dogRot > dogTargetRot) dogRot = dogTargetRot;
//        }
//        if (dogRot == dogTargetRot) {
//            dogState = IDLE; // detenerse tras el giro horario final
//        }
//        break;
//    }
//
//    // Clamp suave para no salir del piso
//    if (dogPos.x < FLOOR_MIN_X + SAFE_MARGIN) dogPos.x = FLOOR_MIN_X + SAFE_MARGIN;
//    if (dogPos.x > FLOOR_MAX_X - SAFE_MARGIN) dogPos.x = FLOOR_MAX_X - SAFE_MARGIN;
//    if (dogPos.z < FLOOR_MIN_Z + SAFE_MARGIN) dogPos.z = FLOOR_MIN_Z + SAFE_MARGIN;
//    if (dogPos.z > FLOOR_MAX_Z - SAFE_MARGIN) dogPos.z = FLOOR_MAX_Z - SAFE_MARGIN;
//
//    // Normaliza el ángulo
//    if (dogRot >= 360.0f) dogRot -= 360.0f;
//    if (dogRot < 0.0f)  dogRot += 360.0f;
//}
//
//void MouseCallback(GLFWwindow* window, double xPos, double yPos)
//{
//    if (firstMouse)
//    {
//        lastX = static_cast<float>(xPos);
//        lastY = static_cast<float>(yPos);
//        firstMouse = false;
//    }
//
//    GLfloat xOffset = static_cast<float>(xPos) - lastX;
//    GLfloat yOffset = lastY - static_cast<float>(yPos);
//
//    lastX = static_cast<float>(xPos);
//    lastY = static_cast<float>(yPos);
//
//    camera.ProcessMouseMovement(xOffset, yOffset);
//}
//

/*Practica 11: Animaciones Maquina de estados
 Laboratorio de computacion grafica
 GPO: 07
 Dayana Plata Alvarez
 No. cuenta: 318300764
 Fecha de entrega: 11/2/2025 */

//#include <iostream>
//#include <cmath>
//
// // GLEW
//#include <GL/glew.h>
//
//// GLFW
//#include <GLFW/glfw3.h>
//
//// Other Libs
//#include "stb_image.h"
//
//// GLM Mathematics
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
////Load Models
//#include "SOIL2/SOIL2.h"
//
//// Other includes
//#include "Shader.h"
//#include "Camera.h"
//#include "Model.h"
//
//// Function prototypes
//void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
//void MouseCallback(GLFWwindow* window, double xPos, double yPos);
//void DoMovement();
//void Animation();
//
//// Window dimensions
//const GLuint WIDTH = 800, HEIGHT = 600;
//int SCREEN_WIDTH, SCREEN_HEIGHT;
//
//// Camera
//Camera  camera(glm::vec3(0.0f, 0.0f, 3.0f));
//GLfloat lastX = WIDTH / 2.0f;
//GLfloat lastY = HEIGHT / 2.0f;
//bool keys[1024];
//bool firstMouse = true;
//// Light attributes
//glm::vec3 lightPos(0.0f, 0.0f, 0.0f);
//bool active;
//
//// Positions of the point lights
//glm::vec3 pointLightPositions[] = {
//    glm::vec3(0.0f,2.0f, 0.0f),
//    glm::vec3(0.0f,0.0f, 0.0f),
//    glm::vec3(0.0f,0.0f,  0.0f),
//    glm::vec3(0.0f,0.0f, 0.0f)
//};
//
//float vertices[] = {
//       -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//        0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//        0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//        0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//       -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//       -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//
//       -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//        0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//        0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//        0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//       -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//       -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//
//       -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//
//        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//        0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//        0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//        0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//
//       -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//        0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//        0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//        0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//       -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//       -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//
//       -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//        0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//        0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//        0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//       -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//       -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
//};
//
//glm::vec3 Light1 = glm::vec3(0);
////Anim
//float rotBall = 0.0f;
//bool AnimBall = false;
//bool AnimDog = false;
//float rotDog = 0.0f;
//int dogAnim = 0;
//float FLegs = 0.0f;
//float RLegs = 0.0f;
//float head = 0.0f;
//float tail = 0.0f;
//glm::vec3 dogPos(0.0f, 0.0f, 0.0f);
//float dogRot = 0.0f;
//bool step = false;
//
//// ------------------- Límites del piso y máquina de estados -------------------
//const float FLOOR_MIN_X = -2.0f;
//const float FLOOR_MAX_X = 2.0f;
//const float FLOOR_MIN_Z = -2.0f;
//const float FLOOR_MAX_Z = 2.0f;
//const float SAFE_MARGIN = 0.15f;
//
//// --- Centro del piso y tolerancia ---
//const float CENTER_X = 0.0f;
//const float CENTER_Z = 0.0f;
//const float CENTER_EPS = 0.05f; // distancia mínima para considerar "llegó al centro"
//
//// Velocidades
//const float DOG_WALK_SPEED = 0.6f;   // unidades/seg
//const float DOG_TURN_SPEED = 90.0f;  // grados/seg
//
//// Máquina de estados del perro (extendida)
//enum DogState {
//    IDLE = 0,
//    WALK_FWD,        // +Z
//    TURN_RIGHT_1,    // +90° horario
//    WALK_RIGHT,      // +X
//    TURN_RIGHT_2,    // +90° horario
//    WALK_BACK,       // -Z
//    TURN_LEFT_CCW,   // mantenemos el nombre
//    WALK_DIAG_CENTER // NUEVO: caminar en diagonal hacia el centro
//};
//DogState dogState = IDLE;
//float dogTargetRot = 0.0f; // destino del giro en grados
//// -----------------------------------------------------------------------------
//
//// Deltatime
//GLfloat deltaTime = 0.0f;
//GLfloat lastFrame = 0.0f;
//
//int main()
//{
//    // Init GLFW
//    glfwInit();
//
//    // Window
//    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Animacion maquina de estados", nullptr, nullptr);
//    if (nullptr == window) {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return EXIT_FAILURE;
//    }
//    glfwMakeContextCurrent(window);
//    glfwGetFramebufferSize(window, &SCREEN_WIDTH, &SCREEN_HEIGHT);
//
//    // Callbacks
//    glfwSetKeyCallback(window, KeyCallback);
//    glfwSetCursorPosCallback(window, MouseCallback);
//
//    // GLEW
//    glewExperimental = GL_TRUE;
//    if (GLEW_OK != glewInit()) {
//        std::cout << "Failed to initialize GLEW" << std::endl;
//        return EXIT_FAILURE;
//    }
//
//    // Viewport
//    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
//
//    Shader lightingShader("Shader/lighting.vs", "Shader/lighting.frag");
//    Shader lampShader("Shader/lamp.vs", "Shader/lamp.frag");
//
//    // Models
//    Model DogBody((char*)"Models/DogBody.obj");
//    Model HeadDog((char*)"Models/HeadDog.obj");
//    Model DogTail((char*)"Models/TailDog.obj");
//    Model F_RightLeg((char*)"Models/F_RightLegDog.obj");
//    Model F_LeftLeg((char*)"Models/F_LeftLegDog.obj");
//    Model B_RightLeg((char*)"Models/B_RightLegDog.obj");
//    Model B_LeftLeg((char*)"Models/B_LeftLegDog.obj");
//    Model Piso((char*)"Models/piso.obj");
//    Model Ball((char*)"Models/ball.obj");
//
//    // VAO/VBO
//    GLuint VBO, VAO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//    glBindVertexArray(VAO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//    // Position
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
//    glEnableVertexAttribArray(0);
//    // Normal
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//
//    // Material samplers
//    lightingShader.Use();
//    glUniform1i(glGetUniformLocation(lightingShader.Program, "Material.difuse"), 0);
//    glUniform1i(glGetUniformLocation(lightingShader.Program, "Material.specular"), 1);
//
//    glm::mat4 projection = glm::perspective(
//        camera.GetZoom(),
//        (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT,
//        0.1f, 100.0f
//    );
//
//    // Game loop
//    while (!glfwWindowShouldClose(window))
//    {
//        // Delta time
//        GLfloat currentFrame = static_cast<float>(glfwGetTime());
//        deltaTime = currentFrame - lastFrame;
//        lastFrame = currentFrame;
//
//        // Input + anim
//        glfwPollEvents();
//        DoMovement();
//        Animation();
//
//        // Clear
//        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        glEnable(GL_DEPTH_TEST);
//
//        // ==== DRAW ====
//        glm::mat4 model;
//        glm::mat4 view = camera.GetViewMatrix();
//        glm::mat4 modelTemp = glm::mat4(1.0f); // una sola vez por frame
//
//        lightingShader.Use();
//
//        glUniform1i(glGetUniformLocation(lightingShader.Program, "diffuse"), 0);
//
//        GLint viewPosLoc = glGetUniformLocation(lightingShader.Program, "viewPos");
//        glUniform3f(viewPosLoc, camera.GetPosition().x, camera.GetPosition().y, camera.GetPosition().z);
//
//        // Dir light
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.direction"), -0.2f, -1.0f, -0.3f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.ambient"), 0.6f, 0.6f, 0.6f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.diffuse"), 0.6f, 0.6f, 0.6f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.specular"), 0.3f, 0.3f, 0.3f);
//
//        // Point light anim
//        glm::vec3 lightColor;
//        lightColor.x = fabsf(sinf(glfwGetTime() * Light1.x));
//        lightColor.y = fabsf(sinf(glfwGetTime() * Light1.y));
//        lightColor.z = sinf(glfwGetTime() * Light1.z);
//
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].position"),
//            pointLightPositions[0].x, pointLightPositions[0].y, pointLightPositions[0].z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].ambient"),
//            lightColor.x, lightColor.y, lightColor.z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].diffuse"),
//            lightColor.x, lightColor.y, lightColor.z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].specular"),
//            1.0f, 0.2f, 0.2f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[0].constant"), 1.0f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[0].linear"), 0.045f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[0].quadratic"), 0.075f);
//
//        // Spotlight (cámara)
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.position"),
//            camera.GetPosition().x, camera.GetPosition().y, camera.GetPosition().z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.direction"),
//            camera.GetFront().x, camera.GetFront().y, camera.GetFront().z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.ambient"), 0.2f, 0.2f, 0.8f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.diffuse"), 0.2f, 0.2f, 0.8f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.specular"), 0.0f, 0.0f, 0.0f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.constant"), 1.0f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.linear"), 0.3f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.quadratic"), 0.7f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.cutOff"), glm::cos(glm::radians(12.0f)));
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.outerCutOff"), glm::cos(glm::radians(18.0f)));
//
//        // Material
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "material.shininess"), 5.0f);
//
//        // Matrices
//        GLint modelLoc = glGetUniformLocation(lightingShader.Program, "model");
//        GLint viewLoc = glGetUniformLocation(lightingShader.Program, "view");
//        GLint projLoc = glGetUniformLocation(lightingShader.Program, "projection");
//        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
//
//        // --- Piso ---
//        model = glm::mat4(1.0f);
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        Piso.Draw(lightingShader);
//
//        // --- Perro ---
//        model = glm::mat4(1.0f);
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        glUniform1i(glGetUniformLocation(lightingShader.Program, "transparency"), 0);
//
//        // Body
//        model = glm::translate(model, dogPos);
//        model = glm::rotate(model, glm::radians(dogRot), glm::vec3(0.0f, 1.0f, 0.0f));
//        modelTemp = model; // base
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        DogBody.Draw(lightingShader);
//
//        // Head
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(0.0f, 0.093f, 0.208f));
//        model = glm::rotate(model, glm::radians(head), glm::vec3(0.0f, 0.0f, 1.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        HeadDog.Draw(lightingShader);
//
//        // Tail 
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(0.0f, 0.026f, -0.288f));
//        model = glm::rotate(model, glm::radians(tail), glm::vec3(0.0f, 0.0f, -1.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        DogTail.Draw(lightingShader);
//
//        // Front Left Leg
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(0.112f, -0.044f, 0.074f));
//        model = glm::rotate(model, glm::radians(FLegs), glm::vec3(-1.0f, 0.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        F_LeftLeg.Draw(lightingShader);
//
//        // Front Right Leg
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(-0.111f, -0.055f, 0.074f));
//        model = glm::rotate(model, glm::radians(FLegs), glm::vec3(1.0f, 0.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        F_RightLeg.Draw(lightingShader);
//
//        // Back Left Leg
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(0.082f, -0.046f, -0.218f));
//        model = glm::rotate(model, glm::radians(RLegs), glm::vec3(1.0f, 0.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        B_LeftLeg.Draw(lightingShader);
//
//        // Back Right Leg
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(-0.083f, -0.057f, -0.231f));
//        model = glm::rotate(model, glm::radians(RLegs), glm::vec3(-1.0f, 0.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        B_RightLeg.Draw(lightingShader);
//
//        // --- Pelota ---
//        model = glm::mat4(1.0f);
//        glEnable(GL_BLEND);
//        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        glUniform1i(glGetUniformLocation(lightingShader.Program, "transparency"), 1);
//        model = glm::rotate(model, glm::radians(rotBall), glm::vec3(0.0f, 1.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        Ball.Draw(lightingShader);
//        glDisable(GL_BLEND);
//        glBindVertexArray(0);
//
//        // --- Lámpara ---
//        lampShader.Use();
//        modelLoc = glGetUniformLocation(lampShader.Program, "model");
//        GLint viewLoc2 = glGetUniformLocation(lampShader.Program, "view");
//        GLint projLoc2 = glGetUniformLocation(lampShader.Program, "projection");
//        glUniformMatrix4fv(viewLoc2, 1, GL_FALSE, glm::value_ptr(view));
//        glUniformMatrix4fv(projLoc2, 1, GL_FALSE, glm::value_ptr(projection));
//
//        model = glm::mat4(1.0f);
//        model = glm::translate(model, lightPos);
//        model = glm::scale(model, glm::vec3(0.2f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//
//        model = glm::mat4(1.0f);
//        model = glm::translate(model, pointLightPositions[0]);
//        model = glm::scale(model, glm::vec3(0.2f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        glBindVertexArray(VAO);
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//        glBindVertexArray(0);
//
//        // Swap
//        glfwSwapBuffers(window);
//    }
//
//    glfwTerminate();
//    return 0;
//}
//
//// Moves/alters the camera positions based on user input
//void DoMovement()
//{
//    if (keys[GLFW_KEY_W] || keys[GLFW_KEY_UP])    camera.ProcessKeyboard(FORWARD, deltaTime);
//    if (keys[GLFW_KEY_S] || keys[GLFW_KEY_DOWN])  camera.ProcessKeyboard(BACKWARD, deltaTime);
//    if (keys[GLFW_KEY_A] || keys[GLFW_KEY_LEFT])  camera.ProcessKeyboard(LEFT, deltaTime);
//    if (keys[GLFW_KEY_D] || keys[GLFW_KEY_RIGHT]) camera.ProcessKeyboard(RIGHT, deltaTime);
//
//    if (keys[GLFW_KEY_T]) { pointLightPositions[0].x += 0.01f; }
//    if (keys[GLFW_KEY_G]) { pointLightPositions[0].x -= 0.01f; }
//    if (keys[GLFW_KEY_Y]) { pointLightPositions[0].y += 0.01f; }
//    if (keys[GLFW_KEY_H]) { pointLightPositions[0].y -= 0.01f; }
//    if (keys[GLFW_KEY_U]) { pointLightPositions[0].z -= 0.1f; }
//    if (keys[GLFW_KEY_J]) { pointLightPositions[0].z += 0.01f; }
//}
//
//// Is called whenever a key is pressed/released via GLFW
//void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//    if (GLFW_KEY_ESCAPE == key && GLFW_PRESS == action) {
//        glfwSetWindowShouldClose(window, GL_TRUE);
//    }
//
//    if (key >= 0 && key < 1024) {
//        if (action == GLFW_PRESS)      keys[key] = true;
//        else if (action == GLFW_RELEASE) keys[key] = false;
//    }
//
//    if (keys[GLFW_KEY_SPACE]) {
//        active = !active;
//        Light1 = active ? glm::vec3(0.2f, 0.8f, 1.0f) : glm::vec3(0.0f);
//    }
//    if (keys[GLFW_KEY_N]) {
//        AnimBall = !AnimBall;
//    }
//    if (keys[GLFW_KEY_B]) {
//        dogAnim = 1;
//        dogState = WALK_FWD;   // comienza caminando hacia +Z
//    }
//}
//
//void Animation() {
//    // Bola
//    if (AnimBall) {
//        rotBall += 0.4f;
//    }
//
//    // Rotación libre del perro (si la usas)
//    if (AnimDog) {
//        rotDog -= 0.6f;
//    }
//
//    // Animación cíclica de patas / cabeza / cola
//    if (dogAnim == 1) {
//        if (!step) {
//            RLegs += 0.3f; FLegs += 0.3f; head += 0.3f; tail += 0.3f;
//            if (RLegs > 15.0f) step = true;
//        }
//        else {
//            RLegs -= 0.3f; FLegs -= 0.3f; head -= 0.3f; tail -= 0.3f;
//            if (RLegs < -15.0f) step = false;
//        }
//    }
//
//    // Movimiento con límites y giros
//    float moveStep = DOG_WALK_SPEED * deltaTime; // unidades/s
//    float turnStep = DOG_TURN_SPEED * deltaTime; // grados/s
//
//    switch (dogState) {
//    case IDLE:
//        break;
//
//        // +Z hasta orilla frontal
//    case WALK_FWD:
//        dogPos.z += moveStep;
//        if (dogPos.z >= (FLOOR_MAX_Z - SAFE_MARGIN)) {
//            dogPos.z = (FLOOR_MAX_Z - SAFE_MARGIN);
//            dogState = TURN_RIGHT_1;
//            dogTargetRot = dogRot + 90.0f; // giro horario
//        }
//        break;
//
//        // Primer giro horario (+90)
//    case TURN_RIGHT_1:
//        if (dogRot < dogTargetRot) {
//            dogRot += turnStep;
//            if (dogRot > dogTargetRot) dogRot = dogTargetRot;
//        }
//        if (dogRot == dogTargetRot) {
//            dogState = WALK_RIGHT; // caminar a +X
//        }
//        break;
//
//        // +X hasta orilla derecha
//    case WALK_RIGHT:
//        dogPos.x += moveStep;
//        if (dogPos.x >= (FLOOR_MAX_X - SAFE_MARGIN)) {
//            dogPos.x = (FLOOR_MAX_X - SAFE_MARGIN);
//            dogState = TURN_RIGHT_2;
//            dogTargetRot = dogRot + 90.0f; // segundo giro horario
//        }
//        break;
//
//        // Segundo giro horario (+90) => queda apuntando a -Z
//    case TURN_RIGHT_2:
//        if (dogRot < dogTargetRot) {
//            dogRot += turnStep;
//            if (dogRot > dogTargetRot) dogRot = dogTargetRot;
//        }
//        if (dogRot == dogTargetRot) {
//            dogState = WALK_BACK; // seguir caminando hacia -Z
//        }
//        break;
//
//        // -Z hasta la orilla trasera
//    case WALK_BACK:
//        dogPos.z -= moveStep;
//        if (dogPos.z <= (FLOOR_MIN_Z + SAFE_MARGIN)) {
//            dogPos.z = (FLOOR_MIN_Z + SAFE_MARGIN);
//            dogState = TURN_LEFT_CCW;
//            // Último giro AHORA HORARIO (+90°)
//            dogTargetRot = dogRot + 90.0f; // giro horario en la última esquina
//        }
//        break;
//
//        // Último giro (ahora horario), y luego ir al centro en diagonal
//    case TURN_LEFT_CCW:
//        if (dogRot < dogTargetRot) {
//            dogRot += turnStep;
//            if (dogRot > dogTargetRot) dogRot = dogTargetRot;
//        }
//        if (dogRot == dogTargetRot) {
//            // calcular yaw que mira al centro del piso
//            float dx = CENTER_X - dogPos.x;
//            float dz = CENTER_Z - dogPos.z;
//            float desiredYaw = atan2f(dx, dz) * 180.0f / 3.14159265f;
//            if (desiredYaw < 0.0f) desiredYaw += 360.0f;
//            dogTargetRot = desiredYaw;
//            dogState = WALK_DIAG_CENTER; // nueva trayectoria
//        }
//        break;
//
//    case WALK_DIAG_CENTER:
//    {
//        // Rotación suave hacia el dogTargetRot
//        float diff = dogTargetRot - dogRot;
//        while (diff > 180.0f) diff -= 360.0f;
//        while (diff < -180.0f) diff += 360.0f;
//
//        if (std::fabs(diff) > 0.01f) {
//            float step = (diff > 0.0f ? +turnStep : -turnStep);
//            if (std::fabs(step) > std::fabs(diff)) step = diff;
//            dogRot += step;
//            if (dogRot >= 360.0f) dogRot -= 360.0f;
//            if (dogRot < 0.0f)    dogRot += 360.0f;
//        }
//
//        // Avance hacia el centro (diagonal)
//        float dx = CENTER_X - dogPos.x;
//        float dz = CENTER_Z - dogPos.z;
//        float dist = std::sqrt(dx * dx + dz * dz);
//
//        if (dist <= CENTER_EPS) {
//            dogPos.x = CENTER_X;
//            dogPos.z = CENTER_Z;
//            dogState = IDLE; // llegó al centro
//        }
//        else {
//            float nx = dx / dist;
//            float nz = dz / dist;
//            float stepMove = moveStep;
//            if (stepMove > dist) stepMove = dist; // no pasarse
//            dogPos.x += nx * stepMove;
//            dogPos.z += nz * stepMove;
//        }
//    }
//    break;
//    }
//
//    // Clamp suave para no salir del piso
//    if (dogPos.x < FLOOR_MIN_X + SAFE_MARGIN) dogPos.x = FLOOR_MIN_X + SAFE_MARGIN;
//    if (dogPos.x > FLOOR_MAX_X - SAFE_MARGIN) dogPos.x = FLOOR_MAX_X - SAFE_MARGIN;
//    if (dogPos.z < FLOOR_MIN_Z + SAFE_MARGIN) dogPos.z = FLOOR_MIN_Z + SAFE_MARGIN;
//    if (dogPos.z > FLOOR_MAX_Z - SAFE_MARGIN) dogPos.z = FLOOR_MAX_Z - SAFE_MARGIN;
//
//    // Normaliza el ángulo
//    if (dogRot >= 360.0f) dogRot -= 360.0f;
//    if (dogRot < 0.0f)    dogRot += 360.0f;
//}
//
//void MouseCallback(GLFWwindow* window, double xPos, double yPos)
//{
//    if (firstMouse)
//    {
//        lastX = static_cast<float>(xPos);
//        lastY = static_cast<float>(yPos);
//        firstMouse = false;
//    }
//
//    GLfloat xOffset = static_cast<float>(xPos) - lastX;
//    GLfloat yOffset = lastY - static_cast<float>(yPos);
//
//    lastX = static_cast<float>(xPos);
//    lastY = static_cast<float>(yPos);
//
//    camera.ProcessMouseMovement(xOffset, yOffset);
//}
/*Practica 11: Animaciones Maquina de estados
 Laboratorio de computacion grafica
 GPO: 07
 Dayana Plata Alvarez
 No. cuenta: 318300764
 Fecha de entrega: 11/2/2025 */
//
//#include <iostream>
//#include <cmath>
//
// // GLEW
//#include <GL/glew.h>
//
//// GLFW
//#include <GLFW/glfw3.h>
//
//// Other Libs
//#include "stb_image.h"
//
//// GLM Mathematics
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
////Load Models
//#include "SOIL2/SOIL2.h"
//
//// Other includes
//#include "Shader.h"
//#include "Camera.h"
//#include "Model.h"
//
//// Function prototypes
//void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
//void MouseCallback(GLFWwindow* window, double xPos, double yPos);
//void DoMovement();
//void Animation();
//
//// Window dimensions
//const GLuint WIDTH = 800, HEIGHT = 600;
//int SCREEN_WIDTH, SCREEN_HEIGHT;
//
//// Camera
//Camera  camera(glm::vec3(0.0f, 0.0f, 3.0f));
//GLfloat lastX = WIDTH / 2.0f;
//GLfloat lastY = HEIGHT / 2.0f;
//bool keys[1024];
//bool firstMouse = true;
//// Light attributes
//glm::vec3 lightPos(0.0f, 0.0f, 0.0f);
//bool active;
//
//// Positions of the point lights
//glm::vec3 pointLightPositions[] = {
//    glm::vec3(0.0f,2.0f, 0.0f),
//    glm::vec3(0.0f,0.0f, 0.0f),
//    glm::vec3(0.0f,0.0f,  0.0f),
//    glm::vec3(0.0f,0.0f, 0.0f)
//};
//
//float vertices[] = {
//       -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//        0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//        0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//        0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//       -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//       -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//
//       -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//        0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//        0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//        0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//       -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//       -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//
//       -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//
//        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//        0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//        0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//        0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//
//       -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//        0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//        0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//        0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//       -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//       -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//
//       -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//        0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//        0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//        0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//       -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//       -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
//};
//
//glm::vec3 Light1 = glm::vec3(0);
////Anim
//float rotBall = 0.0f;
//bool AnimBall = false;
//bool AnimDog = false;
//float rotDog = 0.0f;
//int dogAnim = 0;
//float FLegs = 0.0f;
//float RLegs = 0.0f;
//float head = 0.0f;
//float tail = 0.0f;
//glm::vec3 dogPos(0.0f, 0.0f, 0.0f);
//float dogRot = 0.0f;
//bool step = false;
//
//// ------------------- Límites del piso y máquina de estados -------------------
//const float FLOOR_MIN_X = -2.0f;
//const float FLOOR_MAX_X = 2.0f;
//const float FLOOR_MIN_Z = -2.0f;
//const float FLOOR_MAX_Z = 2.0f;
//const float SAFE_MARGIN = 0.15f;
//
//// --- Centro del piso y tolerancia (previo) ---
//const float CENTER_X = 0.0f;
//const float CENTER_Z = 0.0f;
//const float CENTER_EPS = 0.05f; // distancia mínima para considerar "llegó al centro"
//
//// Velocidades
//const float DOG_WALK_SPEED = 0.6f;   // unidades/seg
//const float DOG_TURN_SPEED = 90.0f;  // grados/seg
//
//// Máquina de estados del perro (extendida)
//enum DogState {
//    IDLE = 0,
//    WALK_FWD,        // +Z
//    TURN_RIGHT_1,    // +90° horario
//    WALK_RIGHT,      // +X
//    TURN_RIGHT_2,    // +90° horario
//    WALK_BACK,       // -Z
//    TURN_LEFT_CCW,   // mantenemos el nombre (usa giro horario final ya hecho)
//    WALK_DIAG_CENTER, // (queda disponible si lo necesitas)
//    TURN_45_CW,       // NUEVO: giro de 45° en sentido horario
//    WALK_STRAIGHT_45  // NUEVO: avanzar recto tras el giro de 45°
//};
//DogState dogState = IDLE;
//float dogTargetRot = 0.0f; // destino del giro en grados
//// -----------------------------------------------------------------------------
//
//// Deltatime
//GLfloat deltaTime = 0.0f;
//GLfloat lastFrame = 0.0f;
//
//int main()
//{
//    // Init GLFW
//    glfwInit();
//
//    // Window
//    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Animacion maquina de estados", nullptr, nullptr);
//    if (nullptr == window) {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return EXIT_FAILURE;
//    }
//    glfwMakeContextCurrent(window);
//    glfwGetFramebufferSize(window, &SCREEN_WIDTH, &SCREEN_HEIGHT);
//
//    // Callbacks
//    glfwSetKeyCallback(window, KeyCallback);
//    glfwSetCursorPosCallback(window, MouseCallback);
//
//    // GLEW
//    glewExperimental = GL_TRUE;
//    if (GLEW_OK != glewInit()) {
//        std::cout << "Failed to initialize GLEW" << std::endl;
//        return EXIT_FAILURE;
//    }
//
//    // Viewport
//    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
//
//    Shader lightingShader("Shader/lighting.vs", "Shader/lighting.frag");
//    Shader lampShader("Shader/lamp.vs", "Shader/lamp.frag");
//
//    // Models
//    Model DogBody((char*)"Models/DogBody.obj");
//    Model HeadDog((char*)"Models/HeadDog.obj");
//    Model DogTail((char*)"Models/TailDog.obj");
//    Model F_RightLeg((char*)"Models/F_RightLegDog.obj");
//    Model F_LeftLeg((char*)"Models/F_LeftLegDog.obj");
//    Model B_RightLeg((char*)"Models/B_RightLegDog.obj");
//    Model B_LeftLeg((char*)"Models/B_LeftLegDog.obj");
//    Model Piso((char*)"Models/piso.obj");
//    Model Ball((char*)"Models/ball.obj");
//
//    // VAO/VBO
//    GLuint VBO, VAO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//    glBindVertexArray(VAO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//    // Position
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
//    glEnableVertexAttribArray(0);
//    // Normal
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//
//    // Material samplers
//    lightingShader.Use();
//    glUniform1i(glGetUniformLocation(lightingShader.Program, "Material.difuse"), 0);
//    glUniform1i(glGetUniformLocation(lightingShader.Program, "Material.specular"), 1);
//
//    glm::mat4 projection = glm::perspective(
//        camera.GetZoom(),
//        (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT,
//        0.1f, 100.0f
//    );
//
//    // Game loop
//    while (!glfwWindowShouldClose(window))
//    {
//        // Delta time
//        GLfloat currentFrame = static_cast<float>(glfwGetTime());
//        deltaTime = currentFrame - lastFrame;
//        lastFrame = currentFrame;
//
//        // Input + anim
//        glfwPollEvents();
//        DoMovement();
//        Animation();
//
//        // Clear
//        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        glEnable(GL_DEPTH_TEST);
//
//        // ==== DRAW ====
//        glm::mat4 model;
//        glm::mat4 view = camera.GetViewMatrix();
//        glm::mat4 modelTemp = glm::mat4(1.0f); // una sola vez por frame
//
//        lightingShader.Use();
//
//        glUniform1i(glGetUniformLocation(lightingShader.Program, "diffuse"), 0);
//
//        GLint viewPosLoc = glGetUniformLocation(lightingShader.Program, "viewPos");
//        glUniform3f(viewPosLoc, camera.GetPosition().x, camera.GetPosition().y, camera.GetPosition().z);
//
//        // Dir light
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.direction"), -0.2f, -1.0f, -0.3f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.ambient"), 0.6f, 0.6f, 0.6f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.diffuse"), 0.6f, 0.6f, 0.6f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.specular"), 0.3f, 0.3f, 0.3f);
//
//        // Point light anim
//        glm::vec3 lightColor;
//        lightColor.x = fabsf(sinf(glfwGetTime() * Light1.x));
//        lightColor.y = fabsf(sinf(glfwGetTime() * Light1.y));
//        lightColor.z = sinf(glfwGetTime() * Light1.z);
//
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].position"),
//            pointLightPositions[0].x, pointLightPositions[0].y, pointLightPositions[0].z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].ambient"),
//            lightColor.x, lightColor.y, lightColor.z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].diffuse"),
//            lightColor.x, lightColor.y, lightColor.z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].specular"),
//            1.0f, 0.2f, 0.2f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[0].constant"), 1.0f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[0].linear"), 0.045f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[0].quadratic"), 0.075f);
//
//        // Spotlight (cámara)
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.position"),
//            camera.GetPosition().x, camera.GetPosition().y, camera.GetPosition().z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.direction"),
//            camera.GetFront().x, camera.GetFront().y, camera.GetFront().z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.ambient"), 0.2f, 0.2f, 0.8f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.diffuse"), 0.2f, 0.2f, 0.8f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.specular"), 0.0f, 0.0f, 0.0f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.constant"), 1.0f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.linear"), 0.3f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.quadratic"), 0.7f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.cutOff"), glm::cos(glm::radians(12.0f)));
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.outerCutOff"), glm::cos(glm::radians(18.0f)));
//
//        // Material
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "material.shininess"), 5.0f);
//
//        // Matrices
//        GLint modelLoc = glGetUniformLocation(lightingShader.Program, "model");
//        GLint viewLoc = glGetUniformLocation(lightingShader.Program, "view");
//        GLint projLoc = glGetUniformLocation(lightingShader.Program, "projection");
//        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
//
//        // --- Piso ---
//        model = glm::mat4(1.0f);
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        Piso.Draw(lightingShader);
//
//        // --- Perro ---
//        model = glm::mat4(1.0f);
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        glUniform1i(glGetUniformLocation(lightingShader.Program, "transparency"), 0);
//
//        // Body
//        model = glm::translate(model, dogPos);
//        model = glm::rotate(model, glm::radians(dogRot), glm::vec3(0.0f, 1.0f, 0.0f));
//        modelTemp = model; // base
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        DogBody.Draw(lightingShader);
//
//        // Head
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(0.0f, 0.093f, 0.208f));
//        model = glm::rotate(model, glm::radians(head), glm::vec3(0.0f, 0.0f, 1.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        HeadDog.Draw(lightingShader);
//
//        // Tail 
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(0.0f, 0.026f, -0.288f));
//        model = glm::rotate(model, glm::radians(tail), glm::vec3(0.0f, 0.0f, -1.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        DogTail.Draw(lightingShader);
//
//        // Front Left Leg
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(0.112f, -0.044f, 0.074f));
//        model = glm::rotate(model, glm::radians(FLegs), glm::vec3(-1.0f, 0.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        F_LeftLeg.Draw(lightingShader);
//
//        // Front Right Leg
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(-0.111f, -0.055f, 0.074f));
//        model = glm::rotate(model, glm::radians(FLegs), glm::vec3(1.0f, 0.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        F_RightLeg.Draw(lightingShader);
//
//        // Back Left Leg
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(0.082f, -0.046f, -0.218f));
//        model = glm::rotate(model, glm::radians(RLegs), glm::vec3(1.0f, 0.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        B_LeftLeg.Draw(lightingShader);
//
//        // Back Right Leg
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(-0.083f, -0.057f, -0.231f));
//        model = glm::rotate(model, glm::radians(RLegs), glm::vec3(-1.0f, 0.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        B_RightLeg.Draw(lightingShader);
//
//        // --- Pelota ---
//        model = glm::mat4(1.0f);
//        glEnable(GL_BLEND);
//        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        glUniform1i(glGetUniformLocation(lightingShader.Program, "transparency"), 1);
//        model = glm::rotate(model, glm::radians(rotBall), glm::vec3(0.0f, 1.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        Ball.Draw(lightingShader);
//        glDisable(GL_BLEND);
//        glBindVertexArray(0);
//
//        // --- Lámpara ---
//        lampShader.Use();
//        modelLoc = glGetUniformLocation(lampShader.Program, "model");
//        GLint viewLoc2 = glGetUniformLocation(lampShader.Program, "view");
//        GLint projLoc2 = glGetUniformLocation(lampShader.Program, "projection");
//        glUniformMatrix4fv(viewLoc2, 1, GL_FALSE, glm::value_ptr(view));
//        glUniformMatrix4fv(projLoc2, 1, GL_FALSE, glm::value_ptr(projection));
//
//        model = glm::mat4(1.0f);
//        model = glm::translate(model, lightPos);
//        model = glm::scale(model, glm::vec3(0.2f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//
//        model = glm::mat4(1.0f);
//        model = glm::translate(model, pointLightPositions[0]);
//        model = glm::scale(model, glm::vec3(0.2f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        glBindVertexArray(VAO);
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//        glBindVertexArray(0);
//
//        // Swap
//        glfwSwapBuffers(window);
//    }
//
//    glfwTerminate();
//    return 0;
//}
//
//// Moves/alters the camera positions based on user input
//void DoMovement()
//{
//    if (keys[GLFW_KEY_W] || keys[GLFW_KEY_UP])    camera.ProcessKeyboard(FORWARD, deltaTime);
//    if (keys[GLFW_KEY_S] || keys[GLFW_KEY_DOWN])  camera.ProcessKeyboard(BACKWARD, deltaTime);
//    if (keys[GLFW_KEY_A] || keys[GLFW_KEY_LEFT])  camera.ProcessKeyboard(LEFT, deltaTime);
//    if (keys[GLFW_KEY_D] || keys[GLFW_KEY_RIGHT]) camera.ProcessKeyboard(RIGHT, deltaTime);
//
//    if (keys[GLFW_KEY_T]) { pointLightPositions[0].x += 0.01f; }
//    if (keys[GLFW_KEY_G]) { pointLightPositions[0].x -= 0.01f; }
//    if (keys[GLFW_KEY_Y]) { pointLightPositions[0].y += 0.01f; }
//    if (keys[GLFW_KEY_H]) { pointLightPositions[0].y -= 0.01f; }
//    if (keys[GLFW_KEY_U]) { pointLightPositions[0].z -= 0.1f; }
//    if (keys[GLFW_KEY_J]) { pointLightPositions[0].z += 0.01f; }
//}
//
//// Is called whenever a key is pressed/released via GLFW
//void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//    if (GLFW_KEY_ESCAPE == key && GLFW_PRESS == action) {
//        glfwSetWindowShouldClose(window, GL_TRUE);
//    }
//
//    if (key >= 0 && key < 1024) {
//        if (action == GLFW_PRESS)      keys[key] = true;
//        else if (action == GLFW_RELEASE) keys[key] = false;
//    }
//
//    if (keys[GLFW_KEY_SPACE]) {
//        active = !active;
//        Light1 = active ? glm::vec3(0.2f, 0.8f, 1.0f) : glm::vec3(0.0f);
//    }
//    if (keys[GLFW_KEY_N]) {
//        AnimBall = !AnimBall;
//    }
//    if (keys[GLFW_KEY_B]) {
//        dogAnim = 1;
//        dogState = WALK_FWD;   // comienza caminando hacia +Z
//    }
//}
//
//void Animation() {
//    // Bola
//    if (AnimBall) {
//        rotBall += 0.4f;
//    }
//
//    // Rotación libre del perro (si la usas)
//    if (AnimDog) {
//        rotDog -= 0.6f;
//    }
//
//    // Animación cíclica de patas / cabeza / cola
//    if (dogAnim == 1) {
//        if (!step) {
//            RLegs += 0.3f; FLegs += 0.3f; head += 0.3f; tail += 0.3f;
//            if (RLegs > 15.0f) step = true;
//        }
//        else {
//            RLegs -= 0.3f; FLegs -= 0.3f; head -= 0.3f; tail -= 0.3f;
//            if (RLegs < -15.0f) step = false;
//        }
//    }
//
//    // Movimiento con límites y giros
//    float moveStep = DOG_WALK_SPEED * deltaTime; // unidades/s
//    float turnStep = DOG_TURN_SPEED * deltaTime; // grados/s
//
//    switch (dogState) {
//    case IDLE:
//        break;
//
//        // +Z hasta orilla frontal
//    case WALK_FWD:
//        dogPos.z += moveStep;
//        if (dogPos.z >= (FLOOR_MAX_Z - SAFE_MARGIN)) {
//            dogPos.z = (FLOOR_MAX_Z - SAFE_MARGIN);
//            dogState = TURN_RIGHT_1;
//            dogTargetRot = dogRot + 90.0f; // giro horario
//        }
//        break;
//
//        // Primer giro horario (+90)
//    case TURN_RIGHT_1:
//        if (dogRot < dogTargetRot) {
//            dogRot += turnStep;
//            if (dogRot > dogTargetRot) dogRot = dogTargetRot;
//        }
//        if (dogRot == dogTargetRot) {
//            dogState = WALK_RIGHT; // caminar a +X
//        }
//        break;
//
//        // +X hasta orilla derecha
//    case WALK_RIGHT:
//        dogPos.x += moveStep;
//        if (dogPos.x >= (FLOOR_MAX_X - SAFE_MARGIN)) {
//            dogPos.x = (FLOOR_MAX_X - SAFE_MARGIN);
//            dogState = TURN_RIGHT_2;
//            dogTargetRot = dogRot + 90.0f; // segundo giro horario
//        }
//        break;
//
//        // Segundo giro horario (+90) => queda apuntando a -Z
//    case TURN_RIGHT_2:
//        if (dogRot < dogTargetRot) {
//            dogRot += turnStep;
//            if (dogRot > dogTargetRot) dogRot = dogTargetRot;
//        }
//        if (dogRot == dogTargetRot) {
//            dogState = WALK_BACK; // seguir caminando hacia -Z
//        }
//        break;
//
//        // -Z hasta la orilla trasera
//    case WALK_BACK:
//        dogPos.z -= moveStep;
//        if (dogPos.z <= (FLOOR_MIN_Z + SAFE_MARGIN)) {
//            dogPos.z = (FLOOR_MIN_Z + SAFE_MARGIN);
//            dogState = TURN_LEFT_CCW;
//            // Último giro AHORA HORARIO (+90°) ya acordado
//            dogTargetRot = dogRot + 90.0f; // horario
//        }
//        break;
//
//        // Último giro (horario). Ahora añadimos un giro adicional de 45° y seguir recto.
//    case TURN_LEFT_CCW:
//        if (dogRot < dogTargetRot) {
//            dogRot += turnStep;
//            if (dogRot > dogTargetRot) dogRot = dogTargetRot;
//        }
//        if (dogRot == dogTargetRot) {
//            // NUEVO: preparar giro de 45° horario
//            dogTargetRot = dogRot + 45.0f;
//            if (dogTargetRot >= 360.0f) dogTargetRot -= 360.0f;
//            dogState = TURN_45_CW;
//        }
//        break;
//
//    case TURN_45_CW:
//        if (dogRot < dogTargetRot) {
//            dogRot += turnStep;
//            if (dogRot > dogTargetRot) dogRot = dogTargetRot;
//        }
//        // considerar wrap-around inverso (por si dogTargetRot < dogRot por normalización)
//        if (dogRot == dogTargetRot) {
//            dogState = WALK_STRAIGHT_45; // avanzar recto con el nuevo rumbo
//        }
//        break;
//
//    case WALK_STRAIGHT_45:
//    {
//        // Avanzar recto según dogRot, sin salir del piso
//        float yaw = glm::radians(dogRot);
//        float dirX = sinf(yaw);
//        float dirZ = cosf(yaw);
//
//        // Propuesta de siguiente posición
//        float nx = dogPos.x + dirX * moveStep;
//        float nz = dogPos.z + dirZ * moveStep;
//
//        // Limitar para no pasar del piso (considerando margen)
//        bool hitEdge = false;
//        if (nx < FLOOR_MIN_X + SAFE_MARGIN) { nx = FLOOR_MIN_X + SAFE_MARGIN; hitEdge = true; }
//        if (nx > FLOOR_MAX_X - SAFE_MARGIN) { nx = FLOOR_MAX_X - SAFE_MARGIN; hitEdge = true; }
//        if (nz < FLOOR_MIN_Z + SAFE_MARGIN) { nz = FLOOR_MIN_Z + SAFE_MARGIN; hitEdge = true; }
//        if (nz > FLOOR_MAX_Z - SAFE_MARGIN) { nz = FLOOR_MAX_Z - SAFE_MARGIN; hitEdge = true; }
//
//        dogPos.x = nx;
//        dogPos.z = nz;
//
//        // Si tocó borde, detente
//        if (hitEdge) {
//            dogState = IDLE;
//        }
//    }
//    break;
//
//    // (Disponible por si lo quieres volver a usar; no se activa en este flujo)
//    case WALK_DIAG_CENTER:
//    {
//        // Rotación suave hacia el dogTargetRot
//        float diff = dogTargetRot - dogRot;
//        while (diff > 180.0f) diff -= 360.0f;
//        while (diff < -180.0f) diff += 360.0f;
//
//        if (fabsf(diff) > 0.01f) {
//            float step = (diff > 0.0f ? +turnStep : -turnStep);
//            if (fabsf(step) > fabsf(diff)) step = diff;
//            dogRot += step;
//            if (dogRot >= 360.0f) dogRot -= 360.0f;
//            if (dogRot < 0.0f)    dogRot += 360.0f;
//        }
//
//        // Avance hacia el centro (diagonal)
//        float dx = CENTER_X - dogPos.x;
//        float dz = CENTER_Z - dogPos.z;
//        float dist = sqrtf(dx * dx + dz * dz);
//
//        if (dist <= CENTER_EPS) {
//            dogPos.x = CENTER_X;
//            dogPos.z = CENTER_Z;
//            dogState = IDLE; // llegó al centro
//        }
//        else {
//            float nx = dx / dist;
//            float nz = dz / dist;
//            float stepMove = moveStep;
//            if (stepMove > dist) stepMove = dist; // no pasarse
//            // Probar siguientes coords sin salirse
//            float tx = dogPos.x + nx * stepMove;
//            float tz = dogPos.z + nz * stepMove;
//
//            if (tx < FLOOR_MIN_X + SAFE_MARGIN) tx = FLOOR_MIN_X + SAFE_MARGIN;
//            if (tx > FLOOR_MAX_X - SAFE_MARGIN) tx = FLOOR_MAX_X - SAFE_MARGIN;
//            if (tz < FLOOR_MIN_Z + SAFE_MARGIN) tz = FLOOR_MIN_Z + SAFE_MARGIN;
//            if (tz > FLOOR_MAX_Z - SAFE_MARGIN) tz = FLOOR_MAX_Z - SAFE_MARGIN;
//
//            dogPos.x = tx;
//            dogPos.z = tz;
//        }
//    }
//    break;
//    }
//
//    // Clamp suave para no salir del piso
//    if (dogPos.x < FLOOR_MIN_X + SAFE_MARGIN) dogPos.x = FLOOR_MIN_X + SAFE_MARGIN;
//    if (dogPos.x > FLOOR_MAX_X - SAFE_MARGIN) dogPos.x = FLOOR_MAX_X - SAFE_MARGIN;
//    if (dogPos.z < FLOOR_MIN_Z + SAFE_MARGIN) dogPos.z = FLOOR_MIN_Z + SAFE_MARGIN;
//    if (dogPos.z > FLOOR_MAX_Z - SAFE_MARGIN) dogPos.z = FLOOR_MAX_Z - SAFE_MARGIN;
//
//    // Normaliza el ángulo
//    if (dogRot >= 360.0f) dogRot -= 360.0f;
//    if (dogRot < 0.0f)    dogRot += 360.0f;
//}
//
//void MouseCallback(GLFWwindow* window, double xPos, double yPos)
//{
//    if (firstMouse)
//    {
//        lastX = static_cast<float>(xPos);
//        lastY = static_cast<float>(yPos);
//        firstMouse = false;
//    }
//
//    GLfloat xOffset = static_cast<float>(xPos) - lastX;
//    GLfloat yOffset = lastY - static_cast<float>(yPos);
//
//    lastX = static_cast<float>(xPos);
//    lastY = static_cast<float>(yPos);
//
//    camera.ProcessMouseMovement(xOffset, yOffset);
//}
//
// 
// 
//#include <iostream>
//#include <cmath>
//
// // GLEW
//#include <GL/glew.h>
//
//// GLFW
//#include <GLFW/glfw3.h>
//
//// Other Libs
//#include "stb_image.h"
//
//// GLM Mathematics
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
////Load Models
//#include "SOIL2/SOIL2.h"
//
//// Other includes
//#include "Shader.h"
//#include "Camera.h"
//#include "Model.h"
//
//// Function prototypes
//void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
//void MouseCallback(GLFWwindow* window, double xPos, double yPos);
//void DoMovement();
//void Animation();
//
//// Window dimensions
//const GLuint WIDTH = 800, HEIGHT = 600;
//int SCREEN_WIDTH, SCREEN_HEIGHT;
//
//// Camera
//Camera  camera(glm::vec3(0.0f, 0.0f, 3.0f));
//GLfloat lastX = WIDTH / 2.0f;
//GLfloat lastY = HEIGHT / 2.0f;
//bool keys[1024];
//bool firstMouse = true;
//// Light attributes
//glm::vec3 lightPos(0.0f, 0.0f, 0.0f);
//bool active;
//
//// Positions of the point lights
//glm::vec3 pointLightPositions[] = {
//    glm::vec3(0.0f,2.0f, 0.0f),
//    glm::vec3(0.0f,0.0f, 0.0f),
//    glm::vec3(0.0f,0.0f,  0.0f),
//    glm::vec3(0.0f,0.0f, 0.0f)
//};
//
//float vertices[] = {
//       -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//        0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//        0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//        0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//       -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//       -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//
//       -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//        0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//        0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//        0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//       -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//       -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//
//       -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//
//        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//        0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//        0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//        0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//
//       -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//        0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//        0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//        0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//       -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//       -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//
//       -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//        0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//        0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//        0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//       -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//       -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
//};
//
//glm::vec3 Light1 = glm::vec3(0);
////Anim
//float rotBall = 0.0f;
//bool AnimBall = false;
//bool AnimDog = false;
//float rotDog = 0.0f;
//int dogAnim = 0;
//float FLegs = 0.0f;
//float RLegs = 0.0f;
//float head = 0.0f;
//float tail = 0.0f;
//glm::vec3 dogPos(0.0f, 0.0f, 0.0f);
//float dogRot = 0.0f;
//bool step = false;
//
//// ------------------- Límites del piso y máquina de estados -------------------
//const float FLOOR_MIN_X = -2.0f;
//const float FLOOR_MAX_X = 2.0f;
//const float FLOOR_MIN_Z = -2.0f;
//const float FLOOR_MAX_Z = 2.0f;
//const float SAFE_MARGIN = 0.15f;
//
//// --- Centro del piso y tolerancia (previo) ---
//const float CENTER_X = 0.0f;
//const float CENTER_Z = 0.0f;
//const float CENTER_EPS = 0.05f; // distancia mínima para considerar "llegó al centro"
//
//// Velocidades (MÁS LENTAS)
//const float DOG_WALK_SPEED = 0.25f;  // antes 0.6f
//const float DOG_TURN_SPEED = 45.0f;  // antes 90.0f
//
//// Máquina de estados del perro (extendida)
//enum DogState {
//    IDLE = 0,
//    WALK_FWD,        // +Z
//    TURN_RIGHT_1,    // +90° horario
//    WALK_RIGHT,      // +X
//    TURN_RIGHT_2,    // +90° horario
//    WALK_BACK,       // -Z
//    TURN_LEFT_CCW,   // (nombre heredado)
//    WALK_DIAG_CENTER, // usar para ir al centro y DETENERSE+GIRAR
//    TURN_45_CW,
//    WALK_STRAIGHT_45
//};
//DogState dogState = IDLE;
//float dogTargetRot = 0.0f; // destino del giro en grados
//// -----------------------------------------------------------------------------
//
//// Deltatime
//GLfloat deltaTime = 0.0f;
//GLfloat lastFrame = 0.0f;
//
//int main()
//{
//    // Init GLFW
//    glfwInit();
//
//    // Window
//    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Animacion maquina de estados", nullptr, nullptr);
//    if (nullptr == window) {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return EXIT_FAILURE;
//    }
//    glfwMakeContextCurrent(window);
//    glfwGetFramebufferSize(window, &SCREEN_WIDTH, &SCREEN_HEIGHT);
//
//    // Callbacks
//    glfwSetKeyCallback(window, KeyCallback);
//    glfwSetCursorPosCallback(window, MouseCallback);
//
//    // GLEW
//    glewExperimental = GL_TRUE;
//    if (GLEW_OK != glewInit()) {
//        std::cout << "Failed to initialize GLEW" << std::endl;
//        return EXIT_FAILURE;
//    }
//
//    // Viewport
//    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
//
//    Shader lightingShader("Shader/lighting.vs", "Shader/lighting.frag");
//    Shader lampShader("Shader/lamp.vs", "Shader/lamp.frag");
//
//    // Models
//    Model DogBody((char*)"Models/DogBody.obj");
//    Model HeadDog((char*)"Models/HeadDog.obj");
//    Model DogTail((char*)"Models/TailDog.obj");
//    Model F_RightLeg((char*)"Models/F_RightLegDog.obj");
//    Model F_LeftLeg((char*)"Models/F_LeftLegDog.obj");
//    Model B_RightLeg((char*)"Models/B_RightLegDog.obj");
//    Model B_LeftLeg((char*)"Models/B_LeftLegDog.obj");
//    Model Piso((char*)"Models/piso.obj");
//    Model Ball((char*)"Models/ball.obj");
//
//    // VAO/VBO
//    GLuint VBO, VAO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//    glBindVertexArray(VAO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//    // Position
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
//    glEnableVertexAttribArray(0);
//    // Normal
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//
//    // Material samplers
//    lightingShader.Use();
//    glUniform1i(glGetUniformLocation(lightingShader.Program, "Material.difuse"), 0);
//    glUniform1i(glGetUniformLocation(lightingShader.Program, "Material.specular"), 1);
//
//    glm::mat4 projection = glm::perspective(
//        camera.GetZoom(),
//        (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT,
//        0.1f, 100.0f
//    );
//
//    // Game loop
//    while (!glfwWindowShouldClose(window))
//    {
//        // Delta time
//        GLfloat currentFrame = static_cast<float>(glfwGetTime());
//        deltaTime = currentFrame - lastFrame;
//        lastFrame = currentFrame;
//
//        // Input + anim
//        glfwPollEvents();
//        DoMovement();
//        Animation();
//
//        // Clear
//        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        glEnable(GL_DEPTH_TEST);
//
//        // ==== DRAW ====
//        glm::mat4 model;
//        glm::mat4 view = camera.GetViewMatrix();
//        glm::mat4 modelTemp = glm::mat4(1.0f); // una sola vez por frame
//
//        lightingShader.Use();
//
//        glUniform1i(glGetUniformLocation(lightingShader.Program, "diffuse"), 0);
//
//        GLint viewPosLoc = glGetUniformLocation(lightingShader.Program, "viewPos");
//        glUniform3f(viewPosLoc, camera.GetPosition().x, camera.GetPosition().y, camera.GetPosition().z);
//
//        // Dir light
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.direction"), -0.2f, -1.0f, -0.3f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.ambient"), 0.6f, 0.6f, 0.6f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.diffuse"), 0.6f, 0.6f, 0.6f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.specular"), 0.3f, 0.3f, 0.3f);
//
//        // Point light anim
//        glm::vec3 lightColor;
//        lightColor.x = fabsf(sinf(glfwGetTime() * Light1.x));
//        lightColor.y = fabsf(sinf(glfwGetTime() * Light1.y));
//        lightColor.z = sinf(glfwGetTime() * Light1.z);
//
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].position"),
//            pointLightPositions[0].x, pointLightPositions[0].y, pointLightPositions[0].z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].ambient"),
//            lightColor.x, lightColor.y, lightColor.z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].diffuse"),
//            lightColor.x, lightColor.y, lightColor.z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].specular"),
//            1.0f, 0.2f, 0.2f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[0].constant"), 1.0f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[0].linear"), 0.045f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[0].quadratic"), 0.075f);
//
//        // Spotlight (cámara)
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.position"),
//            camera.GetPosition().x, camera.GetPosition().y, camera.GetPosition().z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.direction"),
//            camera.GetFront().x, camera.GetFront().y, camera.GetFront().z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.ambient"), 0.2f, 0.2f, 0.8f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.diffuse"), 0.2f, 0.2f, 0.8f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.specular"), 0.0f, 0.0f, 0.0f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.constant"), 1.0f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.linear"), 0.3f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.quadratic"), 0.7f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.cutOff"), glm::cos(glm::radians(12.0f)));
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.outerCutOff"), glm::cos(glm::radians(18.0f)));
//
//        // Material
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "material.shininess"), 5.0f);
//
//        // Matrices
//        GLint modelLoc = glGetUniformLocation(lightingShader.Program, "model");
//        GLint viewLoc = glGetUniformLocation(lightingShader.Program, "view");
//        GLint projLoc = glGetUniformLocation(lightingShader.Program, "projection");
//        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
//
//        // --- Piso ---
//        model = glm::mat4(1.0f);
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        Piso.Draw(lightingShader);
//
//        // --- Perro ---
//        model = glm::mat4(1.0f);
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        glUniform1i(glGetUniformLocation(lightingShader.Program, "transparency"), 0);
//
//        // Body
//        model = glm::translate(model, dogPos);
//        model = glm::rotate(model, glm::radians(dogRot), glm::vec3(0.0f, 1.0f, 0.0f));
//        modelTemp = model; // base
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        DogBody.Draw(lightingShader);
//
//        // Head
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(0.0f, 0.093f, 0.208f));
//        model = glm::rotate(model, glm::radians(head), glm::vec3(0.0f, 0.0f, 1.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        HeadDog.Draw(lightingShader);
//
//        // Tail 
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(0.0f, 0.026f, -0.288f));
//        model = glm::rotate(model, glm::radians(tail), glm::vec3(0.0f, 0.0f, -1.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        DogTail.Draw(lightingShader);
//
//        // Front Left Leg
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(0.112f, -0.044f, 0.074f));
//        model = glm::rotate(model, glm::radians(FLegs), glm::vec3(-1.0f, 0.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        F_LeftLeg.Draw(lightingShader);
//
//        // Front Right Leg
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(-0.111f, -0.055f, 0.074f));
//        model = glm::rotate(model, glm::radians(FLegs), glm::vec3(1.0f, 0.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        F_RightLeg.Draw(lightingShader);
//
//        // Back Left Leg
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(0.082f, -0.046f, -0.218f));
//        model = glm::rotate(model, glm::radians(RLegs), glm::vec3(1.0f, 0.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        B_LeftLeg.Draw(lightingShader);
//
//        // Back Right Leg
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(-0.083f, -0.057f, -0.231f));
//        model = glm::rotate(model, glm::radians(RLegs), glm::vec3(-1.0f, 0.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        B_RightLeg.Draw(lightingShader);
//
//        // --- Pelota ---
//        model = glm::mat4(1.0f);
//        glEnable(GL_BLEND);
//        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        glUniform1i(glGetUniformLocation(lightingShader.Program, "transparency"), 1);
//        model = glm::rotate(model, glm::radians(rotBall), glm::vec3(0.0f, 1.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        Ball.Draw(lightingShader);
//        glDisable(GL_BLEND);
//        glBindVertexArray(0);
//
//        // --- Lámpara ---
//        lampShader.Use();
//        modelLoc = glGetUniformLocation(lampShader.Program, "model");
//        GLint viewLoc2 = glGetUniformLocation(lampShader.Program, "view");
//        GLint projLoc2 = glGetUniformLocation(lampShader.Program, "projection");
//        glUniformMatrix4fv(viewLoc2, 1, GL_FALSE, glm::value_ptr(view));
//        glUniformMatrix4fv(projLoc2, 1, GL_FALSE, glm::value_ptr(projection));
//
//        model = glm::mat4(1.0f);
//        model = glm::translate(model, lightPos);
//        model = glm::scale(model, glm::vec3(0.2f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//
//        model = glm::mat4(1.0f);
//        model = glm::translate(model, pointLightPositions[0]);
//        model = glm::scale(model, glm::vec3(0.2f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        glBindVertexArray(VAO);
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//        glBindVertexArray(0);
//
//        // Swap
//        glfwSwapBuffers(window);
//    }
//
//    glfwTerminate();
//    return 0;
//}
//
//// Moves/alters the camera positions based on user input
//void DoMovement()
//{
//    if (keys[GLFW_KEY_W] || keys[GLFW_KEY_UP])    camera.ProcessKeyboard(FORWARD, deltaTime);
//    if (keys[GLFW_KEY_S] || keys[GLFW_KEY_DOWN])  camera.ProcessKeyboard(BACKWARD, deltaTime);
//    if (keys[GLFW_KEY_A] || keys[GLFW_KEY_LEFT])  camera.ProcessKeyboard(LEFT, deltaTime);
//    if (keys[GLFW_KEY_D] || keys[GLFW_KEY_RIGHT]) camera.ProcessKeyboard(RIGHT, deltaTime);
//
//    if (keys[GLFW_KEY_T]) { pointLightPositions[0].x += 0.01f; }
//    if (keys[GLFW_KEY_G]) { pointLightPositions[0].x -= 0.01f; }
//    if (keys[GLFW_KEY_Y]) { pointLightPositions[0].y += 0.01f; }
//    if (keys[GLFW_KEY_H]) { pointLightPositions[0].y -= 0.01f; }
//    if (keys[GLFW_KEY_U]) { pointLightPositions[0].z -= 0.1f; }
//    if (keys[GLFW_KEY_J]) { pointLightPositions[0].z += 0.01f; }
//}
//
//// Is called whenever a key is pressed/released via GLFW
//void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//    if (GLFW_KEY_ESCAPE == key && GLFW_PRESS == action) {
//        glfwSetWindowShouldClose(window, GL_TRUE);
//    }
//
//    if (key >= 0 && key < 1024) {
//        if (action == GLFW_PRESS)      keys[key] = true;
//        else if (action == GLFW_RELEASE) keys[key] = false;
//    }
//
//    if (keys[GLFW_KEY_SPACE]) {
//        active = !active;
//        Light1 = active ? glm::vec3(0.2f, 0.8f, 1.0f) : glm::vec3(0.0f);
//    }
//    if (keys[GLFW_KEY_N]) {
//        AnimBall = !AnimBall;
//    }
//    if (keys[GLFW_KEY_B]) {
//        dogAnim = 1;
//        // ARRANQUE: ir al centro; allí se detendrá y girará a +Z, luego seguirá de frente
//        dogState = WALK_DIAG_CENTER;
//    }
//}
//
//void Animation() {
//    // Bola
//    if (AnimBall) {
//        rotBall += 0.4f;
//    }
//
//    // Rotación libre del perro (si la usas)
//    if (AnimDog) {
//        rotDog -= 0.6f;
//    }
//
//    // Animación cíclica de patas / cabeza / cola
//    if (dogAnim == 1) {
//        if (!step) {
//            RLegs += 0.3f; FLegs += 0.3f; head += 0.3f; tail += 0.3f;
//            if (RLegs > 15.0f) step = true;
//        }
//        else {
//            RLegs -= 0.3f; FLegs -= 0.3f; head -= 0.3f; tail -= 0.3f;
//            if (RLegs < -15.0f) step = false;
//        }
//    }
//
//    // Movimiento con límites y giros
//    float moveStep = DOG_WALK_SPEED * deltaTime; // unidades/s
//    float turnStep = DOG_TURN_SPEED * deltaTime; // grados/s
//
//    switch (dogState) {
//    case IDLE:
//        break;
//
//        // +Z hasta orilla frontal
//    case WALK_FWD:
//        dogPos.z += moveStep;
//        if (dogPos.z >= (FLOOR_MAX_Z - SAFE_MARGIN)) {
//            dogPos.z = (FLOOR_MAX_Z - SAFE_MARGIN);
//            dogState = TURN_RIGHT_1;
//            dogTargetRot = dogRot + 90.0f; // giro horario
//        }
//        break;
//
//        // Primer giro horario (+90)
//    case TURN_RIGHT_1:
//        if (dogRot < dogTargetRot) {
//            dogRot += turnStep;
//            if (dogRot > dogTargetRot) dogRot = dogTargetRot;
//        }
//        if (dogRot == dogTargetRot) {
//            dogState = WALK_RIGHT; // caminar a +X
//        }
//        break;
//
//        // +X hasta orilla derecha
//    case WALK_RIGHT:
//        dogPos.x += moveStep;
//        if (dogPos.x >= (FLOOR_MAX_X - SAFE_MARGIN)) {
//            dogPos.x = (FLOOR_MAX_X - SAFE_MARGIN);
//            dogState = TURN_RIGHT_2;
//            dogTargetRot = dogRot + 90.0f; // segundo giro horario
//        }
//        break;
//
//        // Segundo giro horario (+90) => queda apuntando a -Z
//    case TURN_RIGHT_2:
//        if (dogRot < dogTargetRot) {
//            dogRot += turnStep;
//            if (dogRot > dogTargetRot) dogRot = dogTargetRot;
//        }
//        if (dogRot == dogTargetRot) {
//            dogState = WALK_BACK; // seguir caminando hacia -Z
//        }
//        break;
//
//        // -Z hasta la orilla trasera
//    case WALK_BACK:
//        dogPos.z -= moveStep;
//        if (dogPos.z <= (FLOOR_MIN_Z + SAFE_MARGIN)) {
//            dogPos.z = (FLOOR_MIN_Z + SAFE_MARGIN);
//            dogState = TURN_LEFT_CCW;
//            // (histórico) último giro horario
//            dogTargetRot = dogRot + 90.0f; // horario
//        }
//        break;
//
//        // Último giro (horario). Mantengo flujo existente.
//    case TURN_LEFT_CCW:
//        if (dogRot < dogTargetRot) {
//            dogRot += turnStep;
//            if (dogRot > dogTargetRot) dogRot = dogTargetRot;
//        }
//        if (dogRot == dogTargetRot) {
//            // En el flujo original, continúa con giro 45°
//            dogTargetRot = dogRot + 45.0f;
//            if (dogTargetRot >= 360.0f) dogTargetRot -= 360.0f;
//            dogState = TURN_45_CW;
//        }
//        break;
//
//    case TURN_45_CW:
//        if (dogRot < dogTargetRot) {
//            dogRot += turnStep;
//            if (dogRot > dogTargetRot) dogRot = dogTargetRot;
//        }
//        if (dogRot == dogTargetRot) {
//            dogState = WALK_STRAIGHT_45; // avanzar recto con el nuevo rumbo
//        }
//        break;
//
//    case WALK_STRAIGHT_45:
//    {
//        float yaw = glm::radians(dogRot);
//        float dirX = sinf(yaw);
//        float dirZ = cosf(yaw);
//
//        float nx = dogPos.x + dirX * moveStep;
//        float nz = dogPos.z + dirZ * moveStep;
//
//        bool hitEdge = false;
//        if (nx < FLOOR_MIN_X + SAFE_MARGIN) { nx = FLOOR_MIN_X + SAFE_MARGIN; hitEdge = true; }
//        if (nx > FLOOR_MAX_X - SAFE_MARGIN) { nx = FLOOR_MAX_X - SAFE_MARGIN; hitEdge = true; }
//        if (nz < FLOOR_MIN_Z + SAFE_MARGIN) { nz = FLOOR_MIN_Z + SAFE_MARGIN; hitEdge = true; }
//        if (nz > FLOOR_MAX_Z - SAFE_MARGIN) { nz = FLOOR_MAX_Z - SAFE_MARGIN; hitEdge = true; }
//
//        dogPos.x = nx;
//        dogPos.z = nz;
//
//        if (hitEdge) {
//            dogState = IDLE;
//        }
//    }
//    break;
//
//    // **USO ESPECIAL**: ir al centro, DETENERSE, GIRAR a +Z y luego caminar al frente
//    case WALK_DIAG_CENTER:
//    {
//        // Rotación suave hacia el dogTargetRot (mantengo esta parte)
//        float diffR = dogTargetRot - dogRot;
//        while (diffR > 180.0f) diffR -= 360.0f;
//        while (diffR < -180.0f) diffR += 360.0f;
//
//        if (fabsf(diffR) > 0.01f) {
//            float stepR = (diffR > 0.0f ? +turnStep : -turnStep);
//            if (fabsf(stepR) > fabsf(diffR)) stepR = diffR;
//            dogRot += stepR;
//            if (dogRot >= 360.0f) dogRot -= 360.0f;
//            if (dogRot < 0.0f)    dogRot += 360.0f;
//        }
//
//        // Avance hacia el centro (diagonal)
//        float dx = CENTER_X - dogPos.x;
//        float dz = CENTER_Z - dogPos.z;
//        float dist = sqrtf(dx * dx + dz * dz);
//
//        if (dist <= CENTER_EPS) {
//            // 1) Llega al centro y se DETIENE
//            dogPos.x = CENTER_X;
//            dogPos.z = CENTER_Z;
//
//            // 2) GIRA EN EL LUGAR hasta mirar +Z (0°)
//            float diff = 0.0f - dogRot;
//            while (diff > 180.0f) diff -= 360.0f;
//            while (diff < -180.0f) diff += 360.0f;
//
//            if (fabsf(diff) > 0.5f) {
//                float step = (diff > 0.0f ? +turnStep : -turnStep);
//                if (fabsf(step) > fabsf(diff)) step = diff;
//                dogRot += step;
//                if (dogRot >= 360.0f) dogRot -= 360.0f;
//                if (dogRot < 0.0f)    dogRot += 360.0f;
//                // Se queda en este estado hasta terminar de girar (parado en centro)
//            }
//            else {
//                // 3) Ya mirando al +Z: comenzar a caminar de frente
//                dogRot = 0.0f;
//                dogState = WALK_FWD;
//            }
//        }
//        else {
//            float nx = dx / dist;
//            float nz = dz / dist;
//            float stepMove = moveStep;
//            if (stepMove > dist) stepMove = dist; // no pasarse
//
//            float tx = dogPos.x + nx * stepMove;
//            float tz = dogPos.z + nz * stepMove;
//
//            if (tx < FLOOR_MIN_X + SAFE_MARGIN) tx = FLOOR_MIN_X + SAFE_MARGIN;
//            if (tx > FLOOR_MAX_X - SAFE_MARGIN) tx = FLOOR_MAX_X - SAFE_MARGIN;
//            if (tz < FLOOR_MIN_Z + SAFE_MARGIN) tz = FLOOR_MIN_Z + SAFE_MARGIN;
//            if (tz > FLOOR_MAX_Z - SAFE_MARGIN) tz = FLOOR_MAX_Z - SAFE_MARGIN;
//
//            dogPos.x = tx;
//            dogPos.z = tz;
//        }
//    }
//    break;
//    }
//
//    // Clamp suave para no salir del piso
//    if (dogPos.x < FLOOR_MIN_X + SAFE_MARGIN) dogPos.x = FLOOR_MIN_X + SAFE_MARGIN;
//    if (dogPos.x > FLOOR_MAX_X - SAFE_MARGIN) dogPos.x = FLOOR_MAX_X - SAFE_MARGIN;
//    if (dogPos.z < FLOOR_MIN_Z + SAFE_MARGIN) dogPos.z = FLOOR_MIN_Z + SAFE_MARGIN;
//    if (dogPos.z > FLOOR_MAX_Z - SAFE_MARGIN) dogPos.z = FLOOR_MAX_Z - SAFE_MARGIN;
//
//    // Normaliza el ángulo
//    if (dogRot >= 360.0f) dogRot -= 360.0f;
//    if (dogRot < 0.0f)    dogRot += 360.0f;
//}
//
//void MouseCallback(GLFWwindow* window, double xPos, double yPos)
//{
//    if (firstMouse)
//    {
//        lastX = static_cast<float>(xPos);
//        lastY = static_cast<float>(yPos);
//        firstMouse = false;
//    }
//
//    GLfloat xOffset = static_cast<float>(xPos) - lastX;
//    GLfloat yOffset = lastY - static_cast<float>(yPos);
//
//    lastX = static_cast<float>(xPos);
//    lastY = static_cast<float>(yPos);
//
//    camera.ProcessMouseMovement(xOffset, yOffset);
//}
//
//
//
//
//#include <iostream>
//#include <cmath>
//
// // GLEW
//#include <GL/glew.h>
//
//// GLFW
//#include <GLFW/glfw3.h>
//
//// Other Libs
//#include "stb_image.h"
//
//// GLM Mathematics
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
////Load Models
//#include "SOIL2/SOIL2.h"
//
//// Other includes
//#include "Shader.h"
//#include "Camera.h"
//#include "Model.h"
//
//// Function prototypes
//void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
//void MouseCallback(GLFWwindow* window, double xPos, double yPos);
//void DoMovement();
//void Animation();
//
//// Window dimensions
//const GLuint WIDTH = 800, HEIGHT = 600;
//int SCREEN_WIDTH, SCREEN_HEIGHT;
//
//// Camera
//Camera  camera(glm::vec3(0.0f, 0.0f, 3.0f));
//GLfloat lastX = WIDTH / 2.0f;
//GLfloat lastY = HEIGHT / 2.0f;
//bool keys[1024];
//bool firstMouse = true;
//// Light attributes
//glm::vec3 lightPos(0.0f, 0.0f, 0.0f);
//bool active;
//
//// Positions of the point lights
//glm::vec3 pointLightPositions[] = {
//    glm::vec3(0.0f,2.0f, 0.0f),
//    glm::vec3(0.0f,0.0f, 0.0f),
//    glm::vec3(0.0f,0.0f,  0.0f),
//    glm::vec3(0.0f,0.0f, 0.0f)
//};
//
//float vertices[] = {
//       -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//        0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//        0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//        0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//       -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//       -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//
//       -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//        0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//        0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//        0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//       -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//       -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//
//       -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//
//        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//        0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//        0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//        0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//
//       -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//        0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//        0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//        0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//       -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//       -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//
//       -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//        0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//        0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//        0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//       -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//       -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
//};
//
//glm::vec3 Light1 = glm::vec3(0);
////Anim
//float rotBall = 0.0f;
//bool AnimBall = false;
//bool AnimDog = false;
//float rotDog = 0.0f;
//int dogAnim = 0;
//float FLegs = 0.0f;
//float RLegs = 0.0f;
//float head = 0.0f;
//float tail = 0.0f;
//glm::vec3 dogPos(0.0f, 0.0f, 0.0f);
//float dogRot = 0.0f;
//bool step = false;
//
//// ------------------- Límites del piso y máquina de estados -------------------
//const float FLOOR_MIN_X = -2.0f;
//const float FLOOR_MAX_X = 2.0f;
//const float FLOOR_MIN_Z = -2.0f;
//const float FLOOR_MAX_Z = 2.0f;
//const float SAFE_MARGIN = 0.15f;
//
//// --- Centro del piso y tolerancia (previo) ---
//const float CENTER_X = 0.0f;
//const float CENTER_Z = 0.0f;
//const float CENTER_EPS = 0.05f; // distancia mínima para considerar "llegó al centro"
//
//// Velocidades (MÁS LENTAS)
//const float DOG_WALK_SPEED = 0.25f;  // antes 0.6f
//const float DOG_TURN_SPEED = 45.0f;  // antes 90.0f
//
//// Máquina de estados del perro (extendida)
//enum DogState {
//    IDLE = 0,
//    WALK_FWD,        // +Z
//    TURN_RIGHT_1,    // +90° horario
//    WALK_RIGHT,      // +X
//    TURN_RIGHT_2,    // +90° horario
//    WALK_BACK,       // -Z
//    TURN_LEFT_CCW,   // (nombre heredado)
//    WALK_DIAG_CENTER, // ir al centro, PAUSAR, GIRAR a +Z y continuar al frente
//    TURN_45_CW,
//    WALK_STRAIGHT_45
//};
//DogState dogState = IDLE;
//float dogTargetRot = 0.0f; // destino del giro en grados
//
//// ------------------- Pausa visible en el centro -------------------
//bool waitAtCenter = false;
//float waitAccum = 0.0f;
//const float CENTER_WAIT_SECONDS = 1.0f; // 1 segundo de pausa visible
//// -----------------------------------------------------------------------------
//
//// Deltatime
//GLfloat deltaTime = 0.0f;
//GLfloat lastFrame = 0.0f;
//
//int main()
//{
//    // Init GLFW
//    glfwInit();
//
//    // Window
//    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Animacion maquina de estados", nullptr, nullptr);
//    if (nullptr == window) {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return EXIT_FAILURE;
//    }
//    glfwMakeContextCurrent(window);
//    glfwGetFramebufferSize(window, &SCREEN_WIDTH, &SCREEN_HEIGHT);
//
//    // Callbacks
//    glfwSetKeyCallback(window, KeyCallback);
//    glfwSetCursorPosCallback(window, MouseCallback);
//
//    // GLEW
//    glewExperimental = GL_TRUE;
//    if (GLEW_OK != glewInit()) {
//        std::cout << "Failed to initialize GLEW" << std::endl;
//        return EXIT_FAILURE;
//    }
//
//    // Viewport
//    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
//
//    Shader lightingShader("Shader/lighting.vs", "Shader/lighting.frag");
//    Shader lampShader("Shader/lamp.vs", "Shader/lamp.frag");
//
//    // Models
//    Model DogBody((char*)"Models/DogBody.obj");
//    Model HeadDog((char*)"Models/HeadDog.obj");
//    Model DogTail((char*)"Models/TailDog.obj");
//    Model F_RightLeg((char*)"Models/F_RightLegDog.obj");
//    Model F_LeftLeg((char*)"Models/F_LeftLegDog.obj");
//    Model B_RightLeg((char*)"Models/B_RightLegDog.obj");
//    Model B_LeftLeg((char*)"Models/B_LeftLegDog.obj");
//    Model Piso((char*)"Models/piso.obj");
//    Model Ball((char*)"Models/ball.obj");
//
//    // VAO/VBO
//    GLuint VBO, VAO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//    glBindVertexArray(VAO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//    // Position
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
//    glEnableVertexAttribArray(0);
//    // Normal
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//
//    // Material samplers
//    lightingShader.Use();
//    glUniform1i(glGetUniformLocation(lightingShader.Program, "Material.difuse"), 0);
//    glUniform1i(glGetUniformLocation(lightingShader.Program, "Material.specular"), 1);
//
//    glm::mat4 projection = glm::perspective(
//        camera.GetZoom(),
//        (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT,
//        0.1f, 100.0f
//    );
//
//    // Game loop
//    while (!glfwWindowShouldClose(window))
//    {
//        // Delta time
//        GLfloat currentFrame = static_cast<float>(glfwGetTime());
//        deltaTime = currentFrame - lastFrame;
//        lastFrame = currentFrame;
//
//        // Input + anim
//        glfwPollEvents();
//        DoMovement();
//        Animation();
//
//        // Clear
//        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        glEnable(GL_DEPTH_TEST);
//
//        // ==== DRAW ====
//        glm::mat4 model;
//        glm::mat4 view = camera.GetViewMatrix();
//        glm::mat4 modelTemp = glm::mat4(1.0f); // una sola vez por frame
//
//        lightingShader.Use();
//
//        glUniform1i(glGetUniformLocation(lightingShader.Program, "diffuse"), 0);
//
//        GLint viewPosLoc = glGetUniformLocation(lightingShader.Program, "viewPos");
//        glUniform3f(viewPosLoc, camera.GetPosition().x, camera.GetPosition().y, camera.GetPosition().z);
//
//        // Dir light
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.direction"), -0.2f, -1.0f, -0.3f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.ambient"), 0.6f, 0.6f, 0.6f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.diffuse"), 0.6f, 0.6f, 0.6f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.specular"), 0.3f, 0.3f, 0.3f);
//
//        // Point light anim
//        glm::vec3 lightColor;
//        lightColor.x = fabsf(sinf(glfwGetTime() * Light1.x));
//        lightColor.y = fabsf(sinf(glfwGetTime() * Light1.y));
//        lightColor.z = sinf(glfwGetTime() * Light1.z);
//
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].position"),
//            pointLightPositions[0].x, pointLightPositions[0].y, pointLightPositions[0].z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].ambient"),
//            lightColor.x, lightColor.y, lightColor.z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].diffuse"),
//            lightColor.x, lightColor.y, lightColor.z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].specular"),
//            1.0f, 0.2f, 0.2f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[0].constant"), 1.0f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[0].linear"), 0.045f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[0].quadratic"), 0.075f);
//
//        // Spotlight (cámara)
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.position"),
//            camera.GetPosition().x, camera.GetPosition().y, camera.GetPosition().z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.direction"),
//            camera.GetFront().x, camera.GetFront().y, camera.GetFront().z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.ambient"), 0.2f, 0.2f, 0.8f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.diffuse"), 0.2f, 0.2f, 0.8f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.specular"), 0.0f, 0.0f, 0.0f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.constant"), 1.0f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.linear"), 0.3f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.quadratic"), 0.7f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.cutOff"), glm::cos(glm::radians(12.0f)));
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.outerCutOff"), glm::cos(glm::radians(18.0f)));
//
//        // Material
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "material.shininess"), 5.0f);
//
//        // Matrices
//        GLint modelLoc = glGetUniformLocation(lightingShader.Program, "model");
//        GLint viewLoc = glGetUniformLocation(lightingShader.Program, "view");
//        GLint projLoc = glGetUniformLocation(lightingShader.Program, "projection");
//        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
//
//        // --- Piso ---
//        model = glm::mat4(1.0f);
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        Piso.Draw(lightingShader);
//
//        // --- Perro ---
//        model = glm::mat4(1.0f);
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        glUniform1i(glGetUniformLocation(lightingShader.Program, "transparency"), 0);
//
//        // Body
//        model = glm::translate(model, dogPos);
//        model = glm::rotate(model, glm::radians(dogRot), glm::vec3(0.0f, 1.0f, 0.0f));
//        modelTemp = model; // base
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        DogBody.Draw(lightingShader);
//
//        // Head
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(0.0f, 0.093f, 0.208f));
//        model = glm::rotate(model, glm::radians(head), glm::vec3(0.0f, 0.0f, 1.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        HeadDog.Draw(lightingShader);
//
//        // Tail 
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(0.0f, 0.026f, -0.288f));
//        model = glm::rotate(model, glm::radians(tail), glm::vec3(0.0f, 0.0f, -1.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        DogTail.Draw(lightingShader);
//
//        // Front Left Leg
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(0.112f, -0.044f, 0.074f));
//        model = glm::rotate(model, glm::radians(FLegs), glm::vec3(-1.0f, 0.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        F_LeftLeg.Draw(lightingShader);
//
//        // Front Right Leg
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(-0.111f, -0.055f, 0.074f));
//        model = glm::rotate(model, glm::radians(FLegs), glm::vec3(1.0f, 0.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        F_RightLeg.Draw(lightingShader);
//
//        // Back Left Leg
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(0.082f, -0.046f, -0.218f));
//        model = glm::rotate(model, glm::radians(RLegs), glm::vec3(1.0f, 0.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        B_LeftLeg.Draw(lightingShader);
//
//        // Back Right Leg
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(-0.083f, -0.057f, -0.231f));
//        model = glm::rotate(model, glm::radians(RLegs), glm::vec3(-1.0f, 0.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        B_RightLeg.Draw(lightingShader);
//
//        // --- Pelota ---
//        model = glm::mat4(1.0f);
//        glEnable(GL_BLEND);
//        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        glUniform1i(glGetUniformLocation(lightingShader.Program, "transparency"), 1);
//        model = glm::rotate(model, glm::radians(rotBall), glm::vec3(0.0f, 1.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        Ball.Draw(lightingShader);
//        glDisable(GL_BLEND);
//        glBindVertexArray(0);
//
//        // --- Lámpara ---
//        lampShader.Use();
//        modelLoc = glGetUniformLocation(lampShader.Program, "model");
//        GLint viewLoc2 = glGetUniformLocation(lampShader.Program, "view");
//        GLint projLoc2 = glGetUniformLocation(lampShader.Program, "projection");
//        glUniformMatrix4fv(viewLoc2, 1, GL_FALSE, glm::value_ptr(view));
//        glUniformMatrix4fv(projLoc2, 1, GL_FALSE, glm::value_ptr(projection));
//
//        model = glm::mat4(1.0f);
//        model = glm::translate(model, lightPos);
//        model = glm::scale(model, glm::vec3(0.2f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//
//        model = glm::mat4(1.0f);
//        model = glm::translate(model, pointLightPositions[0]);
//        model = glm::scale(model, glm::vec3(0.2f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        glBindVertexArray(VAO);
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//        glBindVertexArray(0);
//
//        // Swap
//        glfwSwapBuffers(window);
//    }
//
//    glfwTerminate();
//    return 0;
//}
//
//// Moves/alters the camera positions based on user input
//void DoMovement()
//{
//    if (keys[GLFW_KEY_W] || keys[GLFW_KEY_UP])    camera.ProcessKeyboard(FORWARD, deltaTime);
//    if (keys[GLFW_KEY_S] || keys[GLFW_KEY_DOWN])  camera.ProcessKeyboard(BACKWARD, deltaTime);
//    if (keys[GLFW_KEY_A] || keys[GLFW_KEY_LEFT])  camera.ProcessKeyboard(LEFT, deltaTime);
//    if (keys[GLFW_KEY_D] || keys[GLFW_KEY_RIGHT]) camera.ProcessKeyboard(RIGHT, deltaTime);
//
//    if (keys[GLFW_KEY_T]) { pointLightPositions[0].x += 0.01f; }
//    if (keys[GLFW_KEY_G]) { pointLightPositions[0].x -= 0.01f; }
//    if (keys[GLFW_KEY_Y]) { pointLightPositions[0].y += 0.01f; }
//    if (keys[GLFW_KEY_H]) { pointLightPositions[0].y -= 0.01f; }
//    if (keys[GLFW_KEY_U]) { pointLightPositions[0].z -= 0.1f; }
//    if (keys[GLFW_KEY_J]) { pointLightPositions[0].z += 0.01f; }
//}
//
//// Is called whenever a key is pressed/released via GLFW
//void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//    if (GLFW_KEY_ESCAPE == key && GLFW_PRESS == action) {
//        glfwSetWindowShouldClose(window, GL_TRUE);
//    }
//
//    if (key >= 0 && key < 1024) {
//        if (action == GLFW_PRESS)      keys[key] = true;
//        else if (action == GLFW_RELEASE) keys[key] = false;
//    }
//
//    if (keys[GLFW_KEY_SPACE]) {
//        active = !active;
//        Light1 = active ? glm::vec3(0.2f, 0.8f, 1.0f) : glm::vec3(0.0f);
//    }
//    if (keys[GLFW_KEY_N]) {
//        AnimBall = !AnimBall;
//    }
//    if (keys[GLFW_KEY_B]) {
//        dogAnim = 1;
//        // ARRANQUE: ir al centro; allí se detendrá 1s, girará a +Z y seguirá de frente
//        dogState = WALK_DIAG_CENTER;
//    }
//}
//
//void Animation() {
//    // Bola
//    if (AnimBall) {
//        rotBall += 0.4f;
//    }
//
//    // Rotación libre del perro (si la usas)
//    if (AnimDog) {
//        rotDog -= 0.6f;
//    }
//
//    // Animación cíclica de patas / cabeza / cola
//    if (dogAnim == 1) {
//        if (!step) {
//            RLegs += 0.3f; FLegs += 0.3f; head += 0.3f; tail += 0.3f;
//            if (RLegs > 15.0f) step = true;
//        }
//        else {
//            RLegs -= 0.3f; FLegs -= 0.3f; head -= 0.3f; tail -= 0.3f;
//            if (RLegs < -15.0f) step = false;
//        }
//    }
//
//    // Movimiento con límites y giros
//    float moveStep = DOG_WALK_SPEED * deltaTime; // unidades/s
//    float turnStep = DOG_TURN_SPEED * deltaTime; // grados/s
//
//    switch (dogState) {
//    case IDLE:
//        break;
//
//        // +Z hasta orilla frontal
//    case WALK_FWD:
//        dogPos.z += moveStep;
//        if (dogPos.z >= (FLOOR_MAX_Z - SAFE_MARGIN)) {
//            dogPos.z = (FLOOR_MAX_Z - SAFE_MARGIN);
//            dogState = TURN_RIGHT_1;
//            dogTargetRot = dogRot + 90.0f; // giro horario
//        }
//        break;
//
//        // Primer giro horario (+90)
//    case TURN_RIGHT_1:
//        if (dogRot < dogTargetRot) {
//            dogRot += turnStep;
//            if (dogRot > dogTargetRot) dogRot = dogTargetRot;
//        }
//        if (dogRot == dogTargetRot) {
//            dogState = WALK_RIGHT; // caminar a +X
//        }
//        break;
//
//        // +X hasta orilla derecha
//    case WALK_RIGHT:
//        dogPos.x += moveStep;
//        if (dogPos.x >= (FLOOR_MAX_X - SAFE_MARGIN)) {
//            dogPos.x = (FLOOR_MAX_X - SAFE_MARGIN);
//            dogState = TURN_RIGHT_2;
//            dogTargetRot = dogRot + 90.0f; // segundo giro horario
//        }
//        break;
//
//        // Segundo giro horario (+90) => queda apuntando a -Z
//    case TURN_RIGHT_2:
//        if (dogRot < dogTargetRot) {
//            dogRot += turnStep;
//            if (dogRot > dogTargetRot) dogRot = dogTargetRot;
//        }
//        if (dogRot == dogTargetRot) {
//            dogState = WALK_BACK; // seguir caminando hacia -Z
//        }
//        break;
//
//        // -Z hasta la orilla trasera
//    case WALK_BACK:
//        dogPos.z -= moveStep;
//        if (dogPos.z <= (FLOOR_MIN_Z + SAFE_MARGIN)) {
//            dogPos.z = (FLOOR_MIN_Z + SAFE_MARGIN);
//            dogState = TURN_LEFT_CCW;
//            // (histórico) último giro horario
//            dogTargetRot = dogRot + 90.0f; // horario
//        }
//        break;
//
//        // Último giro (horario). Mantengo flujo existente.
//    case TURN_LEFT_CCW:
//        if (dogRot < dogTargetRot) {
//            dogRot += turnStep;
//            if (dogRot > dogTargetRot) dogRot = dogTargetRot;
//        }
//        if (dogRot == dogTargetRot) {
//            // En el flujo original, continúa con giro 45°
//            dogTargetRot = dogRot + 45.0f;
//            if (dogTargetRot >= 360.0f) dogTargetRot -= 360.0f;
//            dogState = TURN_45_CW;
//        }
//        break;
//
//    case TURN_45_CW:
//        if (dogRot < dogTargetRot) {
//            dogRot += turnStep;
//            if (dogRot > dogTargetRot) dogRot = dogTargetRot;
//        }
//        if (dogRot == dogTargetRot) {
//            dogState = WALK_STRAIGHT_45; // avanzar recto con el nuevo rumbo
//        }
//        break;
//
//    case WALK_STRAIGHT_45:
//    {
//        float yaw = glm::radians(dogRot);
//        float dirX = sinf(yaw);
//        float dirZ = cosf(yaw);
//
//        float nx = dogPos.x + dirX * moveStep;
//        float nz = dogPos.z + dirZ * moveStep;
//
//        bool hitEdge = false;
//        if (nx < FLOOR_MIN_X + SAFE_MARGIN) { nx = FLOOR_MIN_X + SAFE_MARGIN; hitEdge = true; }
//        if (nx > FLOOR_MAX_X - SAFE_MARGIN) { nx = FLOOR_MAX_X - SAFE_MARGIN; hitEdge = true; }
//        if (nz < FLOOR_MIN_Z + SAFE_MARGIN) { nz = FLOOR_MIN_Z + SAFE_MARGIN; hitEdge = true; }
//        if (nz > FLOOR_MAX_Z - SAFE_MARGIN) { nz = FLOOR_MAX_Z - SAFE_MARGIN; hitEdge = true; }
//
//        dogPos.x = nx;
//        dogPos.z = nz;
//
//        if (hitEdge) {
//            dogState = IDLE;
//        }
//    }
//    break;
//
//    // Ir al centro, PAUSA 1s, GIRAR a +Z y luego caminar de frente
//    case WALK_DIAG_CENTER:
//    {
//        // Rotación suave hacia el dogTargetRot (mantengo esta parte)
//        float diffR = dogTargetRot - dogRot;
//        while (diffR > 180.0f) diffR -= 360.0f;
//        while (diffR < -180.0f) diffR += 360.0f;
//
//        if (fabsf(diffR) > 0.01f) {
//            float stepR = (diffR > 0.0f ? +turnStep : -turnStep);
//            if (fabsf(stepR) > fabsf(diffR)) stepR = diffR;
//            dogRot += stepR;
//            if (dogRot >= 360.0f) dogRot -= 360.0f;
//            if (dogRot < 0.0f)    dogRot += 360.0f;
//        }
//
//        // Avance hacia el centro (diagonal)
//        float dx = CENTER_X - dogPos.x;
//        float dz = CENTER_Z - dogPos.z;
//        float dist = sqrtf(dx * dx + dz * dz);
//
//        if (dist <= CENTER_EPS) {
//            // 1) Llega al centro y se DETIENE en el centro
//            dogPos.x = CENTER_X;
//            dogPos.z = CENTER_Z;
//
//            // 2) PAUSA visible de 1s antes de girar
//            if (!waitAtCenter) {
//                waitAtCenter = true;
//                waitAccum = 0.0f;
//                return; // mantener quieto este frame
//            }
//            else {
//                waitAccum += deltaTime;
//                if (waitAccum < CENTER_WAIT_SECONDS) {
//                    return; // seguir esperando hasta completar 1s
//                }
//                // fin de la espera
//                waitAtCenter = false;
//                waitAccum = 0.0f;
//            }
//
//            // 3) GIRA EN EL LUGAR hasta mirar +Z (0°)
//            float diff = 0.0f - dogRot;
//            while (diff > 180.0f) diff -= 360.0f;
//            while (diff < -180.0f) diff += 360.0f;
//
//            if (fabsf(diff) > 0.5f) {
//                float step = (diff > 0.0f ? +turnStep : -turnStep);
//                if (fabsf(step) > fabsf(diff)) step = diff;
//                dogRot += step;
//                if (dogRot >= 360.0f) dogRot -= 360.0f;
//                if (dogRot < 0.0f)    dogRot += 360.0f;
//                // Se queda en este estado (parado en centro) hasta terminar de girar
//            }
//            else {
//                // 4) Ya mirando al +Z: comenzar a caminar de frente
//                dogRot = 0.0f;
//                dogState = WALK_FWD;
//            }
//        }
//        else {
//            float nx = dx / dist;
//            float nz = dz / dist;
//            float stepMove = moveStep;
//            if (stepMove > dist) stepMove = dist; // no pasarse
//
//            float tx = dogPos.x + nx * stepMove;
//            float tz = dogPos.z + nz * stepMove;
//
//            if (tx < FLOOR_MIN_X + SAFE_MARGIN) tx = FLOOR_MIN_X + SAFE_MARGIN;
//            if (tx > FLOOR_MAX_X - SAFE_MARGIN) tx = FLOOR_MAX_X - SAFE_MARGIN;
//            if (tz < FLOOR_MIN_Z + SAFE_MARGIN) tz = FLOOR_MIN_Z + SAFE_MARGIN;
//            if (tz > FLOOR_MAX_Z - SAFE_MARGIN) tz = FLOOR_MAX_Z - SAFE_MARGIN;
//
//            dogPos.x = tx;
//            dogPos.z = tz;
//        }
//    }
//    break;
//    }
//
//    // Clamp suave para no salir del piso
//    if (dogPos.x < FLOOR_MIN_X + SAFE_MARGIN) dogPos.x = FLOOR_MIN_X + SAFE_MARGIN;
//    if (dogPos.x > FLOOR_MAX_X - SAFE_MARGIN) dogPos.x = FLOOR_MAX_X - SAFE_MARGIN;
//    if (dogPos.z < FLOOR_MIN_Z + SAFE_MARGIN) dogPos.z = FLOOR_MIN_Z + SAFE_MARGIN;
//    if (dogPos.z > FLOOR_MAX_Z - SAFE_MARGIN) dogPos.z = FLOOR_MAX_Z - SAFE_MARGIN;
//
//    // Normaliza el ángulo
//    if (dogRot >= 360.0f) dogRot -= 360.0f;
//    if (dogRot < 0.0f)    dogRot += 360.0f;
//}
//
//void MouseCallback(GLFWwindow* window, double xPos, double yPos)
//{
//    if (firstMouse)
//    {
//        lastX = static_cast<float>(xPos);
//        lastY = static_cast<float>(yPos);
//        firstMouse = false;
//    }
//
//    GLfloat xOffset = static_cast<float>(xPos) - lastX;
//    GLfloat yOffset = lastY - static_cast<float>(yPos);
//
//    lastX = static_cast<float>(xPos);
//    lastY = static_cast<float>(yPos);
//
//    camera.ProcessMouseMovement(xOffset, yOffset);
//}
//#include <iostream>
//#include <cmath>
//
// // GLEW
//#include <GL/glew.h>
//
//// GLFW
//#include <GLFW/glfw3.h>
//
//// Other Libs
//#include "stb_image.h"
//
//// GLM Mathematics
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
////Load Models
//#include "SOIL2/SOIL2.h"
//
//// Other includes
//#include "Shader.h"
//#include "Camera.h"
//#include "Model.h"
//
//// Function prototypes
//void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
//void MouseCallback(GLFWwindow* window, double xPos, double yPos);
//void DoMovement();
//void Animation();
//
//// Window dimensions
//const GLuint WIDTH = 800, HEIGHT = 600;
//int SCREEN_WIDTH, SCREEN_HEIGHT;
//
//// Camera
//Camera  camera(glm::vec3(0.0f, 0.0f, 3.0f));
//GLfloat lastX = WIDTH / 2.0f;
//GLfloat lastY = HEIGHT / 2.0f;
//bool keys[1024];
//bool firstMouse = true;
//// Light attributes
//glm::vec3 lightPos(0.0f, 0.0f, 0.0f);
//bool active;
//
//// Positions of the point lights
//glm::vec3 pointLightPositions[] = {
//    glm::vec3(0.0f,2.0f, 0.0f),
//    glm::vec3(0.0f,0.0f, 0.0f),
//    glm::vec3(0.0f,0.0f,  0.0f),
//    glm::vec3(0.0f,0.0f, 0.0f)
//};
//
//float vertices[] = {
//       -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//        0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//        0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//        0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//       -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//       -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//
//       -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//        0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//        0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//        0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//       -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//       -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//
//       -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//       -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//
//        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//        0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//        0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//        0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//
//       -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//        0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//        0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//        0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//       -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//       -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//
//       -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//        0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//        0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//        0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//       -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//       -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
//};
//
//glm::vec3 Light1 = glm::vec3(0);
////Anim
//float rotBall = 0.0f;
//bool AnimBall = false;
//bool AnimDog = false;
//float rotDog = 0.0f;
//int dogAnim = 0;
//float FLegs = 0.0f;
//float RLegs = 0.0f;
//float head = 0.0f;
//float tail = 0.0f;
//glm::vec3 dogPos(0.0f, 0.0f, 0.0f);
//float dogRot = 0.0f;
//bool step = false;
//
//// ------------------- Límites del piso y máquina de estados -------------------
//const float FLOOR_MIN_X = -2.0f;
//const float FLOOR_MAX_X = 2.0f;
//const float FLOOR_MIN_Z = -2.0f;
//const float FLOOR_MAX_Z = 2.0f;
//const float SAFE_MARGIN = 0.15f;
//
//// --- Centro del piso y tolerancia ---
//const float CENTER_X = 0.0f;
//const float CENTER_Z = 0.0f;
//const float CENTER_EPS = 0.05f; // distancia mínima para considerar "llegó al centro"
//
//// Velocidades (MÁS LENTAS)
//const float DOG_WALK_SPEED = 0.25f;  // antes 0.6f
//const float DOG_TURN_SPEED = 45.0f;  // antes 90.0f
//
//// Máquina de estados del perro (extendida)
//enum DogState {
//    IDLE = 0,
//    WALK_FWD,        // +Z
//    TURN_RIGHT_1,    // +90° horario
//    WALK_RIGHT,      // +X
//    TURN_RIGHT_2,    // +90° horario
//    WALK_BACK,       // -Z
//    TURN_LEFT_CCW,   // (nombre heredado; se usa como giro final antes de volver al centro)
//    WALK_DIAG_CENTER, // va hacia el centro (solo mitad del tramo por frame)
//    TURN_45_CW,
//    WALK_STRAIGHT_45,
//    CENTER_ALIGN       // NUEVO: ya en el centro, gira para quedar recto (+Z)
//};
//DogState dogState = IDLE;
//float dogTargetRot = 0.0f; // destino del giro en grados
//// -----------------------------------------------------------------------------
//
//// Deltatime
//GLfloat deltaTime = 0.0f;
//GLfloat lastFrame = 0.0f;
//
//int main()
//{
//    // Init GLFW
//    glfwInit();
//
//    // Window
//    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Animacion maquina de estados", nullptr, nullptr);
//    if (nullptr == window) {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return EXIT_FAILURE;
//    }
//    glfwMakeContextCurrent(window);
//    glfwGetFramebufferSize(window, &SCREEN_WIDTH, &SCREEN_HEIGHT);
//
//    // Callbacks
//    glfwSetKeyCallback(window, KeyCallback);
//    glfwSetCursorPosCallback(window, MouseCallback);
//
//    // GLEW
//    glewExperimental = GL_TRUE;
//    if (GLEW_OK != glewInit()) {
//        std::cout << "Failed to initialize GLEW" << std::endl;
//        return EXIT_FAILURE;
//    }
//
//    // Viewport
//    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
//
//    Shader lightingShader("Shader/lighting.vs", "Shader/lighting.frag");
//    Shader lampShader("Shader/lamp.vs", "Shader/lamp.frag");
//
//    // Models
//    Model DogBody((char*)"Models/DogBody.obj");
//    Model HeadDog((char*)"Models/HeadDog.obj");
//    Model DogTail((char*)"Models/TailDog.obj");
//    Model F_RightLeg((char*)"Models/F_RightLegDog.obj");
//    Model F_LeftLeg((char*)"Models/F_LeftLegDog.obj");
//    Model B_RightLeg((char*)"Models/B_RightLegDog.obj");
//    Model B_LeftLeg((char*)"Models/B_LeftLegDog.obj");
//    Model Piso((char*)"Models/piso.obj");
//    Model Ball((char*)"Models/ball.obj");
//
//    // VAO/VBO
//    GLuint VBO, VAO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//    glBindVertexArray(VAO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//    // Position
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
//    glEnableVertexAttribArray(0);
//    // Normal
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//
//    // Material samplers
//    lightingShader.Use();
//    glUniform1i(glGetUniformLocation(lightingShader.Program, "Material.difuse"), 0);
//    glUniform1i(glGetUniformLocation(lightingShader.Program, "Material.specular"), 1);
//
//    glm::mat4 projection = glm::perspective(
//        camera.GetZoom(),
//        (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT,
//        0.1f, 100.0f
//    );
//
//    // Game loop
//    while (!glfwWindowShouldClose(window))
//    {
//        // Delta time
//        GLfloat currentFrame = static_cast<float>(glfwGetTime());
//        deltaTime = currentFrame - lastFrame;
//        lastFrame = currentFrame;
//
//        // Input + anim
//        glfwPollEvents();
//        DoMovement();
//        Animation();
//
//        // Clear
//        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        glEnable(GL_DEPTH_TEST);
//
//        // ==== DRAW ====
//        glm::mat4 model;
//        glm::mat4 view = camera.GetViewMatrix();
//        glm::mat4 modelTemp = glm::mat4(1.0f); // una sola vez por frame
//
//        lightingShader.Use();
//
//        glUniform1i(glGetUniformLocation(lightingShader.Program, "diffuse"), 0);
//
//        GLint viewPosLoc = glGetUniformLocation(lightingShader.Program, "viewPos");
//        glUniform3f(viewPosLoc, camera.GetPosition().x, camera.GetPosition().y, camera.GetPosition().z);
//
//        // Dir light
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.direction"), -0.2f, -1.0f, -0.3f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.ambient"), 0.6f, 0.6f, 0.6f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.diffuse"), 0.6f, 0.6f, 0.6f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.specular"), 0.3f, 0.3f, 0.3f);
//
//        // Point light anim
//        glm::vec3 lightColor;
//        lightColor.x = fabsf(sinf(glfwGetTime() * Light1.x));
//        lightColor.y = fabsf(sinf(glfwGetTime() * Light1.y));
//        lightColor.z = sinf(glfwGetTime() * Light1.z);
//
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].position"),
//            pointLightPositions[0].x, pointLightPositions[0].y, pointLightPositions[0].z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].ambient"),
//            lightColor.x, lightColor.y, lightColor.z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].diffuse"),
//            lightColor.x, lightColor.y, lightColor.z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].specular"),
//            1.0f, 0.2f, 0.2f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[0].constant"), 1.0f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[0].linear"), 0.045f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[0].quadratic"), 0.075f);
//
//        // Spotlight (cámara)
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.position"),
//            camera.GetPosition().x, camera.GetPosition().y, camera.GetPosition().z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.direction"),
//            camera.GetFront().x, camera.GetFront().y, camera.GetFront().z);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.ambient"), 0.2f, 0.2f, 0.8f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.diffuse"), 0.2f, 0.2f, 0.8f);
//        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.specular"), 0.0f, 0.0f, 0.0f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.constant"), 1.0f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.linear"), 0.3f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.quadratic"), 0.7f);
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.cutOff"), glm::cos(glm::radians(12.0f)));
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.outerCutOff"), glm::cos(glm::radians(18.0f)));
//
//        // Material
//        glUniform1f(glGetUniformLocation(lightingShader.Program, "material.shininess"), 5.0f);
//
//        // Matrices
//        GLint modelLoc = glGetUniformLocation(lightingShader.Program, "model");
//        GLint viewLoc = glGetUniformLocation(lightingShader.Program, "view");
//        GLint projLoc = glGetUniformLocation(lightingShader.Program, "projection");
//        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
//
//        // --- Piso ---
//        model = glm::mat4(1.0f);
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        Piso.Draw(lightingShader);
//
//        // --- Perro ---
//        model = glm::mat4(1.0f);
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        glUniform1i(glGetUniformLocation(lightingShader.Program, "transparency"), 0);
//
//        // Body
//        model = glm::translate(model, dogPos);
//        model = glm::rotate(model, glm::radians(dogRot), glm::vec3(0.0f, 1.0f, 0.0f));
//        modelTemp = model; // base
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        DogBody.Draw(lightingShader);
//
//        // Head
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(0.0f, 0.093f, 0.208f));
//        model = glm::rotate(model, glm::radians(head), glm::vec3(0.0f, 0.0f, 1.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        HeadDog.Draw(lightingShader);
//
//        // Tail 
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(0.0f, 0.026f, -0.288f));
//        model = glm::rotate(model, glm::radians(tail), glm::vec3(0.0f, 0.0f, -1.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        DogTail.Draw(lightingShader);
//
//        // Front Left Leg
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(0.112f, -0.044f, 0.074f));
//        model = glm::rotate(model, glm::radians(FLegs), glm::vec3(-1.0f, 0.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        F_LeftLeg.Draw(lightingShader);
//
//        // Front Right Leg
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(-0.111f, -0.055f, 0.074f));
//        model = glm::rotate(model, glm::radians(FLegs), glm::vec3(1.0f, 0.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        F_RightLeg.Draw(lightingShader);
//
//        // Back Left Leg
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(0.082f, -0.046f, -0.218f));
//        model = glm::rotate(model, glm::radians(RLegs), glm::vec3(1.0f, 0.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        B_LeftLeg.Draw(lightingShader);
//
//        // Back Right Leg
//        model = modelTemp;
//        model = glm::translate(model, glm::vec3(-0.083f, -0.057f, -0.231f));
//        model = glm::rotate(model, glm::radians(RLegs), glm::vec3(-1.0f, 0.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        B_RightLeg.Draw(lightingShader);
//
//        // --- Pelota ---
//        model = glm::mat4(1.0f);
//        glEnable(GL_BLEND);
//        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        glUniform1i(glGetUniformLocation(lightingShader.Program, "transparency"), 1);
//        model = glm::rotate(model, glm::radians(rotBall), glm::vec3(0.0f, 1.0f, 0.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        Ball.Draw(lightingShader);
//        glDisable(GL_BLEND);
//        glBindVertexArray(0);
//
//        // --- Lámpara ---
//        lampShader.Use();
//        modelLoc = glGetUniformLocation(lampShader.Program, "model");
//        GLint viewLoc2 = glGetUniformLocation(lampShader.Program, "view");
//        GLint projLoc2 = glGetUniformLocation(lampShader.Program, "projection");
//        glUniformMatrix4fv(viewLoc2, 1, GL_FALSE, glm::value_ptr(view));
//        glUniformMatrix4fv(projLoc2, 1, GL_FALSE, glm::value_ptr(projection));
//
//        model = glm::mat4(1.0f);
//        model = glm::translate(model, lightPos);
//        model = glm::scale(model, glm::vec3(0.2f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//
//        model = glm::mat4(1.0f);
//        model = glm::translate(model, pointLightPositions[0]);
//        model = glm::scale(model, glm::vec3(0.2f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        glBindVertexArray(VAO);
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//        glBindVertexArray(0);
//
//        // Swap
//        glfwSwapBuffers(window);
//    }
//
//    glfwTerminate();
//    return 0;
//}
//
//// Moves/alters the camera positions based on user input
//void DoMovement()
//{
//    if (keys[GLFW_KEY_W] || keys[GLFW_KEY_UP])    camera.ProcessKeyboard(FORWARD, deltaTime);
//    if (keys[GLFW_KEY_S] || keys[GLFW_KEY_DOWN])  camera.ProcessKeyboard(BACKWARD, deltaTime);
//    if (keys[GLFW_KEY_A] || keys[GLFW_KEY_LEFT])  camera.ProcessKeyboard(LEFT, deltaTime);
//    if (keys[GLFW_KEY_D] || keys[GLFW_KEY_RIGHT]) camera.ProcessKeyboard(RIGHT, deltaTime);
//
//    if (keys[GLFW_KEY_T]) { pointLightPositions[0].x += 0.01f; }
//    if (keys[GLFW_KEY_G]) { pointLightPositions[0].x -= 0.01f; }
//    if (keys[GLFW_KEY_Y]) { pointLightPositions[0].y += 0.01f; }
//    if (keys[GLFW_KEY_H]) { pointLightPositions[0].y -= 0.01f; }
//    if (keys[GLFW_KEY_U]) { pointLightPositions[0].z -= 0.1f; }
//    if (keys[GLFW_KEY_J]) { pointLightPositions[0].z += 0.01f; }
//}
//
//// Is called whenever a key is pressed/released via GLFW
//void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//    if (GLFW_KEY_ESCAPE == key && GLFW_PRESS == action) {
//        glfwSetWindowShouldClose(window, GL_TRUE);
//    }
//
//    if (key >= 0 && key < 1024) {
//        if (action == GLFW_PRESS)      keys[key] = true;
//        else if (action == GLFW_RELEASE) keys[key] = false;
//    }
//
//    if (keys[GLFW_KEY_SPACE]) {
//        active = !active;
//        Light1 = active ? glm::vec3(0.2f, 0.8f, 1.0f) : glm::vec3(0.0f);
//    }
//    if (keys[GLFW_KEY_N]) {
//        AnimBall = !AnimBall;
//    }
//    if (keys[GLFW_KEY_B]) {
//        dogAnim = 1;
//        // ARRANQUE: ir hacia el centro (fase diagonal "a la mitad" por frame)
//        dogState = WALK_DIAG_CENTER;
//    }
//}
//
//void Animation() {
//    // Bola
//    if (AnimBall) {
//        rotBall += 0.4f;
//    }
//
//    // Rotación libre del perro (si la usas)
//    if (AnimDog) {
//        rotDog -= 0.6f;
//    }
//
//    // Animación cíclica de patas / cabeza / cola
//    if (dogAnim == 1) {
//        if (!step) {
//            RLegs += 0.3f; FLegs += 0.3f; head += 0.3f; tail += 0.3f;
//            if (RLegs > 15.0f) step = true;
//        }
//        else {
//            RLegs -= 0.3f; FLegs -= 0.3f; head -= 0.3f; tail -= 0.3f;
//            if (RLegs < -15.0f) step = false;
//        }
//    }
//
//    // Movimiento con límites y giros
//    float moveStep = DOG_WALK_SPEED * deltaTime; // unidades/s
//    float turnStep = DOG_TURN_SPEED * deltaTime; // grados/s
//
//    switch (dogState) {
//    case IDLE:
//        break;
//
//        // +Z hasta orilla frontal
//    case WALK_FWD:
//        dogPos.z += moveStep;
//        if (dogPos.z >= (FLOOR_MAX_Z - SAFE_MARGIN)) {
//            dogPos.z = (FLOOR_MAX_Z - SAFE_MARGIN);
//            dogState = TURN_RIGHT_1;
//            dogTargetRot = dogRot + 90.0f; // giro horario
//        }
//        break;
//
//        // Primer giro horario (+90)
//    case TURN_RIGHT_1:
//        if (dogRot < dogTargetRot) {
//            dogRot += turnStep;
//            if (dogRot > dogTargetRot) dogRot = dogTargetRot;
//        }
//        if (dogRot == dogTargetRot) {
//            dogState = WALK_RIGHT; // caminar a +X
//        }
//        break;
//
//        // +X hasta orilla derecha
//    case WALK_RIGHT:
//        dogPos.x += moveStep;
//        if (dogPos.x >= (FLOOR_MAX_X - SAFE_MARGIN)) {
//            dogPos.x = (FLOOR_MAX_X - SAFE_MARGIN);
//            dogState = TURN_RIGHT_2;
//            dogTargetRot = dogRot + 90.0f; // segundo giro horario
//        }
//        break;
//
//        // Segundo giro horario (+90) => queda apuntando a -Z
//    case TURN_RIGHT_2:
//        if (dogRot < dogTargetRot) {
//            dogRot += turnStep;
//            if (dogRot > dogTargetRot) dogRot = dogTargetRot;
//        }
//        if (dogRot == dogTargetRot) {
//            dogState = WALK_BACK; // seguir caminando hacia -Z
//        }
//        break;
//
//        // -Z hasta la orilla trasera
//    case WALK_BACK:
//        dogPos.z -= moveStep;
//        if (dogPos.z <= (FLOOR_MIN_Z + SAFE_MARGIN)) {
//            dogPos.z = (FLOOR_MIN_Z + SAFE_MARGIN);
//            dogState = TURN_LEFT_CCW;
//            dogTargetRot = dogRot + 90.0f; // giro horario final
//        }
//        break;
//
//        // Último giro: al terminar, en vez de 45° diagonal, vuelve al centro
//    case TURN_LEFT_CCW:
//        if (dogRot < dogTargetRot) {
//            dogRot += turnStep;
//            if (dogRot > dogTargetRot) dogRot = dogTargetRot;
//        }
//        if (dogRot == dogTargetRot) {
//            // Ir al centro para alinear y continuar recto
//            dogState = WALK_DIAG_CENTER;
//        }
//        break;
//
//        // --- NUEVO FLUJO: ir al centro (mitad por frame), luego alinear ---
//    case WALK_DIAG_CENTER:
//    {
//        // Vector hacia el centro
//        float dx = CENTER_X - dogPos.x;
//        float dz = CENTER_Z - dogPos.z;
//        float dist = sqrtf(dx * dx + dz * dz);
//
//        // ¿Llegó?
//        if (dist <= CENTER_EPS) {
//            dogPos.x = CENTER_X;
//            dogPos.z = CENTER_Z;
//            dogState = CENTER_ALIGN; // nuevo estado: girar en el centro
//            break;
//        }
//
//        // Avanza SOLO la MITAD del tramo restante hacia el centro
//        float nx = dx / dist;
//        float nz = dz / dist;
//
//        float stepMove = moveStep;
//        float halfDist = dist * 0.5f;
//        if (stepMove > halfDist) stepMove = halfDist; // <- mitad del tramo actual
//
//        float tx = dogPos.x + nx * stepMove;
//        float tz = dogPos.z + nz * stepMove;
//
//        // Limitar al piso
//        if (tx < FLOOR_MIN_X + SAFE_MARGIN) tx = FLOOR_MIN_X + SAFE_MARGIN;
//        if (tx > FLOOR_MAX_X - SAFE_MARGIN) tx = FLOOR_MAX_X - SAFE_MARGIN;
//        if (tz < FLOOR_MIN_Z + SAFE_MARGIN) tz = FLOOR_MIN_Z + SAFE_MARGIN;
//        if (tz > FLOOR_MAX_Z - SAFE_MARGIN) tz = FLOOR_MAX_Z - SAFE_MARGIN;
//
//        dogPos.x = tx;
//        dogPos.z = tz;
//    }
//    break;
//
//    case CENTER_ALIGN:
//    {
//        // Girar en el lugar hasta mirar a +Z (0°)
//        float diff = 0.0f - dogRot;
//        while (diff > 180.0f) diff -= 360.0f;
//        while (diff < -180.0f) diff += 360.0f;
//
//        if (fabsf(diff) > 0.5f) {
//            float step = (diff > 0.0f ? +turnStep : -turnStep);
//            if (fabsf(step) > fabsf(diff)) step = diff;
//            dogRot += step;
//            if (dogRot >= 360.0f) dogRot -= 360.0f;
//            if (dogRot < 0.0f)    dogRot += 360.0f;
//        }
//        else {
//            // Ya quedó recto: seguir de frente y continuar el ciclo normal
//            dogRot = 0.0f;       // mirando +Z
//            dogState = WALK_FWD; // continúa el recorrido recto
//        }
//    }
//    break;
//
//    // (Estos estados quedan definidos pero ya no se usan en el ciclo recto)
//    case TURN_45_CW:
//        if (dogRot < dogTargetRot) {
//            dogRot += turnStep;
//            if (dogRot > dogTargetRot) dogRot = dogTargetRot;
//        }
//        if (dogRot == dogTargetRot) {
//            dogState = WALK_STRAIGHT_45;
//        }
//        break;
//
//    case WALK_STRAIGHT_45:
//    {
//        float yaw = glm::radians(dogRot);
//        float dirX = sinf(yaw);
//        float dirZ = cosf(yaw);
//
//        float nx = dogPos.x + dirX * moveStep;
//        float nz = dogPos.z + dirZ * moveStep;
//
//        bool hitEdge = false;
//        if (nx < FLOOR_MIN_X + SAFE_MARGIN) { nx = FLOOR_MIN_X + SAFE_MARGIN; hitEdge = true; }
//        if (nx > FLOOR_MAX_X - SAFE_MARGIN) { nx = FLOOR_MAX_X - SAFE_MARGIN; hitEdge = true; }
//        if (nz < FLOOR_MIN_Z + SAFE_MARGIN) { nz = FLOOR_MIN_Z + SAFE_MARGIN; hitEdge = true; }
//        if (nz > FLOOR_MAX_Z - SAFE_MARGIN) { nz = FLOOR_MAX_Z - SAFE_MARGIN; hitEdge = true; }
//
//        dogPos.x = nx;
//        dogPos.z = nz;
//
//        if (hitEdge) {
//            dogState = IDLE;
//        }
//    }
//    break;
//    }
//
//    // Clamp suave para no salir del piso
//    if (dogPos.x < FLOOR_MIN_X + SAFE_MARGIN) dogPos.x = FLOOR_MIN_X + SAFE_MARGIN;
//    if (dogPos.x > FLOOR_MAX_X - SAFE_MARGIN) dogPos.x = FLOOR_MAX_X - SAFE_MARGIN;
//    if (dogPos.z < FLOOR_MIN_Z + SAFE_MARGIN) dogPos.z = FLOOR_MIN_Z + SAFE_MARGIN;
//    if (dogPos.z > FLOOR_MAX_Z - SAFE_MARGIN) dogPos.z = FLOOR_MAX_Z - SAFE_MARGIN;
//
//    // Normaliza el ángulo
//    if (dogRot >= 360.0f) dogRot -= 360.0f;
//    if (dogRot < 0.0f)    dogRot += 360.0f;
//}
//
//void MouseCallback(GLFWwindow* window, double xPos, double yPos)
//{
//    if (firstMouse)
//    {
//        lastX = static_cast<float>(xPos);
//        lastY = static_cast<float>(yPos);
//        firstMouse = false;
//    }
//
//    GLfloat xOffset = static_cast<float>(xPos) - lastX;
//    GLfloat yOffset = lastY - static_cast<float>(yPos);
//
//    lastX = static_cast<float>(xPos);
//    lastY = static_cast<float>(yPos);
//
//    camera.ProcessMouseMovement(xOffset, yOffset);
//
///
///
//
// // Practica 11: Animaciones Maquina de estados 
// Laboratorio de computacion grafica
// GPO: 07 
// Dayana Plata Alvarez 
// No. cuenta: 318300764 
// Fecha de entrega: 11/2/2025 
//
#include <iostream>
#include <cmath>

 // GLEW
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// Other Libs
#include "stb_image.h"

// GLM Mathematics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//Load Models
#include "SOIL2/SOIL2.h"

// Other includes
#include "Shader.h"
#include "Camera.h"
#include "Model.h"

// Function prototypes
void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
void MouseCallback(GLFWwindow* window, double xPos, double yPos);
void DoMovement();
void Animation();

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;
int SCREEN_WIDTH, SCREEN_HEIGHT;

// Camera
Camera  camera(glm::vec3(0.0f, 0.0f, 3.0f));
GLfloat lastX = WIDTH / 2.0f;
GLfloat lastY = HEIGHT / 2.0f;
bool keys[1024];
bool firstMouse = true;
// Light attributes
glm::vec3 lightPos(0.0f, 0.0f, 0.0f);
bool active;

// Positions of the point lights
glm::vec3 pointLightPositions[] = {
    glm::vec3(0.0f,2.0f, 0.0f),
    glm::vec3(0.0f,0.0f, 0.0f),
    glm::vec3(0.0f,0.0f,  0.0f),
    glm::vec3(0.0f,0.0f, 0.0f)
};

float vertices[] = {
       -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
       -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
       -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

       -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
        0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
       -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
       -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,

       -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
       -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
       -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
       -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
       -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
       -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
        0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
        0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
        0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

       -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
        0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
        0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
       -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
       -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

       -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
        0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
       -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
       -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
};

glm::vec3 Light1 = glm::vec3(0);
//Anim
float rotBall = 0.0f;
bool AnimBall = false;
bool AnimDog = false;
float rotDog = 0.0f;
int dogAnim = 0;
float FLegs = 0.0f;
float RLegs = 0.0f;
float head = 0.0f;
float tail = 0.0f;
glm::vec3 dogPos(0.0f, 0.0f, 0.0f);
float dogRot = 0.0f;
bool step = false;

// ------------------- Límites del piso y máquina de estados -------------------
const float FLOOR_MIN_X = -2.0f;
const float FLOOR_MAX_X = 2.0f;
const float FLOOR_MIN_Z = -2.0f;
const float FLOOR_MAX_Z = 2.0f;
const float SAFE_MARGIN = 0.15f;

// --- Centro del piso y tolerancia ---
const float CENTER_X = 0.0f;
const float CENTER_Z = 0.0f;
const float CENTER_EPS = 0.05f; // distancia mínima para considerar "llegó al centro"

// Velocidades (MÁS LENTAS)
const float DOG_WALK_SPEED = 0.15f;  // antes 0.6f
const float DOG_TURN_SPEED = 25.0f;  // antes 90.0f

// Máquina de estados del perro (extendida)
enum DogState {
    IDLE = 0,
    WALK_FWD,        // +Z
    TURN_RIGHT_1,    // +90° horario
    WALK_RIGHT,      // +X
    TURN_RIGHT_2,    // +90° horario
    WALK_BACK,       // -Z
    TURN_LEFT_CCW,   // giro final, luego vamos al centro
    WALK_DIAG_CENTER, // ir al centro (mitad del tramo por frame) SIN girar el cuerpo
    TURN_45_CW,
    WALK_STRAIGHT_45,
    CENTER_ALIGN       // NUEVO: ya en el centro, girar para quedar recto (+Z)
};
DogState dogState = IDLE;
float dogTargetRot = 0.0f; // destino del giro en grados
// -----------------------------------------------------------------------------

// Deltatime
GLfloat deltaTime = 0.0f;
GLfloat lastFrame = 0.0f;

int main()
{
    // Init GLFW
    glfwInit();

    // Window
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Animacion maquina de estados", nullptr, nullptr);
    if (nullptr == window) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return EXIT_FAILURE;
    }
    glfwMakeContextCurrent(window);
    glfwGetFramebufferSize(window, &SCREEN_WIDTH, &SCREEN_HEIGHT);

    // Callbacks
    glfwSetKeyCallback(window, KeyCallback);
    glfwSetCursorPosCallback(window, MouseCallback);

    // GLEW
    glewExperimental = GL_TRUE;
    if (GLEW_OK != glewInit()) {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return EXIT_FAILURE;
    }

    // Viewport
    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    Shader lightingShader("Shader/lighting.vs", "Shader/lighting.frag");
    Shader lampShader("Shader/lamp.vs", "Shader/lamp.frag");

    // Models
    Model DogBody((char*)"Models/DogBody.obj");
    Model HeadDog((char*)"Models/HeadDog.obj");
    Model DogTail((char*)"Models/TailDog.obj");
    Model F_RightLeg((char*)"Models/F_RightLegDog.obj");
    Model F_LeftLeg((char*)"Models/F_LeftLegDog.obj");
    Model B_RightLeg((char*)"Models/B_RightLegDog.obj");
    Model B_LeftLeg((char*)"Models/B_LeftLegDog.obj");
    Model Piso((char*)"Models/piso.obj");
    Model Ball((char*)"Models/ball.obj");

    // VAO/VBO
    GLuint VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // Position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    // Normal
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // Material samplers
    lightingShader.Use();
    glUniform1i(glGetUniformLocation(lightingShader.Program, "Material.difuse"), 0);
    glUniform1i(glGetUniformLocation(lightingShader.Program, "Material.specular"), 1);

    glm::mat4 projection = glm::perspective(
        camera.GetZoom(),
        (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT,
        0.1f, 100.0f
    );

    // Game loop
    while (!glfwWindowShouldClose(window))
    {
        // Delta time
        GLfloat currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // Input + anim
        glfwPollEvents();
        DoMovement();
        Animation();

        // Clear
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST);

        // ==== DRAW ====
        glm::mat4 model;
        glm::mat4 view = camera.GetViewMatrix();
        glm::mat4 modelTemp = glm::mat4(1.0f); // una sola vez por frame

        lightingShader.Use();

        glUniform1i(glGetUniformLocation(lightingShader.Program, "diffuse"), 0);

        GLint viewPosLoc = glGetUniformLocation(lightingShader.Program, "viewPos");
        glUniform3f(viewPosLoc, camera.GetPosition().x, camera.GetPosition().y, camera.GetPosition().z);

        // Dir light
        glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.direction"), -0.2f, -1.0f, -0.3f);
        glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.ambient"), 0.6f, 0.6f, 0.6f);
        glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.diffuse"), 0.6f, 0.6f, 0.6f);
        glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.specular"), 0.3f, 0.3f, 0.3f);

        // Point light anim
        glm::vec3 lightColor;
        lightColor.x = fabsf(sinf(glfwGetTime() * Light1.x));
        lightColor.y = fabsf(sinf(glfwGetTime() * Light1.y));
        lightColor.z = sinf(glfwGetTime() * Light1.z);

        glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].position"),
            pointLightPositions[0].x, pointLightPositions[0].y, pointLightPositions[0].z);
        glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].ambient"),
            lightColor.x, lightColor.y, lightColor.z);
        glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].diffuse"),
            lightColor.x, lightColor.y, lightColor.z);
        glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].specular"),
            1.0f, 0.2f, 0.2f);
        glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[0].constant"), 1.0f);
        glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[0].linear"), 0.045f);
        glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[0].quadratic"), 0.075f);

        // Spotlight (cámara)
        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.position"),
            camera.GetPosition().x, camera.GetPosition().y, camera.GetPosition().z);
        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.direction"),
            camera.GetFront().x, camera.GetFront().y, camera.GetFront().z);
        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.ambient"), 0.2f, 0.2f, 0.8f);
        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.diffuse"), 0.2f, 0.2f, 0.8f);
        glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.specular"), 0.0f, 0.0f, 0.0f);
        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.constant"), 1.0f);
        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.linear"), 0.3f);
        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.quadratic"), 0.7f);
        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.cutOff"), glm::cos(glm::radians(12.0f)));
        glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.outerCutOff"), glm::cos(glm::radians(18.0f)));

        // Material
        glUniform1f(glGetUniformLocation(lightingShader.Program, "material.shininess"), 5.0f);

        // Matrices
        GLint modelLoc = glGetUniformLocation(lightingShader.Program, "model");
        GLint viewLoc = glGetUniformLocation(lightingShader.Program, "view");
        GLint projLoc = glGetUniformLocation(lightingShader.Program, "projection");
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

        // --- Piso ---
        model = glm::mat4(1.0f);
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        Piso.Draw(lightingShader);

        // --- Perro ---
        model = glm::mat4(1.0f);
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glUniform1i(glGetUniformLocation(lightingShader.Program, "transparency"), 0);

        // Body
        model = glm::translate(model, dogPos);
        model = glm::rotate(model, glm::radians(dogRot), glm::vec3(0.0f, 1.0f, 0.0f));
        modelTemp = model; // base
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        DogBody.Draw(lightingShader);

        // Head
        model = modelTemp;
        model = glm::translate(model, glm::vec3(0.0f, 0.093f, 0.208f));
        model = glm::rotate(model, glm::radians(head), glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        HeadDog.Draw(lightingShader);

        // Tail 
        model = modelTemp;
        model = glm::translate(model, glm::vec3(0.0f, 0.026f, -0.288f));
        model = glm::rotate(model, glm::radians(tail), glm::vec3(0.0f, 0.0f, -1.0f));
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        DogTail.Draw(lightingShader);

        // Front Left Leg
        model = modelTemp;
        model = glm::translate(model, glm::vec3(0.112f, -0.044f, 0.074f));
        model = glm::rotate(model, glm::radians(FLegs), glm::vec3(-1.0f, 0.0f, 0.0f));
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        F_LeftLeg.Draw(lightingShader);

        // Front Right Leg
        model = modelTemp;
        model = glm::translate(model, glm::vec3(-0.111f, -0.055f, 0.074f));
        model = glm::rotate(model, glm::radians(FLegs), glm::vec3(1.0f, 0.0f, 0.0f));
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        F_RightLeg.Draw(lightingShader);

        // Back Left Leg
        model = modelTemp;
        model = glm::translate(model, glm::vec3(0.082f, -0.046f, -0.218f));
        model = glm::rotate(model, glm::radians(RLegs), glm::vec3(1.0f, 0.0f, 0.0f));
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        B_LeftLeg.Draw(lightingShader);

        // Back Right Leg
        model = modelTemp;
        model = glm::translate(model, glm::vec3(-0.083f, -0.057f, -0.231f));
        model = glm::rotate(model, glm::radians(RLegs), glm::vec3(-1.0f, 0.0f, 0.0f));
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        B_RightLeg.Draw(lightingShader);

        // --- Pelota ---
        model = glm::mat4(1.0f);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glUniform1i(glGetUniformLocation(lightingShader.Program, "transparency"), 1);
        model = glm::rotate(model, glm::radians(rotBall), glm::vec3(0.0f, 1.0f, 0.0f));
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        Ball.Draw(lightingShader);
        glDisable(GL_BLEND);
        glBindVertexArray(0);

        // --- Lámpara ---
        lampShader.Use();
        modelLoc = glGetUniformLocation(lampShader.Program, "model");
        GLint viewLoc2 = glGetUniformLocation(lampShader.Program, "view");
        GLint projLoc2 = glGetUniformLocation(lampShader.Program, "projection");
        glUniformMatrix4fv(viewLoc2, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(projLoc2, 1, GL_FALSE, glm::value_ptr(projection));

        model = glm::mat4(1.0f);
        model = glm::translate(model, lightPos);
        model = glm::scale(model, glm::vec3(0.2f));
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

        model = glm::mat4(1.0f);
        model = glm::translate(model, pointLightPositions[0]);
        model = glm::scale(model, glm::vec3(0.2f));
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glBindVertexArray(0);

        // Swap
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}

// Moves/alters the camera positions based on user input
void DoMovement()
{
    if (keys[GLFW_KEY_W] || keys[GLFW_KEY_UP])    camera.ProcessKeyboard(FORWARD, deltaTime);
    if (keys[GLFW_KEY_S] || keys[GLFW_KEY_DOWN])  camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (keys[GLFW_KEY_A] || keys[GLFW_KEY_LEFT])  camera.ProcessKeyboard(LEFT, deltaTime);
    if (keys[GLFW_KEY_D] || keys[GLFW_KEY_RIGHT]) camera.ProcessKeyboard(RIGHT, deltaTime);

    if (keys[GLFW_KEY_T]) { pointLightPositions[0].x += 0.01f; }
    if (keys[GLFW_KEY_G]) { pointLightPositions[0].x -= 0.01f; }
    if (keys[GLFW_KEY_Y]) { pointLightPositions[0].y += 0.01f; }
    if (keys[GLFW_KEY_H]) { pointLightPositions[0].y -= 0.01f; }
    if (keys[GLFW_KEY_U]) { pointLightPositions[0].z -= 0.1f; }
    if (keys[GLFW_KEY_J]) { pointLightPositions[0].z += 0.01f; }
}

// Is called whenever a key is pressed/released via GLFW
void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (GLFW_KEY_ESCAPE == key && GLFW_PRESS == action) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }

    if (key >= 0 && key < 1024) {
        if (action == GLFW_PRESS)      keys[key] = true;
        else if (action == GLFW_RELEASE) keys[key] = false;
    }

    if (keys[GLFW_KEY_SPACE]) {
        active = !active;
        Light1 = active ? glm::vec3(0.2f, 0.8f, 1.0f) : glm::vec3(0.0f);
    }
    if (keys[GLFW_KEY_N]) {
        AnimBall = !AnimBall;
    }
    if (keys[GLFW_KEY_B]) {
        dogAnim = 1;
        // ARRANQUE: ir hacia el centro (fase diagonal "a la mitad" por frame, sin girar el cuerpo)
        dogState = WALK_DIAG_CENTER;
    }
}

void Animation() {
    // Bola
    if (AnimBall) {
        rotBall += 0.4f;
    }

    // Rotación libre del perro (si la usas)
    if (AnimDog) {
        rotDog -= 0.6f;
    }

    // Animación cíclica de patas / cabeza / cola
    if (dogAnim == 1) {
        if (!step) {
            RLegs += 0.3f; FLegs += 0.3f; head += 0.3f; tail += 0.3f;
            if (RLegs > 15.0f) step = true;
        }
        else {
            RLegs -= 0.3f; FLegs -= 0.3f; head -= 0.3f; tail -= 0.3f;
            if (RLegs < -15.0f) step = false;
        }
    }

    // Movimiento con límites y giros
    float moveStep = DOG_WALK_SPEED * deltaTime; // unidades/s
    float turnStep = DOG_TURN_SPEED * deltaTime; // grados/s

    switch (dogState) {
    case IDLE:
        break;

        // +Z hasta orilla frontal
    case WALK_FWD:
        dogPos.z += moveStep;
        if (dogPos.z >= (FLOOR_MAX_Z - SAFE_MARGIN)) {
            dogPos.z = (FLOOR_MAX_Z - SAFE_MARGIN);
            dogState = TURN_RIGHT_1;
            dogTargetRot = dogRot + 90.0f; // giro horario
        }
        break;

        // Primer giro horario (+90)
    case TURN_RIGHT_1:
        if (dogRot < dogTargetRot) {
            dogRot += turnStep;
            if (dogRot > dogTargetRot) dogRot = dogTargetRot;
        }
        if (dogRot == dogTargetRot) {
            dogState = WALK_RIGHT; // caminar a +X
        }
        break;

        // +X hasta orilla derecha
    case WALK_RIGHT:
        dogPos.x += moveStep;
        if (dogPos.x >= (FLOOR_MAX_X - SAFE_MARGIN)) {
            dogPos.x = (FLOOR_MAX_X - SAFE_MARGIN);
            dogState = TURN_RIGHT_2;
            dogTargetRot = dogRot + 90.0f; // segundo giro horario
        }
        break;

        // Segundo giro horario (+90) => queda apuntando a -Z
    case TURN_RIGHT_2:
        if (dogRot < dogTargetRot) {
            dogRot += turnStep;
            if (dogRot > dogTargetRot) dogRot = dogTargetRot;
        }
        if (dogRot == dogTargetRot) {
            dogState = WALK_BACK; // seguir caminando hacia -Z
        }
        break;

        // -Z hasta la orilla trasera
    case WALK_BACK:
        dogPos.z -= moveStep;
        if (dogPos.z <= (FLOOR_MIN_Z + SAFE_MARGIN)) {
            dogPos.z = (FLOOR_MIN_Z + SAFE_MARGIN);
            dogState = TURN_LEFT_CCW;
            dogTargetRot = dogRot + 90.0f; // giro horario final
        }
        break;

        // Último giro: al terminar, ve al centro (sin diagonal 45°)
    case TURN_LEFT_CCW:
        if (dogRot < dogTargetRot) {
            dogRot += turnStep;
            if (dogRot > dogTargetRot) dogRot = dogTargetRot;
        }
        if (dogRot == dogTargetRot) {
            dogState = WALK_DIAG_CENTER; // ir al centro
        }
        break;

    // --- Ir al centro (mitad del tramo por frame) y SIN girar el cuerpo ---
    case WALK_DIAG_CENTER:
    {
        // Mantener el cuerpo mirando al frente (sin girar lateral)
        dogRot = -45.0f;

        // Vector hacia el centro
        float dx = CENTER_X - dogPos.x;
        float dz = CENTER_Z - dogPos.z;
        float dist = sqrtf(dx*dx + dz*dz);

        // ¿Llegó?
        if (dist <= CENTER_EPS) {
            dogPos.x = CENTER_X;
            dogPos.z = CENTER_Z;
            dogState = CENTER_ALIGN; // nuevo estado: girar en el centro (a +Z, aunque ya está)
            break;
        }

        // Avanza SOLO la MITAD del tramo restante hacia el centro
        float nx = dx / dist;
        float nz = dz / dist;

        float stepMove = moveStep;
        float halfDist = dist * 0.5f;
        if (stepMove > halfDist) stepMove = halfDist; // <- mitad del tramo actual

        float tx = dogPos.x + nx * stepMove;
        float tz = dogPos.z + nz * stepMove;

        // Limitar al piso
        if (tx < FLOOR_MIN_X + SAFE_MARGIN) tx = FLOOR_MIN_X + SAFE_MARGIN;
        if (tx > FLOOR_MAX_X - SAFE_MARGIN) tx = FLOOR_MAX_X - SAFE_MARGIN;
        if (tz < FLOOR_MIN_Z + SAFE_MARGIN) tz = FLOOR_MIN_Z + SAFE_MARGIN;
        if (tz > FLOOR_MAX_Z - SAFE_MARGIN) tz = FLOOR_MAX_Z - SAFE_MARGIN;

        dogPos.x = tx;
        dogPos.z = tz;
    }
    break;

    case CENTER_ALIGN:
    {
        // Girar en el lugar hasta mirar a +Z (0°)
        float diff = 0.0f - dogRot;
        while (diff > 180.0f) diff -= 360.0f;
        while (diff < -180.0f) diff += 360.0f;

        if (fabsf(diff) > 0.5f) {
            float step = (diff > 0.0f ? +turnStep : -turnStep);
            if (fabsf(step) > fabsf(diff)) step = diff;
            dogRot += step;
            if (dogRot >= 360.0f) dogRot -= 360.0f;
            if (dogRot < 0.0f)    dogRot += 360.0f;
        } else {
            // Ya quedó recto: seguir de frente y continuar el ciclo normal
            dogRot = 0.0f;       // mirando +Z
            dogState = WALK_FWD; // continúa el recorrido recto
        }
    }
    break;

    // (Definidos pero no usados en el nuevo ciclo recto)
    case TURN_45_CW:
        if (dogRot < dogTargetRot) {
            dogRot += turnStep;
            if (dogRot > dogTargetRot) dogRot = dogTargetRot;
        }
        if (dogRot == dogTargetRot) {
            dogState = WALK_STRAIGHT_45;
        }
        break;

    case WALK_STRAIGHT_45:
    {
        float yaw = glm::radians(dogRot);
        float dirX = sinf(yaw);
        float dirZ = cosf(yaw);

        float nx = dogPos.x + dirX * moveStep;
        float nz = dogPos.z + dirZ * moveStep;

        bool hitEdge = false;
        if (nx < FLOOR_MIN_X + SAFE_MARGIN) { nx = FLOOR_MIN_X + SAFE_MARGIN; hitEdge = true; }
        if (nx > FLOOR_MAX_X - SAFE_MARGIN) { nx = FLOOR_MAX_X - SAFE_MARGIN; hitEdge = true; }
        if (nz < FLOOR_MIN_Z + SAFE_MARGIN) { nz = FLOOR_MIN_Z + SAFE_MARGIN; hitEdge = true; }
        if (nz > FLOOR_MAX_Z - SAFE_MARGIN) { nz = FLOOR_MAX_Z - SAFE_MARGIN; hitEdge = true; }

        dogPos.x = nx;
        dogPos.z = nz;

        if (hitEdge) {
            dogState = IDLE;
        }
    }
    break;
    }

    // Clamp suave para no salir del piso
    if (dogPos.x < FLOOR_MIN_X + SAFE_MARGIN) dogPos.x = FLOOR_MIN_X + SAFE_MARGIN;
    if (dogPos.x > FLOOR_MAX_X - SAFE_MARGIN) dogPos.x = FLOOR_MAX_X - SAFE_MARGIN;
    if (dogPos.z < FLOOR_MIN_Z + SAFE_MARGIN) dogPos.z = FLOOR_MIN_Z + SAFE_MARGIN;
    if (dogPos.z > FLOOR_MAX_Z - SAFE_MARGIN) dogPos.z = FLOOR_MAX_Z - SAFE_MARGIN;

    // Normaliza el ángulo
    if (dogRot >= 360.0f) dogRot -= 360.0f;
    if (dogRot < 0.0f)    dogRot += 360.0f;
}

void MouseCallback(GLFWwindow* window, double xPos, double yPos)
{
    if (firstMouse)
    {
        lastX = static_cast<float>(xPos);
        lastY = static_cast<float>(yPos);
        firstMouse = false;
    }

    GLfloat xOffset = static_cast<float>(xPos) - lastX;
    GLfloat yOffset = lastY - static_cast<float>(yPos);

    lastX = static_cast<float>(xPos);
    lastY = static_cast<float>(yPos);

    camera.ProcessMouseMovement(xOffset, yOffset);
}



