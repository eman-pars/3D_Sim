/**
 * @file Object.h
 * @author Abhay Pratap Singh (you@domain.com)
 * @brief Defines classes, structs to represent simple solid objects .
 * @version 0.1
 * @date 2020-03-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */


#include <eigen3/Eigen/Core>
#include <vector>

#ifndef __OBJECT_H__
#define __OBJECT_H__


/**
 * @brief Represents an edge using two numbers indicating the indices of the vertices.
 * 
 */
struct Edge {
    unsigned int pt1;
    unsigned int pt2;
    Edge(unsigned int, unsigned int);
};


/**
 * @brief Represents a face of an object using the edges that make it up.
 * 
 */
struct Face {
    const unsigned int maxEdge;
    unsigned int *edges;
    Face(unsigned int);
    Face(unsigned int, std::vector<unsigned int>);
    void addEdges(std::vector<unsigned int>);
};


/**
 * @brief Represents on solid object with vertices, edges and faces.
 * 
 */
class Object
{
private:
    const unsigned int id;
    const unsigned int vertexCount, edgeCount, faceCount;
    unsigned int edgeFilled, faceFilled;
    Eigen::Matrix4Xd vertices;
    Edge **edges;
    Face **faces;
public:
    void setVertices(Eigen::Matrix4Xd&);
    Eigen::Matrix4Xd& getVertices();
    void addEdge(Edge*);
    void addFace(Face*);
    Object(const unsigned int, unsigned int, unsigned int, unsigned int);
    ~Object();
};

#endif