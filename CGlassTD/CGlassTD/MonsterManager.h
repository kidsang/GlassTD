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
	/// ��ͼ
	Maze* mMaze;
	/// ʱ�������
	static float mTimeCount;
	/// std::list<SceneNode*> mMonsterNodes;
	/// ���ڵĹ��﹤��
	MonsterFactory* mCurrentMonsterFactory;
	/// ���޹����б��������ɲ�ͬ����Ĺ���
	std::vector<MonsterFactory*> mMonsterFactoryList;
	/// �����б�
	std::list<Monster*> mMonstersList;
	/// ��������
	static int mMonsterNum;
	/// �������������һ
	static MonsterManager* mMonsterMgr;

	MonsterManager(Ogre::SceneManager* sceneManager);
	MonsterManager();
	

//protected:
//	
//	static DWORD WINAPI createMonstersThread(PVOID pVoid); 
		
public:
	~MonsterManager(void);
    /// Ogre::String mMonNames[100];
	/// ��ȡ��������
	int getMonsterNum(void);

	/// ���ù�������
	void setMonsterNum(int num);

	/// ��������+1
	void MonsterNumPlus(void);

	/// ��ȡʱ���ۼӼ�������ֵ
	float getTimeCount(void);

	/// ����ʱ���ۼӼ�������ֵ
	void setTimeCount(float timeCount);

	/// ��ȡ�����б�
	std::list<Monster*> getMonstersList(void);

	/// ��ȡ���������
	static MonsterManager* getMonsterManager(void);

	/// void monsterTimer(Ogre::SceneManager* sceneManager);

	/// ��������
	void monsterGenerate(Ogre::SceneManager* sceneManager, float timeSinceLastFrame);

	void setMaze(Maze* maze);

	
	void updateState(std::vector<Bullet> explodedBullets, float timeSinceLastFrame, Ogre::SceneManager* sceneManager);
};
/// ���������ʱ����
const float NEW_MONSTER_TIME = 6.0;


#endif // MonsterManager_h__
