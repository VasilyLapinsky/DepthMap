#pragma once

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class StereoImagePreprocessor
{
private:
	Mat left, right;
	double fx, fy;
	int cvtcode, interpolation, dstCn;
public:
	/*
	@param cvtcode color space conversion code (see #ColorConversionCodes).
	@param fx scale factor along the horizontal axis; when it equals 0, it is computed as
			\f[\texttt{(double)dsize.width/src.cols}\f]
	@param fy scale factor along the vertical axis; when it equals 0, it is computed as
			\f[\texttt{(double)dsize.height/src.rows}\f]
	@param interpolation interpolation method, see #InterpolationFlags OpenCV
	@param dstCn number of channels in the destination image; if the parameter is 0, the number of the
			channels is derived automatically from input image and code.
	*/
	StereoImagePreprocessor(int cvtcode, double fx = 0, double fy = 0,
		int interpolation = INTER_LINEAR, int dstCn = 0);
	/*
	Preprocess an image for DisparityMapMaker
	Result will be stored in the object
	@param image input image which will be preprocessed
	*/
	void process(const Mat& image);
	/* Gives left image after proccessing*/
	Mat getleft();
	/* Gives right image after proccessing*/
	Mat getright();
};
