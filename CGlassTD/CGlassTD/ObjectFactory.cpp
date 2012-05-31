#include "ObjectFactory.h"


ObjectFactory::ObjectFactory(void)
{
}


ObjectFactory::~ObjectFactory(void)
{
}

Ogre::Entity* ObjectFactory::getEntity( SceneManager* sceneManager,Ogre::String mesh,Ogre::String name )
{
	return sceneManager->createEntity(name,mesh);

}

Ogre::Entity* ObjectFactory::getEntity( Ogre::SceneManager* sceneManager,Ogre::String mesh )
{
	return sceneManager->createEntity(mesh);
}

Ogre::SceneNode* ObjectFactory::getSceneNode( Ogre::SceneManager* sceneManager,Ogre::Entity* entity )
{
	SceneNode* sceneNode = sceneManager->getRootSceneNode()->createChildSceneNode();
	sceneNode->attachObject((MovableObject*)entity);
	return sceneNode;
}

Ogre::SceneNode* ObjectFactory::getSceneNode( Ogre::SceneNode* parentNode,Ogre::Entity* entity )
{
	SceneNode* sceneNode = parentNode->createChildSceneNode();
	sceneNode->attachObject((MovableObject*)entity);
	return sceneNode;
}

Ogre::SceneNode* ObjectFactory::getSceneNode( Ogre::SceneManager* sceneManager,Ogre::Entity* entity,Ogre::String nodeName )
{
	SceneNode* sceneNode = sceneManager->getRootSceneNode()->createChildSceneNode(nodeName);
	sceneNode->attachObject((MovableObject*)entity);
	return sceneNode;
}

Ogre::SceneNode* ObjectFactory::getSceneNode( Ogre::SceneNode* parentNode,Ogre::Entity* entity,Ogre::String nodeName )
{
	SceneNode* sceneNode = parentNode->createChildSceneNode(nodeName);
	sceneNode->attachObject((MovableObject*)entity);
	return sceneNode;
}

