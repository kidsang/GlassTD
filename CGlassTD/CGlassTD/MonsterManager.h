#ifndef MonsterManager_h__
#define MonsterManager_h__
#include "MonsterGenerator.h"
#include <list>
class MonsterManager
{
private:
	std::list<SceneNode*> mMonsterNodes;
	std::list<Monster*> mMonsters;
	static int mMonsterNum;
	Ogre::String mMonNames[20];
	
	static MonsterManager* mMonsterMgr;
	MonsterManager(void);
	~MonsterManager(void);
	
public:
	
	static MonsterManager* getMonsterManager(void);
	/// void monsterTimer(Ogre::SceneManager* sceneManager);
	void monsterGenerate(Ogre::SceneManager* sceneManager);
	
};




#endif // MonsterManager_h__
