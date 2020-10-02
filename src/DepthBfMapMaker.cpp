#include "DepthBfMapMaker.h"

DepthBfMapMaker::DepthBfMapMaker(float _B, float _f):
	B{_B}, f{_f}
{ }

float DepthBfMapMaker::compute(float d)
{
	return (B * f) / d;
}

cv::Mat DepthBfMapMaker::compute(cv::Mat & disparityMap)
{
	return (B * f) / disparityMap;
}