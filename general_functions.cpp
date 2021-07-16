#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

void uchar2mat(unsigned char *src, Mat &dst) {
	int rows = dst.rows;
	int cols = dst.cols;
	for (int row = 0; row < rows; ++row) {
		for (int col = 0; col < cols; ++col) {
			dst.at<uchar>(row, col) = src[row*cols + col];
		}
	}
}

void mat2uchar(Mat &src, unsigned char *dst) {
	int rows = src.rows;
	int cols = src.cols;
	for (int row = 0; row < rows; ++row) {
		for (int col = 0; col < cols; ++col) {
			dst[row*cols + col] = src.at<uchar>(row, col);
		}
	}
}