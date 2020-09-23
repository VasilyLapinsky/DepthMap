#pragma once

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class DisparityMapWriter
{
private:
	String wname;
	int rtype, colormap;
public:
	/*
	@param winname Name of the window
	@param rtype desired output matrix type or, rather, the depth since the number of channels are the
		same as the input has; if rtype is negative, the output matrix will have the same type as the input.
	@param colormap The colormap to apply, see #ColormapTypes
	*/
	DisparityMapWriter(const String& winname, int rtype, int colormap);
	/* Show disparity map in the window with custom preparations*/
	void show(const Mat& disparitymap);
};