#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;

int main(int argc, char const *argv[])
{
#if 0
	// if(argc != 2)
	// {
	// 	printf("usage: DisplayImage.out <Image_Path>\n");
	// 	return -1;
	// }

	// cv::Mat image;
	// image = cv::imread( argv[1], 1);

	// if (!image.data)
	// {			
	// 	printf("No image data \n");
	// }

	// //cv::namedWindow("RGB_img", cv::WINDOW_AUTOSIZE );
	// cv::imshow("RGB_img",image);

	// cv::Mat gray;
	// cv::cvtColor(image, gray, CV_BGR2GRAY);

	// //cv::namedWindow("gray_img",cv::WINDOW_AUTOSIZE );
	// cv::imshow("gray_img",gray);

	// //cv::imwrite("lena_gray.jpg", gray);
	// cv::Mat blur;
	// cv::GaussianBlur(gray, blur, cv::Size(7,7), 1.5, 1.5);
	// cv::imshow("blured_img",blur);

	// cv::Mat canny;
	// cv::Canny(blur, canny, 0, 30, 3);
	// cv::imshow("canny", canny);
	// int a =0;

	 // double alpha = 0.5; double beta; double input;

	 // Mat src1, src2, dst;

	 // /// Ask the user enter alpha
	 // std::cout<<" Simple Linear Blender "<<std::endl;
	 // std::cout<<"-----------------------"<<std::endl;
	 // std::cout<<"* Enter alpha [0-1]: ";
	 // std::cin>>input;

	 // /// We use the alpha provided by the user if it is between 0 and 1
	 // if( input >= 0.0 && input <= 1.0 )
	 //   { alpha = input; }

	 // /// Read image ( same size, same type )
	 // src1 = imread("linuxlogo.jpg");
	 // src2 = imread("windowslogo.jpg");

	 // if( !src1.data ) { printf("Error loading src1 \n"); return -1; }
	 // if( !src2.data ) { printf("Error loading src2 \n"); return -1; }

	 // /// Create Windows
	 // namedWindow("Linear Blend", 1);

	 // beta = ( 1.0 - alpha );
	 // addWeighted( src1, alpha, src2, beta, 0.0, dst);

	 // imshow( "Linear Blend", dst );

	// Mat img = imread("lena.jpg");
	// Mat output;
	// img.convertTo(output, -1, 2.2, 50);
	// imshow("output", output);
	/*----------------practice the histogram---------------*/
	Mat src, dst;
	src = imread("lena.jpg");
	std::vector<Mat> bgr_planes;
	split(src, bgr_planes);

	int histSize = 256;

	float range[] = {0, 256};
	const float* histRange = {range};

	bool uniform = true; bool accumulate = false;

	Mat b_hist, g_hist, r_hist;

	calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);

	// Draw the histogram for B, G, R
	int hist_w = 512; int hist_h = 400;
	int bin_w = cvRound((double) hist_w/histSize);

	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0,0,0));

	// normalize the result
	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

	// Draw for each channel
	for(int i = 1; i < histSize; i++){
		line(histImage, Point(bin_w*(i-1),hist_h - cvRound(b_hist.at<float>(i - 1))),
			  			Point(bin_w*(i),hist_h - cvRound(b_hist.at<float>(i))),
			  			Scalar(255,255,0), 2, 8, 0);
        line( histImage, Point( bin_w*(i-1), hist_h - cvRound(g_hist.at<float>(i-1)) ) ,
                        Point( bin_w*(i), hist_h - cvRound(g_hist.at<float>(i)) ),
                        Scalar( 0, 255, 0), 2, 8, 0  );
        line( histImage, Point( bin_w*(i-1), hist_h - cvRound(r_hist.at<float>(i-1)) ) ,
                        Point( bin_w*(i), hist_h - cvRound(r_hist.at<float>(i)) ),
                        Scalar( 0, 0, 255), 2, 8, 0  );
	}

	// Display
	namedWindow("calcHist Demo", CV_WINDOW_AUTOSIZE);
	imshow("calcHist Demo", histImage);
#endif

#if 0

	cv::Mat a(1200,1200,CV_32F);
	imshow("testing",a);
	typedef cv::Point_<int> Point;
	Point a(2,3), b(3,4);
	Point c = a + b;
	std::cout<< c.x <<", "<<c.y<<std::endl;
	cv::Mat image(200,200, CV_8UC3, cv::Scalar(0));
	cv::RotatedRect rRect = cv::RotatedRect(cv::Point2f(100,100), cv::Size2f(100,50), 45);

	cv::Point2f vertices[4];
	rRect.points(vertices);
	for(int i = 0; i < 4; ++i){
		cv::line(image, vertices[i], vertices[(i+1)%4], cv::Scalar(0,255,0));
	}
	cv::Rect brect = rRect.boundingRect();
	cv::rectangle(image, brect, cv::Scalar(255,0,0));

	cv::imshow("rectangles", image);
#endif
	// Mat src, dst;
	// src = imread("lena.jpg");
	// // blur(src,dst,Size(10,10));
	// // GaussianBlur(src,dst,Size(25,25),0,0);
	// // medianBlur(src,dst,15);
	// bilateralFilter(src,dst,5,200,2000);
	// imshow("output",dst);

	cv::waitKey(0);
	return 0;
}