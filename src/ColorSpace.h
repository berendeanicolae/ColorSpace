#ifndef COLOR_SPACE_H
#define COLOR_SPACE_H

namespace ColorSpace {
	struct Rgb;

	struct IColorSpace {
		IColorSpace() {}
		virtual ~IColorSpace() {}

		virtual void Initialize(Rgb *color) = 0;
		virtual void ToRgb(Rgb *color) = 0;
		template <typename TColorSpace>
		void To(TColorSpace *color);
	};


	struct Rgb : public IColorSpace {
		double r, g, b;

		Rgb();
		Rgb(double r, double g, double b);

		virtual void Initialize(Rgb *color);
		virtual void ToRgb(Rgb *color);
	};

	struct Xyz : public IColorSpace {
		double x, y, z;

		Xyz();
		Xyz(double x, double y, double z);

		virtual void Initialize(Rgb *color);
		virtual void ToRgb(Rgb *color);
	};

	/*struct Hsl : public IColorSpace {
	double h, s, l;
	};*/

	struct Lab : public IColorSpace {
		double l, a, b;

		Lab();
		Lab(double l, double a, double b);

		virtual void Initialize(Rgb *color);
		virtual void ToRgb(Rgb *color);
	};

	/*struct Lch : public IColorSpace {
	double l, c, h;
	};

	struct Luv : public IColorSpace {
	double l, u, v;
	};

	struct Yxy : public IColorSpace {
	double y1, x, y2;
	};

	struct Cmy : public IColorSpace {
	double c, m, y;
	};

	struct Cmyk : public IColorSpace {
	double c, m, y, k;
	};

	struct Hsv : public IColorSpace {
	double h, s, v;
	};

	struct Hsb : public IColorSpace {
	double h, s, b;
	};

	struct HunterLab : public IColorSpace {
	double l, a, b;
	};*/
}

#endif // COLOR_SPACE_H

