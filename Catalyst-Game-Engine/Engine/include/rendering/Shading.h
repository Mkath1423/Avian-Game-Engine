#pragma once

#include <string>
#include <GL/glew.h>

namespace Rendering {

	namespace Shading {

		namespace {
			const std::string shaders[1][2] = { {"vertsrc", "fragsrc"} };
		}

		enum class ShaderType {
			DEFAULT
		};

		class Shader {

		private:

			unsigned int id;

			bool isActive;

			void deleteShader();
		public:
			Shader(const std::string& vertSrc, const std::string& fragSrc);
			~Shader();

			unsigned int getID();

			void use();
			void detach();

		};
	}
}