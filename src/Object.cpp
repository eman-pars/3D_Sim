#include "Object.h"

struct Edge {
    unsigned int pt1, pt2;
    Edge(unsigned int a, unsigned int b): pt1(a), pt2(b) {}
};

struct Face
{
    const unsigned int maxEdge;
    unsigned int *edges;

    Face(unsigned int n): maxEdge(n) {
        edges = NULL;
    }

    void addEdges(unsigned int e[]) {
        if ( (sizeof(e) / sizeof(unsigned int)) != maxEdge) return;
        else edges = e;
    }
};


Object::Object(const unsigned int iden, unsigned int vCount, unsigned int eCount,
                unsigned int fCount): id(iden), vertexCount(vCount), edgeCount(eCount), faceCount(fCount) {
    vertices.resize(4, vertexCount);
    edges = new Edge*[edgeCount];
    faces = new Face*[faceCount];
}

void Object::addEdge(Edge *e) {
    if( edgeCount == edgeFilled ) return;
    else *(edges + edgeFilled++) = e;
}


void Object::addFace(Face *f) {
    if( faceCount == faceFilled ) return;
    else *(faces + faceFilled++ ) = f;
}



