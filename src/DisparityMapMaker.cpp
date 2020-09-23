#include "DisparityMapMaker.h"

DisparityMapMaker::DisparityMapMaker(int numDisp, int bSize) :
	numDisparities{ numDisp }, blockSize{ bSize }
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