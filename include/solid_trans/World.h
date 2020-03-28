#include <solid_trans/Object.h>
#include <solid_trans/Camera.h>
#include <solid_trans/Screen.h>

#ifndef __WORLD_H__
#define __WORLD_H__


struct Spawn
{
    Object *obj;
    Eigen::Matrix4d T;
    Eigen::Matrix4Xd& getVertices();
};


class World
{
private:
    std::vector<Spawn*> spawns;
    Camera *camera;
    Screen *screen;
    
public:
    void setScreen(Screen*);
    void setCamera(Camera*);
    void transform(Spawn*, Eigen::Matrix4d&);
    void transformCamera(Eigen::Matrix4d&);
    Eigen::Matrix4Xd& getSpawnVertices(Spawn*);
    Spawn* getSpawnPtr(int num);
    World();
    ~World();
};

World::World()
{
}

World::~World()
{
}



#endif