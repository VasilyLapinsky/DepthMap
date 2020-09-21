#include "disparitymap.h"
 

StereoImagePreprocessor::StereoImagePreprocessor(int _cvtcode, double _fx = 0, double _fy = 0,
	int _interpolation = INTER_LINEAR, int _dstCn = 0):
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

DisparityMapMaker::DisparityMapMaker(int numDisp = 0, int bSize = 21):
	numDisparities{numDisp}, blockSize{bSize}
{
	// Creating matchers and filter
	left_matcher = StereoBM::create(numDisparities, blockSize);
	wls_filter = createDisparityWLSFilter(left_matcher);
	right_matcher = createRightMatcher(left_matcher);
}

void DisparityMapMaker::compute(const Mat& left, const Mat& right)
{
	// Computer disparity map for left and right images
	Mat left_disparity, right_disparity;
	left_matcher->compute(left, right, left_disparity);
	right_matcher->compute(right, left, right_disparity);

	// Apply wls filter
	wls_filter->filter(left_disparity, left, disparitymap, right_disparity);
}

Mat DisparityMapMaker::getDisparityMap()
{
	return disparitymap;
}

DisparityMapWriter::DisparityMapWriter(const String& winname, int rtp, int cmap):
	wname{winname}, rtype{rtp}, colormap{cmap}
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

