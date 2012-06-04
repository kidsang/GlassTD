#ifndef __LevelStage_h_
#define __LevelStage_h_

#include "Stage.h"

class LevelStage : public Stage
{
public:
	/// 构造函数
	LevelStage(Ogre::SceneManager* sceneManager, StageManager* stageManager);

	/// 析构函数
	virtual ~LevelStage();

	/// 场景的运行逻辑
	/// @param timeSinceLastFrame 从上一帧到现在流逝的时间
	/// @note 这个函数每一帧调用，处理的是每一帧的逻辑
	void run(float timeSinceLastFrame);

	// 对事件的响应
	/// 按下键盘触发此函数
	/// @param arg 事件的信息
	void onKeyPressed(const OIS::KeyEvent &arg);

	/// 鼠标移动触发此函数
	/// @param arg 事件的信息
	void onMouseMoved(const OIS::MouseEvent &arg);

	/// 按下鼠标触发此函数
	/// @param arg 事件的信息
	/// @param id 哪个按键
	void onMousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id);

	/// 释放鼠标触发此函数
	/// @param arg 事件的信息
	/// @param id 哪个按键
	void onMouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id);


protected:
	/// 当前的阶段，目前只有两个阶段，第一阶段（布局）和第二阶段（打怪）
	static enum Step
	{
		FIRST_STEP, SECOND_STEP
	};
	int mCurrentStep;

	/// 设置当前阶段
	void setCurrentStep(Step step);

	/// 第一阶段的run函数
	virtual void step1Run(float timeSinceLastFrame) = 0;

	/// 第一阶段的onKeyPressed函数
	virtual void step1OnKeyPressed(const OIS::KeyEvent &arg) = 0;

	/// 第一阶段的onMouseMoved函数
	virtual void step1OnMouseMoved(const OIS::MouseEvent &arg) = 0;

	/// 第一阶段的onMousePressed函数
	virtual void step1OnMousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id) = 0;

	/// 第一阶段的onMouseReleased函数
	virtual void step1OnMouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id) = 0;


	/// 第二阶段的run函数
	virtual void step2Run(float timeSinceLastFrame) = 0;

	/// 第二阶段的onKeyPressed函数
	virtual void step2OnKeyPressed(const OIS::KeyEvent &arg) = 0;

	/// 第二阶段的onMouseMoved函数
	virtual void step2OnMouseMoved(const OIS::MouseEvent &arg) = 0;

	/// 第二阶段的onMousePressed函数
	virtual void step2OnMousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id) = 0;

	/// 第二阶段的onMouseReleased函数
	virtual void step2OnMouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id) = 0;
};


#endif