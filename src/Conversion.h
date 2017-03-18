#ifndef RGB_CONVERTER_H
#define RGB_CONVERTER_H

#include "ColorSpace.h"
#include <cmath>
#include <algorithm>

namespace ColorSpace {
	template <typename TColorSpace>
	struct IConverter {
		static void ToColorSpace(Rgb *color, TColorSpace *item);
		static void ToColor(Rgb *color, TColorSpace *item);
	};

	template <>
	struct IConverter<Rgb> {
		static void ToColorSpace(Rgb *color, Rgb *item);
		static void ToColor(Rgb *color, Rgb *item);
	};
	typedef IConverter<Rgb> RgbConverter;

	template <>
	struct IConverter<Lab> {
		static void ToColorSpace(Rgb *color, Lab *item);
		static void ToColor(Rgb *color, Lab *item);
	};
	typedef IConverter<Lab> LabConverter;

	template <>
	struct IConverter<Xyz> {
		static void ToColorSpace(Rgb *color, Xyz *item);
		static void ToColor(Rgb *color, Xyz *item);
	};
	typedef IConverter<Xyz> XyzConverter;
}

#endif // RGB_CONVERTER_H

