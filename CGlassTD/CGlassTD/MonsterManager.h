#ifndef MonsterManager_h__
#define MonsterManager_h__
#include "MonsterGenerator.h"
#include <windows.h>
#include "List.hpp"

class MonsterManager
{
private:
	/// ʱ�������
	static float mTimeCount;
	/// std::list<SceneNode*> mMonsterNodes;
	/// �����б�
	MyList<Monster*> mMonstersList;
	/// ��������
	static int mMonsterNum;
	/// �������������һ
	static MonsterManager* mMonsterMgr;
	/// �������ɹ���
	MonsterGenerator* mMonsterGen;

	MonsterManager(Ogre::SceneManager* sceneManager);
	MonsterManager();
	~MonsterManager(void);

//protected:
//	
//	static DWORD WINAPI createMonstersThread(PVOID pVoid); 
		
public:
	Ogre::String mMonNames[100];
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
	MyList<Monster*>* getMonstersList(void);

	/// ��ȡ���������
	static MonsterManager* getMonsterManager(void);

	/// void monsterTimer(Ogre::SceneManager* sceneManager);

	/// ��������
	void monsterGenerate(Ogre::SceneManager* sceneManager, float timeSinceLastFrame);
	
};
/// ���������ʱ����
const float NEW_MONSTER_TIME = 6.0;


#endif // MonsterManager_h__
