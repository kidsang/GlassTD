#include "MonsterGenerator.h"

Monster* MonsterGenerator::createMonster(Ogre::SceneManager* mSceneMgr, Ogre::String mesh, Ogre::String name)
{
	Ogre::SceneNode* monsterNode = mSceneMgr->getRootSceneNode();
	Monster* mon;
	mon = new OrdinaryMonster(mSceneMgr, monsterNode, mesh, name);
	return mon;
}

MonsterGenerator::MonsterGenerator( void )
{

}

MonsterGenerator::~MonsterGenerator( void )
{

}
