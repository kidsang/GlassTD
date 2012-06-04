#include "Stage.h"

Stage::Stage(Ogre::SceneManager* sceneManager, StageManager* stageManager)
	: mSceneManager(sceneManager), mStageManager(stageManager)
{
	mCamera = mSceneManager->getCamera("PlayerCam");
}

Stage::~Stage(void)
{
}

void Stage::jumpToNextStage(Stage* nextStage)
{
	mStageManager->setStage(nextStage);
	delete this;
}