#include "Cell.h"

Cell::Cell(void)
{

}

Cell::Cell(Ogre::SceneManager* sceneManager, Ogre::SceneNode* parentNode,bool state,int maxContain,Position& pos )
	:mState(state),mMaxContain(maxContain)
{
	this->mEntity = ObjectFactory::createEntity(sceneManager,"cell.mesh");
	this->mSceneNode = ObjectFactory::createSceneNode(parentNode,this->mEntity, Vector3(Real(pos.getX() * 60 + 30),Real(0), Real(pos.getZ() * 60.0 + 30)));
	this->mPos = pos;
}


Cell::~Cell(void)
{
}

bool Cell::isContain()
{
	return true;
}

bool Cell::Contain()
{
	return true;
}
