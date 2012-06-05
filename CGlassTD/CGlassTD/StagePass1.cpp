#include "StagePass1.h"
#include <OgreLogManager.h>
#include "ParamParser.h"

StagePass1::StagePass1(Ogre::SceneManager* sceneManager, StageManager* stageManager)
	: Stage(sceneManager, stageManager),
	mGravity(Vector3(0, -200, 0))
{
	// ����cannon
	SceneNode* node = sceneManager->getRootSceneNode()->createChildSceneNode();
	SceneNode* node1 = sceneManager->getRootSceneNode()->createChildSceneNode();
	Entity* cannon = sceneManager->createEntity("cannon.mesh");
	node->attachObject((MovableObject*)cannon);
	node->setPosition(0, 200, 550);
	Entity* fort = sceneManager->createEntity("fort.mesh");
	node1->attachObject((MovableObject*)fort);
	node1->setPosition(0, 200, 550);
	mCannon = new Cannon(node, cannon);
	// ��cannon�����ڵ�
	ParamParser bulletParser = ParamParser("BulletDefine.xml");
	bulletParser.parse();
	bulletParser.moveToFirst();
	while (bulletParser.hasNext())
		mCannon->addBulletFactory(new BulletFactory(*bulletParser.getNext()));
	//mCannon->addBulletFactory(new BulletFactory());

	/// �����Թ���ͼ
	const int mapWidth = 16;
	const int mapHeight = 16;
	int iMap[mapHeight *mapWidth] =
	{
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
		1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 
		1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 
		0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 
		0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 
		0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 
		1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 
		1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 
		1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 
		1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 
		0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 
		0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 
		1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 
		1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 
		};
	mMaze = new Maze(sceneManager, iMap, mapWidth, mapHeight);

	/// ����һ��monster������
	mMonsterManager = MonsterManager::getMonsterManager();

	/// �ı侵ͷ�ӽ�
	//mCamera->lookAt(Vector3(0, 0, -100s));//lookat ò��û��
	mCamera->setPosition(Vector3(0, 2000, 2000));
	mCamera->setDirection(-mCamera->getPosition());

	/// ������պ�
	//mSceneManager->setSkyBox(true, "Examples/EveSpaceSkyBox");
}


StagePass1::~StagePass1(void)
{
	// ɾ����
	delete mCannon;
	// ɾ���ڵ�
	mBulletList.clear();
	// ɾ���Թ�
	delete mMaze;
}

void StagePass1::onKeyPressed( const OIS::KeyEvent &arg )
{
	if (arg.key == OIS::KC_SPACE)
	{
		Bullet* bullet = mCannon->fire(mSceneManager);
		if (bullet)
			mBulletList.insertAhead(bullet);
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
	MyList<Monster*>* monsterList = mMonsterManager->getMonstersList();
	monsterList->start();
	while (monsterList->forward())
	{
		Monster* monster = monsterList->getData();
		
		monster->addTimeToAnimation(timeSinceLastFrame);
		monster->go(timeSinceLastFrame, Vector3(4, 0, 0));
	}
	/// ʹ�ڵ�����
	mBulletList.start();
	while (mBulletList.forward())
	{
		mBulletList.getData()->fly(timeSinceLastFrame, Vector3(0, -200, 0));
	}
}
