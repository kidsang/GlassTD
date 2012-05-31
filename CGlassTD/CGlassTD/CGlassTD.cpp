#include "CGlassTD.h"
#include "TestBullet.h"

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
}

//-------------------------------------------------------------------------------------
void CGlassTD::createScene(void)
{
    Ogre::Entity* ogreHead = mSceneMgr->createEntity("Head", "ogrehead.mesh");

    Ogre::SceneNode* headNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
    headNode->attachObject(ogreHead);

    // Set ambient light
    mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));

    // Create a light
    Ogre::Light* l = mSceneMgr->createLight("MainLight");
    l->setPosition(20,80,50);

	// ����by kid
	BulletFactory* bf;
	bf = new TestBulletFactory();
	mBulletFactoryMap.insert(std::make_pair(bf->getType(), bf));
}

bool CGlassTD::frameRenderingQueued( const Ogre::FrameEvent& evt )
{
	BaseApplication::frameRenderingQueued(evt);

	//
	return true;
}



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
