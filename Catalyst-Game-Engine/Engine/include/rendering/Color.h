#pragma once
#include <glm/vec4.hpp>
#include <glm/vec3.hpp>

namespace color {

	glm::vec4 HSVtoRGB(float h, float s, float v, float a = 1.0f);
	glm::vec4 HSVtoRGB(glm::vec4 hsva);

	glm::vec4 RGBtoHSV(float r, float g, float b, float a = 1.0f);
	glm::vec4 RGBtoHSV(glm::vec4 rgba);

	enum ColorSpace {
		RGB,
		HSV
	};

	class Color
	{
	private:
		glm::vec4 rgba;

	public:
		Color(glm::vec3 color, ColorSpace colorSpace);
		Color(glm::vec4 color, ColorSpace colorSpace);
		Color(float arg1, float arg2, float arg3, ColorSpace colorSpace);
		Color(float arg1, float arg2, float arg3, float alpha, ColorSpace colorSpace);

		void setRGBA(glm::vec4 color);
		glm::vec4 getRGBA();

		void setHSVA(glm::vec4 color);
		glm::vec4 getHSVA();

		float getRed();
		void  setRed(float red);

		float getGreen();
		void  setGreen(float green);

		float getBlue();
		void  setBlue(float blue);

		float getAlpha();
		void  setAlpha(float alpha);
	
		float getHue();
		void  setHue(float hue);

		float getSaturation();
		void  setSaturation(float saturation);

		float getValue();
		void  setValue(float value);
	};
}




