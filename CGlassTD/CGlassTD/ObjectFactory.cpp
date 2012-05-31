#include "ObjectFactory.h"


ObjectFactory::ObjectFactory(void)
{
}


ObjectFactory::~ObjectFactory(void)
{
}

Ogre::Entity* ObjectFactory::createEntity( SceneManager* sceneManager,Ogre::String mesh,Ogre::String name )
{
	return sceneManager->createEntity(name,mesh);

}

Ogre::Entity* ObjectFactory::createEntity( Ogre::SceneManager* sceneManager,Ogre::String mesh )
{
	return sceneManager->createEntity(mesh);
}


Ogre::SceneNode* ObjectFactory::createSceneNode( Ogre::SceneNode* parentNode,Ogre::Entity* entity )
{
	SceneNode* sceneNode = parentNode->createChildSceneNode();
	sceneNode->attachObject((MovableObject*)entity);
	return sceneNode;
}


Ogre::SceneNode* ObjectFactory::createSceneNode( Ogre::SceneNode* parentNode,Ogre::Entity* entity,Ogre::Vector3& vector )
{
	SceneNode* sceneNode = parentNode->createChildSceneNode(vector);
	sceneNode->attachObject((MovableObject*)entity);
	return sceneNode;
}


