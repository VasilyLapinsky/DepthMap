#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/ximgproc.hpp>

using namespace std;
using namespace cv;
using namespace ximgproc;


class DisparityMapMaker
{
private:
	Mat disparitymap;
	int numDisparities, blockSize;
	Ptr<StereoMatcher> left_matcher;
	Ptr<StereoMatcher> right_matcher;
	Ptr<DisparityWLSFilter> wls_filter;
public:
	/*
	@param numDisparities the disparity search range. For each pixel algorithm
		will find the best disparity from 0 (default minimum disparity) to numDisparities.
		The search range can then be shifted by changing the minimum disparity.
	@param blockSizehe linear size of the blocks compared by the algorithm.
		The size should be odd (as the block is centered at the current pixel).
	*/
	DisparityMapMaker(int numDisparities = 0, int blockSize = 21);
	/*
	Computer a disparite map for leand and right images. The result stored in the obj.
	*/
	void compute(const Mat& left, const Mat& right);
	/* Get stored disparity map*/
	Mat getDisparityMap();
};