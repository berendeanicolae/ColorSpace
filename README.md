# ColorSpace
[![Build status](https://ci.appveyor.com/api/projects/status/9imauslkfcma7yps/branch/master?svg=true)](https://ci.appveyor.com/project/berendeanicolae/colorspace/branch/master)

C++ library for converting between color spaces and comparing colors.

## Color Conversion
You can convert between any supported color spaces using the ```To``` template method:
```c++
ColorSpace::Lab lab(100, 0, 0);
ColorSpace::Cmy cmy;
lab.To<ColorSpace::Cmy>(&cmy);
```
## Color Comparison
You can compare colors by using the ```Compare``` method of each comparison class:
```c++
ColorSpace::Lab a(100, 0, 0);
ColorSpace::RGb b(255, 255, 255);
ColorSpace::Cie2000Comparison::Compare(&a, &b);
```

## Currently Supported Color Spaces
* CMY
* CMYK
* HSL
* HSB
* HSV
* CIE L*AB
* Hunter LAB
* LCH
* LUV
* RGB
* XYZ
* YXY

## Currently Supported Comparisons
* Euclidean
* CIE1976
* CIE94
* CIE2000
* CMC

## License
ColorSpace is licenced under the MIT License, see LICENSE for more information.
