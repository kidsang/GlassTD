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

	/// �����Թ���ͼ
	const int mapWidth = 20;
	const int mapHeight = 20;
	int iMap[mapHeight *mapWidth] =
	{
		1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
		0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0,
		0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0,
		0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		};
	mMaze = new Maze(pSceneManager, iMap, mapWidth, mapHeight);

	/// ����һ��monster������
	mMonsterManager = MonsterManager::getMonsterManager();
	

}


StagePass1::~StagePass1(void)
{
	// ɾ����
	delete mCannon;
	// ɾ���ڵ�
	for (auto iter = mBulletList.begin(); iter != mBulletList.end(); ++iter)
		delete (*iter);
	// ɾ���Թ�
	delete mMaze;
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
	/// MonsterManager* monsterMgr = MonsterManager::getMonsterManager();
	/// ��������
	mMonsterManager->monsterGenerate(mpSceneManager, timeSinceLastFrame);
	/// ���������б�
	std::list<Monster*> monsterList = mMonsterManager->getMonstersList();
	for (auto iter = monsterList.begin(); iter != monsterList.end(); ++iter)
	{	
		(*iter)->addTimeToAnimation(timeSinceLastFrame);
		(*iter)->go(timeSinceLastFrame, Vector3(0, 0, 10));
	}
	for (auto iter = mBulletList.begin(); iter != mBulletList.end(); ++iter)
		(*iter)->fly(timeSinceLastFrame, Vector3(0, -10, 0));
}
