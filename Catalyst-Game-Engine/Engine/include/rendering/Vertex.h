#pragma once

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

#include <vector>

#include "rendering/Buffers.h"

using Rendering::Buffers::VBO;
using Rendering::Buffers::EBO;

namespace Rendering {
	namespace VertexArray {

		class AttributeSettings {

		private:
			unsigned int id;
			unsigned int type;
			unsigned int size;
			bool normalized;
			unsigned int offset;
			unsigned int stride;
			unsigned int divisor;

			void disable();
			void enable();
			void set_enabled(bool is_enabled);

		public:
			AttributeSettings(
				unsigned int id,
				unsigned int type,
				unsigned int size,
				unsigned int offset,
				unsigned int stride,
				bool normalized = false,
				unsigned int divisor = 0
			);

			friend class VAO;
		};

		template <typename T>
		class VertexArray {
		private:

			int count;

			unsigned int id;

			VBO vbo;
			std::vector<T> verticies;

			EBO ebo;
			std::vector<int> indicies;

		public:

			VertexArray(int max_count, std::vector<AttributeSettings> attributeSettings);
			~VertexArray();

			void addVerticies(const T* verticies, const int* indicies, const int count);
			void setVerticies(const T* verticies, const int* indicies, const int count, const int index);

			int getSize(); 
		};

	}
}
