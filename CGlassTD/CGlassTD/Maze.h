#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreEntity.h>
using namespace Ogre;

#ifndef __Maze_h_
#define __Maze_h_
class Maze
{
private:
	SceneNode* mSceneNode;
public:
	Maze(void);
	Maze(SceneManager* sceneManager);
	~Maze(void);
};
#endif

