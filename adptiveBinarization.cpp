#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <chrono>

#include "integral_img.h"
using namespace std;
using namespace cv;

#define bThreshold 0.95


void adativeBinarization(Mat &src, Mat &dst, int w, int h) {
	int rows = src.rows;
	int cols = src.cols;
	int count = w * h;
	// compute the integral image of src
	Mat isrc(rows, cols, CV_32S);
	
	integralImg(src, isrc);
	//
	//return;
	int hw = (w - 1) / 2;
	int hh = (h - 1) / 2;
	int sum = 0;
	//cout << "----" << hh + 1 << endl;
	//cout << "----" << hw + 1 << endl;
	for (int row = hh + 1; row < rows - hh; row++) {//start form hh + 1 becuse of using the integral image
		for (int col = hw + 1; col < cols - hw; col++) {
			int x1 = col - hw;
			int y1 = row - hh;
			int x2 = col + hw;
			int y2 = row + hh;
			sum = isrc.at<int>(y2, x2) -
				isrc.at<int>(y1 - 1, x2) -
				isrc.at<int>(y2, x1 - 1) +
				isrc.at<int>(y1 - 1,x1 - 1);

			//cout << sum << endl;

			if (src.at<uchar>(row, col)*count > sum*bThreshold) {
				dst.at<uchar>(row, col) = 0;
			}
			else {
				dst.at<uchar>(row, col) = 255;
			}
			
			
		}
	}



}

void adativeBinarization(unsigned char *src, unsigned char *dst, int w, int h, int rows, int cols) {
	int count = w * h;
	// compute the integral image of src
	int *isrc = new int[rows*cols];

	// auto t1 = std::chrono::high_resolution_clock::now();
	integralImg(src, isrc, rows, cols);
	
	// auto t2 = std::chrono::high_resolution_clock::now();

	// auto duration = std::chrono::duration_cast<std::q        ㄆ  chrono::milliseconds>(t2 - t1).count();

	// std::cout << "ii-execution time = "<<duration << "ms."<<endl;

	int hw = (w - 1) / 2;
	int hh = (h - 1) / 2;
	int sum = 0;
	//cout << "----" << hh + 1 << endl;
	//cout << "----" << hw + 1 << endl;
	for (int row = hh + 1; row < rows - hh; row++) {//start form hh + 1 becuse of using the integral image
		for (int col = hw + 1; col < cols - hw; col++) {
			int x1 = col - hw;
			int y1 = row - hh;
			int x2 = col + hw;
			int y2 = row + hh;
			sum = isrc[y2*cols + x2] -
				isrc[(y1 - 1)*cols + x2] -
				isrc[y2*cols + x1 - 1] +
				isrc[(y1 - 1)*cols + x1 - 1];

			//cout << sum << endl;

			if (src[row*cols + col] * count > sum*bThreshold) {
				dst[row*cols + col] = 0;
			}
			else {
				dst[row*cols + col] = 255;
			}
		}
	}
	delete []isrc;

}



