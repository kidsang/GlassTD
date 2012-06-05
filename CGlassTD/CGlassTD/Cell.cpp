#include "Cell.h"

Cell::Cell(void)
{

}


Cell::Cell( Ogre::SceneManager* sceneManager,Ogre::SceneNode* parentNode,Ogre::Vector2* pos, CellType type)
{
	this->mEntity = ObjectFactory::createEntity(sceneManager,"cubess.mesh");
	int x = this->mEntity->getBoundingBox().getSize().x;
	int z = this->mEntity->getBoundingBox().getSize().z;
	this->mSceneNode = ObjectFactory::createSceneNode(parentNode,this->mEntity, Vector3(x * pos->x,Real(0), z * pos->y));
	this->mType = type;
	if(this->mType == CellType::FREE)
	{
		this->mSceneNode->setVisible(false);
	}
}

Cell::Cell( Ogre::SceneManager* sceneManager,Ogre::SceneNode* parentNode,Ogre::Vector2* pos,int type )
{
	this->mEntity = ObjectFactory::createEntity(sceneManager,"cubess.mesh");
	int x = this->mEntity->getBoundingBox().getSize().x;
	int z = this->mEntity->getBoundingBox().getSize().z;
	this->mSceneNode = ObjectFactory::createSceneNode(parentNode,this->mEntity, Vector3(x * pos->x,Real(0), z * pos->y));
	switch(type){
	case 0:
		this->mType = CellType::FREE;
		break;
	case 1:
		this->mType = CellType::WALL;
		break;
	case 2:
		this->mType = CellType::SPIKEWEED;
		break;
	case 3:
		this->mType = CellType::SWAMP;
		break;
	default:
		this->mType = CellType::FREE;
	}
	if(this->mType == CellType::FREE)
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

int Cell::getHeight()
{
	return this->mEntity->getBoundingBox().getSize().y;
}
