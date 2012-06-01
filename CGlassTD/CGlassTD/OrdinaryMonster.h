#ifndef OrdinaryMonster_h__
#define OrdinaryMonster_h__
#include "Monster.h"
class OrdinaryMonster:Monster
{
public:
	OrdinaryMonster();
	OrdinaryMonster(Ogre::SceneManager* sceneMgr, Ogre::SceneNode* parentNode, Position& pos, Ogre::String mesh);
	OrdinaryMonster(Ogre::SceneManager* sceneMgr, Ogre::SceneNode* parentNode, Position& pos, Ogre::String mesh, Ogre::String name);
	~OrdinaryMonster();
	
};
#endif // OrdinaryMonster_h__