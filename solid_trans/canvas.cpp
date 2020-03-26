#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include "Transformations.h"

double radians(double degrees) {
    return degrees / 180 * M_PI;
}


void setup_window(cv::Mat& canvas) {
    canvas = cv::Mat(800, 800, CV_8UC(3), cv::Scalar(255, 255, 255));
    canvas.reshape(800, 800);
    cv::namedWindow("Canvas", cv::WINDOW_NORMAL);
    cv::resizeWindow("Canvas", 800, 800);
}


void getImagePoints(Transformations Tr, Eigen::Matrix4Xd vertices, cv::Point **corners, const int n) {
    if( n <= 0 ) return;
    if( corners == NULL ) return;
    Eigen::Matrix4d T = Tr.rotateZ(radians(10));
    vertices = T * vertices;

    for( int i = 0; i < n; i++ ) {
        if(*(corners + i) == NULL ) return;
        **(corners + i) = cv::Point(vertices(0, i), vertices(1, i));
    }
}


void draw_lines(cv::Mat& image, cv::Point **points, int n) {
    for( int i = 0; i < n; i++ ) {
        cv::line(image, **(points + i%n), **(points + (i+1)%n), cv::Scalar(0), 2);
    }
}


void init_square(Eigen::Matrix4Xd& vertices, cv::Point **points) {
    vertices.resize(4, 4);
    vertices << 0, 0, 300, 300,
                0, 300, 300, 0, 0, 0, 0, 0, 1, 1, 1, 1;
    

    *points = new cv::Point(0,0);
    *(points + 1) = new cv::Point(0, 300);
    *(points + 2) = new cv::Point(300, 300);
    *(points + 3) = new cv::Point(300, 0);
}




int main(int argc, char** argv) {
    Transformations Tr;
    cv::Mat canvas;
    setup_window(canvas);

    Eigen::Matrix4Xd vertices;
    cv::Point *points[] = {NULL, NULL, NULL, NULL};
    init_square(vertices, points);
    draw_lines(canvas, points, 4);
    cv::imshow("Canvas", canvas);
    vertices = Tr.translate(Eigen::Vector3d(300, 300, 0)) * vertices;
    int frames = 20;
    while(frames--) {
        getImagePoints(Tr, vertices, points, 4);
        draw_lines(canvas, points, 4);
        cv::imshow("Canvas", canvas);
        cv::waitKey(0);
    }
    return 0;
}