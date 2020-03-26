#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>


int main(int argc, char** argv) {
    cv::Mat image1, image2;

    cv::Mat canvas(800, 800, CV_8UC(3), cv::Scalar(255, 255, 255));
    canvas.reshape(800, 800);

    cv::line(canvas, cv::Point(5, 5), cv::Point(100, 400), cv::Scalar(0), 2);

    cv::namedWindow("Canvas", cv::WINDOW_NORMAL);
    cv::resizeWindow("Canvas", 800, 800);
    cv::imshow("Canvas", canvas);
    cv::waitKey(0);
    return 0;
}