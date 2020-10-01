#include "DepthImageMaker.h"

DepthImageMaker::DepthImageMaker(cv::Mat& Q, int numDisparities, int blockSize):
	dispMaker{numDisparities, blockSize}, depthMaker{Q}
{ }

DepthImageMaker::DepthImageMaker(std::string filename, int numDisparities, int blockSize):
	dispMaker{ numDisparities, blockSize }, depthMaker{ filename }
{}

double DepthImageMaker::compute(cv::Mat& left, cv::Mat& right, int targetX, int targetY)
{
	dispMaker.compute(left, right);
	return depthMaker.compute(dispMaker.getDisparityMap(), targetX, targetY);
}