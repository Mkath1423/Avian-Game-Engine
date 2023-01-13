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
	

		}

	}
}