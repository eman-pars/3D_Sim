#include <solid_trans/World.h>


Spawn::Spawn(): obj(NULL) {
    T << 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1;
}

Eigen::Matrix4Xd& Spawn::getVertices() {
    Eigen::Matrix4Xd world_coor =  T * obj->getVertices();
    return world_coor;
}


void World::setScreen(Screen *s) {
    screen = s;
}

void World::setCamera(Camera *c) {
    camera = c;
}

void World::transform(Spawn *s, Eigen::Matrix4d& E) {
    s->T = E * s->T;
}

Spawn* World::getSpawnPtr(int index) {
    return spawns[index];
}

Eigen::Matrix4Xd& World::getSpawnVertices(Spawn *s) {
    return s->getVertices();
}

void World::transformCamera(Eigen::Matrix4d& E) {
}

World::World(): camera(NULL), screen(NULL) {

}

World::~World() {
    delete camera;
    delete screen;
}