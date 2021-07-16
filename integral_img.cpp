#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

void integralImg(Mat &src, Mat &dst) {
	int rows = src.rows;
	int cols = src.cols;
	dst.at<int>(0, 0) = src.at<uchar>(0, 0);
	//cout << dst.at<int>(0, 0)<<"///" << endl;
	// for first row
	for (int col = 1; col < cols; ++col) {
		dst.at<int>(0, col) = dst.at<int>(0, col - 1) + src.at<uchar>(0, col);
		//cout << dst.at<int>(0,  col)<< endl;
	}
	//cout << dst.at<int>(0, 1) << endl;
	// for first column
	for (int row = 1; row < rows; ++row) {
		//cout << dst.at<int>(0, 1) << "---------------"<<endl;
		dst.at<int>(row, 0) = dst.at<int>(row - 1, 0) + src.at<uchar>(row, 0);
		//cout << dst.at<int>(row, 0) << "-----ddd----------" << endl;
	}
	//cout << "------" << dst.at<int>(0, 1) <<"-------jjj----" <<endl;
	// for others
	int a, b, c, d;
	

	for (int row = 1; row < rows; ++row) {
		//iprow = dst.ptr<int>(row);
		//iprow_1 = dst.ptr<int>(row - 1);
		//cprow = src.ptr<uchar>(row);
		for (int col = 1; col < cols; ++col) {

			a = dst.at<int>(row - 1, col - 1);
			b = dst.at<int>(row - 1, col);
			c = dst.at<int>(row, col - 1);
			d = src.at<uchar>(row, col);
			
			//a = iprow_1[col - 1];
			//b = iprow_1[col];
			//c = iprow[col - 1];
			//d = cprow[col];

			dst.at<int>(row, col) = b + c - a + d;
		}
	}

}

void integralImg(unsigned char *src, int *dst, int rows, int cols) {
	
	dst[0] = src[0];
	
	// for first row
	for (int col = 1; col < cols; ++col) {
		dst[col] = dst[col - 1] + src[col];
	}
	// for first column
	for (int row = 1; row < rows; ++row) {
		dst[row*cols] = dst[row*cols - row] + src[row*cols];
	}

	// for others
	int a, b, c, d;

	for (int row = 1; row < rows; ++row) {
		for (int col = 1; col < cols; ++col) {

			a = dst[(row - 1)*cols + col - 1];
			b = dst[(row - 1)*cols + col];
			c = dst[row*cols + col - 1];
			d = src[row*cols + col];

			dst[row*cols + col] = b + c - a + d;
		}
	}

}
