#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <opencv2/opencv.hpp>
#include"opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

int HW01_TestFunction();
int HW02_ReadAndShowData(int numberOfImgs);

vector <cv::Mat>Imgs;
vector <cv::Mat>ImgGray;
vector <cv::Mat>ImgBinarys;

int main() {
	HW01_TestFunction();
	waitKey(0);
	destroyAllWindows();
	HW02_ReadAndShowData(8);

	waitKey(0);
	return 0;
}


int HW01_TestFunction() {
	Mat img = imread("C:\\Users\\GINA\\Desktop\\opencv-1and2-chihyili\\testImage\\lena.jpg");
	Mat img2 = imread("C:\\Users\\GINA\\Desktop\\opencv-1and2-chihyili\\testImage\\lena.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	Mat img3;
	threshold(img2, img3, 100, 255, THRESH_BINARY);
	imshow("origin", img);
	imshow("gray", img2);
	imshow("threshold", img3);
	waitKey(0);
	return 0;
}

int HW02_ReadAndShowData(int numberOfImgs) {
	
	vector<cv::String>address;

	address.push_back("C:/Users/GINA/Desktop/opencv-1and2-chihyili/testImage/capture/1.jpg");
	address.push_back("C:/Users/GINA/Desktop/opencv-1and2-chihyili/testImage/capture/2.jpg");
	address.push_back("C:/Users/GINA/Desktop/opencv-1and2-chihyili/testImage/capture/3.jpg");
	address.push_back("C:/Users/GINA/Desktop/opencv-1and2-chihyili/testImage/capture/4.jpg");
	address.push_back("C:/Users/GINA/Desktop/opencv-1and2-chihyili/testImage/capture/5.jpg");
	address.push_back("C:/Users/GINA/Desktop/opencv-1and2-chihyili/testImage/capture/6.jpg");
	address.push_back("C:/Users/GINA/Desktop/opencv-1and2-chihyili/testImage/capture/7.jpg");
	address.push_back("C:/Users/GINA/Desktop/opencv-1and2-chihyili/testImage/capture/8.jpg");
	for (int i = 0; i < numberOfImgs; i++) {
		Mat img = imread(address[i]);
		Imgs.push_back(img);

		Mat imgGray;
		cvtColor(img,imgGray, CV_BGR2GRAY);
		ImgGray.push_back(imgGray);

		Mat imgBin;
		threshold(imgGray, imgBin, 100.0, 255.0, THRESH_BINARY);
		ImgBinarys.push_back(imgBin);

	}
	for (int i = 0; i < numberOfImgs; i++) {
		imshow("img", Imgs[i]);
		imshow("imgGray", ImgGray[i]);
		imshow("imgBin", ImgBinarys[i]);

		moveWindow("img", 50, 50);
		moveWindow("imgGray", 350, 50);
		moveWindow("imgBin", 650, 50);

		waitKey(0);
		destroyAllWindows();
	}
	return 0;
}





