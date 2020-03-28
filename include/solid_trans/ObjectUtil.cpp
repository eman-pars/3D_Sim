#include <vector>

#include <solid_trans/Object.h>

Object* createCube(unsigned int id, int side) {
    Object *cube = new Object(id, 8, 12, 6);
    Eigen::Matrix4Xd vertices(4, 8);
    vertices << side/2, side/2, side/2, side/2, -side/2, -side/2, -side/2, -side/2,
                side/2, side/2, -side/2, -side/2, side/2, side/2, -side/2, -side/2,
                -side/2, side/2, side/2, -side/2, -side/2, side/2, side/2, -side/2,
                1, 1, 1, 1, 1, 1, 1, 1;
    cube->setVertices(vertices);
    // for( int i = 0; i < 4; i++ ) {
    //     cube->addEdge(new Edge(i, (i+1)%4));
    //     cube->addEdge(new Edge(i+4, 4+(i+1)%4));
    //     cube->addEdge(new Edge(i, i+4));
    // }
    // cube->addFace( new Face(4, {0, 1, 2, 3}));
    // cube->addFace( new Face(4, {4, 5, 6, 7}));
    // cube->addFace( new Face(4, {0, 4, 5, 1}));
    // cube->addFace( new Face(4, {1, 5, 6, 2}));
    // cube->addFace( new Face(4, {2, 6, 7, 3}));
    // cube->addFace( new Face(4, {3, 7, 4, 0}));
    return cube;
}