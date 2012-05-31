#include "Position.h"
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreEntity.h>
#include "ObjectFactory.h"
using namespace std;
using namespace Ogre;

#ifndef __Cell_h_
#define __Cell_h_

class Cell
{
private:
	bool mState;
	int mMaxContain;
	int mCurrentContain;
	Position mPos;
	Entity* mEntity;
	SceneNode* mSceneNode;

public:
	Cell(void);
	Cell(Ogre::SceneManager* sceneManager,Ogre::SceneNode* parentNode,bool state,int maxContain,Position& pos);
	~Cell(void);
	bool isContain();
	bool Contain();
};

#endif

