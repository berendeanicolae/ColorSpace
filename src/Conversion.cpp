#include "Conversion.h"
#include "ColorSpace.h"
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
			item->s = delta / (1 - abs(2 * item->l - 1)) * 100;

			if (r == max) {
				item->h = 60*fmod((g-b)/delta, 6);
			}
			else if (g == max) {
				item->h = 60 * ((b - r) / delta + 2);
			}
			else if (b == max) {
				item->h = 60 * ((r - g) / delta + 4);
			}
		}
		item->l *= 100;
	}
	void HslConverter::ToColor(Rgb *color, Hsl *item) {
		double r;
		double g;
		double b;

		if (item->s == 0) {
			r = item->l * 255;
			g = item->l * 255;
			b = item->l * 255;
		}
		else {
			double temp1, temp2;

			if (item->l < 0.5) {
				temp2 = item->l*(1 + item->s);
			}
			else {
				temp2 = (item->l + item->s) - (item->s*item->l);
			}
			temp1 = 2 * item->l - temp2;

			r = 255 * Hue_2_RGB(temp1, temp2, item->h + 1.0 / 3.0);
			g = 255 * Hue_2_RGB(temp1, temp2, item->h);
			b = 255 * Hue_2_RGB(temp1, temp2, item->h - 1.0 / 3.0);
		}

		color->r = r;
		color->g = g;
		color->b = b;
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
		double y = (item->l + 16.0) / 116.0;
		double x = item->a / 500.0 + y;
		double z = y - item->b / 200.0;

		double x3 = x*x*x;
		double y3 = y*y*y;
		double z3 = z*z*z;

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
		double c = sqrt(sqrt(lab.a*lab.a + lab.b*lab.b));
		double h = atan2(lab.b, lab.a);

		h = h * 180 / M_PI;
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
		item->l = (y <= XyzConverter::eps) ? (XyzConverter::kappa*white.y) : (116 * cbrt(white.y) - 16);
		item->u = 13 * item->l * (4 * xyz.x / (xyz.x + 15 * xyz.y + 3 * xyz.z) - 4 * white.x / (white.x + 15 * white.y + 3 * white.z)); // TODO: division by 0
		item->v = 13 * item->l * (9 * xyz.y / (xyz.x + 15 * xyz.y + 3 * xyz.z) - 9 * white.y / (white.x + 15 * white.y + 3 * white.z));
	}
	void LuvConverter::ToColor(Rgb *color, Luv *item) {
		const Xyz &white = XyzConverter::whiteReference;
		Xyz xyz;

		double y = (item->l > XyzConverter::eps*XyzConverter::kappa) ? pow((item->l + 16) / 116, 3) : (item->l / XyzConverter::kappa);
		double up = 4 * white.x / (white.x + 15 * white.y + 3 * white.z);
		double vp = 9 * white.y / (white.x + 15 * white.y + 3 * white.z);
		xyz.x = (y*(39 * item->l / (item->v + 13 * item->l*vp) - 5) + 5 * y) / (1.0 / 3.0*(52 * item->l / (item->u + 13 * item->l*up) - 1) + 1.0 / 3.0);
		xyz.y = y;
		xyz.z = xyz.x*(1.0 / 3.0*(52 * item->l / (item->u + 13 * item->l*up) - 1)) - 5 * y;
		XyzConverter::ToColor(color, &xyz);
	}

	void YxyConverter::ToColorSpace(Rgb *color, Yxy *item) {
		Xyz xyz;

		XyzConverter::ToColorSpace(color, &xyz);
		item->y1 = xyz.y;
		item->x = xyz.x / (xyz.x + xyz.y + xyz.z); // TODO: division by 0
		item->y2 = xyz.z / (xyz.x + xyz.y + xyz.z); // TODO: division by 0
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
		if (abs(item->k - 1) < 1e-3) {
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
		color->r = item->c * (1 - item->k) + item->k;
		color->g = item->m * (1 - item->k) + item->k;
		color->b = item->y * (1 - item->k) + item->k;
	}

	void HsvConverter::ToColorSpace(Rgb *color, Hsv *item) {
		double r = color->r / 255.0;
		double g = color->g / 255.0;
		double b = color->b / 255.0;

		double min = std::min(r, std::min(g, b));
		double max = std::max(r, std::max(g, b));
		double delta = max - min;

		item->v = max;
		if (delta == 0) {
			item->h = 0;
			item->s = -1;
		}
		else {
			item->s = delta / max;

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
			if (item->h > 0) {
				item->h += 360;
			}
		}
	}
	void HsvConverter::ToColor(Rgb *color, Hsv *item) {
		if (item->s == 0) {
			color->r = item->v * 255;
			color->g = item->v * 255;
			color->b = item->v * 255;
		}
		else {
			int range = floor(item->h / 60);
			double f = item->h - range;
			double p = item->v*(1 - item->s);
			double q = item->v*(1 - item->s*f);
			double t = item->v*(1 - item->s*(1 - f));

			switch (range) {
				case 0:
					color->r = item->v;
					color->g = t;
					color->b = p;
					break;
				case 1:
					color->r = q;
					color->g = item->v;
					color->b = p;
					break;
				case 2:
					color->r = p;
					color->g = item->v;
					color->b = t;
					break;
				case 3:
					color->r = p;
					color->g = q;
					color->b = item->v;
					break;
				case 4:
					color->r = t;
					color->g = p;
					color->b = item->v;
					break;
				default:		// case 5:
					color->r = item->v;
					color->g = p;
					color->b = q;
					break;
			}
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
		HsvConverter::ToColorSpace(color, &hsv);
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

