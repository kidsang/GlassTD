#include "OrdinaryMonster.h"

OrdinaryMonster::OrdinaryMonster()
{
	
}

OrdinaryMonster::OrdinaryMonster( Ogre::SceneManager* sceneMgr, Ogre::SceneNode* parentNode, Position& pos, Ogre::String mesh, Ogre::String name)
{
	mMesh = mesh;
	mName = name;
	this->mNode = ObjectFactory::createSceneNode(parentNode,ObjectFactory::createEntity(sceneMgr, mesh, name), Ogre::Vector3(Real(pos.getX() * 60 + 30),Real(0), Real(pos.getZ() * 60.0 + 30)));
}

OrdinaryMonster::OrdinaryMonster( Ogre::SceneManager* sceneMgr, Ogre::SceneNode* parentNode, Position& pos, Ogre::String mesh )
{
	mMesh = mesh;
	this->mNode = ObjectFactory::createSceneNode(parentNode,ObjectFactory::createEntity(sceneMgr, mesh), Ogre::Vector3(Real(pos.getX() * 60 + 30),Real(0), Real(pos.getZ() * 60.0 + 30)));

}

OrdinaryMonster::~OrdinaryMonster()
{

}