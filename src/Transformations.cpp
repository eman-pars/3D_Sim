/**
 * @file Transformations.cpp
 * @author Abhay Pratap Singh (you@domain.com)
 * @brief implements Transformations.h
 * @version 0.1
 * @date 2020-03-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <solid_trans/Transformations.h>


/**
 * @brief Returns Transformation Matrix to rotate by 'angle' angles about 'axis' axis.
 * 
 * @param axis 3D Vector denoting the rotation axis.
 * @param angle in radians.
 * @return Eigen::Matrix4d The required 4x4 Transformation Matrix.
 */
Eigen::Matrix4d Transformations::rotate(Eigen::Vector3f axis, double angle) {
    axis.normalize();
    double u = axis(0), v = axis(1), w = axis(2);
    Eigen::Matrix4d T;
    double C = cos(angle), S = sin(angle);
    double a_11 = C + u*u*(1-C);
    double a_12 = u*v*(1-C) - w*S;
    double a_13 = u*w*(1-C) + v*S;
    double a_21 = v*u*(1-C) + w*S;
    double a_22 = C + v*v*(1-C);
    double a_23 = v*w*(1-C) - u*S;
    double a_31 = u*w*(1-C) - v*S;
    double a_32 = v*w*(1-C) + u*S;
    double a_33 = C + w*w*(1-C);
    T.row(0) << a_11, a_12, a_13, 0;
    T.row(1) << a_21, a_22, a_23, 0;
    T.row(2) << a_31, a_32, a_33, 0;
    T.row(3) << 0, 0, 0, 1;
    return T;
}

/**
 * @brief Returns Transformation Matrix for rotating about X-axis by 'angle' angles.
 * 
 * @param angle in radians.
 * @return Eigen::Matrix4d Required 4x4 Transformation Matrix. 
 */
Eigen::Matrix4d Transformations::rotateX(double angle) {
    return rotate(Eigen::Vector3f(1, 0, 0), angle);
}



/**
 * @brief Returns Transformation Matrix for rotating about Y-axis by 'angle' angles.
 * 
 * @param angle in radians.
 * @return Eigen::Matrix4d Required 4x4 Transformation Matrix. 
 */
Eigen::Matrix4d Transformations::rotateY(double angle) {
    return rotate(Eigen::Vector3f(0, 1, 0), angle);
}



/**
 * @brief Returns Transformation Matrix for rotating about Z-axis by 'angle' angles.
 * 
 * @param angle in radians.
 * @return Eigen::Matrix4d Required 4x4 Transformation Matrix. 
 */
Eigen::Matrix4d Transformations::rotateZ(double angle) {
    return rotate(Eigen::Vector3f(0, 0, 1), angle);
}


/**
 * @brief Returns Transformation Matrix for reflecting about YZ plane.
 * 
 * @return Eigen::Matrix4d Required 4x4 Transformation Matrix.
 */
Eigen::Matrix4d Transformations::reflectX() {
    Eigen::Matrix4d T;
    T.row(0) << -1, 0, 0, 0;
    T.row(1) << 0, 1, 0, 0;
    T.row(2) << 0, 0, 1, 0;
    T.row(3) << 0, 0, 0, 1;
    return T;
}

/**
 * @brief Returns Transformation Matrix for reflecting about XZ plane.
 * 
 * @return Eigen::Matrix4d Required 4x4 Transformation Matrix.
 */
Eigen::Matrix4d Transformations::reflectY() {
    Eigen::Matrix4d T;
    T.row(0) << 1, 0, 0, 0;
    T.row(1) << 0, -1, 0, 0;
    T.row(2) << 0, 0, 1, 0;
    T.row(3) << 0, 0, 0, 1;
    return T;
}

/**
 * @brief Returns Transformation Matrix for reflecting about XY plane.
 * 
 * @return Eigen::Matrix4d Required 4x4 Transformation Matrix.
 */
Eigen::Matrix4d Transformations::reflectZ() {
    Eigen::Matrix4d T;
    T.row(0) << 1, 0, 0, 0;
    T.row(1) << 0, 1, 0, 0;
    T.row(2) << 0, 0, -1, 0;
    T.row(3) << 0, 0, 0, 1;
    return T;
}

/**
 * @brief Returns Transformation Matrix for translation.
 * 
 * @param displacement in metres
 * @return Eigen::Matrix4d Required 4x4 Transformation Matrix.
 */
Eigen::Matrix4d Transformations::translate(Eigen::Vector3d displacement) {
    Eigen::Matrix4d T;
    T.row(0) << 1, 0, 0, displacement.x();
    T.row(1) << 0, 1, 0, displacement.y();
    T.row(2) << 0, 0, 1, displacement.z();
    T.row(3) << 0, 0, 0, 1;
    return T;
}

/**
 * @brief Returns Transformation Matrix for Scaling of dimensions along principal axes.
 * 
 * @param factorX x-scaling
 * @param factorY y-scaling
 * @param factorZ z-scaling
 * @return Eigen::Matrix4d Required 4x4 Transformation Matrix.
 */
Eigen::Matrix4d Transformations::scale(const double factorX, const double factorY, const double factorZ) {
    Eigen::Matrix4d T;
    T.row(0) << factorX, 0, 0, 0;
    T.row(1) << 0, factorY, 0, 0;
    T.row(2) << 0, 0, factorZ, 0;
    T.row(3) << 0, 0, 0, 1;
    return T;
}

/**
 * @brief Returns Transformation Matrix for Scaling of all dimensions.
 * 
 * @param factor 
 * @return Eigen::Matrix4d Required 4x4 Transformation Matrix.
 */
Eigen::Matrix4d Transformations::scaleAll(const double factor) {
    return scale(factor, factor, factor);
}

/**
 * @brief Construct a new Transformations:: Transformations object
 * 
 */
Transformations::Transformations() {

}

Transformations::~Transformations() {

}