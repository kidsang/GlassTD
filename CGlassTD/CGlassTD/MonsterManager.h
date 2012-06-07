#ifndef MonsterManager_h__
#define MonsterManager_h__
#include <list>
#include <windows.h>
#include "Monster.h"
#include "ParamParser.h"
#include "Bullet.h"
#include "Maze.h"
class MonsterManager
{
private:
	/// 地图
	Maze* mMaze;
	/// 时间计数器
	static float mTimeCount;
	/// std::list<SceneNode*> mMonsterNodes;
	/// 现在的怪物工厂
	MonsterFactory* mCurrentMonsterFactory;
	/// 怪兽工厂列表，用于生成不同种类的怪物
	std::vector<MonsterFactory*> mMonsterFactoryList;
	/// 怪物列表
	std::list<Monster*> mMonstersList;
	/// 怪物数量
	static int mMonsterNum;
	/// 怪物管理器，单一
	static MonsterManager* mMonsterMgr;

	MonsterManager(Ogre::SceneManager* sceneManager);
	MonsterManager();
	

//protected:
//	
//	static DWORD WINAPI createMonstersThread(PVOID pVoid); 
		
public:
	~MonsterManager(void);
    /// Ogre::String mMonNames[100];
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
	std::list<Monster*> getMonstersList(void);

	/// 获取怪物管理器
	static MonsterManager* getMonsterManager(void);

	/// void monsterTimer(Ogre::SceneManager* sceneManager);

	/// 怪物生成
	void monsterGenerate(Ogre::SceneManager* sceneManager, float timeSinceLastFrame);

	void setMaze(Maze* maze);

	
	void updateState(std::vector<NameValueList> explodedBullets, float timeSinceLastFrame, Ogre::SceneManager* sceneManager);
};
/// 新增怪物的时间间隔
const float NEW_MONSTER_TIME = 6.0;


#endif // MonsterManager_h__
