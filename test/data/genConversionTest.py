import sys
import xml.etree.ElementTree as ET

if len(sys.argv)!=2:
    print("Usage: {0} <data_file>".format(sys.argv[0]))
    raise SystemExit


root = ET.parse(sys.argv[1]).getroot()
template = \
'''
TEST_F(TestFixtureConversion, ColorConversion{color}{src}{dst}) {{
	ColorSpace::{src} srcColor({srcVal});
	ColorSpace::{dst} dstColor;
	ColorSpace::{dst} target({dstVal});

	srcColor.To<ColorSpace::{dst}>(&dstColor);

{cond}
}}
'''


def getColor(color):
    if color=='Yxy': return ["y1", "x", "y2"]

    capitals = [i for i in range(len(color)) if color[i].isupper()]
    lastCapital = capitals[-1]
    dstColor = color[lastCapital:].lower()

    return dstColor


def getAssert(color):
    dstColor = getColor(color)
    asserts = []
    for e in dstColor:
        asserts.append("\tASSERT_TRUE(nearlyEqual(dstColor.{0}, target.{0}));".format(e))

    return "\n".join(asserts)


def getSrcVal(color, dict):
    values = []
    for c in getColor(color):
        values.append(dict[c.upper()])

    return ", ".join(values)

for model in root:
    colorModel = model.tag
    for test in model:
        testName = test.attrib["Name"]
        for color in test:
            srcVal = getSrcVal(colorModel, test.attrib)
            dstVal = getSrcVal(color.tag, color.attrib)
            print(template.format(color=testName, src=colorModel, srcVal=srcVal, dst=color.tag, dstVal=dstVal, cond=getAssert(color.tag)))

