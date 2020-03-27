#include "Object.h"

Object* createCube(unsigned int id, unsigned int side) {
    Object *cube = new Object(id, 8, 12, 6);
    Eigen::MatrixX4d vertices(4, 8);
    vertices << side/2, side/2, side/2, side/2, -side/2, -side/2, -side/2, -side/2,
                side/2, side/2, -side/2, -side/2, side/2, side/2, -side/2, -side/2,
                -side/2, side/2, side/2, -side/2, -side/2, side/2, side/2, -side/2,
                1, 1, 1, 1, 1, 1, 1, 1;
}