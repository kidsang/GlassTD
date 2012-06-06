
#ifndef Monster_h__
#define Monster_h__

#include "BaseApplication.h"
#include "ObjectFactory.h"
#include <stack>
const int ORDINARY_MONSTER = 0;
const int FLY_MONSTER = 1;
const int FULL_BLOOD = 100;
const float BEGIN_POS_X = -100.0f;
const float BEGIN_POS_Y = 0.f;
const float BEGIN_POS_Z = -100.f;
const float HARM_TIME = 4.0f;
const float HARM_SPEED = 0.4f;

struct HarmList
{
	int iceHarm;
	float iceHarmTime;
	int fireHarm;
	float fireHarmTime;
	HarmList(int iceHarmTemp, int fireHarmTemp)
		:iceHarm(iceHarmTemp), 
		fireHarm(fireHarmTemp),
		iceHarmTime(HARM_TIME),
		fireHarmTime(HARM_TIME){};
};
struct Pos
{
	int x;
	int y;
};
struct CellNode
{
	Pos parent;
	Pos self;
	int dist;
};
struct Judge
{
	CellNode node;
	Judge* next;
};
class Monster
{
protected:
	/// Maze maze;
	/// ���޵��ٶ�
	float mSpeed;
	/// �����Ѫ��
	int mBlood;
	/// ���������һ����ά����)
	Ogre::Vector3 mFace;
	/// ���������
	int mKind;
	Ogre::SceneNode* mNode;
	Ogre::String mMesh;
	Ogre::AnimationState* mAnimationState;
	/// ���޵İ뾶��Χ
	float mRadius;
	/// �˺��б�
	HarmList mHarmList;
	/// �����Ƿ�����
    bool mIsDead;
public:
	Monster(void);
	Monster(Ogre::SceneManager* sceneMgr, Ogre::SceneNode* parentNode);
	~Monster(void);
	void go(float timeSinceLastFrame, Ogre::Vector3& direction);
	int getBlood(void);
	void setBlood(int mBlood);
	int getKind(void);
	Ogre::Vector3 getFace(void);
	void setFace(Ogre::Vector3& mFace);
	Ogre::String getMesh();
	void setMesh(Ogre::String mesh);

	/// ���ö���
	void setAnimate();
	/// ����ʱ��ˢ�¶���״̬
	void addTimeToAnimation(float timeSinceLastFrame);
	/// ��ȡ���޵İ뾶
	int getRadius();
	/// ���Ź���
	void monsterScale(float x, float y, float z);
	/// �˺����
	void harmCheck(float timeSinceLastFrame);
	/// ��������
	bool isMonsterDead();
private:
	void makeMap(Cell* cell);
	bool isValid(Pos& pos);
bool isTarget(Pos& pos);
};


#endif // Monster_h__
