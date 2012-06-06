#include "StagePass1.h"
#include <OgreLogManager.h>
#include "ParamParser.h"

StagePass1::StagePass1(Ogre::SceneManager* sceneManager, StageManager* stageManager)
	: Stage(sceneManager, stageManager),
	mGravity(Vector3(0, -200, 0))
{
	// ����cannon
	ParamParser cannonParser= ParamParser("CannonDefine.xml");
	cannonParser.parse();
	cannonParser.moveToFirst();
	NameValueList* cannonParams = cannonParser.getNext(); 
	SceneNode* node = sceneManager->getRootSceneNode()->createChildSceneNode();
	Entity* cannon = sceneManager->createEntity((*cannonParams)["mesh"]);
	node->attachObject((MovableObject*)cannon);
	mCannon = new Cannon(node, cannon);
	if (cannonParams->find("material") != cannonParams->end())
		cannon->setMaterialName((*cannonParams)["material"]);
	std::vector<std::string> nums;
	if (cannonParams->find("position") != cannonParams->end())
	{
		nums = mysplit((*cannonParams)["position"]);
		node->setPosition((float)atof(nums[0].c_str()), (float)atof(nums[1].c_str()), (float)atof(nums[2].c_str()));
	}
	if (cannonParams->find("strength") != cannonParams->end())
		mCannon->setFireStrength((float)(atof((*cannonParams)["strength"].c_str())));
	if (cannonParams->find("colddown") != cannonParams->end())
		mCannon->setColdDown((float)(atof((*cannonParams)["colddown"].c_str())));
	if (cannonParams->find("offset") != cannonParams->end())
	{
		nums = mysplit((*cannonParams)["offset"]);
		mCannon->setFireOffset(Vector3((float)atof(nums[0].c_str()), (float)atof(nums[1].c_str()), (float)atof(nums[2].c_str())));
	}
	// ��̨?
	SceneNode* node1 = sceneManager->getRootSceneNode()->createChildSceneNode();
	Entity* fort = sceneManager->createEntity("fort.mesh");
	node1->attachObject((MovableObject*)fort);
	node1->setPosition(0, 200, 550);

	// ��cannon�����ڵ�
	ParamParser bulletParser = ParamParser("BulletDefine.xml");
	bulletParser.parse();
	bulletParser.moveToFirst();
	while (bulletParser.hasNext())
		mCannon->addBulletFactory(new BulletFactory(*bulletParser.getNext()));
	//mCannon->addBulletFactory(new BulletFactory());

	/// �����Թ���ͼ
	/*const int mapWidth = 16;
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
		};*/
	ParamParser mazeParser = ParamParser("MazeDefine.xml");
	mazeParser.parse();
	mazeParser.moveToFirst();
	NameValueList* mazeParams = mazeParser.getNext();
	int mapWidth = 2;
	int mapHeight = 2;
	if (mazeParams->find("width") != mazeParams->end())
		mapWidth = atoi((*mazeParams)["width"].c_str());
	if (mazeParams->find("height") != mazeParams->end())
		mapHeight = atoi((*mazeParams)["height"].c_str());
	int size = mapHeight * mapWidth;
	int* map = new int[size]();
	if (mazeParams->find("map") != mazeParams->end())
	{
		nums = mysplit((*mazeParams)["map"]);
		for (int i=0; i<size; i++)
			map[i] = atoi(nums[i].c_str());
	}	
	mMaze = new Maze(sceneManager, map, mapWidth, mapHeight);

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
	//mBulletList.clear();
	// ɾ���Թ�
	delete mMaze;
}

void StagePass1::onKeyPressed( const OIS::KeyEvent &arg )
{
	if (arg.key == OIS::KC_SPACE)
	{
		Bullet* bullet = mCannon->fire(mSceneManager);
		if (bullet)
			mBulletManager.add(bullet);
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
{/*
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
	}*/
	mBulletManager.fly(timeSinceLastFrame, mGravity);
	mMonsterManager->updateState(
		mBulletManager.getAndRemoveExplodedBullets(mMaze->getHorizon()),
		timeSinceLastFrame
		);
}
