#include "Window.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/vec2.hpp>

#include <map>
#include <string>

#include "events/VectorState.h"
#include "events/BooleanState.h"

namespace Context {
    Window::Window(int width, int height, std::string title) :
        width(width),
        height(height),
        title(title)
    {
 
        window_size = Events::VectorStateTracker(glm::vec2(width, height), glm::vec2(0, 0));

        framebuffer_size = Events::VectorStateTracker(glm::vec2(width, height), glm::vec2(0, 0));

        window_content_scale = Events::VectorStateTracker(glm::vec2(width, height), glm::vec2(0, 0));

        window_pos = Events::VectorStateTracker(glm::vec2(width, height), glm::vec2(0, 0));

        window_iconify = Events::BooleanStateTracker();

        window_maximize = Events::BooleanStateTracker();

        window_focus = Events::BooleanStateTracker();
    }

    void Window::setWindowHint(CreationHint hint, bool value)
    {
        glfwWindowHint((int)hint, value);
    }

    void Window::create()
    {
        id = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    }

    //TODO: REMOVE ONCE LOOP IS ABSTRACTED
    GLFWwindow* Window::getId() {
        return id;
    }

    void Window::setSize(int width, int height)
    {
        this->width = width;
        this->height = height;
    }


    void Window::setWindowCallbacks() {
        glfwSetWindowSizeCallback(id, window_size_callback);
    }
        

    void Window::window_close_callback(GLFWwindow* window) { }

    void Window::window_refresh_callback(GLFWwindow* window) { }

    void Window::window_size_callback(GLFWwindow* window, int width, int height)
    {
        if (!(window == id)) return;
        window_size.updatePosition(static_cast<float>(width), static_cast<float>(height));
    }

    void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
        if (!(window == id)) return;
        framebuffer_size.updatePosition(static_cast<float>(width), static_cast<float>(height));
    }
    void Window::window_content_scale_callback(GLFWwindow* window, float xscale, float yscale)
    {
        if (!(window == id)) return;
        window_content_scale.updatePosition(static_cast<float>(width), static_cast<float>(height));
    }
    void Window::window_pos_callback(GLFWwindow* window, int xpos, int ypos)
    {
        if (!(window == id)) return;
        window_pos.updatePosition(static_cast<float>(width), static_cast<float>(height));
    }
    void Window::window_iconify_callback(GLFWwindow* window, int iconified)
    {
        if (!(window == id)) return;
        window_iconify.updateValue((iconified == GL_TRUE) ? true : false);
    }
    void Window::window_maximize_callback(GLFWwindow* window, int maximized)
    {
        if (!(window == id)) return;
    }
    void Window::window_focus_callback(GLFWwindow* window, int focused)
    {
        if (!(window == id)) return;
    }

    glm::vec2 Window::getSize() { return window_size.getPosition(); }
    VectorState Window::getSizeInfo() { return window_size.getState(); }

    glm::vec2 Window::getFrameBufferSize() { return framebuffer_size.getPosition(); }
    VectorState Window::getFrameBufferSizeInfo() { return framebuffer_size.getState(); }

    glm::vec2 Window::getContentScale() { return window_content_scale.getPosition(); }
    VectorState Window::getContentScaleInfo() { return window_content_scale.getState(); }

    glm::vec2   Window::getPosition() { return window_pos.getPosition(); }
    glm::vec2   Window::getVelocity() { return window_pos.getVelocity(); }
    VectorState Window::getPositionInfo() { return window_pos.getState(); }

    bool         Window::getWindowIconify() { return window_iconify.getValue(); }
    BooleanState Window::getWindowIconifyInfo() { return window_iconify.getState(); }

    bool         Window::getWindowMaximize() { return window_maximize.getValue(); }
    BooleanState Window::getWindowMaximizeInfo() { return window_maximize.getState(); }

    bool         Window::getWindowFocus() { return window_focus.getValue(); }
    BooleanState Window::getWindowFocusInfo() { return window_focus.getState(); }
}