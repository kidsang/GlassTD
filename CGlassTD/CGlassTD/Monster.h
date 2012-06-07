
#ifndef Monster_h__
#define Monster_h__

#include "BaseApplication.h"
#include "ObjectFactory.h"
#include "Common.h"
#include "HarmCheck.h"
#include "Maze.h"
using namespace Ogre;
#include <stack>

class Cell;

const float FULL_BLOOD = 100.0f;
const float BEGIN_POS_X = -100.0f;
const float BEGIN_POS_Y = 0.f;
const float BEGIN_POS_Z = -100.f;
const float FIRE_HARM_TIME = 1.0f;    ///�������˺�����ʱ��
const float ICE_HARM_TIME = 1.0f;     /// �������˺�����ʱ��
const float ICE_HARM_SPEED = 0.4f;    /// ������Ӱ����ٶ�ֵ
const float FIRE_HARM_BLOOD = 0.01f;  /// �������˺���Ѫ��ֵ
const float SPIKEWEED_HARM_BLOOD = 1.0f;  /// �ش��˺���Ѫ��ֵ
const float SWAMP_HARM_SPEED = 0.4f;  /// ����Ӱ����ٶ�ֵ

struct HarmList
{
	/// �������˺�
	float iceHarm;
	/// �������˺�����ʱ��
	float iceHarmTime;
	/// �������˺�
	float fireHarm;
	/// �������˺�����ʱ��
	float fireHarmTime;

	/// �Ƿ񱻲�����׽��
	bool beCaught;
	/// �ش��˺�
	float spikeweedHarm;
	/// �Ƿ�վ�ڵش���
	bool isOnSpikeweed;
	/// �����˺�
	float swampHarm;
	/// �Ƿ���������
	bool isInSwamp;

	HarmList()
		:iceHarm(0), 
		fireHarm(0),
		spikeweedHarm(SPIKEWEED_HARM_BLOOD),
		swampHarm(SWAMP_HARM_SPEED),
		isOnSpikeweed(false),
		beCaught(false),
		isInSwamp(false),
		iceHarmTime(ICE_HARM_TIME),
		fireHarmTime(FIRE_HARM_TIME){};
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
	/// ��ͼ
	Maze* mMaze;
	/// ���޵��ٶ�
	float mSpeed;
	/// ���޵��ٶȱ��ݣ��Ա㻹ԭ�ٶ�
	float mSpeedTemp;
	/// �����Ѫ��
	float mBlood;
	/// ���������һ����ά����)
	Ogre::Vector3 mFace;
	/// ���������
	std::string mType;
	Ogre::SceneNode* mNode;
	Ogre::String mMesh;
	Ogre::AnimationState* mAnimationState;
	/// ���޵İ뾶��Χ
	float mRadius;
	/// �˺��б�
	HarmList mHarmList;
	/// �����Ƿ�����
    bool mIsDead;
	/// �˺������
	HarmCheck* mHarmCheck;
	
public:
	Monster(){}
	Monster(SceneNode* node);
	Monster(SceneNode* node, Maze* maze);
	Monster(Ogre::SceneManager* sceneMgr, Ogre::SceneNode* parentNode);
	~Monster(void);
	void go(float timeSinceLastFrame, Ogre::Vector3& direction);
	float getBlood(void);
	void setBlood(int mBlood);
	std::string getType(void);
	Ogre::Vector3 getFace(void);
	void setFace(Ogre::Vector3& mFace);
	Ogre::String getMesh();
	void setMesh(Ogre::String mesh);
	void setType(std::string type);
	void setSpeed(float speed);
	void setRadius(float radius);
	/// ���ö���
	void setAnimate();
	/// ����ʱ��ˢ�¶���״̬
	void addTimeToAnimation(float timeSinceLastFrame);
	/// ��ȡ���޵İ뾶
	float getRadius();
	/// ���Ź���
	void monsterScale(float x, float y, float z);
	/// �˺����
	void harmCheck(float timeSinceLastFrame);
	/// ��������
	bool isMonsterDead();
private:
	int* map;
	void makeMap(Cell* cell);
	bool isValid(Pos& pos);
	bool isFinal(Pos& pos);
	void MarkIt(Pos&);
	void stepTo(Pos& pos);
	void pushPos(Pos&, stack<Pos>&);
	bool findPath(Pos, Pos);
	bool isTarget(Pos& pos);
	/// ���ù����յ��Ļ������˺�
	void setHitByFire();
	/// ���ù����յ��ı������˺�
	void setHitByIce();
	/// ���ñ�������׽ס
	void setBeCaughtByTrap();
	/// �����ڵش���
	void setInsideSpikeweed();
	/// �����ڵش���
	void setOutsideSpikeweed();
	/// ������������
	void setInsideSwamp();
	/// ������������
	void setOutsideSwamp();
};


class MonsterFactory
{
	NameValueList mParams;
	std::string mType;

public:
	MonsterFactory(NameValueList params)
		:mParams(params)
	{
		mType = params["name"];
	}
	~MonsterFactory()
	{

	}

	Monster* createInstance(SceneManager* sceneMgr);
	
	std::string getType();
};

#endif // Monster_h__
