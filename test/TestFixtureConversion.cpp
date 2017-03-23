#include "TestFixtureConversion.h"
#include "utils.h"

#include <ColorSpace.h>
#include <Conversion.h>

TEST_F(TestFixtureConversion, ColorConversionWhiteRgbCmy) {
	ColorSpace::Rgb srcColor(255, 255, 255);
	ColorSpace::Cmy dstColor;
	ColorSpace::Cmy target(0, 0, 0);

	srcColor.To<ColorSpace::Cmy>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.c, target.c));
	ASSERT_TRUE(nearlyEqual(dstColor.m, target.m));
	ASSERT_TRUE(nearlyEqual(dstColor.y, target.y));
}


TEST_F(TestFixtureConversion, ColorConversionWhiteRgbCmyk) {
	ColorSpace::Rgb srcColor(255, 255, 255);
	ColorSpace::Cmyk dstColor;
	ColorSpace::Cmyk target(0, 0, 0, 0);

	srcColor.To<ColorSpace::Cmyk>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.c, target.c));
	ASSERT_TRUE(nearlyEqual(dstColor.m, target.m));
	ASSERT_TRUE(nearlyEqual(dstColor.y, target.y));
	ASSERT_TRUE(nearlyEqual(dstColor.k, target.k));
}


TEST_F(TestFixtureConversion, ColorConversionWhiteRgbHsl) {
	ColorSpace::Rgb srcColor(255, 255, 255);
	ColorSpace::Hsl dstColor;
	ColorSpace::Hsl target(0, 0, 100);

	srcColor.To<ColorSpace::Hsl>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.h, target.h));
	ASSERT_TRUE(nearlyEqual(dstColor.s, target.s));
	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
}


TEST_F(TestFixtureConversion, ColorConversionWhiteRgbLab) {
	ColorSpace::Rgb srcColor(255, 255, 255);
	ColorSpace::Lab dstColor;
	ColorSpace::Lab target(100, 0, 0);

	srcColor.To<ColorSpace::Lab>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
	ASSERT_TRUE(nearlyEqual(dstColor.a, target.a));
	ASSERT_TRUE(nearlyEqual(dstColor.b, target.b));
}


TEST_F(TestFixtureConversion, ColorConversionWhiteRgbLch) {
	ColorSpace::Rgb srcColor(255, 255, 255);
	ColorSpace::Lch dstColor;
	ColorSpace::Lch target(100, .01166, 296.813);

	srcColor.To<ColorSpace::Lch>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
	ASSERT_TRUE(nearlyEqual(dstColor.c, target.c));
	ASSERT_TRUE(nearlyEqual(dstColor.h, target.h));
}


TEST_F(TestFixtureConversion, ColorConversionWhiteRgbRgb) {
	ColorSpace::Rgb srcColor(255, 255, 255);
	ColorSpace::Rgb dstColor;
	ColorSpace::Rgb target(255, 255, 255);

	srcColor.To<ColorSpace::Rgb>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.r, target.r));
	ASSERT_TRUE(nearlyEqual(dstColor.g, target.g));
	ASSERT_TRUE(nearlyEqual(dstColor.b, target.b));
}


TEST_F(TestFixtureConversion, ColorConversionWhiteRgbXyz) {
	ColorSpace::Rgb srcColor(255, 255, 255);
	ColorSpace::Xyz dstColor;
	ColorSpace::Xyz target(95.050, 100, 108.900);

	srcColor.To<ColorSpace::Xyz>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.x, target.x));
	ASSERT_TRUE(nearlyEqual(dstColor.y, target.y));
	ASSERT_TRUE(nearlyEqual(dstColor.z, target.z));
}


TEST_F(TestFixtureConversion, ColorConversionWhiteRgbYxy) {
	ColorSpace::Rgb srcColor(255, 255, 255);
	ColorSpace::Yxy dstColor;
	ColorSpace::Yxy target(100, .31272, .32900);

	srcColor.To<ColorSpace::Yxy>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.y1, target.y1));
	ASSERT_TRUE(nearlyEqual(dstColor.x, target.x));
	ASSERT_TRUE(nearlyEqual(dstColor.y2, target.y2));
}


TEST_F(TestFixtureConversion, ColorConversionWhiteRgbLuv) {
	ColorSpace::Rgb srcColor(255, 255, 255);
	ColorSpace::Luv dstColor;
	ColorSpace::Luv target(100, .00089, -.017);

	srcColor.To<ColorSpace::Luv>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
	ASSERT_TRUE(nearlyEqual(dstColor.u, target.u));
	ASSERT_TRUE(nearlyEqual(dstColor.v, target.v));
}


TEST_F(TestFixtureConversion, ColorConversionWhiteRgbHsv) {
	ColorSpace::Rgb srcColor(255, 255, 255);
	ColorSpace::Hsv dstColor;
	ColorSpace::Hsv target(0, 0, 1);

	srcColor.To<ColorSpace::Hsv>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.h, target.h));
	ASSERT_TRUE(nearlyEqual(dstColor.s, target.s));
	ASSERT_TRUE(nearlyEqual(dstColor.v, target.v));
}


TEST_F(TestFixtureConversion, ColorConversionWhiteRgbHsb) {
	ColorSpace::Rgb srcColor(255, 255, 255);
	ColorSpace::Hsb dstColor;
	ColorSpace::Hsb target(0, 0, 1);

	srcColor.To<ColorSpace::Hsb>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.h, target.h));
	ASSERT_TRUE(nearlyEqual(dstColor.s, target.s));
	ASSERT_TRUE(nearlyEqual(dstColor.b, target.b));
}


TEST_F(TestFixtureConversion, ColorConversionWhiteRgbHunterLab) {
	ColorSpace::Rgb srcColor(255, 255, 255);
	ColorSpace::HunterLab dstColor;
	ColorSpace::HunterLab target(100, -5.336, 5.433);

	srcColor.To<ColorSpace::HunterLab>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
	ASSERT_TRUE(nearlyEqual(dstColor.a, target.a));
	ASSERT_TRUE(nearlyEqual(dstColor.b, target.b));
}


TEST_F(TestFixtureConversion, ColorConversionBlackRgbCmy) {
	ColorSpace::Rgb srcColor(0, 0, 0);
	ColorSpace::Cmy dstColor;
	ColorSpace::Cmy target(1, 1, 1);

	srcColor.To<ColorSpace::Cmy>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.c, target.c));
	ASSERT_TRUE(nearlyEqual(dstColor.m, target.m));
	ASSERT_TRUE(nearlyEqual(dstColor.y, target.y));
}


TEST_F(TestFixtureConversion, ColorConversionBlackRgbCmyk) {
	ColorSpace::Rgb srcColor(0, 0, 0);
	ColorSpace::Cmyk dstColor;
	ColorSpace::Cmyk target(0, 0, 0, 1);

	srcColor.To<ColorSpace::Cmyk>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.c, target.c));
	ASSERT_TRUE(nearlyEqual(dstColor.m, target.m));
	ASSERT_TRUE(nearlyEqual(dstColor.y, target.y));
	ASSERT_TRUE(nearlyEqual(dstColor.k, target.k));
}


TEST_F(TestFixtureConversion, ColorConversionBlackRgbHsl) {
	ColorSpace::Rgb srcColor(0, 0, 0);
	ColorSpace::Hsl dstColor;
	ColorSpace::Hsl target(0, 0, 0);

	srcColor.To<ColorSpace::Hsl>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.h, target.h));
	ASSERT_TRUE(nearlyEqual(dstColor.s, target.s));
	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
}


TEST_F(TestFixtureConversion, ColorConversionBlackRgbLab) {
	ColorSpace::Rgb srcColor(0, 0, 0);
	ColorSpace::Lab dstColor;
	ColorSpace::Lab target(0, 0, 0);

	srcColor.To<ColorSpace::Lab>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
	ASSERT_TRUE(nearlyEqual(dstColor.a, target.a));
	ASSERT_TRUE(nearlyEqual(dstColor.b, target.b));
}


TEST_F(TestFixtureConversion, ColorConversionBlackRgbLch) {
	ColorSpace::Rgb srcColor(0, 0, 0);
	ColorSpace::Lch dstColor;
	ColorSpace::Lch target(0, 0, 0);

	srcColor.To<ColorSpace::Lch>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
	ASSERT_TRUE(nearlyEqual(dstColor.c, target.c));
	ASSERT_TRUE(nearlyEqual(dstColor.h, target.h));
}


TEST_F(TestFixtureConversion, ColorConversionBlackRgbRgb) {
	ColorSpace::Rgb srcColor(0, 0, 0);
	ColorSpace::Rgb dstColor;
	ColorSpace::Rgb target(0, 0, 0);

	srcColor.To<ColorSpace::Rgb>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.r, target.r));
	ASSERT_TRUE(nearlyEqual(dstColor.g, target.g));
	ASSERT_TRUE(nearlyEqual(dstColor.b, target.b));
}


TEST_F(TestFixtureConversion, ColorConversionBlackRgbXyz) {
	ColorSpace::Rgb srcColor(0, 0, 0);
	ColorSpace::Xyz dstColor;
	ColorSpace::Xyz target(0, 0, 0);

	srcColor.To<ColorSpace::Xyz>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.x, target.x));
	ASSERT_TRUE(nearlyEqual(dstColor.y, target.y));
	ASSERT_TRUE(nearlyEqual(dstColor.z, target.z));
}


TEST_F(TestFixtureConversion, ColorConversionBlackRgbYxy) {
	ColorSpace::Rgb srcColor(0, 0, 0);
	ColorSpace::Yxy dstColor;
	ColorSpace::Yxy target(0, 0, 0);

	srcColor.To<ColorSpace::Yxy>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.y1, target.y1));
	ASSERT_TRUE(nearlyEqual(dstColor.x, target.x));
	ASSERT_TRUE(nearlyEqual(dstColor.y2, target.y2));
}


TEST_F(TestFixtureConversion, ColorConversionBlackRgbLuv) {
	ColorSpace::Rgb srcColor(0, 0, 0);
	ColorSpace::Luv dstColor;
	ColorSpace::Luv target(0, 0, 0);

	srcColor.To<ColorSpace::Luv>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
	ASSERT_TRUE(nearlyEqual(dstColor.u, target.u));
	ASSERT_TRUE(nearlyEqual(dstColor.v, target.v));
}


TEST_F(TestFixtureConversion, ColorConversionBlackRgbHsv) {
	ColorSpace::Rgb srcColor(0, 0, 0);
	ColorSpace::Hsv dstColor;
	ColorSpace::Hsv target(0, 0, 0);

	srcColor.To<ColorSpace::Hsv>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.h, target.h));
	ASSERT_TRUE(nearlyEqual(dstColor.s, target.s));
	ASSERT_TRUE(nearlyEqual(dstColor.v, target.v));
}


TEST_F(TestFixtureConversion, ColorConversionBlackRgbHsb) {
	ColorSpace::Rgb srcColor(0, 0, 0);
	ColorSpace::Hsb dstColor;
	ColorSpace::Hsb target(0, 0, 0);

	srcColor.To<ColorSpace::Hsb>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.h, target.h));
	ASSERT_TRUE(nearlyEqual(dstColor.s, target.s));
	ASSERT_TRUE(nearlyEqual(dstColor.b, target.b));
}


TEST_F(TestFixtureConversion, ColorConversionBlackRgbHunterLab) {
	ColorSpace::Rgb srcColor(0, 0, 0);
	ColorSpace::HunterLab dstColor;
	ColorSpace::HunterLab target(0, 0, 0);

	srcColor.To<ColorSpace::HunterLab>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
	ASSERT_TRUE(nearlyEqual(dstColor.a, target.a));
	ASSERT_TRUE(nearlyEqual(dstColor.b, target.b));
}


TEST_F(TestFixtureConversion, ColorConversionGoldenrodRgbCmy) {
	ColorSpace::Rgb srcColor(218, 165, 32);
	ColorSpace::Cmy dstColor;
	ColorSpace::Cmy target(.14510, .35294, .87451);

	srcColor.To<ColorSpace::Cmy>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.c, target.c));
	ASSERT_TRUE(nearlyEqual(dstColor.m, target.m));
	ASSERT_TRUE(nearlyEqual(dstColor.y, target.y));
}


TEST_F(TestFixtureConversion, ColorConversionGoldenrodRgbCmyk) {
	ColorSpace::Rgb srcColor(218, 165, 32);
	ColorSpace::Cmyk dstColor;
	ColorSpace::Cmyk target(0, .24312, .85321, .14510);

	srcColor.To<ColorSpace::Cmyk>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.c, target.c));
	ASSERT_TRUE(nearlyEqual(dstColor.m, target.m));
	ASSERT_TRUE(nearlyEqual(dstColor.y, target.y));
	ASSERT_TRUE(nearlyEqual(dstColor.k, target.k));
}


TEST_F(TestFixtureConversion, ColorConversionGoldenrodRgbHsl) {
	ColorSpace::Rgb srcColor(218, 165, 32);
	ColorSpace::Hsl dstColor;
	ColorSpace::Hsl target(43, 74.4, 49);

	srcColor.To<ColorSpace::Hsl>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.h, target.h));
	ASSERT_TRUE(nearlyEqual(dstColor.s, target.s));
	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
}


TEST_F(TestFixtureConversion, ColorConversionGoldenrodRgbLab) {
	ColorSpace::Rgb srcColor(218, 165, 32);
	ColorSpace::Lab dstColor;
	ColorSpace::Lab target(70.816, 8.525, 68.765);

	srcColor.To<ColorSpace::Lab>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
	ASSERT_TRUE(nearlyEqual(dstColor.a, target.a));
	ASSERT_TRUE(nearlyEqual(dstColor.b, target.b));
}


TEST_F(TestFixtureConversion, ColorConversionGoldenrodRgbLch) {
	ColorSpace::Rgb srcColor(218, 165, 32);
	ColorSpace::Lch dstColor;
	ColorSpace::Lch target(70.816, 69.291, 82.933);

	srcColor.To<ColorSpace::Lch>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
	ASSERT_TRUE(nearlyEqual(dstColor.c, target.c));
	ASSERT_TRUE(nearlyEqual(dstColor.h, target.h));
}


TEST_F(TestFixtureConversion, ColorConversionGoldenrodRgbRgb) {
	ColorSpace::Rgb srcColor(218, 165, 32);
	ColorSpace::Rgb dstColor;
	ColorSpace::Rgb target(218, 165, 32);

	srcColor.To<ColorSpace::Rgb>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.r, target.r));
	ASSERT_TRUE(nearlyEqual(dstColor.g, target.g));
	ASSERT_TRUE(nearlyEqual(dstColor.b, target.b));
}


TEST_F(TestFixtureConversion, ColorConversionGoldenrodRgbXyz) {
	ColorSpace::Rgb srcColor(218, 165, 32);
	ColorSpace::Xyz dstColor;
	ColorSpace::Xyz target(42.629, 41.920, 7.211);

	srcColor.To<ColorSpace::Xyz>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.x, target.x));
	ASSERT_TRUE(nearlyEqual(dstColor.y, target.y));
	ASSERT_TRUE(nearlyEqual(dstColor.z, target.z));
}


TEST_F(TestFixtureConversion, ColorConversionGoldenrodRgbYxy) {
	ColorSpace::Rgb srcColor(218, 165, 32);
	ColorSpace::Yxy dstColor;
	ColorSpace::Yxy target(41.920, .46457, .45684);

	srcColor.To<ColorSpace::Yxy>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.y1, target.y1));
	ASSERT_TRUE(nearlyEqual(dstColor.x, target.x));
	ASSERT_TRUE(nearlyEqual(dstColor.y2, target.y2));
}


TEST_F(TestFixtureConversion, ColorConversionGoldenrodRgbLuv) {
	ColorSpace::Rgb srcColor(218, 165, 32);
	ColorSpace::Luv dstColor;
	ColorSpace::Luv target(70.816, 44.368, 69.994);

	srcColor.To<ColorSpace::Luv>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
	ASSERT_TRUE(nearlyEqual(dstColor.u, target.u));
	ASSERT_TRUE(nearlyEqual(dstColor.v, target.v));
}


TEST_F(TestFixtureConversion, ColorConversionGoldenrodRgbHsv) {
	ColorSpace::Rgb srcColor(218, 165, 32);
	ColorSpace::Hsv dstColor;
	ColorSpace::Hsv target(42.903, .85, .85);

	srcColor.To<ColorSpace::Hsv>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.h, target.h));
	ASSERT_TRUE(nearlyEqual(dstColor.s, target.s));
	ASSERT_TRUE(nearlyEqual(dstColor.v, target.v));
}


TEST_F(TestFixtureConversion, ColorConversionGoldenrodRgbHsb) {
	ColorSpace::Rgb srcColor(218, 165, 32);
	ColorSpace::Hsb dstColor;
	ColorSpace::Hsb target(42.903, .85, .85);

	srcColor.To<ColorSpace::Hsb>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.h, target.h));
	ASSERT_TRUE(nearlyEqual(dstColor.s, target.s));
	ASSERT_TRUE(nearlyEqual(dstColor.b, target.b));
}


TEST_F(TestFixtureConversion, ColorConversionGoldenrodRgbHunterLab) {
	ColorSpace::Rgb srcColor(218, 165, 32);
	ColorSpace::HunterLab dstColor;
	ColorSpace::HunterLab target(64.746, 4.222, 38.719);

	srcColor.To<ColorSpace::HunterLab>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
	ASSERT_TRUE(nearlyEqual(dstColor.a, target.a));
	ASSERT_TRUE(nearlyEqual(dstColor.b, target.b));
}


TEST_F(TestFixtureConversion, ColorConversionSteelBlueCmyCmy) {
	ColorSpace::Cmy srcColor(.72549, .49020, .29412);
	ColorSpace::Cmy dstColor;
	ColorSpace::Cmy target(.72549, .49020, .29412);

	srcColor.To<ColorSpace::Cmy>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.c, target.c));
	ASSERT_TRUE(nearlyEqual(dstColor.m, target.m));
	ASSERT_TRUE(nearlyEqual(dstColor.y, target.y));
}


TEST_F(TestFixtureConversion, ColorConversionSteelBlueCmyCmyk) {
	ColorSpace::Cmy srcColor(.72549, .49020, .29412);
	ColorSpace::Cmyk dstColor;
	ColorSpace::Cmyk target(.61111, .27778, 0, .29412);

	srcColor.To<ColorSpace::Cmyk>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.c, target.c));
	ASSERT_TRUE(nearlyEqual(dstColor.m, target.m));
	ASSERT_TRUE(nearlyEqual(dstColor.y, target.y));
	ASSERT_TRUE(nearlyEqual(dstColor.k, target.k));
}


TEST_F(TestFixtureConversion, ColorConversionSteelBlueCmyHsl) {
	ColorSpace::Cmy srcColor(.72549, .49020, .29412);
	ColorSpace::Hsl dstColor;
	ColorSpace::Hsl target(207, 44, 49);

	srcColor.To<ColorSpace::Hsl>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.h, target.h));
	ASSERT_TRUE(nearlyEqual(dstColor.s, target.s));
	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
}


TEST_F(TestFixtureConversion, ColorConversionSteelBlueCmyLab) {
	ColorSpace::Cmy srcColor(.72549, .49020, .29412);
	ColorSpace::Lab dstColor;
	ColorSpace::Lab target(52.467, -4.070, -32.198);

	srcColor.To<ColorSpace::Lab>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
	ASSERT_TRUE(nearlyEqual(dstColor.a, target.a));
	ASSERT_TRUE(nearlyEqual(dstColor.b, target.b));
}


TEST_F(TestFixtureConversion, ColorConversionSteelBlueCmyLch) {
	ColorSpace::Cmy srcColor(.72549, .49020, .29412);
	ColorSpace::Lch dstColor;
	ColorSpace::Lch target(52.467, 32.454, 262.796);

	srcColor.To<ColorSpace::Lch>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
	ASSERT_TRUE(nearlyEqual(dstColor.c, target.c));
	ASSERT_TRUE(nearlyEqual(dstColor.h, target.h));
}


TEST_F(TestFixtureConversion, ColorConversionSteelBlueCmyRgb) {
	ColorSpace::Cmy srcColor(.72549, .49020, .29412);
	ColorSpace::Rgb dstColor;
	ColorSpace::Rgb target(70, 130, 180);

	srcColor.To<ColorSpace::Rgb>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.r, target.r));
	ASSERT_TRUE(nearlyEqual(dstColor.g, target.g));
	ASSERT_TRUE(nearlyEqual(dstColor.b, target.b));
}


TEST_F(TestFixtureConversion, ColorConversionSteelBlueCmyXyz) {
	ColorSpace::Cmy srcColor(.72549, .49020, .29412);
	ColorSpace::Xyz dstColor;
	ColorSpace::Xyz target(18.746, 20.562, 46.161);

	srcColor.To<ColorSpace::Xyz>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.x, target.x));
	ASSERT_TRUE(nearlyEqual(dstColor.y, target.y));
	ASSERT_TRUE(nearlyEqual(dstColor.z, target.z));
}


TEST_F(TestFixtureConversion, ColorConversionSteelBlueCmyYxy) {
	ColorSpace::Cmy srcColor(.72549, .49020, .29412);
	ColorSpace::Yxy dstColor;
	ColorSpace::Yxy target(20.562, .21934, .24058);

	srcColor.To<ColorSpace::Yxy>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.y1, target.y1));
	ASSERT_TRUE(nearlyEqual(dstColor.x, target.x));
	ASSERT_TRUE(nearlyEqual(dstColor.y2, target.y2));
}


TEST_F(TestFixtureConversion, ColorConversionSteelBlueCmyLuv) {
	ColorSpace::Cmy srcColor(.72549, .49020, .29412);
	ColorSpace::Luv dstColor;
	ColorSpace::Luv target(52.467, -25.107, -48.374);

	srcColor.To<ColorSpace::Luv>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
	ASSERT_TRUE(nearlyEqual(dstColor.u, target.u));
	ASSERT_TRUE(nearlyEqual(dstColor.v, target.v));
}


TEST_F(TestFixtureConversion, ColorConversionDarkVioletCmykCmy) {
	ColorSpace::Cmyk srcColor(.29858, 1, 0, .17255);
	ColorSpace::Cmy dstColor;
	ColorSpace::Cmy target(.41961, 1, .17255);

	srcColor.To<ColorSpace::Cmy>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.c, target.c));
	ASSERT_TRUE(nearlyEqual(dstColor.m, target.m));
	ASSERT_TRUE(nearlyEqual(dstColor.y, target.y));
}


TEST_F(TestFixtureConversion, ColorConversionDarkVioletCmykCmyk) {
	ColorSpace::Cmyk srcColor(.29858, 1, 0, .17255);
	ColorSpace::Cmyk dstColor;
	ColorSpace::Cmyk target(.29858, 1, 0, .17255);

	srcColor.To<ColorSpace::Cmyk>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.c, target.c));
	ASSERT_TRUE(nearlyEqual(dstColor.m, target.m));
	ASSERT_TRUE(nearlyEqual(dstColor.y, target.y));
	ASSERT_TRUE(nearlyEqual(dstColor.k, target.k));
}


TEST_F(TestFixtureConversion, ColorConversionDarkVioletCmykHsl) {
	ColorSpace::Cmyk srcColor(.29858, 1, 0, .17255);
	ColorSpace::Hsl dstColor;
	ColorSpace::Hsl target(282, 100, 41);

	srcColor.To<ColorSpace::Hsl>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.h, target.h));
	ASSERT_TRUE(nearlyEqual(dstColor.s, target.s));
	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
}


TEST_F(TestFixtureConversion, ColorConversionDarkVioletCmykLab) {
	ColorSpace::Cmyk srcColor(.29858, 1, 0, .17255);
	ColorSpace::Lab dstColor;
	ColorSpace::Lab target(39.579, 76.336, -70.378);

	srcColor.To<ColorSpace::Lab>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
	ASSERT_TRUE(nearlyEqual(dstColor.a, target.a));
	ASSERT_TRUE(nearlyEqual(dstColor.b, target.b));
}


TEST_F(TestFixtureConversion, ColorConversionDarkVioletCmykLch) {
	ColorSpace::Cmyk srcColor(.29858, 1, 0, .17255);
	ColorSpace::Lch dstColor;
	ColorSpace::Lch target(39.579, 103.828, 317.325);

	srcColor.To<ColorSpace::Lch>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
	ASSERT_TRUE(nearlyEqual(dstColor.c, target.c));
	ASSERT_TRUE(nearlyEqual(dstColor.h, target.h));
}


TEST_F(TestFixtureConversion, ColorConversionDarkVioletCmykRgb) {
	ColorSpace::Cmyk srcColor(.29858, 1, 0, .17255);
	ColorSpace::Rgb dstColor;
	ColorSpace::Rgb target(148, 0, 211);

	srcColor.To<ColorSpace::Rgb>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.r, target.r));
	ASSERT_TRUE(nearlyEqual(dstColor.g, target.g));
	ASSERT_TRUE(nearlyEqual(dstColor.b, target.b));
}


TEST_F(TestFixtureConversion, ColorConversionDarkVioletCmykXyz) {
	ColorSpace::Cmyk srcColor(.29858, 1, 0, .17255);
	ColorSpace::Xyz dstColor;
	ColorSpace::Xyz target(23.970, 10.999, 62.487);

	srcColor.To<ColorSpace::Xyz>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.x, target.x));
	ASSERT_TRUE(nearlyEqual(dstColor.y, target.y));
	ASSERT_TRUE(nearlyEqual(dstColor.z, target.z));
}


TEST_F(TestFixtureConversion, ColorConversionDarkVioletCmykYxy) {
	ColorSpace::Cmyk srcColor(.29858, 1, 0, .17255);
	ColorSpace::Yxy dstColor;
	ColorSpace::Yxy target(10.99, .24596, .11286);

	srcColor.To<ColorSpace::Yxy>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.y1, target.y1));
	ASSERT_TRUE(nearlyEqual(dstColor.x, target.x));
	ASSERT_TRUE(nearlyEqual(dstColor.y2, target.y2));
}


TEST_F(TestFixtureConversion, ColorConversionAliceBlueHslCmy) {
	ColorSpace::Hsl srcColor(208, 100, 97);
	ColorSpace::Cmy dstColor;
	ColorSpace::Cmy target(.06, .028, 0);

	srcColor.To<ColorSpace::Cmy>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.c, target.c));
	ASSERT_TRUE(nearlyEqual(dstColor.m, target.m));
	ASSERT_TRUE(nearlyEqual(dstColor.y, target.y));
}


TEST_F(TestFixtureConversion, ColorConversionAliceBlueHslCmyk) {
	ColorSpace::Hsl srcColor(208, 100, 97);
	ColorSpace::Cmyk dstColor;
	ColorSpace::Cmyk target(.06, .028, 0, 0);

	srcColor.To<ColorSpace::Cmyk>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.c, target.c));
	ASSERT_TRUE(nearlyEqual(dstColor.m, target.m));
	ASSERT_TRUE(nearlyEqual(dstColor.y, target.y));
	ASSERT_TRUE(nearlyEqual(dstColor.k, target.k));
}


TEST_F(TestFixtureConversion, ColorConversionAliceBlueHslHsl) {
	ColorSpace::Hsl srcColor(208, 100, 97);
	ColorSpace::Hsl dstColor;
	ColorSpace::Hsl target(208, 100, 97);

	srcColor.To<ColorSpace::Hsl>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.h, target.h));
	ASSERT_TRUE(nearlyEqual(dstColor.s, target.s));
	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
}


TEST_F(TestFixtureConversion, ColorConversionAliceBlueHslLab) {
	ColorSpace::Hsl srcColor(208, 100, 97);
	ColorSpace::Lab dstColor;
	ColorSpace::Lab target(97.179, -1.3688, -4.358);

	srcColor.To<ColorSpace::Lab>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
	ASSERT_TRUE(nearlyEqual(dstColor.a, target.a));
	ASSERT_TRUE(nearlyEqual(dstColor.b, target.b));
}


TEST_F(TestFixtureConversion, ColorConversionAliceBlueHslLch) {
	ColorSpace::Hsl srcColor(208, 100, 97);
	ColorSpace::Lch dstColor;
	ColorSpace::Lch target(97.179, 4.5683, 252.551);

	srcColor.To<ColorSpace::Lch>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
	ASSERT_TRUE(nearlyEqual(dstColor.c, target.c));
	ASSERT_TRUE(nearlyEqual(dstColor.h, target.h));
}


TEST_F(TestFixtureConversion, ColorConversionAliceBlueHslRgb) {
	ColorSpace::Hsl srcColor(208, 100, 97);
	ColorSpace::Rgb dstColor;
	ColorSpace::Rgb target(240, 248, 255);

	srcColor.To<ColorSpace::Rgb>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.r, target.r));
	ASSERT_TRUE(nearlyEqual(dstColor.g, target.g));
	ASSERT_TRUE(nearlyEqual(dstColor.b, target.b));
}


TEST_F(TestFixtureConversion, ColorConversionAliceBlueHslXyz) {
	ColorSpace::Hsl srcColor(208, 100, 97);
	ColorSpace::Xyz dstColor;
	ColorSpace::Xyz target(87.553, 92.880, 107.921);

	srcColor.To<ColorSpace::Xyz>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.x, target.x));
	ASSERT_TRUE(nearlyEqual(dstColor.y, target.y));
	ASSERT_TRUE(nearlyEqual(dstColor.z, target.z));
}


TEST_F(TestFixtureConversion, ColorConversionAliceBlueHslYxy) {
	ColorSpace::Hsl srcColor(208, 100, 97);
	ColorSpace::Yxy dstColor;
	ColorSpace::Yxy target(92.880, .30363, .32210);

	srcColor.To<ColorSpace::Yxy>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.y1, target.y1));
	ASSERT_TRUE(nearlyEqual(dstColor.x, target.x));
	ASSERT_TRUE(nearlyEqual(dstColor.y2, target.y2));
}


TEST_F(TestFixtureConversion, ColorConversionRedLabCmy) {
	ColorSpace::Lab srcColor(53.240, 80.092, 67.203);
	ColorSpace::Cmy dstColor;
	ColorSpace::Cmy target(0.0000035, .99970, 1);

	srcColor.To<ColorSpace::Cmy>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.c, target.c));
	ASSERT_TRUE(nearlyEqual(dstColor.m, target.m));
	ASSERT_TRUE(nearlyEqual(dstColor.y, target.y));
}


TEST_F(TestFixtureConversion, ColorConversionRedLabCmyk) {
	ColorSpace::Lab srcColor(53.240, 80.092, 67.203);
	ColorSpace::Cmyk dstColor;
	ColorSpace::Cmyk target(0, .99970, 1, .0000035);

	srcColor.To<ColorSpace::Cmyk>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.c, target.c));
	ASSERT_TRUE(nearlyEqual(dstColor.m, target.m));
	ASSERT_TRUE(nearlyEqual(dstColor.y, target.y));
	ASSERT_TRUE(nearlyEqual(dstColor.k, target.k));
}


TEST_F(TestFixtureConversion, ColorConversionRedLabHsl) {
	ColorSpace::Lab srcColor(53.240, 80.092, 67.203);
	ColorSpace::Hsl dstColor;
	ColorSpace::Hsl target(0, 100, 50);

	srcColor.To<ColorSpace::Hsl>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.h, target.h));
	ASSERT_TRUE(nearlyEqual(dstColor.s, target.s));
	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
}


TEST_F(TestFixtureConversion, ColorConversionRedLabLab) {
	ColorSpace::Lab srcColor(53.240, 80.092, 67.203);
	ColorSpace::Lab dstColor;
	ColorSpace::Lab target(53.240, 80.092, 67.203);

	srcColor.To<ColorSpace::Lab>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
	ASSERT_TRUE(nearlyEqual(dstColor.a, target.a));
	ASSERT_TRUE(nearlyEqual(dstColor.b, target.b));
}


TEST_F(TestFixtureConversion, ColorConversionRedLabLch) {
	ColorSpace::Lab srcColor(53.240, 80.092, 67.203);
	ColorSpace::Lch dstColor;
	ColorSpace::Lch target(53.33, 104.575, 40);

	srcColor.To<ColorSpace::Lch>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
	ASSERT_TRUE(nearlyEqual(dstColor.c, target.c));
	ASSERT_TRUE(nearlyEqual(dstColor.h, target.h));
}


TEST_F(TestFixtureConversion, ColorConversionRedLabRgb) {
	ColorSpace::Lab srcColor(53.240, 80.092, 67.203);
	ColorSpace::Rgb dstColor;
	ColorSpace::Rgb target(255, 0, 0);

	srcColor.To<ColorSpace::Rgb>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.r, target.r));
	ASSERT_TRUE(nearlyEqual(dstColor.g, target.g));
	ASSERT_TRUE(nearlyEqual(dstColor.b, target.b));
}


TEST_F(TestFixtureConversion, ColorConversionRedLabXyz) {
	ColorSpace::Lab srcColor(53.240, 80.092, 67.203);
	ColorSpace::Xyz dstColor;
	ColorSpace::Xyz target(41.240, 21.260, 1.930);

	srcColor.To<ColorSpace::Xyz>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.x, target.x));
	ASSERT_TRUE(nearlyEqual(dstColor.y, target.y));
	ASSERT_TRUE(nearlyEqual(dstColor.z, target.z));
}


TEST_F(TestFixtureConversion, ColorConversionRedLabYxy) {
	ColorSpace::Lab srcColor(53.240, 80.092, 67.203);
	ColorSpace::Yxy dstColor;
	ColorSpace::Yxy target(21.260, 0.64007, .32997);

	srcColor.To<ColorSpace::Yxy>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.y1, target.y1));
	ASSERT_TRUE(nearlyEqual(dstColor.x, target.x));
	ASSERT_TRUE(nearlyEqual(dstColor.y2, target.y2));
}


TEST_F(TestFixtureConversion, ColorConversionMaroonLchCmy) {
	ColorSpace::Lch srcColor(24.829, 60.093, 38.180);
	ColorSpace::Cmy dstColor;
	ColorSpace::Cmy target(.509804, .99986, 1);

	srcColor.To<ColorSpace::Cmy>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.c, target.c));
	ASSERT_TRUE(nearlyEqual(dstColor.m, target.m));
	ASSERT_TRUE(nearlyEqual(dstColor.y, target.y));
}


TEST_F(TestFixtureConversion, ColorConversionMaroonLchCmyk) {
	ColorSpace::Lch srcColor(24.829, 60.093, 38.180);
	ColorSpace::Cmyk dstColor;
	ColorSpace::Cmyk target(.0, .99972, 1, .50980);

	srcColor.To<ColorSpace::Cmyk>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.c, target.c));
	ASSERT_TRUE(nearlyEqual(dstColor.m, target.m));
	ASSERT_TRUE(nearlyEqual(dstColor.y, target.y));
	ASSERT_TRUE(nearlyEqual(dstColor.k, target.k));
}


TEST_F(TestFixtureConversion, ColorConversionMaroonLchHsl) {
	ColorSpace::Lch srcColor(24.829, 60.093, 38.180);
	ColorSpace::Hsl dstColor;
	ColorSpace::Hsl target(0, 100, 24.5);

	srcColor.To<ColorSpace::Hsl>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.h, target.h));
	ASSERT_TRUE(nearlyEqual(dstColor.s, target.s));
	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
}


TEST_F(TestFixtureConversion, ColorConversionMaroonLchLab) {
	ColorSpace::Lch srcColor(24.829, 60.093, 38.180);
	ColorSpace::Lab dstColor;
	ColorSpace::Lab target(24.829, 47.237, 37.146);

	srcColor.To<ColorSpace::Lab>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
	ASSERT_TRUE(nearlyEqual(dstColor.a, target.a));
	ASSERT_TRUE(nearlyEqual(dstColor.b, target.b));
}


TEST_F(TestFixtureConversion, ColorConversionMaroonLchLch) {
	ColorSpace::Lch srcColor(24.829, 60.093, 38.180);
	ColorSpace::Lch dstColor;
	ColorSpace::Lch target(24.829, 60.093, 38.180);

	srcColor.To<ColorSpace::Lch>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
	ASSERT_TRUE(nearlyEqual(dstColor.c, target.c));
	ASSERT_TRUE(nearlyEqual(dstColor.h, target.h));
}


TEST_F(TestFixtureConversion, ColorConversionMaroonLchRgb) {
	ColorSpace::Lch srcColor(24.829, 60.093, 38.180);
	ColorSpace::Rgb dstColor;
	ColorSpace::Rgb target(125, .03555, .00182);

	srcColor.To<ColorSpace::Rgb>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.r, target.r));
	ASSERT_TRUE(nearlyEqual(dstColor.g, target.g));
	ASSERT_TRUE(nearlyEqual(dstColor.b, target.b));
}


TEST_F(TestFixtureConversion, ColorConversionMaroonLchXyz) {
	ColorSpace::Lch srcColor(24.829, 60.093, 38.180);
	ColorSpace::Xyz dstColor;
	ColorSpace::Xyz target(8.458, 4.360, .396);

	srcColor.To<ColorSpace::Xyz>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.x, target.x));
	ASSERT_TRUE(nearlyEqual(dstColor.y, target.y));
	ASSERT_TRUE(nearlyEqual(dstColor.z, target.z));
}


TEST_F(TestFixtureConversion, ColorConversionMaroonLchYxy) {
	ColorSpace::Lch srcColor(24.829, 60.093, 38.180);
	ColorSpace::Yxy dstColor;
	ColorSpace::Yxy target(4.360, 0.64005, .32998);

	srcColor.To<ColorSpace::Yxy>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.y1, target.y1));
	ASSERT_TRUE(nearlyEqual(dstColor.x, target.x));
	ASSERT_TRUE(nearlyEqual(dstColor.y2, target.y2));
}


TEST_F(TestFixtureConversion, ColorConversionRivergumXyzCmy) {
	ColorSpace::Xyz srcColor(13.123, 15.372, 13.174);
	ColorSpace::Cmy dstColor;
	ColorSpace::Cmy target(.614, .55494, .62627);

	srcColor.To<ColorSpace::Cmy>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.c, target.c));
	ASSERT_TRUE(nearlyEqual(dstColor.m, target.m));
	ASSERT_TRUE(nearlyEqual(dstColor.y, target.y));
}


TEST_F(TestFixtureConversion, ColorConversionRivergumXyzCmyk) {
	ColorSpace::Xyz srcColor(13.123, 15.372, 13.174);
	ColorSpace::Cmyk dstColor;
	ColorSpace::Cmyk target(.1327, 0, .16028, .55494);

	srcColor.To<ColorSpace::Cmyk>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.c, target.c));
	ASSERT_TRUE(nearlyEqual(dstColor.m, target.m));
	ASSERT_TRUE(nearlyEqual(dstColor.y, target.y));
	ASSERT_TRUE(nearlyEqual(dstColor.k, target.k));
}


TEST_F(TestFixtureConversion, ColorConversionRivergumXyzHsl) {
	ColorSpace::Xyz srcColor(13.123, 15.372, 13.174);
	ColorSpace::Hsl dstColor;
	ColorSpace::Hsl target(109.999, 8.654, 40.7843);

	srcColor.To<ColorSpace::Hsl>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.h, target.h));
	ASSERT_TRUE(nearlyEqual(dstColor.s, target.s));
	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
}


TEST_F(TestFixtureConversion, ColorConversionRivergumXyzLab) {
	ColorSpace::Xyz srcColor(13.123, 15.372, 13.174);
	ColorSpace::Lab dstColor;
	ColorSpace::Lab target(46.140, -9.421, 8.218);

	srcColor.To<ColorSpace::Lab>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
	ASSERT_TRUE(nearlyEqual(dstColor.a, target.a));
	ASSERT_TRUE(nearlyEqual(dstColor.b, target.b));
}


TEST_F(TestFixtureConversion, ColorConversionRivergumXyzLch) {
	ColorSpace::Xyz srcColor(13.123, 15.372, 13.174);
	ColorSpace::Lch dstColor;
	ColorSpace::Lch target(46.140, 12.502, 138.898);

	srcColor.To<ColorSpace::Lch>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
	ASSERT_TRUE(nearlyEqual(dstColor.c, target.c));
	ASSERT_TRUE(nearlyEqual(dstColor.h, target.h));
}


TEST_F(TestFixtureConversion, ColorConversionRivergumXyzRgb) {
	ColorSpace::Xyz srcColor(13.123, 15.372, 13.174);
	ColorSpace::Rgb dstColor;
	ColorSpace::Rgb target(98.43, 113.49, 95.30);

	srcColor.To<ColorSpace::Rgb>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.r, target.r));
	ASSERT_TRUE(nearlyEqual(dstColor.g, target.g));
	ASSERT_TRUE(nearlyEqual(dstColor.b, target.b));
}


TEST_F(TestFixtureConversion, ColorConversionRivergumXyzXyz) {
	ColorSpace::Xyz srcColor(13.123, 15.372, 13.174);
	ColorSpace::Xyz dstColor;
	ColorSpace::Xyz target(13.123, 15.372, 13.174);

	srcColor.To<ColorSpace::Xyz>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.x, target.x));
	ASSERT_TRUE(nearlyEqual(dstColor.y, target.y));
	ASSERT_TRUE(nearlyEqual(dstColor.z, target.z));
}


TEST_F(TestFixtureConversion, ColorConversionRivergumXyzYxy) {
	ColorSpace::Xyz srcColor(13.123, 15.372, 13.174);
	ColorSpace::Yxy dstColor;
	ColorSpace::Yxy target(15.372, .31493, .36892);

	srcColor.To<ColorSpace::Yxy>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.y1, target.y1));
	ASSERT_TRUE(nearlyEqual(dstColor.x, target.x));
	ASSERT_TRUE(nearlyEqual(dstColor.y2, target.y2));
}


TEST_F(TestFixtureConversion, ColorConversionSilverLuvCmy) {
	ColorSpace::Luv srcColor(77.704, .001, -.013);
	ColorSpace::Cmy dstColor;
	ColorSpace::Cmy target(.24706, .24704, .24706);

	srcColor.To<ColorSpace::Cmy>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.c, target.c));
	ASSERT_TRUE(nearlyEqual(dstColor.m, target.m));
	ASSERT_TRUE(nearlyEqual(dstColor.y, target.y));
}


TEST_F(TestFixtureConversion, ColorConversionSilverLuvCmyk) {
	ColorSpace::Luv srcColor(77.704, .001, -.013);
	ColorSpace::Cmyk dstColor;
	ColorSpace::Cmyk target(.0000148, .000, .0000186, .24704);

	srcColor.To<ColorSpace::Cmyk>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.c, target.c));
	ASSERT_TRUE(nearlyEqual(dstColor.m, target.m));
	ASSERT_TRUE(nearlyEqual(dstColor.y, target.y));
	ASSERT_TRUE(nearlyEqual(dstColor.k, target.k));
}


TEST_F(TestFixtureConversion, ColorConversionSilverLuvHsl) {
	ColorSpace::Luv srcColor(77.704, .001, -.013);
	ColorSpace::Hsl dstColor;
	ColorSpace::Hsl target(60, 0.7874, 75.098);

	srcColor.To<ColorSpace::Hsl>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.h, target.h));
	ASSERT_TRUE(nearlyEqual(dstColor.s, target.s));
	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
}


TEST_F(TestFixtureConversion, ColorConversionSilverLuvLab) {
	ColorSpace::Luv srcColor(77.704, .001, -.013);
	ColorSpace::Lab dstColor;
	ColorSpace::Lab target(77.704, .0026, -.00696);

	srcColor.To<ColorSpace::Lab>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
	ASSERT_TRUE(nearlyEqual(dstColor.a, target.a));
	ASSERT_TRUE(nearlyEqual(dstColor.b, target.b));
}


TEST_F(TestFixtureConversion, ColorConversionSilverLuvLch) {
	ColorSpace::Luv srcColor(77.704, .001, -.013);
	ColorSpace::Lch dstColor;
	ColorSpace::Lch target(77.704, .0074, 290.49463);

	srcColor.To<ColorSpace::Lch>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
	ASSERT_TRUE(nearlyEqual(dstColor.c, target.c));
	ASSERT_TRUE(nearlyEqual(dstColor.h, target.h));
}


TEST_F(TestFixtureConversion, ColorConversionSilverLuvRgb) {
	ColorSpace::Luv srcColor(77.704, .001, -.013);
	ColorSpace::Rgb dstColor;
	ColorSpace::Rgb target(192, 192, 192);

	srcColor.To<ColorSpace::Rgb>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.r, target.r));
	ASSERT_TRUE(nearlyEqual(dstColor.g, target.g));
	ASSERT_TRUE(nearlyEqual(dstColor.b, target.b));
}


TEST_F(TestFixtureConversion, ColorConversionSilverLuvXyz) {
	ColorSpace::Luv srcColor(77.704, .001, -.013);
	ColorSpace::Xyz dstColor;
	ColorSpace::Xyz target(50.102, 52.711, 57.402);

	srcColor.To<ColorSpace::Xyz>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.x, target.x));
	ASSERT_TRUE(nearlyEqual(dstColor.y, target.y));
	ASSERT_TRUE(nearlyEqual(dstColor.z, target.z));
}


TEST_F(TestFixtureConversion, ColorConversionSilverLuvYxy) {
	ColorSpace::Luv srcColor(77.704, .001, -.013);
	ColorSpace::Yxy dstColor;
	ColorSpace::Yxy target(52.711, .31272, .32900);

	srcColor.To<ColorSpace::Yxy>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.y1, target.y1));
	ASSERT_TRUE(nearlyEqual(dstColor.x, target.x));
	ASSERT_TRUE(nearlyEqual(dstColor.y2, target.y2));
}


TEST_F(TestFixtureConversion, ColorConversionSilverLuvLuv) {
	ColorSpace::Luv srcColor(77.704, .001, -.013);
	ColorSpace::Luv dstColor;
	ColorSpace::Luv target(77.704, .001, -.013);

	srcColor.To<ColorSpace::Luv>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
	ASSERT_TRUE(nearlyEqual(dstColor.u, target.u));
	ASSERT_TRUE(nearlyEqual(dstColor.v, target.v));
}


TEST_F(TestFixtureConversion, ColorConversionAquamarineHsvCmy) {
	ColorSpace::Hsv srcColor(160, .5, 1);
	ColorSpace::Cmy dstColor;
	ColorSpace::Cmy target(.50196, 0, .16666);

	srcColor.To<ColorSpace::Cmy>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.c, target.c));
	ASSERT_TRUE(nearlyEqual(dstColor.m, target.m));
	ASSERT_TRUE(nearlyEqual(dstColor.y, target.y));
}


TEST_F(TestFixtureConversion, ColorConversionAquamarineHsvCmyk) {
	ColorSpace::Hsv srcColor(160, .5, 1);
	ColorSpace::Cmyk dstColor;
	ColorSpace::Cmyk target(.5, 0, .16666, 0);

	srcColor.To<ColorSpace::Cmyk>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.c, target.c));
	ASSERT_TRUE(nearlyEqual(dstColor.m, target.m));
	ASSERT_TRUE(nearlyEqual(dstColor.y, target.y));
	ASSERT_TRUE(nearlyEqual(dstColor.k, target.k));
}


TEST_F(TestFixtureConversion, ColorConversionAquamarineHsvHsl) {
	ColorSpace::Hsv srcColor(160, .5, 1);
	ColorSpace::Hsl dstColor;
	ColorSpace::Hsl target(160, 100, 74.9019);

	srcColor.To<ColorSpace::Hsl>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.h, target.h));
	ASSERT_TRUE(nearlyEqual(dstColor.s, target.s));
	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
}


TEST_F(TestFixtureConversion, ColorConversionAquamarineHsvLab) {
	ColorSpace::Hsv srcColor(160, .5, 1);
	ColorSpace::Lab dstColor;
	ColorSpace::Lab target(92.036, -45.521, 9.49689);

	srcColor.To<ColorSpace::Lab>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
	ASSERT_TRUE(nearlyEqual(dstColor.a, target.a));
	ASSERT_TRUE(nearlyEqual(dstColor.b, target.b));
}


TEST_F(TestFixtureConversion, ColorConversionAquamarineHsvLch) {
	ColorSpace::Hsv srcColor(160, .5, 1);
	ColorSpace::Lch dstColor;
	ColorSpace::Lch target(92.036, 46.545, 167.957);

	srcColor.To<ColorSpace::Lch>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
	ASSERT_TRUE(nearlyEqual(dstColor.c, target.c));
	ASSERT_TRUE(nearlyEqual(dstColor.h, target.h));
}


TEST_F(TestFixtureConversion, ColorConversionAquamarineHsvRgb) {
	ColorSpace::Hsv srcColor(160, .5, 1);
	ColorSpace::Rgb dstColor;
	ColorSpace::Rgb target(127, 255, 212);

	srcColor.To<ColorSpace::Rgb>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.r, target.r));
	ASSERT_TRUE(nearlyEqual(dstColor.g, target.g));
	ASSERT_TRUE(nearlyEqual(dstColor.b, target.b));
}


TEST_F(TestFixtureConversion, ColorConversionAquamarineHsvXyz) {
	ColorSpace::Hsv srcColor(160, .5, 1);
	ColorSpace::Xyz dstColor;
	ColorSpace::Xyz target(56.396, 80.785, 74.908);

	srcColor.To<ColorSpace::Xyz>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.x, target.x));
	ASSERT_TRUE(nearlyEqual(dstColor.y, target.y));
	ASSERT_TRUE(nearlyEqual(dstColor.z, target.z));
}


TEST_F(TestFixtureConversion, ColorConversionAquamarineHsvYxy) {
	ColorSpace::Hsv srcColor(160, .5, 1);
	ColorSpace::Yxy dstColor;
	ColorSpace::Yxy target(80.785, .26591, .38090);

	srcColor.To<ColorSpace::Yxy>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.y1, target.y1));
	ASSERT_TRUE(nearlyEqual(dstColor.x, target.x));
	ASSERT_TRUE(nearlyEqual(dstColor.y2, target.y2));
}


TEST_F(TestFixtureConversion, ColorConversionAquamarineHsvLuv) {
	ColorSpace::Hsv srcColor(160, .5, 1);
	ColorSpace::Luv dstColor;
	ColorSpace::Luv target(92.036, -55.917, 21.99756);

	srcColor.To<ColorSpace::Luv>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
	ASSERT_TRUE(nearlyEqual(dstColor.u, target.u));
	ASSERT_TRUE(nearlyEqual(dstColor.v, target.v));
}


TEST_F(TestFixtureConversion, ColorConversionAquamarineHsbCmy) {
	ColorSpace::Hsb srcColor(160, .5, 1);
	ColorSpace::Cmy dstColor;
	ColorSpace::Cmy target(.50196, 0, .16666);

	srcColor.To<ColorSpace::Cmy>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.c, target.c));
	ASSERT_TRUE(nearlyEqual(dstColor.m, target.m));
	ASSERT_TRUE(nearlyEqual(dstColor.y, target.y));
}


TEST_F(TestFixtureConversion, ColorConversionAquamarineHsbCmyk) {
	ColorSpace::Hsb srcColor(160, .5, 1);
	ColorSpace::Cmyk dstColor;
	ColorSpace::Cmyk target(.5, 0, .16666, 0);

	srcColor.To<ColorSpace::Cmyk>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.c, target.c));
	ASSERT_TRUE(nearlyEqual(dstColor.m, target.m));
	ASSERT_TRUE(nearlyEqual(dstColor.y, target.y));
	ASSERT_TRUE(nearlyEqual(dstColor.k, target.k));
}


TEST_F(TestFixtureConversion, ColorConversionAquamarineHsbHsl) {
	ColorSpace::Hsb srcColor(160, .5, 1);
	ColorSpace::Hsl dstColor;
	ColorSpace::Hsl target(160, 100, 74.9019);

	srcColor.To<ColorSpace::Hsl>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.h, target.h));
	ASSERT_TRUE(nearlyEqual(dstColor.s, target.s));
	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
}


TEST_F(TestFixtureConversion, ColorConversionAquamarineHsbLab) {
	ColorSpace::Hsb srcColor(160, .5, 1);
	ColorSpace::Lab dstColor;
	ColorSpace::Lab target(92.036, -45.521, 9.49689);

	srcColor.To<ColorSpace::Lab>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
	ASSERT_TRUE(nearlyEqual(dstColor.a, target.a));
	ASSERT_TRUE(nearlyEqual(dstColor.b, target.b));
}


TEST_F(TestFixtureConversion, ColorConversionAquamarineHsbLch) {
	ColorSpace::Hsb srcColor(160, .5, 1);
	ColorSpace::Lch dstColor;
	ColorSpace::Lch target(92.036, 46.545, 167.957);

	srcColor.To<ColorSpace::Lch>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
	ASSERT_TRUE(nearlyEqual(dstColor.c, target.c));
	ASSERT_TRUE(nearlyEqual(dstColor.h, target.h));
}


TEST_F(TestFixtureConversion, ColorConversionAquamarineHsbRgb) {
	ColorSpace::Hsb srcColor(160, .5, 1);
	ColorSpace::Rgb dstColor;
	ColorSpace::Rgb target(127, 255, 212);

	srcColor.To<ColorSpace::Rgb>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.r, target.r));
	ASSERT_TRUE(nearlyEqual(dstColor.g, target.g));
	ASSERT_TRUE(nearlyEqual(dstColor.b, target.b));
}


TEST_F(TestFixtureConversion, ColorConversionAquamarineHsbXyz) {
	ColorSpace::Hsb srcColor(160, .5, 1);
	ColorSpace::Xyz dstColor;
	ColorSpace::Xyz target(56.396, 80.785, 74.908);

	srcColor.To<ColorSpace::Xyz>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.x, target.x));
	ASSERT_TRUE(nearlyEqual(dstColor.y, target.y));
	ASSERT_TRUE(nearlyEqual(dstColor.z, target.z));
}


TEST_F(TestFixtureConversion, ColorConversionAquamarineHsbYxy) {
	ColorSpace::Hsb srcColor(160, .5, 1);
	ColorSpace::Yxy dstColor;
	ColorSpace::Yxy target(80.785, .26591, .38090);

	srcColor.To<ColorSpace::Yxy>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.y1, target.y1));
	ASSERT_TRUE(nearlyEqual(dstColor.x, target.x));
	ASSERT_TRUE(nearlyEqual(dstColor.y2, target.y2));
}


TEST_F(TestFixtureConversion, ColorConversionAquamarineHsbLuv) {
	ColorSpace::Hsb srcColor(160, .5, 1);
	ColorSpace::Luv dstColor;
	ColorSpace::Luv target(92.036, -55.917, 21.99756);

	srcColor.To<ColorSpace::Luv>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.l, target.l));
	ASSERT_TRUE(nearlyEqual(dstColor.u, target.u));
	ASSERT_TRUE(nearlyEqual(dstColor.v, target.v));
}


TEST_F(TestFixtureConversion, ColorConversionBabyBlueHunterLabRgb) {
	ColorSpace::HunterLab srcColor(85.308, -27.915, -13.675);
	ColorSpace::Rgb dstColor;
	ColorSpace::Rgb target(133, 237, 255);

	srcColor.To<ColorSpace::Rgb>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.r, target.r));
	ASSERT_TRUE(nearlyEqual(dstColor.g, target.g));
	ASSERT_TRUE(nearlyEqual(dstColor.b, target.b));
}


TEST_F(TestFixtureConversion, ColorConversionBabyBlueHunterLabXyz) {
	ColorSpace::HunterLab srcColor(85.308, -27.915, -13.675);
	ColorSpace::Xyz dstColor;
	ColorSpace::Xyz target(58.007, 72.775, 105.596);

	srcColor.To<ColorSpace::Xyz>(&dstColor);

	ASSERT_TRUE(nearlyEqual(dstColor.x, target.x));
	ASSERT_TRUE(nearlyEqual(dstColor.y, target.y));
	ASSERT_TRUE(nearlyEqual(dstColor.z, target.z));
}

