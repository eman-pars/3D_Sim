#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include "Transformations.h"

double radians(double degrees) {
    return degrees / 180.0 * M_PI;
}


void setup_window(cv::Mat& canvas) {
    canvas = cv::Mat(800, 800, CV_8UC(3), cv::Scalar(255, 255, 255));
    canvas.reshape(800, 800);
    cv::namedWindow("Canvas", cv::WINDOW_NORMAL);
    cv::resizeWindow("Canvas", 800, 800);
}


void getImagePoints(Transformations Tr, Eigen::Matrix4Xd& vertices, cv::Point **corners, const int n) {
    if( n <= 0 ) return;
    if( corners == NULL ) return;
    for( int i = 0; i < n; i++ ) {
        if(*(corners + i) == NULL ) return;
        **(corners + i) = cv::Point((int)vertices(0, i), (int)vertices(1, i));
    }
}


void draw_lines(cv::Mat& image, cv::Point **points, int n) {
    for( int i = 0; i < n; i++ ) {
        cv::line(image, **(points + i%n), **(points + (i+1)%n), cv::Scalar(0), 2);
    }
}


void draw_cube(cv::Mat& image, cv::Point **points) {
    for( int i = 0; i < 4; i++ ) {
        cv::line(image, **(points + i), **(points + (i+1)%4), cv::Scalar(0), 2);
        cv::line(image, **(points + i+4), **(points + 4 + (i+1)%4), cv::Scalar(0), 2);
        cv::line(image, **(points + i), **(points + 4+i), cv::Scalar(0), 2); 
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


void init_cube(Eigen::Matrix4Xd& vertices, cv::Point **points) {
    vertices.resize(4, 8);
    vertices << 100, 100, 100, 100, -100, -100, -100, -100,
                100, 100, -100, -100, 100, 100, -100, -100,
                400, 600, 600, 400, 400, 600, 600, 400,
                1, 1, 1, 1, 1, 1, 1, 1;
    for( int i = 0; i < 8; i++ ) {
        *(points + i) = new cv::Point(vertices(0, i), vertices(1, i));
    }
}


void camera_pass(Eigen::Matrix4Xd& vertices, cv::Point **points) {
    int n = vertices.cols();
    Eigen::Matrix3Xd CAM(3, 4);
    CAM << 200, 0, 400, 0, 0, 200, 400, 0, 0, 0, 1, 0;

    for( int i = 0; i < n; i++ ) {
        Eigen::Vector3d image_point = CAM * vertices.col(i);
        *(points + i) = new cv::Point(image_point(0) / image_point(2), 400 - image_point(1) / image_point(2));
    }
}

int main(int argc, char** argv) {
    Transformations Tr;
    cv::Mat canvas;
    setup_window(canvas);

    Eigen::Matrix4Xd vertices;
    cv::Point *points[] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    //init_square(vertices, points);
    init_cube(vertices, points);
    //draw_lines(canvas, points, 4);
    draw_cube(canvas, points);
    cv::imshow("Canvas", canvas);

    Eigen::Matrix4d temp = Tr.translate(Eigen::Vector3d(0, 200, 500)) * Tr.rotateZ(radians(9)) * Tr.translate(Eigen::Vector3d(0, -200, -500));
    vertices = Tr.translate(Eigen::Vector3d(0, 200, 0)) * vertices;

    int frames = 50;
    while(frames--) {
        // vertices = Tr.translate(Eigen::Vector3d(0, 0, -500)) * Tr.rotateZ(radians(9)) * vertices;
        // getImagePoints(Tr, vertices, points, 4);
        // vertices = Tr.translate(Eigen::Vector3d(-300, -300, 0)) * vertices;
        // draw_lines(canvas, points, 4);
        camera_pass(vertices, points);
        draw_cube(canvas, points);
        vertices = temp * vertices;
        cv::putText(canvas, "Frame: ", cv::Point(0, 400), cv::FONT_HERSHEY_SIMPLEX, 0.8, cv::Scalar(0, 0, 255),2);
        cv::imshow("Canvas", canvas);
        canvas = cv::Scalar(255, 255, 255);
        cv::waitKey(50);
    }
    return 0;
}