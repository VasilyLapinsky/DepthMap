#include "DepthMapMaker.h"

DepthMapMaker::DepthMapMaker(cv::Mat& _Q):
	Q{_Q}
{ }

void readQ(string filename, Mat& Q)
{
	Q = Q.zeros(4, 4, CV_32F);
	ifstream in(filename);
	char ch;
	std::in >> ch; // read [
	for (int i = 0; i < 4; ++i)
	{
		double temp;
		for (int j = 0; j < 4; ++j)
		{
			std::in >> temp >> ch;// read number and ','
			Q.at<float>(i, j) = temp;
		}
	}
}

DepthMapMaker::DepthMapMaker(std::string filename)
{
	readQ(filename, Q);
}

float DepthMapMaker::compute(cv::Mat& disparityMap, int targetX, int targetY)
{
	// Making temp vector
	Mat vec(4, 1, CV_32F);
	// Initialize vector: [x, y, d, 1]
	vec.at<float>(0) = float(targetX);
	vec.at<float>(1) = float(targetY);
	vec.at<float>(2) = disparitymap.at<short>(targetX, targetY) / 16.0f;
	vec.at<float>(3) = 1;
	// compute Q*vec result is vector [X, Y, Z, W]
	vec = Q * vec;
	// return Z/W 
	return vec.at<float>(2) / vec.at<float>(3);
}