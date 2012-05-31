#include "Stage.h"

Stage::Stage(Ogre::SceneManager* pSceneManager, StageManager* pStageManager)
	: mpSceneManager(pSceneManager), mpStageManager(pStageManager)
{
}

Stage::~Stage(void)
{
}

void Stage::jumpToNextStage(Stage* pNextStage)
{
	mpStageManager->setStage(pNextStage);
	delete this;
}