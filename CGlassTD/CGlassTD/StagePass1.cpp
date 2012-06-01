#include "StagePass1.h"
#include "TestBullet.h"

StagePass1::StagePass1(Ogre::SceneManager* pSceneManager, StageManager* pStageManager)
	: Stage(pSceneManager, pStageManager)
{
	// ����cannon
	SceneNode* node = pSceneManager->getRootSceneNode()->createChildSceneNode();
	Entity* cannon = pSceneManager->createEntity("cube.mesh");
	node->attachObject((MovableObject*)cannon);
	node->setScale(0.1, 0.1, 0.1);
	mCannon = new Cannon(node, cannon);
	// ��cannon�����ڵ�
	mCannon->addBulletFactory(new TestBulletFactory());
}


StagePass1::~StagePass1(void)
{
	// ɾ����
	delete mCannon;
	// ɾ���ڵ�
	for (auto iter = mBulletList.begin(); iter != mBulletList.end(); ++iter)
		delete (*iter);
}

void StagePass1::onKeyPressed( const OIS::KeyEvent &arg )
{
}

void StagePass1::onMouseMoved( const OIS::MouseEvent &arg )
{
}

void StagePass1::onMousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
}

void StagePass1::onMouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
}

void StagePass1::run( float timeSinceLastFrame )
{
}
