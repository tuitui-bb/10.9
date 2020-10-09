#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
//CV_EXPORTS int creatTrackbar(const String& trackbarname, const String& winname,
//	int* vaule, int count,
//	TrackbarCallback onChange = 0,
//	void* userdata = 0);
String window_name = "binaryMat";
void threshod_Mat(int th, void* data)
{
	Mat src = *(Mat*)(data);

	Mat dst;
	threshold(src, dst, th, 255, 0);
	imshow(window_name, dst);

}

int main()
{
	Mat srcMat;
	Mat gryMat;
	
	int lowTh = 30;
	int maxTh = 255;

	srcMat = imread("D:\\asaki.jpg");
	if (!srcMat.data)
	{
		std::cout << "Í¼ÏñÔØÈëÊ§°Ü£¡" << std::endl;
		return 0;
	}
	cvtColor(srcMat, gryMat,CV_BGR2GRAY);
	imshow(window_name, gryMat);
	createTrackbar("threshold",window_name,&lowTh,maxTh,threshod_Mat,&gryMat);
	waitKey(0);

	return 0;

}


