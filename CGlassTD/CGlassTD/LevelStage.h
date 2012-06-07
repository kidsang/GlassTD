#ifndef __LevelStage_h_
#define __LevelStage_h_

#include <vector>
using std::vector;
#include "Stage.h"
#include "Step.h"

class LevelStage : public Stage
{
public:
	/// 构造函数
	LevelStage(Ogre::SceneManager* sceneManager, StageManager* stageManager);

	/// 析构函数
	virtual ~LevelStage();

	/// 向关卡里添加步骤
	/// @note Step类由外部创建，但是外部不需要释放它们，该类销毁时会释放这些Step
	void pushStep(Step* step);

	/// 设置第i个步骤为开始步骤
	/// @note 应该只由框架调用
	void setStartStep(unsigned i);

	/// 场景的运行逻辑
	/// @param timeSinceLastFrame 从上一帧到现在流逝的时间
	/// @note 这个函数每一帧调用，处理的是每一帧的逻辑
	/// @note 应该只由框架调用
	void run(float timeSinceLastFrame);

	// 对事件的响应
	/// 按下键盘触发此函数
	/// @param arg 事件的信息
	/// @note 应该只由框架调用
	void onKeyPressed(const OIS::KeyEvent &arg);

	/// 鼠标移动触发此函数
	/// @param arg 事件的信息
	/// @note 应该只由框架调用
	void onMouseMoved(const OIS::MouseEvent &arg);

	/// 按下鼠标触发此函数
	/// @param arg 事件的信息
	/// @param id 哪个按键
	/// @note 应该只由框架调用
	void onMousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id);

	/// 释放鼠标触发此函数
	/// @param arg 事件的信息
	/// @param id 哪个按键
	/// @note 应该只由框架调用
	void onMouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id);


protected:
	/// 跳到第i个步骤
	void jumpToStep(unsigned i);

protected:
	unsigned mCurrentStep;
	vector< Step* > mSteps;
};


#endif