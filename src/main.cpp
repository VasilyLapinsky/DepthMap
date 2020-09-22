#include "disparitymap.h"

void videoCameraTest()
{
	VideoCapture cap(1);
	if (!cap.isOpened()) {
		cout << "Error opening video stream or file" << endl;
		return;
	}
	StereoImagePreprocessor preProcessor(COLOR_BGR2GRAY, 0.5, 0.5, INTER_LINEAR_EXACT);
	DisparityMapMaker maker(32, 15);
	DisparityMapWriter writer("Disparity map", CV_8UC1, COLORMAP_AUTUMN);

	Mat image;
	for (;;) {
		cap >> image;
		preProcessor.process(image);
		maker.compute(preProcessor.getleft(), preProcessor.getright());
		writer.show(maker.getDisparityMap());
		if (waitKey(33) >= 0) break;
	}
}

int main()
{
	videoCameraTest();
	return 0;
}