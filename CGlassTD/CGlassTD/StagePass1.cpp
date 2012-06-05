#include "StagePass1.h"
#include "TestBullet.h"
#include <OgreLogManager.h>

StagePass1::StagePass1(Ogre::SceneManager* sceneManager, StageManager* stageManager)
	: Stage(sceneManager, stageManager),
	mGravity(Vector3(0, -200, 0))
{
	// 新增cannon
	SceneNode* node = sceneManager->getRootSceneNode()->createChildSceneNode();
	Entity* cannon = sceneManager->createEntity("cannon.mesh");
	node->attachObject((MovableObject*)cannon);
	node->setPosition(0, 200, 550);
	mCannon = new Cannon(node, cannon);
	// 给cannon增加炮弹
	mCannon->addBulletFactory(new TestBulletFactory());

	/// 加载迷宫地图
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

	/// 新增一个monster管理器
	mMonsterManager = MonsterManager::getMonsterManager();

	/// 改变镜头视角
	//mCamera->lookAt(Vector3(0, 0, -100s));//lookat 貌似没用
	mCamera->setPosition(Vector3(0, 1000, 1000));
	mCamera->setDirection(-mCamera->getPosition());

	/// 设置天空盒
	//mSceneManager->setSkyBox(true, "Examples/EveSpaceSkyBox");
}


StagePass1::~StagePass1(void)
{
	// 删除炮
	delete mCannon;
	// 删除炮弹
	for (auto iter = mBulletList.begin(); iter != mBulletList.end(); ++iter)
		delete (*iter);
	// 删除迷宫
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
	/// 产生怪物
	mMonsterManager->monsterGenerate(mSceneManager, timeSinceLastFrame);
	/// 遍历怪物列表
	std::list<Monster*> monsterList = mMonsterManager->getMonstersList();
	for (auto iter = monsterList.begin(); iter != monsterList.end(); ++iter)
		(*iter)->go(timeSinceLastFrame, Vector3(0, 0, 10));
	/// 使炮弹飞行
	for (auto iter = mBulletList.begin(); iter != mBulletList.end(); ++iter)
		(*iter)->fly(timeSinceLastFrame, Vector3(0, -200, 0));
}
