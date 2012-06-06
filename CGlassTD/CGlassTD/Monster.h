
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
	/// 怪兽的速度
	float mSpeed;
	/// 怪物的血量
	int mBlood;
	/// 怪物的面向（一个三维向量)
	Ogre::Vector3 mFace;
	/// 怪物的种类
	int mKind;
	Ogre::SceneNode* mNode;
	Ogre::String mMesh;
	Ogre::AnimationState* mAnimationState;
	/// 怪兽的半径范围
	float mRadius;
	/// 伤害列表
	HarmList mHarmList;
	/// 怪兽是否死亡
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

	/// 设置动画
	void setAnimate();
	/// 根据时间刷新动画状态
	void addTimeToAnimation(float timeSinceLastFrame);
	/// 获取怪兽的半径
	int getRadius();
	/// 缩放怪物
	void monsterScale(float x, float y, float z);
	/// 伤害检测
	void harmCheck(float timeSinceLastFrame);
	/// 怪兽死掉
	bool isMonsterDead();
private:
	void makeMap(Cell* cell);
	bool isValid(Pos& pos);
bool isTarget(Pos& pos);
};


#endif // Monster_h__
