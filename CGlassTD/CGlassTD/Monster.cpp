#include "Monster.h"

Monster::Monster(void)
	:mSpeed(0),
	mPos(Ogre::Vector2(BEGIN_POS_X, BEGIN_POS_Y)),
	mBlood(FULL_BLOOD),
    mFace(Ogre::Vector3(0, 0, 1)),
    mKind(ORDINARY_MONSTER)
{
	
}
//
//Monster::Monster( Ogre::SceneManager* sceneMgr, Ogre::SceneNode* parentNode, Position& pos)
//{	
//	
//}

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
	return mBlood;
}
void Monster::setBlood(int mBlood)
{
	this->mBlood = mBlood;
}
int Monster::getKind(void)
{
	return mKind;
}
Ogre::Vector2 Monster::getPosition(void)
{
	return mPos;
}
void Monster::setPosition(Ogre::Vector2& mPos)
{
	this->mPos = mPos;
}
Ogre::Vector3 Monster::getFace()
{
	return mFace;
}
void Monster::setFace(Ogre::Vector3& mFace)
{
	this->mFace = mFace;
}

Ogre::String Monster::getMesh()
{
	return mMesh;
}

void Monster::setMesh( Ogre::String mesh )
{
	mMesh = mesh;
}

Ogre::String Monster::getName()
{
	return mName;
}

void Monster::setName( Ogre::String name )
{
	mName = name;
}

