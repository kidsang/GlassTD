#ifndef __Step_h_
#define __Step_h_

#include <OISEvents.h>
#include <OISInputManager.h>
#include <OISKeyboard.h>
#include <OISMouse.h>

class LevelStage;

/// 关卡LevelStage中需要的步骤，同个关卡的所有步骤共享数据，但是行为不同
/// @author: LiaoNanhao
/// @note: 此类体系使用状态模式封装，禁止析构从外面传进来的数据
class Step
{
public:
	/// 构造函数
	/// @param levelStage 关卡的LevelStage类的指针，实现状态模式必须
	Step(LevelStage* levelStage);

	/// 析构函数，只析构局部数据
	virtual ~Step();

	// --------------------

	/// 场景的运行逻辑
	/// @param timeSinceLastFrame 从上一帧到现在流逝的时间
	/// @note 这个函数每一帧调用，处理的是每一帧的逻辑
	virtual void run(float timeSinceLastFrame) = 0;

	// 对事件的响应
	/// 按下键盘触发此函数
	/// @param arg 事件的信息
	virtual void onKeyPressed(const OIS::KeyEvent &arg) = 0;

	/// 鼠标移动触发此函数
	/// @param arg 事件的信息
	virtual void onMouseMoved(const OIS::MouseEvent &arg) = 0;

	/// 按下鼠标触发此函数
	/// @param arg 事件的信息
	/// @param id 哪个按键
	virtual void onMousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id) = 0;

	/// 释放鼠标触发此函数
	/// @param arg 事件的信息
	/// @param id 哪个按键
	virtual void onMouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id) = 0;
	
protected:
	LevelStage* mLevelStage;
};


#endif