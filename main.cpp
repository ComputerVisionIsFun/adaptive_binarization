#include <iostream>
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "adaptiveBinarization.h"
using namespace std;
using namespace cv;

int main()
{
	
	Mat img = imread("test.png", 0);
	Mat edge = img.clone();
	edge.setTo(0);
	adativeBinarization(img, edge, 3, 3);
	
	// imshow("edge", edge);
	imwrite("test_result.png", edge);
	// waitKey(0);
	
	return 0;
}