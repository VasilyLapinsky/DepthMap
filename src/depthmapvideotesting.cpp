#include "depthmapvideotesting.h"

void addTarget(cv::Mat& img, int x, int y)
{
	for (int i = x - 50; i < x + 50; i++) {
		img.at<Vec3b>(y, i)[0] = 255;
		img.at<Vec3b>(y, i)[1] = 255;
		img.at<Vec3b>(y, i)[2] = 255;
	}
	for (int j = y - 50; j < y + 50; j++) {
		img.at<Vec3b>(j, x)[0] = 255;
		img.at<Vec3b>(j, x)[1] = 255;
		img.at<Vec3b>(j, x)[2] = 255;
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
	Mat image, left;

	for (;;) {
		cap >> image;
		preProcessor.process(image);
		preProcessor.getleft().copyTo(left);
		distance = depthMaker.compute(left, targetX, targetY);

		addTarget(left, targetX, targetY);
		putText(left, "Distance:   " + to_string(distance), Point(100, 100),
			FONT_HERSHEY_COMPLEX_SMALL, 0.8, Scalar(200, 200, 250), 1);
		imshow("result", left);

		if (waitKey(33) >= 0) break;
	}
}