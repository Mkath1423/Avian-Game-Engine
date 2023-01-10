#pragma once

#include <string>
#include <GL/glew.h>

#include <vector>

namespace Rendering {
	namespace Buffers {

		namespace {
			// Buffer formats
			const int quad[] = {0, 1, 2, 2, 3, 0};

			const int * indexFormats[1] = { quad };
		}
		
		enum class IndexFormats:int{
			Quad
		};

		

		class VBO {
		private:
			unsigned int bufferID;
			unsigned int bufferSize;

			bool isBound;

			void initializeBuffer();

		public:
			VBO(unsigned int sizeBytes);
			~VBO();

			void bind();
			void unbind();

			void bufferSubData(float* data, int subDataSize = -1, const int offset = 0);
		};

		class EBO {
		private:
			unsigned int bufferID;
			unsigned int bufferSize;

		public:
			EBO(const unsigned int* indices, const int indices_per_element, const int vertices_per_element, const int numberElements);
			~EBO();

			void bind();
			void unbind();
		};

		class VAO {
		private:
			VBO vbo;
			EBO ebo;

			unsigned int vertexSize;

		public:
			VAO(VBO vbo, EBO ebo);
		};

		//// vao
		//int generateVAO();
		//void bindVAO(const int vaoID);
		//void unbindVAO();

		//void setLayout(const int location, const int size, const int stride, const int offset);

		//// buffers
		//int generateBuffer();
		//void bindBuffer(BufferType bufferFormat, const int bufferID);
		//void bufferData(BufferType bufferFormat, const int bufferID, const void* data);
	}
}
