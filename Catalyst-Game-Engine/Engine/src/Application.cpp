#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <format>

#include "ErrorChecking.h"
#include "rendering/Buffers.h"
#include "rendering/Shading.h"
#include "Inputs.h"

#include "Window.h"

#define print(x) std::cout << x << std::endl;

using Rendering::Buffers::VBO;
using Rendering::Buffers::EBO;
using Rendering::Shading::Shader;
using Context::Window;

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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
        -1.f, -1.f,
        0.f, -1.f,
        0.f, 0.f,
        -1.f, 0.f,

        0.f, 0.f,
        0.f, 1.f,
        1.f, 1.f,
        1.f, 0.f
    }; 
 

    unsigned int indexs[] = {
        0, 1, 2,
        2, 3, 0
    };

    unsigned int vao;
    GLCall(glGenVertexArrays(1, &vao));
    GLCall(glBindVertexArray(vao))

    VBO vbo = VBO(8 * 2 * sizeof(float));
    vbo.bufferSubData(positions);

    GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(float), 0));
    GLCall(glEnableVertexAttribArray(0));

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
    
     GLCall(int u_colorID = glGetUniformLocation(shader.getID(), "u_Color"));

     ASSERT(u_colorID != -1);

     float r = 0.0f;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		Inputs::update(0.1f);

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        GLCall(glBindVertexArray(vao))

        GLCall(glUniform4f(u_colorID, r, 0.8f, 0.3f, 1.0f));
        GLCall(glDrawElements(GL_TRIANGLES, 6 * 2, GL_UNSIGNED_INT, nullptr));
        r += 0.01f;

        if (r >= 1.0f) {
            r = 0;
        }

        print("x: " + std::to_string(w.getSize().x) + "y: " + std::to_string(w.getSize().y))

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

