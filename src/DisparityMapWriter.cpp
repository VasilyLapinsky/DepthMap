#include "DisparityMapWriter.h"

DisparityMapWriter::DisparityMapWriter(const String& winname, int rtp, int cmap) :
	wname{ winname }, rtype{ rtp }, colormap{ cmap }
{ }

void DisparityMapWriter::show(const Mat& disparitymap)
{
	// Convert matrix values type
	Mat adjMap;
	disparitymap.convertTo(adjMap, rtype);
	Mat falseColorsMap;
	// Changing color map
	applyColorMap(adjMap, falseColorsMap, colormap);
	imshow(wname, falseColorsMap);
}