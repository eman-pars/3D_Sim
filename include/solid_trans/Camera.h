#include <eigen3/Eigen/Core>
#include <opencv2/core/core.hpp>

#ifndef __CAMERA_H__
#define __CAMERA_H__

class Camera
{
private:
    Eigen::MatrixXd C_Mat;
public:
    cv::Point
    Camera();
    ~Camera();
};

Camera::Camera()
{
}

Camera::~Camera()
{
}


#endif