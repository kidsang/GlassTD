#include "CGlassTD.h"
#include "Common.h"

//-------------------------------------------------------------------------------------
CGlassTD::CGlassTD(void)
{
}
//-------------------------------------------------------------------------------------
CGlassTD::~CGlassTD(void)
{
	// Çå¿Õ
	for (auto iter = mBulletFactoryMap.begin(); iter != mBulletFactoryMap.end(); ++iter)
		delete (*iter).second;

	// ²âÊÔ
	delete mTestBullet;
}

//-------------------------------------------------------------------------------------
void CGlassTD::createScene(void)
{
    /*Ogre::Entity* ogreHead = mSceneMgr->createEntity("Head", "sphere.mesh");

    Ogre::SceneNode* headNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
    headNode->attachObject(ogreHead);*/

    // Set ambient light
    mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));

    // Create a light
    Ogre::Light* l = mSceneMgr->createLight("MainLight");
    l->setPosition(20,80,50);

	// ²âÊÔby kid
	BulletFactory* bf;
	bf = new TestBulletFactory();
	mBulletFactoryMap.insert(std::make_pair(bf->getType(), bf));
	TestBulletFactory* tbf = static_cast<TestBulletFactory*>(bf);
	mTestBullet = tbf->createInstance(mSceneMgr, NameValueList());
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
