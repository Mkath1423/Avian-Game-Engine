#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <format>

#include "ErrorChecking.h"
#include "rendering/Buffers.h"
#include "rendering/Shading.h"
#include "Inputs.h"

#include "Window.h"

#define print(x) std::cout << x << "\n";

using Rendering::Buffers::VBO;
using Rendering::Buffers::EBO;
using Rendering::Shading::Shader;
using Context::Window;
using Context::CreationHint;

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    /* Create a windowed mode window and its OpenGL context */
    Window w = Window(750, 750, "WINDOW TEST");

    w.create();
    window = w.getId();

    if (!window)
    {
        glfwTerminate();
        return -1;
    }


    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    Inputs::setCallbacks(window);

    if (glewInit() != GLEW_OK)
        std::cout << "Error!" << std::endl;

    std::cout << glGetString(GL_VERSION) << std::endl;

    float positions[] = {
        0.0f, 0.0f, 0,      1.0f, 0.0f, 0.5f, 1.0f,
        0.0f, 1.0f, 0,      0.0f, 0.0f, 0.0f, 1.0f,
        1.0f, 1.0f,  0,     0.0f, 0.0f, 0.0f, 1.0f,
        1.0f, 0.0f,  0,     0.0f, 0.0f, 0.0f, 1.0f,

        0.0f, 0.0f, 0,    1.0f, 1.0f, 0.0f, 1.0f,
        0.0f, -0.25f, 0,     1.0f, 1.0f, 0.0f, 1.0f,
        -0.10f, -0.5f, 0,     1.0f, 1.0f, 0.0f, 1.0f,
        -0.1f, 0.0f, 0,     1.0f, 1.0f, 0.0f, 1.0f,

    }; 

   
    unsigned int indexs[] = {
        0, 1, 2,
        2, 3, 0,
    };

    int vertexSize = (3 + 4) * sizeof(float);

    for (int i = 0; i < 6 * 8; i++) {
        print(positions[i]);
    }

    unsigned int vao;
    GLCall(glGenVertexArrays(1, &vao));
    GLCall(glBindVertexArray(vao))

    VBO vbo = VBO(8 * vertexSize);

    GLCall(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vertexSize, 0));
    GLCall(glEnableVertexAttribArray(0));

    GLCall(glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, vertexSize, (void*)(3 * sizeof(float))));
    GLCall(glEnableVertexAttribArray(1));

    vbo.bufferSubData(positions);


    EBO ibo = EBO(indexs, 6, 4, 2);


    /*unsigned int ibo;
    GLCall(glGenBuffers(1, &ibo));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3 * 2 * sizeof(unsigned int), &indexs, GL_STATIC_DRAW));*/

    GLCall(glBindVertexArray(0))
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));


	/*VAOLayout vaoLayout;

	ParseShader(filename, &vertexShader, &fragmentShader);*/

    Shader shader = Shader("resources/shaders/default.vert", "resources/shaders/default.frag");
    shader.use();


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		Inputs::update(0.1f);

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        GLCall(glBindVertexArray(vao))

        GLCall(glDrawElements(GL_TRIANGLES, 6 * 2, GL_UNSIGNED_INT, nullptr));

        //print("x: " + std::to_string(w.getSize().x) + "y: " + std::to_string(w.getSize().y))

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

