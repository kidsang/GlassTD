#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
using namespace Ogre;

#ifndef __ObjectFactory_h_
#define __ObjectFactory_h_

class ObjectFactory
{
public:
	ObjectFactory(void);
	~ObjectFactory(void);
	static Ogre::Entity* getEntity(Ogre::SceneManager* sceneManager,Ogre::String mesh,Ogre::String name);
	static Ogre::Entity* getEntity(Ogre::SceneManager* sceneManager,Ogre::String mesh);
	static Ogre::SceneNode* getSceneNode(Ogre::SceneManager* sceneManager,Ogre::Entity* entity,Ogre::String nodeName);
	static Ogre::SceneNode* getSceneNode(Ogre::SceneNode* parentNode,Ogre::Entity* entity,Ogre::String nodeName);
	static Ogre::SceneNode* getSceneNode(Ogre::SceneManager* sceneManager,Ogre::Entity* entity);
	static Ogre::SceneNode* getSceneNode(Ogre::SceneNode* parentNode,Ogre::Entity* entity);
};
#endif


