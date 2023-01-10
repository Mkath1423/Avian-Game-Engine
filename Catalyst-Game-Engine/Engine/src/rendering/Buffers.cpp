#include "rendering/Buffers.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "ErrorChecking.h"

namespace Rendering {
	namespace Buffers {
		// attribute layout


		// vertex buffer
		VBO::VBO(const unsigned int sizeBytes) {
			bufferSize = sizeBytes;

			bufferID = -1;
			isBound = false;
			GLCall(glGenBuffers(1, &bufferID));

			bind();
			initializeBuffer();
		}

		VBO::~VBO() {
			GLCall(glDeleteBuffers(1, &bufferID))
		}

		void VBO::bind() {
			if (isBound) return;

			GLCall(glBindBuffer(GL_ARRAY_BUFFER, bufferID))
				isBound = true;
		}

		void VBO::unbind() {
			if (!isBound) return;

			GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0))
				isBound = false;
		}

		void VBO::initializeBuffer() {
			bind();
			GLCall(glBufferData(GL_ARRAY_BUFFER, bufferSize, nullptr, GL_DYNAMIC_DRAW))
		}

		void VBO::bufferSubData(float* data, const int subDataSize, const int offset) {
			int size = subDataSize;

			if (size + offset > bufferSize) size = bufferSize - offset;
			if (size <= 0) size = bufferSize;

			GLCall(glNamedBufferSubData(bufferID, 0, size, data));
		}


		// element buffer
		EBO::EBO(const unsigned int* indices,
			const int indices_per_element,
			const int vertices_per_element,
			const int numberElements)
		{
			unsigned int* buffer = new unsigned int[indices_per_element * numberElements];

			for (int elem = 0; elem < numberElements; elem++) {
				for (int i = 0; i < indices_per_element; i++) {
					buffer[i + elem * indices_per_element] = indices[i] + elem * vertices_per_element;
				}
			}

			bufferSize = indices_per_element * numberElements * sizeof(unsigned int);

			bufferID = -1;
			GLCall(glGenBuffers(1, &bufferID));

			bind();
			GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, bufferSize, buffer, GL_STATIC_DRAW));
			delete[] buffer;

		}

		EBO::~EBO()
		{
			GLCall(glDeleteBuffers(1, &bufferID))
		}

		void EBO::bind()
		{
			GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID));
		}

		void EBO::unbind()
		{
			GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
		}
	}
}