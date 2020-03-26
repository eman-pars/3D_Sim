#include "eigen3/Eigen/Core"


#ifndef __TRANSFORMATIONS_H__
#define __TRANSFORMATIONS_H__

class Transformations
{
private:
    
public:
    Eigen::Matrix4d reflect(Eigen::Vector3f);
    Eigen::Matrix4d reflectX();
    Eigen::Matrix4d reflectY();
    Eigen::Matrix4d reflectZ();
    Eigen::Matrix4d rotate(Eigen::Vector3f, double);
    Eigen::Matrix4d rotateX(double);
    Eigen::Matrix4d rotateY(double);
    Eigen::Matrix4d rotateZ(double);
    Eigen::Matrix4d translate(Eigen::Vector3f);
    Eigen::Matrix4d scaleAll(const double);
    Eigen::Matrix4d scale(const double, const double, const double);
    Transformations();
    ~Transformations();
};

#endif
