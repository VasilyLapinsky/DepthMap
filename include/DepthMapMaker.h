#pragma once

#include <opencv2/opencv.hpp>

// Computes depth from disparity map
class DepthMapMaker
{
private:
	cv::Mat Q;
public:
	/*
	@param Q - 4x4 perspective transformation matrix
	*/
	DepthMapMaker(cv::Mat& Q);
	/*
	@param filename - name of file from where will be read 
		4x4 perspective transformation matrix Q
	*/
	DepthMapMaker(std::string filename);

	/*
	Computes depth form disparity map in specific point(targetX, targetY)
	@param disparitymap - input disparity map
	@targetX - x coordinate of target point
	@targetY - y coordinate of target point
	*/
	float compute(cv::Mat& disparityMap, int targetX, int targetY);
};