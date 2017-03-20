#include "Conversion.h"
#include "ColorSpace.h"
#include <cmath>

namespace ColorSpace {
	void RgbConverter::ToColorSpace(Rgb *color, Rgb *item) {
		item->r = color->r;
		item->g = color->g;
		item->b = color->b;
	}
	void RgbConverter::ToColor(Rgb *color, Rgb *item) {
		color->r = item->r;
		color->g = item->g;
		color->b = item->b;
	}

	void XyzConverter::ToColorSpace(Rgb *color, Xyz *item) {
		double r = color->r / 255.0;
		double g = color->g / 255.0;
		double b = color->b / 255.0;

		r = ((r > 0.04045) ? pow((r + 0.055) / 1.055, 2.4) : (r / 12.92)) * 100.0;
		g = ((g > 0.04045) ? pow((g + 0.055) / 1.055, 2.4) : (g / 12.92)) * 100.0;
		b = ((b > 0.04045) ? pow((b + 0.055) / 1.055, 2.4) : (b / 12.92)) * 100.0;

		item->x = r*0.4124 + g*0.3576 + b*0.1805;
		item->y = r*0.2126 + g*0.7152 + b*0.0722;
		item->z = r*0.0193 + g*0.1192 + b*0.9505;
	}
	void XyzConverter::ToColor(Rgb *color, Xyz *item) {
		double x = item->x / 100.0;
		double y = item->y / 100.0;
		double z = item->z / 100.0;

		double r = x * 3.2406 + y * -1.5372 + z * -0.4986;
		double g = x * -0.9689 + y * 1.8758 + z * 0.0415;
		double b = x * 0.0557 + y * -0.2040 + z * 1.0570;

		r = ((r > 0.0031308) ? (1.055*pow(r, 1 / 2.4) - 0.055) : (12.92*r)) * 255.0;
		g = ((g > 0.0031308) ? (1.055*pow(g, 1 / 2.4) - 0.055) : (12.92*g)) * 255.0;
		b = ((b > 0.0031308) ? (1.055*pow(b, 1 / 2.4) - 0.055) : (12.92*b)) * 255.0;
		
		color->r = r;
		color->g = g;
		color->b = b;
	}

	void HslConverter::ToColorSpace(Rgb *color, Hsl *item) {
	}
	void HslConverter::ToColor(Rgb *color, Hsl *item) {
	}

	void LabConverter::ToColorSpace(Rgb *color, Lab *item) {
		Xyz xyz;

		XyzConverter::ToColorSpace(color, &xyz);

		double x = xyz.x / 95.047;
		double y = xyz.y / 100.00;
		double z = xyz.z / 108.883;

		x = (x > 0.008856) ? pow(x, 1.0 / 3.0) : (7.787 * x + 16.0 / 116.0);
		y = (y > 0.008856) ? pow(y, 1.0 / 3.0) : (7.787 * y + 16.0 / 116.0);
		z = (z > 0.008856) ? pow(z, 1.0 / 3.0) : (7.787 * z + 16.0 / 116.0);

		item->l = (116.0 * y) - 16;
		item->a = 500 * (x - y);
		item->b = 200 * (y - z);
	}
	void LabConverter::ToColor(Rgb *color, Lab *item) {
		double y = (item->l + 16) / 116.0;
		double x = item->a / 500.0 + y;
		double z = y - item->b / 200.0;

		double x3 = x*x*x;
		double y3 = y*y*y;
		double z3 = z*z*z;

		x = ((x3 > 0.008856) ? x3 : ((x - 16.0 / 116.0) / 7.787)) * 95.047;
		y = ((y3 > 0.008856) ? y3 : ((y - 16.0 / 116.0) / 7.787)) * 100.0;
		x = ((z3 > 0.008856) ? z3 : ((z - 16.0 / 116.0) / 7.787)) * 108.883;

		Xyz xyz(x, y, z);
		XyzConverter::ToColor(color, &xyz);
	}

	void LchConverter::ToColorSpace(Rgb *color, Lch *item) {
	}
	void LchConverter::ToColor(Rgb *color, Lch *item) {
	}

	void LuvConverter::ToColorSpace(Rgb *color, Luv *item) {
	}
	void LuvConverter::ToColor(Rgb *color, Luv *item) {
	}

	void YxyConverter::ToColorSpace(Rgb *color, Yxy *item) {
	}
	void YxyConverter::ToColor(Rgb *color, Yxy *item) {
	}

	void CmyConverter::ToColorSpace(Rgb *color, Cmy *item) {
	}
	void CmyConverter::ToColor(Rgb *color, Cmy *item) {
	}

	void CmykConverter::ToColorSpace(Rgb *color, Cmyk *item) {
	}
	void CmykConverter::ToColor(Rgb *color, Cmyk *item) {
	}

	void HsvConverter::ToColorSpace(Rgb *color, Hsv *item) {
	}
	void HsvConverter::ToColor(Rgb *color, Hsv *item) {
	}

	void HsbConverter::ToColorSpace(Rgb *color, Hsb *item) {
	}
	void HsbConverter::ToColor(Rgb *color, Hsb *item) {
	}

	void HunterLabConverter::ToColorSpace(Rgb *color, HunterLab *item) {
	}
	void HunterLabConverter::ToColor(Rgb *color, HunterLab *item) {
	}
}

