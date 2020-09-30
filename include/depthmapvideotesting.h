#include "StereoImagePreprocessor.h"
#include "DepthImageMaker.h"

/* adds target to an image */
void addTarget(cv::Mat& img, int x, int y);

// test depth map with stero camera
void videoCameraDepthTest(int targetX, int targetY);