#ifndef MonsterManager_h__
#define MonsterManager_h__
#include "MonsterGenerator.h"
#include <windows.h>
#include "List.hpp"

class MonsterManager
{
private:
	/// 时间计数器
	static float mTimeCount;
	/// std::list<SceneNode*> mMonsterNodes;
	/// 怪物列表
	MyList<Monster*> mMonstersList;
	/// 怪物数量
	static int mMonsterNum;
	/// 怪物管理器，单一
	static MonsterManager* mMonsterMgr;
	/// 怪物生成工厂
	MonsterGenerator* mMonsterGen;

	MonsterManager(Ogre::SceneManager* sceneManager);
	MonsterManager();
	~MonsterManager(void);

//protected:
//	
//	static DWORD WINAPI createMonstersThread(PVOID pVoid); 
		
public:
	Ogre::String mMonNames[100];
	/// 获取怪物数量
	int getMonsterNum(void);

	/// 设置怪物数量
	void setMonsterNum(int num);

	/// 怪物数量+1
	void MonsterNumPlus(void);

	/// 获取时间累加计数器的值
	float getTimeCount(void);

	/// 设置时间累加计数器的值
	void setTimeCount(float timeCount);

	/// 获取怪物列表
	MyList<Monster*>* getMonstersList(void);

	/// 获取怪物管理器
	static MonsterManager* getMonsterManager(void);

	/// void monsterTimer(Ogre::SceneManager* sceneManager);

	/// 怪物生成
	void monsterGenerate(Ogre::SceneManager* sceneManager, float timeSinceLastFrame);
	
};
/// 新增怪物的时间间隔
const float NEW_MONSTER_TIME = 6.0;


#endif // MonsterManager_h__
