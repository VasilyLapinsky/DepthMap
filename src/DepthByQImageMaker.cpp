#include "DepthByQImageMaker.h"

DepthByQImageMaker::DepthByQImageMaker(cv::Mat& Q, int numDisparities, int blockSize):
	dispMaker{numDisparities, blockSize}, depthMaker{Q}
{ }

DepthByQImageMaker::DepthByQImageMaker(std::string filename, int numDisparities, int blockSize):
	dispMaker{ numDisparities, blockSize }, depthMaker{ filename }
{}

double DepthByQImageMaker::compute(cv::Mat& left, cv::Mat& right, int targetX, int targetY)
{
	dispMaker.compute(left, right);
	return depthMaker.compute(dispMaker.getDisparityMap(), targetX, targetY);
}