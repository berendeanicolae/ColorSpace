#include "ColorSpace.h"
#include "Conversion.h"

namespace ColorSpace {
	template <typename TColorSpace>
	void IColorSpace::To(TColorSpace *color) {
		Rgb rgb;

		this->ToRgb(&rgb);
		IConverter<TColorSpace>::ToColorSpace(&rgb, color);
	}

	Rgb::Rgb() {}
	Rgb::Rgb(double r, double g, double b) : r(r), g(g), b(b) {}
	void Rgb::Initialize(Rgb *color) {
		RgbConverter::ToColorSpace(color, this);
	}
	void Rgb::ToRgb(Rgb *color) {
		RgbConverter::ToColor(color, this);
	}


	Xyz::Xyz() {}
	Xyz::Xyz(double x, double y, double z) : x(x), y(y), z(z) {}
	void Xyz::Initialize(Rgb *color) {
		XyzConverter::ToColorSpace(color, this);
	}
	void Xyz::ToRgb(Rgb *color) {
		XyzConverter::ToColor(color, this);
	}

	Hsl::Hsl() {}
	Hsl::Hsl(double h, double s, double l) : h(h), s(s), l(l) {}
	void Hsl::Initialize(Rgb *color) {
		HslConverter::ToColorSpace(color, this);
	}
	void Hsl::ToRgb(Rgb *color) {
		HslConverter::ToColor(color, this);
	}

	Lab::Lab() {}
	Lab::Lab(double l, double a, double b) : l(l), a(a), b(b) {}
	void Lab::Initialize(Rgb *color) {
		LabConverter::ToColorSpace(color, this);
	}
	void Lab::ToRgb(Rgb *color) {
		LabConverter::ToColor(color, this);
	}

	Lch::Lch() {}
	Lch::Lch(double l, double c, double h) : l(l), c(c), h(h) {}
	void Lch::Initialize(Rgb *color) {
		LchConverter::ToColorSpace(color, this);
	}
	void Lch::ToRgb(Rgb *color) {
		LchConverter::ToColor(color, this);
	}

	Luv::Luv() {}
	Luv::Luv(double l, double u, double v) : l(l), u(u), v(v) {}
	void Luv::Initialize(Rgb *color) {
		LuvConverter::ToColorSpace(color, this);
	}
	void Luv::ToRgb(Rgb *color) {
		LuvConverter::ToColor(color, this);
	}

	Yxy::Yxy() {}
	Yxy::Yxy(double y1, double x, double y2) : y1(y1), x(x), y2(y2) {}
	void Yxy::Initialize(Rgb *color) {
		YxyConverter::ToColorSpace(color, this);
	}
	void Yxy::ToRgb(Rgb *color) {
		YxyConverter::ToColor(color, this);
	}

	Cmy::Cmy() {}
	Cmy::Cmy(double c, double m, double y) : c(c), m(m), y(y) {}
	void Cmy::Initialize(Rgb *color) {
		CmyConverter::ToColorSpace(color, this);
	}
	void Cmy::ToRgb(Rgb *color) {
		CmyConverter::ToColor(color, this);
	}

	Cmyk::Cmyk() {}
	Cmyk::Cmyk(double c, double m, double y, double k) : c(c), m(m), y(y), k(k) {}
	void Cmyk::Initialize(Rgb *color) {
		CmykConverter::ToColorSpace(color, this);
	}
	void Cmyk::ToRgb(Rgb *color) {
		CmykConverter::ToColor(color, this);
	}

	Hsv::Hsv() {}
	Hsv::Hsv(double h, double s, double v) : h(h), s(s), v(v) {}
	void Hsv::Initialize(Rgb *color) {
		HsvConverter::ToColorSpace(color, this);
	}
	void Hsv::ToRgb(Rgb *color) {
		HsvConverter::ToColor(color, this);
	}

	Hsb::Hsb() {}
	Hsb::Hsb(double h, double s, double b) : h(h), s(s), b(b) {}
	void Hsb::Initialize(Rgb *color) {
		HsbConverter::ToColorSpace(color, this);
	}
	void Hsb::ToRgb(Rgb *color) {
		HsbConverter::ToColor(color, this);
	}

	HunterLab::HunterLab() {}
	HunterLab::HunterLab(double l, double a, double b) : l(l), a(a), b(b) {}
	void HunterLab::Initialize(Rgb *color) {
		HunterLabConverter::ToColorSpace(color, this);
	}
	void HunterLab::ToRgb(Rgb *color) {
		HunterLabConverter::ToColor(color, this);
	}
}

