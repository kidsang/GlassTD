
#ifndef Monster_h__
#define Monster_h__

#include "BaseApplication.h"
#include "ObjectFactory.h"

struct HarmList
{
	int iceHarm;
	int fireHarm;
	HarmList(int iceHarmTemp, int fireHarmTemp):iceHarm(iceHarmTemp), fireHarm(fireHarmTemp){};
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
};

const int ORDINARY_MONSTER = 0;
const int FLY_MONSTER = 1;
const int FULL_BLOOD = 100;
const float BEGIN_POS_X = -100.0f;
const float BEGIN_POS_Y = 0.f;
const float BEGIN_POS_Z = -100.f;
#endif // Monster_h__
