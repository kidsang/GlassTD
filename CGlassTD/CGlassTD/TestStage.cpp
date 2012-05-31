#include "TestStage.h"

TestStage::TestStage(Ogre::SceneManager* pSceneManager, StageManager* pStageManager)
	: Stage(pSceneManager, pStageManager)
{
	Ogre::Entity* ogreHead = mpSceneManager->createEntity("Head", "ogrehead.mesh");

	Ogre::SceneNode* headNode = mpSceneManager->getRootSceneNode()->createChildSceneNode();
	headNode->attachObject(ogreHead);

	// Set ambient light
	mpSceneManager->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));

	// Create a light
	Ogre::Light* l = mpSceneManager->createLight("MainLight");
	l->setPosition(20,80,50);
}

TestStage::~TestStage()
{
}

void TestStage::onKeyPressed(const OIS::KeyEvent &arg)
{
}

void TestStage::onMouseMoved(const OIS::MouseEvent &arg)
{
}

void TestStage::onMousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
}

void TestStage::onMouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
}