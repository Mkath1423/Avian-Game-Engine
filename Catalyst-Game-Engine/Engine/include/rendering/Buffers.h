#pragma once

#include <string>
#include <GL/glew.h>

#include <vector>

#include "ErrorChecking.h"

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

		
		template<typename T>
		class Buffer {
		private:
			unsigned int size;
			unsigned int id;

		public:


			Buffer(unsigned int size_, unsigned int usage_ = GL_DYNAMIC_DRAW) {
				this->size = size_;

				glGenBuffers(1, &id);
				GLCall(glNamedBufferData(id, size, nullptr, usage_));

			}

			~Buffer() {
				glDeleteBuffers(1, &id);
			};

			void bind(unsigned int target) {
				GLCall(glBindBuffer(target, id))
			}

			void buffer(const T* data) {
				GLCall(glNamedBufferSubData(id, 0, size, data));
			}

			void buffer(const T* data, unsigned int offset_, unsigned int size_) {
				GLCall(glBufferSubData(id,
					offset_,
					(offset_ + size_) <= size ? size_ : (size - offset_),
					data
				));
			}
		};

		class VertexBuffer {
		private:
			Buffer<float> vertexBuffer;
			Buffer<int> indexBuffer;

			unsigned int size;

			int id;

		public:

			VertexBuffer(const float* vertexArray, const int* indexArray, unsigned int size);
			~VertexBuffer();

			void set(const float* verticies, const int* indicies, const unsigned int count, const unsigned int offset);

			void draw();
			void draw(unsigned int offset, unsigned  int size);
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
