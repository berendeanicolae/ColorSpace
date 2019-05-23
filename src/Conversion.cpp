#include "Conversion.h"
#include "ColorSpace.h"
#include "Utils.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <algorithm>

namespace ColorSpace {
	double Hue_2_RGB(double v1, double v2, double vh) {
		if (vh < 0) vh += 1;
		if (vh > 1) vh -= 1;
		if (6 * vh < 1) return v1 + (v2 - v1) * 6 * vh;
		if (2 * vh < 1) return v2;
		if (3 * vh < 2) return v1 + (v2 - v1)*(2.0 / 3.0 - vh) * 6;
		return v1;
	}



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

		item->x = r*0.4124564 + g*0.3575761 + b*0.1804375;
		item->y = r*0.2126729 + g*0.7151522 + b*0.0721750;
		item->z = r*0.0193339 + g*0.1191920 + b*0.9503041;
	}
	void XyzConverter::ToColor(Rgb *color, Xyz *item) {
		double x = item->x / 100.0;
		double y = item->y / 100.0;
		double z = item->z / 100.0;

		double r = x * 3.2404542 + y * -1.5371385 + z * -0.4985314;
		double g = x * -0.9692660 + y * 1.8760108 + z * 0.0415560;
		double b = x * 0.0556434 + y * -0.2040259 + z * 1.0572252;

		r = ((r > 0.0031308) ? (1.055*pow(r, 1 / 2.4) - 0.055) : (12.92*r)) * 255.0;
		g = ((g > 0.0031308) ? (1.055*pow(g, 1 / 2.4) - 0.055) : (12.92*g)) * 255.0;
		b = ((b > 0.0031308) ? (1.055*pow(b, 1 / 2.4) - 0.055) : (12.92*b)) * 255.0;
		
		color->r = r;
		color->g = g;
		color->b = b;
	}
	const double XyzConverter::eps = 216.0 / 24389.0;
	const double XyzConverter::kappa = 24389.0 / 27.0;
	const Xyz XyzConverter::whiteReference(95.047, 100.000, 108.883);

	void HslConverter::ToColorSpace(Rgb *color, Hsl *item) {
		double r = color->r / 255.0;
		double g = color->g / 255.0;
		double b = color->b / 255.0;

		double min = std::min(r, std::min(g, b));
		double max = std::max(r, std::max(g, b));
		double delta = max - min;
		
		item->l = (max + min) / 2;
		if (delta == 0)
		{
			item->h = item->s = 0;
		}
		else {
			if (item->l < 0.5) {
				item->s = delta / (max + min) * 100;
			}
			else {
				item->s = delta / (1 - std::abs(2 * item->l - 1)) * 100;
			}

			if (r == max) {
				item->h =  (g - b) / delta;
			}
			else if (g == max) {
				item->h = (b - r) / delta + 2;
			}
			else if (b == max) {
				item->h = (r - g) / delta + 4;
			}
			item->h = fmod(60 * item->h + 360, 360);
		}
		item->l *= 100;
	}
	void HslConverter::ToColor(Rgb *color, Hsl *item) {
		double h = item->h / 360;
		double s = item->s / 100;
		double l = item->l / 100;

		if (item->s == 0) {
			color->r = color->g = color->b = item->l * 255;
		}
		else {
			double temp1, temp2;

			temp2 = (l < 0.5) ? (l*(1 + s)) : (l + s - (s*l));
			temp1 = 2 * l - temp2;

			color->r = 255 * Hue_2_RGB(temp1, temp2, h + 1.0 / 3.0);
			color->g = 255 * Hue_2_RGB(temp1, temp2, h);
			color->b = 255 * Hue_2_RGB(temp1, temp2, h - 1.0 / 3.0);
		}
	}

	void LabConverter::ToColorSpace(Rgb *color, Lab *item) {
		Xyz xyz;

		XyzConverter::ToColorSpace(color, &xyz);

		double x = xyz.x / 95.047;
		double y = xyz.y / 100.00;
		double z = xyz.z / 108.883;

		x = (x > 0.008856) ? cbrt(x) : (7.787 * x + 16.0 / 116.0);
		y = (y > 0.008856) ? cbrt(y) : (7.787 * y + 16.0 / 116.0);
		z = (z > 0.008856) ? cbrt(z) : (7.787 * z + 16.0 / 116.0);

		item->l = (116.0 * y) - 16;
		item->a = 500 * (x - y);
		item->b = 200 * (y - z);
	}
	void LabConverter::ToColor(Rgb *color, Lab *item) {
		double y = (item->l + 16.0) / 116.0;
		double x = item->a / 500.0 + y;
		double z = y - item->b / 200.0;

		double x3 = POW3(x);
		double y3 = POW3(y);
		double z3 = POW3(z);

		x = ((x3 > 0.008856) ? x3 : ((x - 16.0 / 116.0) / 7.787)) * 95.047;
		y = ((y3 > 0.008856) ? y3 : ((y - 16.0 / 116.0) / 7.787)) * 100.0;
		z = ((z3 > 0.008856) ? z3 : ((z - 16.0 / 116.0) / 7.787)) * 108.883;

		Xyz xyz(x, y, z);
		XyzConverter::ToColor(color, &xyz);
	}

	void LchConverter::ToColorSpace(Rgb *color, Lch *item) {
		Lab lab;

		LabConverter::ToColorSpace(color, &lab);
		double l = lab.l;
		double c = sqrt(lab.a*lab.a + lab.b*lab.b);
		double h = atan2(lab.b, lab.a);

		h = h / M_PI * 180;
		if (h < 0) {
			h += 360;
		}
		else if (h >= 360) {
			h -= 360;
		}

		item->l = l;
		item->c = c;
		item->h = h;
	}
	void LchConverter::ToColor(Rgb *color, Lch *item) {
		Lab lab;

		item->h = item->h * M_PI / 180;

		lab.l = item->l;
		lab.a = cos(item->h)*item->c;
		lab.b = sin(item->h)*item->c;

		LabConverter::ToColor(color, &lab);
	}

	void LuvConverter::ToColorSpace(Rgb *color, Luv *item) {
		const Xyz &white = XyzConverter::whiteReference;
		Xyz xyz;

		XyzConverter::ToColorSpace(color, &xyz);
		double y = xyz.y / white.y;
		double temp = (xyz.x + 15 * xyz.y + 3 * xyz.z);
		double tempr = (white.x + 15 * white.y + 3 * white.z);

		item->l = (y > XyzConverter::eps) ? (116 * cbrt(y) - 16) : (XyzConverter::kappa*y);
		item->u = 52 * item->l * (((temp > 1e-3) ? (xyz.x / temp) : 0) - white.x / tempr);
		item->v = 117 * item->l * (((temp > 1e-3) ? (xyz.y / temp) : 0) - white.y / tempr);
	}
	void LuvConverter::ToColor(Rgb *color, Luv *item) {
		const Xyz &white = XyzConverter::whiteReference;
		Xyz xyz;

		double y = (item->l > XyzConverter::eps*XyzConverter::kappa) ? POW3((item->l + 16) / 116) : (item->l / XyzConverter::kappa);
		double tempr = white.x + 15 * white.y + 3 * white.z;
		double up = 4 * white.x / tempr;
		double vp = 9 * white.y / tempr;

		double a = 1. / 3. * (52 * item->l / (item->u + 13 * item->l*up) - 1);
		double b = -5 * y;
		double x = (y*(39 * item->l / (item->v + 13 * item->l*vp) - 5) - b) / (a + 1. / 3.);
		double z = x*a + b;

		xyz.x = x * 100;
		xyz.y = y * 100;
		xyz.z = z * 100;

		XyzConverter::ToColor(color, &xyz);
	}

	void YxyConverter::ToColorSpace(Rgb *color, Yxy *item) {
		Xyz xyz;

		XyzConverter::ToColorSpace(color, &xyz);
		double temp = xyz.x + xyz.y + xyz.z;
		item->y1 = xyz.y;
		item->x = (temp==0) ? 0 : (xyz.x / temp);
		item->y2 = (temp==0) ? 0 : (xyz.y / temp);
	}
	void YxyConverter::ToColor(Rgb *color, Yxy *item) {
		Xyz xyz;

		xyz.x = item->x*(item->y1 / item->y2);
		xyz.y = item->y1;
		xyz.z = (1 - item->x - item->y2)*(item->y1 / item->y2);
		XyzConverter::ToColor(color, &xyz);
	}

	void CmyConverter::ToColorSpace(Rgb *color, Cmy *item) {
		item->c = 1 - color->r / 255;
		item->m = 1 - color->g / 255;
		item->y = 1 - color->b / 255;
	}
	void CmyConverter::ToColor(Rgb *color, Cmy *item) {
		color->r = (1 - item->c) * 255;
		color->g = (1 - item->m) * 255;
		color->b = (1 - item->y) * 255;
	}

	void CmykConverter::ToColorSpace(Rgb *color, Cmyk *item) {
		Cmy cmy;

		CmyConverter::ToColorSpace(color, &cmy);
		double k = 1.0;
		k = std::min(k, cmy.c);
		k = std::min(k, cmy.m);
		k = std::min(k, cmy.y);

		item->k = k;
		if (std::abs(item->k - 1) < 1e-3) {
			item->c = 0;
			item->m = 0;
			item->y = 0;
		}
		else {
			item->c = (cmy.c - k) / (1 - k);
			item->m = (cmy.m - k) / (1 - k);
			item->y = (cmy.y - k) / (1 - k);
		}
	}
	void CmykConverter::ToColor(Rgb *color, Cmyk *item) {
		Cmy cmy;

		cmy.c = item->c * (1 - item->k) + item->k;
		cmy.m = item->m * (1 - item->k) + item->k;
		cmy.y = item->y * (1 - item->k) + item->k;
		CmyConverter::ToColor(color, &cmy);
	}

	void HsvConverter::ToColorSpace(Rgb *color, Hsv *item) {
		double r = color->r / 255.0;
		double g = color->g / 255.0;
		double b = color->b / 255.0;

		double min = std::min(r, std::min(g, b));
		double max = std::max(r, std::max(g, b));
		double delta = max - min;

		item->v = max;
		item->s = (max > 1e-3) ? (delta / max) : 0;

		if (delta == 0) {
			item->h = 0;
		}
		else {
			if (r == max) {
				item->h = (g - b) / delta;
			}
			else if (g == max) {
				item->h = 2 + (b - r) / delta;
			}
			else if (b == max) {
				item->h = 4 + (r - g) / delta;
			}

			item->h *= 60;
			item->h = fmod(item->h + 360, 360);
		}
	}
	void HsvConverter::ToColor(Rgb *color, Hsv *item) {
		int range = (int)floor(item->h / 60);
		double c = item->v*item->s;
		double x = c*(1 - std::abs(fmod(item->h / 60, 2) - 1));
		double m = item->v - c;

		switch (range) {
			case 0:
				color->r = (c + m) * 255;
				color->g = (x + m) * 255;
				color->b = m * 255;
				break;
			case 1:
				color->r = (x + m) * 255;
				color->g = (c + m) * 255;
				color->b = m * 255;
				break;
			case 2:
				color->r = m * 255;
				color->g = (c + m) * 255;
				color->b = (x + m) * 255;
				break;
			case 3:
				color->r = m * 255;
				color->g = (x + m) * 255;
				color->b = (c + m) * 255;
				break;
			case 4:
				color->r = (x + m) * 255;
				color->g = m * 255;
				color->b = (c + m) * 255;
				break;
			default:		// case 5:
				color->r = (c + m) * 255;
				color->g = m * 255;
				color->b = (x + m) * 255;
				break;
		}
	}

	void HsbConverter::ToColorSpace(Rgb *color, Hsb *item) {
		Hsv hsv;

		HsvConverter::ToColorSpace(color, &hsv);
		item->h = hsv.h;
		item->s = hsv.s;
		item->b = hsv.v;
	}
	void HsbConverter::ToColor(Rgb *color, Hsb *item) {
		Hsv hsv;

		hsv.h = item->h;
		hsv.s = item->s;
		hsv.v = item->b;
		HsvConverter::ToColor(color, &hsv);
	}

	void HunterLabConverter::ToColorSpace(Rgb *color, HunterLab *item) {
		Xyz xyz;

		XyzConverter::ToColorSpace(color, &xyz);
		item->l = 10.0*sqrt(xyz.y);
		item->a = (xyz.y != 0) ? (17.5*(1.02*xyz.x - xyz.y) / sqrt(xyz.y)) : 0;
		item->b = (xyz.y != 0) ? (7.0*(xyz.y - 0.847*xyz.z) / sqrt(xyz.y)) : 0;
	}
	void HunterLabConverter::ToColor(Rgb *color, HunterLab *item) {
		double x = (item->a / 17.5) *(item->l / 10.0);
		double y = item->l*item->l / 100;
		double z = item->b / 7.0 * item->l / 10.0;

		Xyz xyz((x+y)/1.02, y, -(z-y)/0.847);
		XyzConverter::ToColor(color, &xyz);
	}
}

