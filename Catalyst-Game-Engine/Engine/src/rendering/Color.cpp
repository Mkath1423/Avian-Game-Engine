#include "Color.h"

#include <glm/vec3.hpp>

namespace color {

	
	glm::vec4 HSVtoRGB(float h, float s, float v, float a) {
		float c = v * s;
		float x = c * (1 - abs(int(h / 60.0f) % 2 - 1));
		float m = v - c;

		glm::vec4 out(0.0f);

		if      (0.0f   <= h && h < 60.0f ) out = glm::vec4(c, x, 0.0f, a);
		else if (60.0f  <= h && h < 120.0f) out = glm::vec4(x, c, 0.0f, a);
		else if (120.0f <= h && h < 180.0f) out = glm::vec4(0.0f, c, x, a);
		else if (180.0f <= h && h < 240.0f) out = glm::vec4(0.0f, x, c, a);
		else if (240.0f <= h && h < 300.0f) out = glm::vec4(x, 0.0f, c, a);
		else                                out = glm::vec4(c, 0.0f, x, a);

		return glm::vec4(out.x + m, out.y + m, out.z + m, out.w);
	}
	glm::vec4 HSVtoRGB(glm::vec4 color) { return HSVtoRGB(color.x, color.y, color.z, color.w); }

	glm::vec4 RGBtoHSV(float r, float g, float b, float a) {
		float color[] = { r, g, b };

		float cmax = 0.0f;
		int maxIdx = -1;

		float cmin = 1.0f;
		int minIdx = -1;

		for (int i = 0; i < 3; i++) {
			if (color[i] > cmax) { cmax = color[i]; maxIdx = i; }
			if (color[i] < cmin) { cmin = color[i]; maxIdx = i; }
		}

		float cdiff = cmax - cmin;

		glm::vec4 out = glm::vec4(0.0f);

		// hue
		     if (maxIdx == 0) out.x = 60  * (int((g - b) / cdiff) % 6); 
		else if (maxIdx == 1) out.x = 60 * (((b - r) / cdiff) + 2);     
		else if (maxIdx == 2) out.x = 60 * (((b - r) / cdiff) + 4);     
		else                  out.x = 0.0f;                             

		// saturation
		if (cmax == 0.0f) out.y = 0;
		else              out.y = cdiff / cmax;

		// value
		out.z = cmax; 

		out.w = a;

		return out;
	}
	glm::vec4 RGBtoHSV(glm::vec4 color) { return RGBtoHSV(color.x, color.y, color.z, color.w); }

	Color::Color(const glm::vec3 color, ColorSpace colorSpace) {
		Color::Color(color.x, color.y, color.z, 1.0f, colorSpace);
	}

	Color::Color(const glm::vec4 color, ColorSpace colorSpace) {
		Color::Color(color.x, color.y, color.z, color.w, colorSpace);
	}

	Color::Color(const float arg1, const float arg2, const float arg3, ColorSpace colorSpace)
	{
		Color::Color(arg1, arg2, arg3, 1.0f, colorSpace);
	}

	Color::Color(float arg1, float arg2, float arg3, float arg4, ColorSpace colorSpace)
	{
		if (colorSpace == RGB) {
			rgba = glm::vec4(arg1, arg2, arg3, arg4);
		}

		else if (colorSpace == HSV) {
			rgba = HSVtoRGB(arg1, arg2, arg3);
		}
	}

	void Color::setRGBA(glm::vec4 color) {
		rgba = color;
	}

	glm::vec4 Color::getRGBA() {
		return glm::vec4(rgba);
	}

	void Color::setHSVA(glm::vec4 color) {
		rgba = HSVtoRGB(color);
	}
	
	glm::vec4 Color::getHSVA() {
		return RGBtoHSV(rgba);
	}

	float Color::getRed()
	{
		return rgba.r;
	}

	void Color::setRed(float red)
	{
		if (red > 1.0f) red /= 255;
		rgba.r = red;
	}

	float Color::getGreen()
	{
		return rgba.g;
	}

	void Color::setGreen(float green)
	{
		if (green > 1.0f) green /= 255;
		rgba.g = green;
	}

	float Color::getBlue()
	{
		return rgba.b;
	}

	void Color::setBlue(float blue)
	{
		if (blue > 1.0f) blue /= 255;
		rgba.b = blue;
	}

	float Color::getAlpha()
	{
		return rgba.a;
	}

	void Color::setAlpha(float alpha)
	{
		if (alpha > 1.0f) alpha /= 255;
		rgba.b = alpha;
	}

	float Color::getHue()
	{
		return RGBtoHSV(rgba.r, rgba.g, rgba.b).x;
	}

	void Color::setHue(float hue)
	{
		glm::vec4 hsva = RGBtoHSV(rgba);
		hsva.x = hue;
		rgba = hsva;
	}

	float Color::getSaturation()
	{
		return RGBtoHSV(rgba.r, rgba.g, rgba.b).y;
	}

	void Color::setSaturation(float saturation)
	{
		glm::vec4 hsva = RGBtoHSV(rgba);
		hsva.y = saturation;
		rgba = hsva;
	}

	float Color::getValue()
	{
		return RGBtoHSV(rgba.r, rgba.g, rgba.b).z;
	}

	void Color::setValue(float value)
	{
		glm::vec4 hsva = RGBtoHSV(rgba);
		hsva.z = value;
		rgba = hsva;

	}


}
