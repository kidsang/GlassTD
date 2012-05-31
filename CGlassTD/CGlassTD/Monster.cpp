#include "Monster.h"

Monster::Monster(void)
	:speed(0),
	blood(FULL_BLOOD),
    face(Ogre::Vector3(0, 0, 1)),
    kind(ORDINARY_MONSTER)
{
	
}

Monster::~Monster(void)
{

}

//Ogre::SceneNode* Monster::getNode(Ogre::String mesh, Ogre::String name)
//{
//	
//	
//}

void Monster::go(void)
{

}

int Monster::getBlood(void)
{
	return blood;
}
void Monster::setBlood(int blood)
{
	this->blood = blood;
}
int Monster::getType(void)
{
	return kind;
}
Ogre::Vector3 Monster::getPosition(void)
{
	return pos;
}
void Monster::setPosition(Ogre::Vector3& pos)
{
	this->pos = pos;
}
Ogre::Vector3 Monster::getFace()
{
	return face;
}
void Monster::setFace(Ogre::Vector3& face)
{
	this->face = face;
}

