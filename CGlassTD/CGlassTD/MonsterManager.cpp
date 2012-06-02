#include "MonsterManager.h"

MonsterManager* MonsterManager::mMonsterMgr = NULL;
int MonsterManager::mMonsterNum = 3;

MonsterManager::MonsterManager(void)
{
	for(int i = 0; i < 20; i++)
	{
		mMonNames[i] = "monster" + i;
	}
}

MonsterManager::~MonsterManager(void)
{

}

MonsterManager* MonsterManager::getMonsterManager(void)
{
	if(mMonsterMgr == NULL)
		mMonsterMgr = new MonsterManager();
	return mMonsterMgr;
}
//
//void MonsterManager::monsterTimer(Ogre::SceneManager* sceneManager)
//{
//	MonsterManager* monsterMgr = getMonterManager();
//	SetTimer(1, 3000, monsterMgr->monsterGenerate(sceneManager));
//}

void MonsterManager::monsterGenerate(Ogre::SceneManager* sceneManager)
{
	MonsterGenerator* monsterGen = new MonsterGenerator();

	Ogre::String mesh = "penguin.mesh";
	for(int i = 0; i < 3; i++)
	{	
		//SetTimer(1, 3000, monsterGen().createMonster(sceneManager, mesh, monNames[i]));
		mMonsters.push_back(monsterGen->createMonster(sceneManager, mesh, mMonNames[i]));
		Sleep(3000);
	}
}