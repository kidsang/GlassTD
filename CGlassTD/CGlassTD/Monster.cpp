#include "Monster.h"
#include "Cell.h"
Monster::Monster(SceneNode* node)
	:mSpeed(1),
	mSpeedTemp(1),
	/*mPos(Ogre::Vector3(BEGIN_POS_X, 10, BEGIN_POS_Y)),*/
	mBlood(0),
    mFace(Ogre::Vector3(0, 0, 1)),
	mRadius(1),
	mType(),
	mHarmList(),
	mIsDead(false)
{
	mNode = node;
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
	harmCheck(timeSinceLastFrame);
	mNode->setPosition(mNode->getPosition() + direction * timeSinceLastFrame * mSpeed);
	int* mp = new int[256];
	Ogre::Vector2* target = new Ogre::Vector2(Real(10), Real(10));
	Ogre::Vector2* start = new Ogre::Vector2(Real(2), Real(1));
	
}

float Monster::getBlood(void)
{
	return mBlood;
}
void Monster::setBlood(int mBlood)
{
	this->mBlood = mBlood;
}
std::string Monster::getType(void)
{
	return mType;
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

float Monster::getRadius()
{
	return mRadius;
}

void Monster::monsterScale( float x, float y, float z )
{
	mNode->scale(x, y, z);
}

void Monster::harmCheck(float timeSinceLastFrame)
{
	/// 火属性伤害时间到，属性伤害消失
	if(mHarmList.fireHarmTime < 0)
	{
		mHarmList.fireHarm = 0;
		mHarmList.fireHarmTime = FIRE_HARM_TIME;
	}
	/// 冰属性伤害时间到，属性伤害消失
	if(mHarmList.iceHarmTime < 0)
	{
		mHarmList.iceHarm = 0;
		mHarmList.iceHarmTime = ICE_HARM_TIME;
		mSpeed = mSpeedTemp;
	}
	/// 火属性伤害运作
	if(mHarmList.fireHarm != 0)
	{
		mBlood -= mHarmList.fireHarm;
		mHarmList.fireHarmTime -= timeSinceLastFrame;
	}
	/// 冰属性伤害运作
	if(mHarmList.iceHarm != 0)
	{
		mSpeed = mSpeedTemp * ICE_HARM_SPEED;
		mHarmList.iceHarmTime -= timeSinceLastFrame;
	}

	if(mHarmList.beCaught == true)
	{	
		mBlood = 0;
	}

	if(mHarmList.isOnSpikeweed)
	{
		mBlood -= mHarmList.spikeweedHarm;
	}

	if(mHarmList.isInSwamp)
	{
		mSpeed = mSpeedTemp * mHarmList.swampHarm;
	}
	else 
	{
		mSpeed = mSpeedTemp;
	}

	/// 判断是否死亡
	if(mBlood < 0 || mBlood == 0)
	{
		mIsDead = true;
	}

}

bool Monster::isMonsterDead()
{
	return mIsDead;
}

void Monster::setHitByFire()
{
	mHarmList.fireHarm = FIRE_HARM_BLOOD;
}

void Monster::setHitByIce()
{
	mHarmList.iceHarm = ICE_HARM_SPEED;
}

void Monster::setBeCaughtByTrap()
{
	mHarmList.beCaught = true;
}

void Monster::setInsideSpikeweed()
{
    mHarmList.isOnSpikeweed = true;
}

void Monster::setOutsideSpikeweed()
{
	mHarmList.isOnSpikeweed = false;
}

void Monster::setInsideSwamp()
{
	mHarmList.isInSwamp = false;
}

void Monster::setOutsideSwamp()
{
	mHarmList.isInSwamp = false;
}

void Monster::setSpeed( float speed )
{
	mSpeed = speed;
	mSpeedTemp = speed;
}

void Monster::setRadius( float radius )
{
	mRadius = radius;
}

void Monster::setType( std::string type )
{
	mType = type;
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


Monster* MonsterFactory::createInstance(SceneManager* sceneMgr)
{
	Ogre::SceneNode* monsterNode = sceneMgr->getRootSceneNode()->createChildSceneNode();
	Ogre::Entity* entity = sceneMgr->createEntity(mParams["mesh"]);
	monsterNode->attachObject(entity);
	Monster* mon;
	mon = new Monster(monsterNode);
	if (mParams.find("radius") != mParams.end())
		mon->setRadius((float)atof(mParams["radius"].c_str()));

	if (mParams.find("blood") != mParams.end())
		mon->setBlood((float)atof(mParams["blood"].c_str()));

	if (mParams.find("speed") != mParams.end())
		mon->setSpeed((float)atof(mParams["speed"].c_str()));

	if (mParams.find("spell") != mParams.end())
		mon->setType((mParams["spell"].c_str()));
	return mon;
}

std::string MonsterFactory::getType()
{
	return mType;
}
