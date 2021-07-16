#include <iostream>
#include <chrono>
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "general_functions.h"
#include "adaptiveBinarization.h"
using namespace std;
using namespace cv;

// Parameters
#define BinarizationW 3
#define BinarizationH 3

const string img_folder = "/Users/chiang-en/Documents/AdaptiveBinarization/";
int main()
{
	Mat src = imread(img_folder + "00.png", 0);
	Mat dst = src.clone();
	
	Rect roi;
	Rect test = { 100,100, 50, 50 };
	roi.x = (BinarizationW - 1)/2 + 1;
	roi.y = (BinarizationH - 1) / 2 + 1;
	roi.width = dst.cols - (BinarizationW - 1) - 1;
	roi.height = dst.rows - (BinarizationH - 1) - 1;

	auto t1 = std::chrono::high_resolution_clock::now();

	unsigned char *usrc = new uchar[src.rows*src.cols];
	uchar *udst = new uchar[src.rows*src.cols];
	mat2uchar(src, usrc);
	threshold(src, dst, 0,255, THRESH_BINARY|THRESH_OTSU);
	adativeBinarization(usrc, udst, BinarizationW, BinarizationH, src.rows, src.cols);
	uchar2mat(udst, dst);
	delete [] usrc;
	delete[] udst;

	auto t2 = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();

	std::cout << "execution time = "<<duration << "ms."<<endl;


	//imwrite("0test.png", dst(roi).clone());
	
	imshow("roi", dst(roi));
	imshow("src", src);
	waitKey(0);
	
	return 0;
}