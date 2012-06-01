#include "CGlassTD.h"
#include "TestBullet.h"
#include "OrdinaryMonster.h"
//-------------------------------------------------------------------------------------
CGlassTD::CGlassTD(void)
{
}
//-------------------------------------------------------------------------------------
CGlassTD::~CGlassTD(void)
{
	// ���
	for (auto iter = mBulletFactoryMap.begin(); iter != mBulletFactoryMap.end(); ++iter)
		delete (*iter).second;

	if (mpStageManager != NULL)
	{
		delete mpStageManager;
	}
}

//-------------------------------------------------------------------------------------
void CGlassTD::createScene(void)
{
	/*Ogre::SceneNode* monsterNode = mSceneMgr->getRootSceneNode();
	OrdinaryMonster mon(mSceneMgr, monsterNode, Position(10, 10), "ogrehead.mesh", "name");*/
 /*   Ogre::Entity* ogreHead = mSceneMgr->createEntity("Head", "ogrehead.mesh");

    Ogre::SceneNode* headNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
    headNode->attachObject(ogreHead);

    // Set ambient light
    mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));

    // Create a light
    Ogre::Light* l = mSceneMgr->createLight("MainLight");
    l->setPosition(20,80,50);
	*/

	mpStageManager = new StageManager(mSceneMgr);
	mpStageManager->runStage();

	// ����by kid
	BulletFactory* bf;
	bf = new TestBulletFactory();
	mBulletFactoryMap.insert(std::make_pair(bf->getType(), bf));
}

bool CGlassTD::frameRenderingQueued( const Ogre::FrameEvent& evt )
{
	BaseApplication::frameRenderingQueued(evt);

	return true;
}
/*
bool CGlassTD::keyPressed(const OIS::KeyEvent &arg)
{
	Stage* pCurrentStage = mpStageManager->getStage();
	pCurrentStage->onKeyPressed(arg);
	return true;
}

bool CGlassTD::mouseMoved(const OIS::MouseEvent &arg)
{
	Stage* pCurrentStage = mpStageManager->getStage();
	pCurrentStage->onMouseMoved(arg);
	return true;
}

bool CGlassTD::mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
	Stage* pCurrentStage = mpStageManager->getStage();
	pCurrentStage->onMousePressed(arg, id);
	return true;
}

bool CGlassTD::mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
	Stage* pCurrentStage = mpStageManager->getStage();
	pCurrentStage->onMouseReleased(arg, id);
	return true;
}
*/


#include "windows.h"

INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
{
	// Create application object
	CGlassTD app;

	try {
		app.go();
	} catch( Ogre::Exception& e ) {
		MessageBox( NULL, e.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
	}

	return 0;
}
