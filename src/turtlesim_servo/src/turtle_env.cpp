#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(){
	Mat turtle = imread("/home/shengjian/bulldog_ws/src/turtlesim_servo/images/diamondback.png");
	Point2f center = Point2f(turtle.rows/2, turtle.cols/2);
	double angle = 30.0;
	Mat dst;
	Size turtle_size = turtle.size();

	Mat background(256, 256, CV_8UC3, Scalar(0,0,0));

	Mat M = getRotationMatrix2D(center, angle, 1.0);
	warpAffine(turtle, dst, M, turtle_size, INTER_LINEAR, BORDER_CONSTANT, Scalar(0,0,0));

	int offset_x = 20;
	int offset_y = 20;
	dst.copyTo(background(Rect(offset_x, offset_y, dst.cols, dst.rows)));
	turtle.copyTo(background(Rect(offset_x+dst.cols, offset_y+dst.rows, turtle.cols, turtle.rows)));
	printf("%d, %d, %d, %d", dst.cols, dst.rows, turtle.cols, turtle.rows);
	imshow("rotate", background);

	waitKey(0);

	return 0;
}