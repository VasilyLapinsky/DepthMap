#include "StereoImagePreProcessor.h"

StereoImagePreprocessor::StereoImagePreprocessor(int _cvtcode, double _fx, double _fy, int _interpolation, int _dstCn) :
	cvtcode{ _cvtcode }, fx{ _fx }, fy{ _fy }, interpolation{ _interpolation }, dstCn{ _dstCn }
{ }

void StereoImagePreprocessor::process(const Mat& image)
{
	// Cut stereo image for two images
	image(Rect{ 0, 0, image.cols / 2, image.rows }).copyTo(left);
	image(Rect{ image.cols / 2, 0, image.cols / 2, image.rows }).copyTo(right);
	// Resize images
	resize(left, left, Size(), fx, fy, interpolation);
	resize(right, right, Size(), fx, fy, interpolation);
	// Change image color set
	cvtColor(left, left, COLOR_BGR2GRAY);
	cvtColor(right, right, COLOR_BGR2GRAY);
}

Mat StereoImagePreprocessor::getleft()
{
	return left;
}

Mat StereoImagePreprocessor::getright()
{
	return right;
}