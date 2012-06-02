#include "Cell.h"

Cell::Cell(void)
{

}

Cell::Cell(Ogre::SceneManager* sceneManager, Ogre::SceneNode* parentNode,int state,int maxContain,Position& pos )
	:mState(state),mMaxContain(maxContain)
{
	this->mEntity = ObjectFactory::createEntity(sceneManager,"cubess.mesh");
	int x = this->mEntity->getBoundingBox().getSize().x;
	int z = this->mEntity->getBoundingBox().getSize().z;
	this->mSceneNode = ObjectFactory::createSceneNode(parentNode,this->mEntity, Vector3(Real(x * pos.getX()),Real(0), Real(z * pos.getZ())));
	if(state == 0)
	{
		this->mSceneNode->setVisible(false);
	}
	this->mPos = pos;
}


Cell::~Cell(void)
{
}

bool Cell::isContain(Monster& monster)
{
	return true;
}

int Cell::getContain()
{
	return mMaxContain - mState;
}

int Cell::getHeight()
{
	return this->mEntity->getBoundingBox().getSize().y;
}
