#include <eigen3/Eigen/Core>


#ifndef __OBJECT_H__
#define __OBJECT_H__

struct Edge;
struct Face;

class Object
{
private:
    const unsigned int id;
    const unsigned int vertexCount, edgeCount, faceCount;
    unsigned int edgeFilled, faceFilled;
    Eigen::MatrixX4d vertices;
    Edge **edges;
    Face **faces;
public:
    void addVertices(Eigen::Matrix4d);
    void addEdge(Edge*);
    void addFace(Face*);
    Object(const unsigned int, unsigned int, unsigned int, unsigned int);
    ~Object();
};

#endif