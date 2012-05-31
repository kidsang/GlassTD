#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <string.h>
using namespace Ogre;
using namespace std;

#ifndef __ObjectFactory_h_
#define __ObjectFactory_h_

class ObjectFactory
{
public:
	ObjectFactory(void);
	~ObjectFactory(void);
	static Ogre::Entity getEntity(Ogre::SceneManager* sceneManager,String mesh,String name);
	static Ogre::Entity getEntity(Ogre::SceneManager* sceneManager,String mesh);
	static Ogre::SceneNode getSceneNode(Ogre::SceneManager* sceneManager,Ogre::Entity* entity);
	static Ogre::SceneNode getSceneNode(Ogre::SceneNode* parentNode,Ogre::Entity* entity);
};
#endif


