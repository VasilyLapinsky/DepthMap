#include "StereoImagePreprocessor.h"
#include "DepthByQImageMaker.h"
#include "DepthByBfImageMaker.h"
#include "DisparityMapWriter.h"

/* adds target to an image */
void addTarget(cv::Mat& img, int x, int y);

// test depth map by Q with stero camera
void videoCameraDepthTest(int targetX, int targetY);

// test depth map by Bf with stereo camera
void videoCameraDepthBfTest();