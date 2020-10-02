#pragma once

#include <opencv2/opencv.hpp>


/* Comutes depth using formula: depth = (B*f)/d */
class DepthBfMapMaker
{
private:
	float B, f;
public:
	/*
	@param B - baseline, distance between cameras
	@param f - focal length
	*/
	DepthBfMapMaker(float B, float f);

	// @param d- disparity value in the point
	float compute(float d);
	/*
	Returns depth map
	@param disparityMap - disparity map
	*/
	cv::Mat compute(cv::Mat& disparityMap);
};