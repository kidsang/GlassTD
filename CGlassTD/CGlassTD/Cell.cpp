#include "Cell.h"

Cell::Cell(void)
{

}


Cell::Cell( Ogre::SceneManager* sceneManager,Ogre::SceneNode* parentNode,Ogre::Vector2* pos, CellType type, float harmValue)
{
	this->mHarmValue = harmValue;
	this->mEntity = ObjectFactory::createEntity(sceneManager,"cubess.mesh");
	float x = this->mEntity->getBoundingBox().getSize().x;
	float z = this->mEntity->getBoundingBox().getSize().z;
	this->mSceneNode = ObjectFactory::createSceneNode(parentNode,this->mEntity, Vector3(x * pos->x,Real(0), z * pos->y));
	this->mType = type;
	if(this->mType == FREE)
	{
		this->mSceneNode->setVisible(false);
	}
}

Cell::Cell( Ogre::SceneManager* sceneManager,Ogre::SceneNode* parentNode,Ogre::Vector2* pos,int type, float harmValue)
{
	this->mHarmValue = harmValue;
	this->mEntity = ObjectFactory::createEntity(sceneManager,"cubess.mesh");
	float x = this->mEntity->getBoundingBox().getSize().x;
	float z = this->mEntity->getBoundingBox().getSize().z;
	this->mSceneNode = ObjectFactory::createSceneNode(parentNode,this->mEntity, Vector3(x * pos->x,Real(0), z * pos->y));
	switch(type){
	case 0:
		this->mType = FREE;
		break;
	case 1:
		this->mType = WALL;
		break;
	case 2:
		this->mType = SPIKEWEED;
		break;
	case 3:
		this->mType = SWAMP;
		break;
	default:
		this->mType = FREE;
	}
	if(this->mType == FREE)
	{
		this->mSceneNode->setVisible(false);
	}
}

Cell::~Cell(void)
{
}


CellType Cell::getCellType()
{
	return this->mType;
}

float Cell::getHeight()
{
	return this->mEntity->getBoundingBox().getSize().y;
}

float Cell::getHarmValue()
{
	return this->mHarmValue;
}
