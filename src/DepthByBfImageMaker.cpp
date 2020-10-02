#include "DepthByBfImageMaker.h"

DepthByBfImageMaker::DepthByBfImageMaker(float B, float f, int numDisparities, int blockSize):
	dispMaker{numDisparities, blockSize}, depthMaker{B, f}
{ }

float DepthByBfImageMaker::compute(cv::Mat& left, cv::Mat& right, int targetX, int targetY)
{
	dispMaker.compute(left, right);
	return depthMaker.compute(dispMaker.getDisparityMap().at<short>(targetX, targetY)/16.0f);
}
cv::Mat DepthByBfImageMaker::compute(cv::Mat& left, cv::Mat& right)
{
	dispMaker.compute(left, right);
	cv::Mat temp = dispMaker.getDisparityMap() / 16.0f;
	return depthMaker.compute(temp);
}