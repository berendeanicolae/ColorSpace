#ifndef RGB_CONVERTER_H
#define RGB_CONVERTER_H

namespace ColorSpace {
	struct Rgb;
	struct Xyz;
	struct Hsl;
	struct Lab;
	struct Lch;
	struct Luv;
	struct Yxy;
	struct Cmy;
	struct Cmyk;
	struct Hsv;
	struct Hsb;
	struct HunterLab;

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
	struct IConverter<Xyz> {
		static void ToColorSpace(Rgb *color, Xyz *item);
		static void ToColor(Rgb *color, Xyz *item);
		static const double eps;
		static const double kappa;
		static const Xyz whiteReference;
	};
	typedef IConverter<Xyz> XyzConverter;

	template <>
	struct IConverter<Hsl> {
		static void ToColorSpace(Rgb *color, Hsl *item);
		static void ToColor(Rgb *color, Hsl *item);
	};
	typedef IConverter<Hsl> HslConverter;

	template <>
	struct IConverter<Lab> {
		static void ToColorSpace(Rgb *color, Lab *item);
		static void ToColor(Rgb *color, Lab *item);
	};
	typedef IConverter<Lab> LabConverter;

	template <>
	struct IConverter<Lch> {
		static void ToColorSpace(Rgb *color, Lch *item);
		static void ToColor(Rgb *color, Lch *item);
	};
	typedef IConverter<Lch> LchConverter;

	template <>
	struct IConverter<Luv> {
		static void ToColorSpace(Rgb *color, Luv *item);
		static void ToColor(Rgb *color, Luv *item);
	};
	typedef IConverter<Luv> LuvConverter;

	template <>
	struct IConverter<Yxy> {
		static void ToColorSpace(Rgb *color, Yxy *item);
		static void ToColor(Rgb *color, Yxy *item);
	};
	typedef IConverter<Yxy> YxyConverter;

	template <>
	struct IConverter<Cmy> {
		static void ToColorSpace(Rgb *color, Cmy *item);
		static void ToColor(Rgb *color, Cmy *item);
	};
	typedef IConverter<Cmy> CmyConverter;

	template <>
	struct IConverter<Cmyk> {
		static void ToColorSpace(Rgb *color, Cmyk *item);
		static void ToColor(Rgb *color, Cmyk *item);
	};
	typedef IConverter<Cmyk> CmykConverter;

	template <>
	struct IConverter<Hsv> {
		static void ToColorSpace(Rgb *color, Hsv *item);
		static void ToColor(Rgb *color, Hsv *item);
	};
	typedef IConverter<Hsv> HsvConverter;

	template <>
	struct IConverter<Hsb> {
		static void ToColorSpace(Rgb *color, Hsb *item);
		static void ToColor(Rgb *color, Hsb *item);
	};
	typedef IConverter<Hsb> HsbConverter;

	template <>
	struct IConverter<HunterLab> {
		static void ToColorSpace(Rgb *color, HunterLab *item);
		static void ToColor(Rgb *color, HunterLab *item);
	};
	typedef IConverter<HunterLab> HunterLabConverter;
}

#endif // RGB_CONVERTER_H

