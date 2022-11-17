#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <map>
#include <string>

#include <VectorState.h>
#include <BooleanState.h>

using Events::BooleanStateTracker;
using Events::BooleanState;
using Events::VectorStateTracker;
using Events::VectorState;

namespace Context {

	enum class CreationHint {
		RESIZABLE=GLFW_RESIZABLE,
		VISIBLE = GLFW_VISIBLE,
		DECORATED = GLFW_DECORATED,
		FOCUSED = GLFW_FOCUSED,
		AUTO_ICONIFY = GLFW_AUTO_ICONIFY,
		FLOATING = GLFW_FLOATING,
		MAXIMIZED = GLFW_MAXIMIZED,
		CENTER_CURSOR = GLFW_CENTER_CURSOR,
		TRANSPARENT_FRAMEBUFFER = GLFW_TRANSPARENT_FRAMEBUFFER,
		FOCUS_ON_SHOW = GLFW_FOCUS_ON_SHOW,
		SCALE_TO_MONITOR = GLFW_SCALE_TO_MONITOR,
		REFRESH_RATE = GLFW_REFRESH_RATE
	};

	enum class Attribute {
		RESIZABLE = GLFW_RESIZABLE,
		DECORATED = GLFW_DECORATED,
		FOCUSED = GLFW_FOCUSED,
		AUTO_ICONIFY = GLFW_AUTO_ICONIFY,
		FLOATING = GLFW_FLOATING,
		MAXIMIZED = GLFW_MAXIMIZED,
		FOCUS_ON_SHOW = GLFW_FOCUS_ON_SHOW,
	};

	class Window {
	private:
		GLFWwindow* id = nullptr;
		
		std::string title = "Catalyst Window";
		GLFWimage icon;

		int width = 640;
		int height = 480;

		GLFWmonitor* monitor;
		
		void window_close_callback(GLFWwindow* window);
		void window_refresh_callback(GLFWwindow* window);

		VectorStateTracker window_size;
		void window_size_callback(GLFWwindow* window, int width, int height);

		VectorStateTracker framebuffer_size;
		void framebuffer_size_callback(GLFWwindow* window, int width, int height);

		VectorStateTracker window_content_scale;
		void window_content_scale_callback(GLFWwindow* window, float xscale, float yscale);

		VectorStateTracker window_pos;
		void window_pos_callback(GLFWwindow* window, int xpos, int ypos);

		BooleanStateTracker window_iconify;
		void window_iconify_callback(GLFWwindow* window, int iconified);

		BooleanStateTracker window_maximize;
		void window_maximize_callback(GLFWwindow* window, int maximized);

		BooleanStateTracker window_focus;
		void window_focus_callback(GLFWwindow* window, int focused);

	public:
		Window(int width, int height, std::string title);
		// Window(int width, int height, std::string title, int monitor);

		void setWindowHint(CreationHint hint, bool value);
		void create();

		void setWindowCallbacks();
			
		void setSize(int width, int height);

		glm::vec2 getSize();
		VectorState getSizeInfo();

		glm::vec2 getFrameBufferSize();
		VectorState getFrameBufferSizeInfo();

		glm::vec2 getContentScale();
		VectorState getContentScaleInfo();

		glm::vec2 getPosition();
		glm::vec2 getVelocity();
		VectorState getPositionInfo();

		bool getWindowIconify();
		BooleanState getWindowIconifyInfo();

		bool getWindowMaximize();
		BooleanState getWindowMaximizeInfo();

		bool getWindowFocus();
		BooleanState getWindowFocusInfo();

		GLFWwindow* getId();
	};



}