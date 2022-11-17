#include "rendering/Shading.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "ErrorChecking.h"

namespace Rendering {

	namespace Shading {
		namespace {
			unsigned int CompileShader(unsigned int type, const std::string& source) {

				unsigned int id = glCreateShader(type);
				const char* src = source.c_str();

				glShaderSource(id, 1, &src, nullptr);

				glCompileShader(id);

				int result;
				glGetShaderiv(id, GL_COMPILE_STATUS, &result);

				if (result == GL_FALSE) {
					int length;
					glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);


					char* message = (char*)alloca(length * sizeof(char));
					glGetShaderInfoLog(id, length, &length, message);

					std::cout << "Shader Compilation Error: " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << "" << std::endl;
					std::cout << message << std::endl;

					glDeleteShader(id);
					return 0;
				}

				return id;
			}

			unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader) {

				unsigned int program = glCreateProgram();

				unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
				unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

				glAttachShader(program, vs);
				glAttachShader(program, fs);

				glLinkProgram(program);

				glValidateProgram(program);

				glDeleteShader(vs);
				glDeleteShader(fs);

				return program;
			}

			std::string ParseShader(const std::string& filepath) {
				std::ifstream stream(filepath);

				std::string line;
				std::stringstream source;

				while (std::getline(stream, line)) {
					std::cout << line << std::endl;
					source << line << "\n";
				}

				return source.str();
			}
		}

		Shader::Shader(const std::string& vertSrc, const std::string& fragSrc) {
			std::string vert = ParseShader(vertSrc);
			std::string frag = ParseShader(fragSrc);

			id = CreateShader(vert, frag);

			isActive = false;
		}

		Shader::~Shader() {
			deleteShader();
		}

		unsigned int Shader::getID() {
			return id;
		}

		void Shader::use() {
			if (isActive) return;

			glUseProgram(id);
			isActive = true;
		}

		void Shader::detach() {
			if (!isActive) return;

			glUseProgram(0);
			isActive = false;
		}

		void Shader::deleteShader() {
			glDeleteShader(id);
		}
	}
}