#ifndef MonsterGenerator_h__
#define MonsterGenerator_h__

#include "OrdinaryMonster.h"
class MonsterGenerator
{
	
public:
	MonsterGenerator(void);
	~MonsterGenerator(void);
	/*/// 产生怪物
	Monster* createMonster(Ogre::SceneManager* sceneManager, Ogre::String mesh, Ogre::String name);*/
	/// 产生怪物
	Monster* createMonster(Ogre::SceneManager* mSceneMgr, Ogre::String mesh);
};
//
//const int DenstinationX = 10;
//const int DenstinationY = 10;

#endif // MonsterGenerator_h__
 