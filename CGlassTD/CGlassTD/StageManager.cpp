#include "StageManager.h"
#include "Stage.h"

StageManager::StageManager(Ogre::SceneManager* pSceneManager)
	: mpCurrentStage(NULL), mpSceneManager(pSceneManager)
{
}

StageManager::~StageManager(void)
{
	if (mpCurrentStage != NULL)
	{
		delete mpCurrentStage;
	}
}

void StageManager::setStage(Stage* pStage)
{
	mpCurrentStage = pStage;
}

Stage* StageManager::getStage() const
{
	return mpCurrentStage;
}