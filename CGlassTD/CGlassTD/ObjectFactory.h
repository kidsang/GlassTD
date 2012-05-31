#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreEntity.h>
using namespace Ogre;

#ifndef __ObjectFactory_h_
#define __ObjectFactory_h_

class ObjectFactory
{
public:
	ObjectFactory(void);
	~ObjectFactory(void);
	static Ogre::Entity* createEntity(Ogre::SceneManager* sceneManager,Ogre::String mesh,Ogre::String name);
	static Ogre::Entity* createEntity(Ogre::SceneManager* sceneManager,Ogre::String mesh);
	static Ogre::SceneNode* createSceneNode(Ogre::SceneNode* parentNode,Ogre::Entity* entity);
	static Ogre::SceneNode* createSceneNode(Ogre::SceneNode* parentNode,Ogre::Entity* entity,Ogre::Vector3& vector);
};


#endif


