#include "Monster.h"

Monster::Monster(void)
	:mSpeed(1),
	/*mPos(Ogre::Vector3(BEGIN_POS_X, 10, BEGIN_POS_Y)),*/
	mBlood(FULL_BLOOD),
    mFace(Ogre::Vector3(0, 0, 1)),
	mRadius(1),
    mKind(ORDINARY_MONSTER),
	mHarmList(0, 0)
{
	
}
//
//Monster::Monster( Ogre::SceneManager* sceneMgr, Ogre::SceneNode* parentNode, Position& pos)
//{	
//	
//}

Monster::~Monster(void)
{
	/*if(mNode != NULL)
		delete mNode;*/
}

//Ogre::SceneNode* Monster::getNode(Ogre::String mesh, Ogre::String name)
//{
//	
//	
//}

void Monster::go(float timeSinceLastFrame, Ogre::Vector3& direction)
{
	mNode->setPosition(mNode->getPosition() + direction * timeSinceLastFrame);
	int* mp = new int[256];
	Ogre::Vector2* target = new Ogre::Vector2(Real(10), Real(10));
	Ogre::Vector2* start = new Ogre::Vector2(Real(2), Real(1));
	
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
//Ogre::Vector3 Monster::getPosition(void)
//{
//	return mPos;
//}
//void Monster::setPosition(Ogre::Vector3& mPos)
//{
//	this->mPos = mPos;
//}
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

void Monster::setAnimate()
{
	Ogre::Entity* entity;
	entity = (Ogre::Entity*)mNode->getAttachedObject(0);
	mAnimationState = entity->getAnimationState("Walk");
	mAnimationState->setLoop(true);
	mAnimationState->setEnabled(true);
}

void Monster::addTimeToAnimation( float timeSinceLastFrame )
{
	mAnimationState->addTime(timeSinceLastFrame);
}

int Monster::getRadius()
{
	return mRadius;
}

void Monster::monsterScale( float x, float y, float z )
{
	mNode->scale(x, y, z);
}

//Ogre::String Monster::getName()
//{
//	return mName;
//}
//
//void Monster::setName( Ogre::String name )
//{
//	mName = name;
//}

