#include "LevelStage.h"

LevelStage::LevelStage(Ogre::SceneManager* sceneManager, StageManager* stageManager)
	: Stage(sceneManager, stageManager), mCurrentStep(FIRST_STEP)
{
}

LevelStage::~LevelStage()
{
}

void LevelStage::setCurrentStep(LevelStage::Step step)
{
	mCurrentStep = step;
}

void LevelStage::run(float timeSinceLastFrame)
{
	if (mCurrentStep == FIRST_STEP)
	{
		this->step1Run(timeSinceLastFrame);
	}
	else if (mCurrentStep == SECOND_STEP)
	{
		this->step2Run(timeSinceLastFrame);
	}
}

void LevelStage::onKeyPressed(const OIS::KeyEvent &arg)
{
	if (mCurrentStep == FIRST_STEP)
	{
		this->step1OnKeyPressed(arg);
	}
	else if (mCurrentStep == SECOND_STEP)
	{
		this->step2OnKeyPressed(arg);
	}
}

void LevelStage::onMouseMoved(const OIS::MouseEvent &arg)
{
	if (mCurrentStep == FIRST_STEP)
	{
		this->step1OnMouseMoved(arg);
	}
	else if (mCurrentStep == SECOND_STEP)
	{
		this->step2OnMouseMoved(arg);
	}
}

void LevelStage::onMousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
	if (mCurrentStep == FIRST_STEP)
	{
		this->step1OnMousePressed(arg, id);
	}
	else if (mCurrentStep == SECOND_STEP)
	{
		this->step2OnMousePressed(arg, id);
	}
}

void LevelStage::onMouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
	if (mCurrentStep == FIRST_STEP)
	{
		this->step1OnMouseReleased(arg, id);
	}
	else if (mCurrentStep == SECOND_STEP)
	{
		this->step2OnMouseReleased(arg, id);
	}
}