#include<stdio.h> 
#include<iostream> 
#include<opencv2/opencv.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
using namespace cv;
using namespace std; 

void matchingMethod(int, void*);

// declare some global variables, such as the image, template, and 
// result matrices, as well as the match method and the window name
int match_method = TM_CCORR_NORMED;
Mat img, template_img, result_img;
const char* image_window = "Result Image";

int main()
{
	// load the source image, template
	img = imread("sorce_image.jpg", IMREAD_COLOR);
	template_img = imread("template_image.jpg", IMREAD_COLOR);

	// in case the resolution of the input images is different, we will 
	// resize the template image. otherwise, this command is not required.
	resize(template_img, template_img, Size(template_img.cols * 0.75, template_img.rows * 0.75), 0, 0, INTER_LINEAR);
	namedWindow(image_window, WINDOW_AUTOSIZE);
	matchingMethod(0, 0);
	waitKey(0);
	return EXIT_SUCCESS;
}

void matchingMethod(int, void*)
{
	Point minLoc, maxLoc;
	double minVal, maxVal;
	int result_cols, result_rows;
	
	result_cols = img.cols - template_img.cols + 1;
	result_rows = img.rows - template_img.rows + 1;
	result_img.create(result_rows, result_cols, CV_32FC1);

	// perform the template matching operation and normalize the results
	matchTemplate(img, template_img, result_img, match_method);
	normalize(result_img, result_img, 0, 1, NORM_MINMAX, -1, Mat());

	// localize the minimum and maximum values in the result matrix result_img by using minMaxLoc()
	minMaxLoc(result_img, &minVal, &maxVal, &minLoc, &maxLoc, Mat());

	// draw a rectangle around the highest possible matching area
	rectangle(img, maxLoc, Point(maxLoc.x + template_img.cols, maxLoc.y + template_img.rows), Scalar::all(0), 2, 8, 0);

	// save and show the result image 
	imwrite("result_image.jpg", img);
	imshow(image_window, img);
}