#include "ColorSpace.h"
#include "Conversion.h"

namespace ColorSpace {
	Rgb::Rgb() {}
	Rgb::Rgb(double r, double g, double b) : r(r), g(g), b(b) {}
	void Rgb::Initialize(Rgb *color) {
		RgbConverter::ToColorSpace(color, this);
	}
	void Rgb::ToRgb(Rgb *color) {
		RgbConverter::ToColor(color, this);
	}
	void Rgb::Copy(IColorSpace *color) {
		Rgb *rgb = static_cast<Rgb*>(color);
		rgb->r = r;
		rgb->g = g;
		rgb->b = b;
	}


	Xyz::Xyz() {}
	Xyz::Xyz(double x, double y, double z) : x(x), y(y), z(z) {}
	void Xyz::Initialize(Rgb *color) {
		XyzConverter::ToColorSpace(color, this);
	}
	void Xyz::ToRgb(Rgb *color) {
		XyzConverter::ToColor(color, this);
	}
	void Xyz::Copy(IColorSpace *color) {
		Xyz *xyz = static_cast<Xyz*>(color);
		xyz->x = x;
		xyz->y = y;
		xyz->z = z;
	}

	Hsl::Hsl() {}
	Hsl::Hsl(double h, double s, double l) : h(h), s(s), l(l) {}
	void Hsl::Initialize(Rgb *color) {
		HslConverter::ToColorSpace(color, this);
	}
	void Hsl::ToRgb(Rgb *color) {
		HslConverter::ToColor(color, this);
	}
	void Hsl::Copy(IColorSpace *color) {
		Hsl *hsl = static_cast<Hsl*>(color);
		hsl->h = h;
		hsl->s = s;
		hsl->l = l;
	}

	Lab::Lab() {}
	Lab::Lab(double l, double a, double b) : l(l), a(a), b(b) {}
	void Lab::Initialize(Rgb *color) {
		LabConverter::ToColorSpace(color, this);
	}
	void Lab::ToRgb(Rgb *color) {
		LabConverter::ToColor(color, this);
	}
	void Lab::Copy(IColorSpace *color) {
		Lab *lab = static_cast<Lab*>(color);
		lab->l = l;
		lab->a = a;
		lab->b = b;
	}

	Lch::Lch() {}
	Lch::Lch(double l, double c, double h) : l(l), c(c), h(h) {}
	void Lch::Initialize(Rgb *color) {
		LchConverter::ToColorSpace(color, this);
	}
	void Lch::ToRgb(Rgb *color) {
		LchConverter::ToColor(color, this);
	}
	void Lch::Copy(IColorSpace *color) {
		Lch *lch = static_cast<Lch*>(color);
		lch->l = l;
		lch->c = c;
		lch->h = h;
	}

	Luv::Luv() {}
	Luv::Luv(double l, double u, double v) : l(l), u(u), v(v) {}
	void Luv::Initialize(Rgb *color) {
		LuvConverter::ToColorSpace(color, this);
	}
	void Luv::ToRgb(Rgb *color) {
		LuvConverter::ToColor(color, this);
	}
	void Luv::Copy(IColorSpace *color) {
		Luv *luv = static_cast<Luv*>(color);
		luv->l = l;
		luv->u = u;
		luv->v = v;
	}

	Yxy::Yxy() {}
	Yxy::Yxy(double y1, double x, double y2) : y1(y1), x(x), y2(y2) {}
	void Yxy::Initialize(Rgb *color) {
		YxyConverter::ToColorSpace(color, this);
	}
	void Yxy::ToRgb(Rgb *color) {
		YxyConverter::ToColor(color, this);
	}
	void Yxy::Copy(IColorSpace *color) {
		Yxy *yxy = static_cast<Yxy*>(color);
		yxy->y1 = y1;
		yxy->x = x;
		yxy->y2 = y2;
	}

	Cmy::Cmy() {}
	Cmy::Cmy(double c, double m, double y) : c(c), m(m), y(y) {}
	void Cmy::Initialize(Rgb *color) {
		CmyConverter::ToColorSpace(color, this);
	}
	void Cmy::ToRgb(Rgb *color) {
		CmyConverter::ToColor(color, this);
	}
	void Cmy::Copy(IColorSpace *color) {
		Cmy *cmy = static_cast<Cmy*>(color);
		cmy->c = c;
		cmy->m = m;
		cmy->y = y;
	}

	Cmyk::Cmyk() {}
	Cmyk::Cmyk(double c, double m, double y, double k) : c(c), m(m), y(y), k(k) {}
	void Cmyk::Initialize(Rgb *color) {
		CmykConverter::ToColorSpace(color, this);
	}
	void Cmyk::ToRgb(Rgb *color) {
		CmykConverter::ToColor(color, this);
	}
	void Cmyk::Copy(IColorSpace *color) {
		Cmyk *cmyk = static_cast<Cmyk*>(color);
		cmyk->c = c;
		cmyk->m = m;
		cmyk->y = y;
		cmyk->k = k;
	}

	Hsv::Hsv() {}
	Hsv::Hsv(double h, double s, double v) : h(h), s(s), v(v) {}
	void Hsv::Initialize(Rgb *color) {
		HsvConverter::ToColorSpace(color, this);
	}
	void Hsv::ToRgb(Rgb *color) {
		HsvConverter::ToColor(color, this);
	}
	void Hsv::Copy(IColorSpace *color) {
		Hsv *hsv = static_cast<Hsv*>(color);
		hsv->h = h;
		hsv->s = s;
		hsv->v = v;
	}

	Hsb::Hsb() {}
	Hsb::Hsb(double h, double s, double b) : h(h), s(s), b(b) {}
	void Hsb::Initialize(Rgb *color) {
		HsbConverter::ToColorSpace(color, this);
	}
	void Hsb::ToRgb(Rgb *color) {
		HsbConverter::ToColor(color, this);
	}
	void Hsb::Copy(IColorSpace *color) {
		Hsb *hsb = static_cast<Hsb*>(color);
		hsb->h = h;
		hsb->s = s;
		hsb->b = b;
	}

	HunterLab::HunterLab() {}
	HunterLab::HunterLab(double l, double a, double b) : l(l), a(a), b(b) {}
	void HunterLab::Initialize(Rgb *color) {
		HunterLabConverter::ToColorSpace(color, this);
	}
	void HunterLab::ToRgb(Rgb *color) {
		HunterLabConverter::ToColor(color, this);
	}
	void HunterLab::Copy(IColorSpace *color) {
		HunterLab *lab = static_cast<HunterLab*>(color);
		lab->l = l;
		lab->a = a;
		lab->b = b;
	}
}

