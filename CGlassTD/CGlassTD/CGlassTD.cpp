#include "CGlassTD.h"
#include "Common.h"

//-------------------------------------------------------------------------------------
CGlassTD::CGlassTD(void)
{
}
//-------------------------------------------------------------------------------------
CGlassTD::~CGlassTD(void)
{
	// «Âø’◊”µØπ§≥ß
	for (auto iter = mBulletFactoryMap.begin(); iter != mBulletFactoryMap.end(); ++iter)
		delete (*iter).second;
	// «Âø’◊”µØ
	for (auto iter = mBulletList.begin(); iter != mBulletList.end(); ++iter)
		delete (*iter);
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

	// ≤‚ ‘by kid
	BulletFactory* bf;
	bf = new TestBulletFactory();
	mBulletFactoryMap.insert(std::make_pair(bf->getType(), bf));
	TestBulletFactory* tbf = static_cast<TestBulletFactory*>(bf);
	mTestBullet = tbf->createInstance(mSceneMgr, NameValueList());
	mBulletList.push_back(mTestBullet);
	mTestBullet->fire(Ogre::Vector3(0.f), Ogre::Vector3(4, 0, 0));
}

bool CGlassTD::frameRenderingQueued( const Ogre::FrameEvent& evt )
{
	BaseApplication::frameRenderingQueued(evt);

	// ≤‚ ‘≈⁄µØ
	//auto iter = mBulletFactoryMap.find("testbullet");
	//TestBullet* tb = static_cast<TestBullet*>((*iter).second->createInstance(mSceneMgr, NameValueList()));
	//tb->fire(Ogre::Vector3(0.f), Ogre::Vector3(4, 0, 0));
	//mBulletList.push_back(tb);
	// ≤‚ ‘≈⁄µØ
	for (auto iter = mBulletList.begin(); iter != mBulletList.end(); ++iter)
		(*iter)->fly(evt.timeSinceLastFrame, Ogre::Vector3(0, -10, 0));

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
