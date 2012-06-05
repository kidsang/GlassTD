#include "StagePass1.h"
#include "TestBullet.h"
#include <OgreLogManager.h>

StagePass1::StagePass1(Ogre::SceneManager* sceneManager, StageManager* stageManager)
	: Stage(sceneManager, stageManager),
	mGravity(Vector3(0, -200, 0))
{
	// ����cannon
	SceneNode* node = sceneManager->getRootSceneNode()->createChildSceneNode();
	Entity* cannon = sceneManager->createEntity("cannon.mesh");
	node->attachObject((MovableObject*)cannon);
	node->setPosition(0, 200, 550);
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
	mMaze = new Maze(sceneManager, iMap, mapWidth, mapHeight);

	/// ����һ��monster������
	mMonsterManager = MonsterManager::getMonsterManager();

	/// �ı侵ͷ�ӽ�
	//mCamera->lookAt(Vector3(0, 0, -100s));//lookat ò��û��
	mCamera->setPosition(Vector3(0, 1000, 1000));
	mCamera->setDirection(-mCamera->getPosition());

	/// ������պ�
	//mSceneManager->setSkyBox(true, "Examples/EveSpaceSkyBox");
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
		Bullet* bullet = mCannon->fire(mSceneManager);
		if (bullet)
			mBulletList.push_back(bullet);
	}
}

void StagePass1::onMouseMoved( const OIS::MouseEvent &arg )
{
	mCannon->rotate(-arg.state.X.rel, arg.state.Y.rel);
	//char buffX[255], buffY[255];
	//LogManager::getSingletonPtr()->logMessage(std::string("--->") + itoa(arg.state.X.rel,buffX,10) + "," + itoa(arg.state.Y.rel,buffY,10));
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
	mMonsterManager->monsterGenerate(mSceneManager, timeSinceLastFrame);
	/// ���������б�
	std::list<Monster*> monsterList = mMonsterManager->getMonstersList();
	for (auto iter = monsterList.begin(); iter != monsterList.end(); ++iter)
		(*iter)->go(timeSinceLastFrame, Vector3(0, 0, 10));
	/// ʹ�ڵ�����
	for (auto iter = mBulletList.begin(); iter != mBulletList.end(); ++iter)
		(*iter)->fly(timeSinceLastFrame, Vector3(0, -200, 0));
}
