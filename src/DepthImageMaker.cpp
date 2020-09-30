#include "DepthImageMaker.h"

DepthImageMaker::DepthImageMaker(cv::Mat& Q, int numDisparities = 0, int blockSize = 21):
	dispMaker{numDisparities, blockSize}, depthMaker{Q}
{ }

DepthImageMaker::DepthImageMaker(std::string filename, int numDisparities = 0, int blockSize = 21):
	dispMaker{ numDisparities, blockSize }, depthMaker{ filename }
{}

double DepthImageMaker::compute(Mat& image, int targetX, int targetY)
{
	dispMaker.compute(image);
	return depthMaker.compute(dispMaker.getDisparityMap(), targetX, targetY);
}