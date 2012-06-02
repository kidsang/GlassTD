#include "OrdinaryMonster.h"

OrdinaryMonster::OrdinaryMonster()
{
	mSpeed = LOW_SPEED;
}

OrdinaryMonster::OrdinaryMonster( Ogre::SceneManager* sceneMgr, Ogre::SceneNode* parentNode, Ogre::String mesh, Ogre::String name)
{
	mSpeed = LOW_SPEED;
	mMesh = mesh;
	mName = name;
	this->mNode = ObjectFactory::createSceneNode(parentNode,ObjectFactory::createEntity(sceneMgr, mesh, name), Ogre::Vector3(Real(mPos.x),Real(0), Real(mPos.z)));
}

OrdinaryMonster::OrdinaryMonster( Ogre::SceneManager* sceneMgr, Ogre::SceneNode* parentNode, Ogre::String mesh )
{
	mSpeed = LOW_SPEED;
	mMesh = mesh;
	this->mNode = ObjectFactory::createSceneNode(parentNode,ObjectFactory::createEntity(sceneMgr, mesh), Ogre::Vector3(Real(mPos.x),Real(0), Real(mPos.z)));

}

OrdinaryMonster::~OrdinaryMonster()
{

}