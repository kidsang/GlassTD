#include "StagePass1.h"
#include "TestBullet.h"

StagePass1::StagePass1(Ogre::SceneManager* pSceneManager, StageManager* pStageManager)
	: Stage(pSceneManager, pStageManager)
{
	// ÐÂÔöcannon
	SceneNode* node = pSceneManager->getRootSceneNode()->createChildSceneNode();
	Entity* cannon = pSceneManager->createEntity("cube.mesh");
	node->attachObject((MovableObject*)cannon);
	node->setScale(0.1, 0.1, 0.1);
	mCannon = new Cannon(node, cannon);
	// ¸øcannonÔö¼ÓÅÚµ¯
	mCannon->addBulletFactory(new TestBulletFactory());
}


StagePass1::~StagePass1(void)
{
	// É¾³ýÅÚ
	delete mCannon;
	// É¾³ýÅÚµ¯
	for (auto iter = mBulletList.begin(); iter != mBulletList.end(); ++iter)
		delete (*iter);
}

void StagePass1::onKeyPressed( const OIS::KeyEvent &arg )
{
	if (arg.key == OIS::KC_SPACE)
	{
		mBulletList.push_back(mCannon->fire(mpSceneManager));
	}
}

void StagePass1::onMouseMoved( const OIS::MouseEvent &arg )
{
	mCannon->rotate(-arg.state.X.rel, arg.state.Y.rel);
}

void StagePass1::onMousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
}

void StagePass1::onMouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
}

void StagePass1::run( float timeSinceLastFrame )
{
	for (auto iter = mBulletList.begin(); iter != mBulletList.end(); ++iter)
		(*iter)->fly(timeSinceLastFrame, Vector3(0, -10, 0));
}
