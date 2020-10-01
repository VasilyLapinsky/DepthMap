#include "DepthMapMaker.h"

DepthMapMaker::DepthMapMaker(cv::Mat& _Q):
	Q{_Q}
{ }

void readQ(std::string filename, cv::Mat& Q)
{
	Q = Q.zeros(4, 4, CV_32F);
	std::ifstream in(filename);
	if (!in.is_open()) {
		throw std::invalid_argument("Can't open an file: " + filename + " !");
	}
	char ch;
	in >> ch; // read [
	for (int i = 0; i < 4; ++i)
	{
		double temp;
		for (int j = 0; j < 4; ++j)
		{
			in >> temp >> ch;// read number and ','
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
	cv::Mat vec(4, 1, CV_32F);
	// Initialize vector: [x, y, d, 1]
	vec.at<float>(0) = float(targetX);
	vec.at<float>(1) = float(targetY);
	vec.at<float>(2) = disparityMap.at<short>(targetX, targetY) / 16.0f;
	vec.at<float>(3) = 1;
	// compute Q*vec result is vector [X, Y, Z, W]
	cv::Mat result = Q * vec;
	// return Z/W 
	return result.at<float>(2) / result.at<float>(3);
}