#pragma once
#include "DisparityMapMaker.h"
#include "DepthBfMapMaker.h"

/*
Computes depth in secific point or for all image usig formula:
	depth = (B*f)/d; where B - baseline, f - focal length, d - disparity value
*/
class DepthByBfImageMaker
{
private:
	DisparityMapMaker dispMaker;
	DepthBfMapMaker depthMaker;
public:
	/*
	@param B - baseline, distance between cameras
	@param f - focal length
	@param numDisparities - number of disparities for disparity map computations(default 0)
	@param blockSize - block size for disparity map computations(default 21)
	*/
	DepthByBfImageMaker(float B, float f, int numDisparities = 0, int blockSize = 21);

	/*
	Returns depth in specific point(targetX, targetY)
	@param left - left part of stereo image
	@param right - right part of stereo image
	@paran targetX - x coordiante of target point(x,y)
	@paran targetY - y coordiante of target point(x,y)
	*/
	float compute(cv::Mat& left, cv::Mat& right, int targetX, int targetY);

	/*
	Returns Mat of depths
	@param left - left part of stereo image
	@param right - right part of stereo image
	*/
	cv::Mat compute(cv::Mat& left, cv::Mat& right);
};