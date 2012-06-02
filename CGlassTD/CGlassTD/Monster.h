
#ifndef Monster_h__
#define Monster_h__

#include "BaseApplication.h"
#include "ObjectFactory.h"
#include "Position.h"

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
	Ogre::Vector2 mPos;
	Ogre::SceneNode* mNode;
	Ogre::Entity* entity;
	Ogre::String mMesh;
	Ogre::String mName;

public:
	Monster(void);
	Monster(Ogre::SceneManager* sceneMgr, Ogre::SceneNode* parentNode);
	~Monster(void);
	void go(void);
	int getBlood(void);
	void setBlood(int mBlood);
	int getKind(void);
	Ogre::Vector2 getPosition(void);
	void setPosition(Ogre::Vector2& mPos);
	Ogre::Vector3 getFace(void);
	void setFace(Ogre::Vector3& mFace);
	Ogre::String getMesh();
	void setMesh(Ogre::String mesh);
	Ogre::String getName();
	void setName(Ogre::String name);

};

const int ORDINARY_MONSTER = 0;
const int FLY_MONSTER = 1;
const int FULL_BLOOD = 100;
const int BEGIN_POS_X = -10;
const int BEGIN_POS_Y = -10;
#endif // Monster_h__
