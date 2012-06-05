#include "MonsterManager.h"

MonsterManager* MonsterManager::mMonsterMgr = NULL;
int MonsterManager::mMonsterNum = 0;
float MonsterManager::mTimeCount = 0.0f;


MonsterManager::MonsterManager()
{
	mMonsterGen = new MonsterGenerator();

	for(int i = 0; i < 100; i++)
	{
		mMonNames[i] = "monster" + i;
	}
}

MonsterManager::~MonsterManager(void)
{
	if(mMonsterMgr != NULL)
	    delete mMonsterMgr;
	
	mMonstersList.clear();
	delete mMonsterGen;
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

void MonsterManager::monsterGenerate(Ogre::SceneManager* sceneManager, float timeSinceLastFrame)
{
	//::CreateThread(NULL, 0, createMonstersThread, sceneManager, NULL, NULL);
	
	mMonsterMgr->setTimeCount(mMonsterMgr->getTimeCount() + timeSinceLastFrame);
	/// std::list<Monster*> monsterList = mMonsterMgr->getMonstersList();
	if(mMonsterMgr->getTimeCount() > NEW_MONSTER_TIME)
	{
		Ogre::String mesh = "robot.mesh";
		Monster* monster = mMonsterGen->createMonster(sceneManager, mesh);
		/// monster->monsterScale(0.1, 0.1, 0.1);
		monster->setAnimate();
		mMonstersList.insertAhead(monster);
		mMonsterMgr->MonsterNumPlus();
		mMonsterMgr->setTimeCount(0.0f);
	}
}

MyList<Monster*>* MonsterManager::getMonstersList( void )
{
	return &mMonstersList;
}

//
//DWORD WINAPI MonsterManager::createMonstersThread(PVOID pVoid)
//{
//	
//	
//	//Ogre::SceneManager* param = (Ogre::SceneManager*)pVoid;
//	///// param = (Ogre::SceneManager*)pVoid;
//	///// MoveMemory(param, pVoid, sizeof(Ogre::SceneManager));
//	//Ogre::SceneManager* sceneManager = param;
//
//	//HANDLE mutex;
//	//mutex=::CreateMutex(NULL,FALSE,"MUTEX");
//	//
//	//MonsterGenerator* monsterGen = new MonsterGenerator();
//	//Ogre::String mesh = "penguin.mesh";
//	//for(int i = 0; i < 3; i++)
//	//{	
//	//	if(i == 2)
//	//		mesh = "robot.mesh";
//	//	//SetTimer(1, 3000, monsterGen().createMonster(sceneManager, mesh, monNames[i]));
//	//	::WaitForSingleObject(mutex,100);
//	//	if(mMonsterMgr == NULL)
//	//		break;
//	//	mMonsters->push_back(monsterGen->createMonster(sceneManager, mesh, mMonNames[i]));
//	//	Sleep(2000);
//	//	::ReleaseMutex(mutex);
//	//	
//	//}
//	return 0;
//}

float MonsterManager::getTimeCount(void)
{
	return mTimeCount;
}

void MonsterManager::setTimeCount(float timeCount)
{
	mTimeCount = timeCount;
}

int MonsterManager::getMonsterNum(void)
{
	return mMonsterNum;
}

void MonsterManager::setMonsterNum(int num)
{
	mMonsterNum = num;
}

void MonsterManager::MonsterNumPlus(void)
{
	mMonsterNum++;
}
