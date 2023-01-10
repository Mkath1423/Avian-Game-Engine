#include "rendering/Vertex.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Rendering {
	namespace VertexArray {
		AttributeSettings::AttributeSettings(
			unsigned int id,
			unsigned int type,
			unsigned int size,
			unsigned int offset,
			unsigned int stride,
			bool normalized,
			unsigned int divisor
		) {
			this->id = id;
			this->type = type;
			this->size = size;
			this->offset = offset;
			this->stride = stride;
			this->normalized = normalized;
			this->divisor = divisor;
		}

		void AttributeSettings::disable() {
			glDisableVertexAttribArray(id);
		}

		void AttributeSettings::enable() {
			glEnableVertexAttribArray(id);
		}

		void AttributeSettings::set_enabled(bool enable) {
			if (enable) {
				this->enable();
			}
			else {
				disable();
			}
		}

		template<typename T>
		VertexArray<T>::VertexArray(int max_count, std::vector<AttributeSettings> attributeSettings)
		{
			this->count = max_count;

			unsigned int vao;
			glGenVertexArrays(1, &vao);
			glBindVertexArray(vao);

			// Create buffer and copy data
			VBO positions_vbo = VBO(numberOfVertecies * 2 * sizeof(float));

			// define vertex layout
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
			glEnableVertexAttribArray(0);

			VBO colors_vbo = VBO(numberOfVertecies * 4 * sizeof(float));

			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
			glEnableVertexAttribArray(1);

			// Create index buffer
			EBO ibo = EBO(indices, 6, 4, 2);

			glBindVertexArray(0);

			positions_vbo.bufferSubData(positions);
			colors_vbo.bufferSubData(colors);

		}

	}
}