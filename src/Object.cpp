#include <solid_trans/Object.h>

/**
 * @brief Construct a new Edge:: Edge object
 * 
 * @param a Index of first vertex
 * @param b Index of second vertex
 */
Edge::Edge(unsigned int a, unsigned int b): pt1(a), pt2(b) {}


/**
 * @brief Construct a new Face:: Face object
 * 
 * @param n Number of Edges making the face.
 */
Face::Face(unsigned int n): maxEdge(n) {
    edges = NULL;
}


/**
 * @brief Construct a new Face:: Face object
 * 
 * @param n Number of Edges making the face.
 * @param e Indices of edges.
 */
Face::Face(unsigned int n, std::vector<unsigned int> e): maxEdge(n){
    if ( e.size() != maxEdge) return;
    else edges = &e[0];
}


/**
 * @brief Adds the edges of the face.
 * 
 * @param e Indices of edges.
 */
void Face::addEdges(std::vector<unsigned int> e) {
    if ( e.size() != maxEdge) return;
    else edges = &e[0];
}


/**
 * @brief Construct a new Object:: Object object
 * 
 * @param iden Identifier
 * @param vCount Number of Vertices in the object.
 * @param eCount Number of Edges in the object.
 * @param fCount Number of Faces in the object.
 */
Object::Object(const unsigned int iden, unsigned int vCount, unsigned int eCount,
                unsigned int fCount): id(iden), vertexCount(vCount), edgeCount(eCount), faceCount(fCount) {
    vertices.resize(4, vertexCount);
    edges = new Edge*[edgeCount];
    faces = new Face*[faceCount];
}

/**
 * @brief Destroy the Object:: Object object
 * 
 */
Object::~Object() {
    delete[] edges;
    delete[] faces;
}


/**
 * @brief Sets the veritices of solid.
 * 
 * @param verti 
 */
void Object::setVertices(Eigen::Matrix4Xd& verti) {
    vertices = verti;
}

Eigen::Matrix4Xd& Object::getVertices() {
    return vertices;
}

void Object::addEdge(Edge *e) {
    if( edgeCount == edgeFilled ) return;
    else *(edges + edgeFilled++) = e;
}


void Object::addFace(Face *f) {
    if( faceCount == faceFilled ) return;
    else *(faces + faceFilled++ ) = f;
}



