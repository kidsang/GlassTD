#ifndef OrdinaryMonster_h__
#define OrdinaryMonster_h__
#include "Monster.h"
class OrdinaryMonster:public Monster
{
	
public:
	OrdinaryMonster();
	OrdinaryMonster(Ogre::SceneManager* sceneMgr, Ogre::SceneNode* parentNode, Ogre::String mesh);
	/*OrdinaryMonster(Ogre::SceneManager* sceneMgr, Ogre::SceneNode* parentNode, Ogre::String mesh, Ogre::String name);*/
	~OrdinaryMonster();
	
};

const float LOW_SPEED = 1.0;

#endif // OrdinaryMonster_h__