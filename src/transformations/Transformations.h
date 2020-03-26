/**
 * @file Transformations.h
 * @author Abhay Pratap Singh (you@domain.com)
 * @brief Defines Transformations class for performing rigid-body transformations.
 * @version 0.1
 * @date 2020-03-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "eigen3/Eigen/Core"


#ifndef __TRANSFORMATIONS_H__
#define __TRANSFORMATIONS_H__


/**
 * @brief Returns 4x4 Trasnformation Matrix for basic rigid-body transformations.
 * 
 */
class Transformations
{
private:
    
public:
    Eigen::Matrix4d reflectX();
    Eigen::Matrix4d reflectY();
    Eigen::Matrix4d reflectZ();
    Eigen::Matrix4d rotate(Eigen::Vector3f, double);
    Eigen::Matrix4d rotateX(double);
    Eigen::Matrix4d rotateY(double);
    Eigen::Matrix4d rotateZ(double);
    Eigen::Matrix4d translate(Eigen::Vector3d);
    Eigen::Matrix4d scaleAll(const double);
    Eigen::Matrix4d scale(const double, const double, const double);
    Transformations();
    ~Transformations();
};

#endif
