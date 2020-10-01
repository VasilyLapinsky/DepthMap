#include "depthmapvideotesting.h"

void addTarget(cv::Mat& img, int x, int y)
{
	for (int i = x - 50; i < x + 50; i++) {
		img.at<uchar>(y, i) = 250;
	}
	for (int j = y - 50; j < y + 50; j++) {
		img.at<uchar>(j, x) = 250;
	}
}

void videoCameraDepthTest(int targetX, int targetY)
{
	VideoCapture cap(1);
	if (!cap.isOpened()) {
		cout << "Error opening video stream or file" << endl;
		return;
	}
	StereoImagePreprocessor preProcessor(COLOR_BGR2GRAY, 1, 1, INTER_LINEAR_EXACT);
	DepthImageMaker depthMaker("Qf25.txt", 32, 15);
	double distance;
	Mat image, left, right;

	for (;;) {
		cap >> image;
		preProcessor.process(image);
		preProcessor.getleft().copyTo(left);
		preProcessor.getright().copyTo(right);
		distance = depthMaker.compute(left, right, targetX, targetY);

		addTarget(left, targetX, targetY);
		putText(left, "Distance:   " + to_string(distance), Point(100, 100),
			FONT_HERSHEY_COMPLEX_SMALL, 0.8, Scalar(200, 200, 250), 1);
		imshow("result", left);

		if (waitKey(33) >= 0) break;
	}
}