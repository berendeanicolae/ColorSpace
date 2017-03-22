import sys

if len(sys.argv)!=2:
    print("Usage: {0} <data_file>".format(sys.argv[0]))
    raise SystemExit

template = '''\
TEST_F(TestFixtureComparison, CIE00_Test{index}) {{
	ColorSpace::Lab a({srcVal});
	ColorSpace::Lab b({dstVal});

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie2000Comparison::Compare(&a, &b), {target}));
}}
'''

fileHandle = open(sys.argv[1], 'rb')
lines = fileHandle.readlines()
fileHandle.close()
for i in range(len(lines)):
    test = lines[i].strip().split(",")
    srcVal = ", ".join(test[0:3])
    dstVal = ", ".join(test[3:6])
    target = test[6]
    print(template.format(index=i+1, srcVal=srcVal, dstVal=dstVal, target=target))

