
#ifndef Monster_h__
#define Monster_h__

#include "BaseApplication.h"
class Monster
{
	/// Maze maze;
	/// ���޵��ٶ�
	float speed;
	/// �����Ѫ��
	int blood;
	/// ���������һ����ά����)
	Ogre::Vector3 face;
	/// ���������
	int kind;
	Ogre::Vector3 pos;
	Ogre::SceneNode* node;
	Ogre::Entity* entity;
	Ogre::String mesh;
	Ogre::String name;

public:
	Monster(void);
	~Monster(void);
	void go(void);
	int getBlood(void);
	void setBlood(int blood);
	int getType(void);
	Ogre::Vector3 getPosition(void);
	void setPosition(Ogre::Vector3& pos);
	Ogre::Vector3 getFace(void);
	void setFace(Ogre::Vector3& face);

};

const int ORDINARY_MONSTER = 0;
const int FLY_MONSTER = 1;
const int FULL_BLOOD = 100;

#endif // Monster_h__
