#include "LevelStage.h"

LevelStage::LevelStage(Ogre::SceneManager* sceneManager, StageManager* stageManager)
	: Stage(sceneManager, stageManager), mCurrentStep(-1)
{
	mSteps.clear();
}

LevelStage::~LevelStage()
{
	unsigned size = mSteps.size();
	for (unsigned i = 0; i < size; ++i )
	{
		if (mSteps[i] != NULL)
		{
			delete mSteps[i];
			mSteps[i] = NULL;
		}
	}
}

void LevelStage::pushStep(Step* step)
{
	mSteps.push_back(step);
}

void LevelStage::setStartStep(unsigned i)
{
	this->jumpToStep(i);
}

void LevelStage::run(float timeSinceLastFrame)
{
	mSteps[mCurrentStep]->run(timeSinceLastFrame);
}

void LevelStage::onKeyPressed(const OIS::KeyEvent &arg)
{
	mSteps[mCurrentStep]->onKeyPressed(arg);
}

void LevelStage::onMouseMoved(const OIS::MouseEvent &arg)
{
	mSteps[mCurrentStep]->onMouseMoved(arg);
}

void LevelStage::onMousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
	mSteps[mCurrentStep]->onMousePressed(arg, id);
}

void LevelStage::onMouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
	mSteps[mCurrentStep]->onMouseReleased(arg, id);
}


void LevelStage::jumpToStep(unsigned i)
{
	mCurrentStep = i;
}