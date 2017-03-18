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


	Lab::Lab() {}
	Lab::Lab(double l, double a, double b) : l(l), a(a), b(b) {}
	void Lab::Initialize(Rgb *color) {
		LabConverter::ToColorSpace(color, this);
	}
	void Lab::ToRgb(Rgb *color) {
		LabConverter::ToColor(color, this);
	}
}

