#pragma once
#include "DisparityMapMaker.h"
#include "DepthMapMaker.h"

// Computes depth from an image
class DepthByQImageMaker
{
private:
	DisparityMapMaker dispMaker;
	DepthMapMaker depthMaker;
public:
	/*
	@param Q - 4x4 perspective transformation matrix
	@param numDisparities - number of disparities for disparity map computation
	@blockSize - block size for disparity map computation
	*/
	DepthByQImageMaker(cv::Mat& Q, int numDisparities = 0, int blockSize = 21);

	/*
	@param filename - name of file from where will be read 
		4x4 perspective transformation matrix Q
	@param numDisparities - number of disparities for disparity map computation
	@blockSize - block size for disparity map computation
	*/
	DepthByQImageMaker(std::string filename, int numDisparities = 0, int blockSize = 21);

	/*
	Computes depth in specific place(targetX, targetY) of an image
	@param image - input image
	@targetX - x coordinate of target point
	@targetY - y coordinate of target point
	*/
	double compute(cv::Mat& left, cv::Mat& right, int targetX, int targetY);
};