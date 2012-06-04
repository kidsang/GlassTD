#ifndef __Stage_h_
#define __Stage_h_


#include "StageManager.h"
#include <OgreCamera.h>

/// 舞台抽象类，负责场景的管理
/// @author: LiaoNanhao
class Stage
{
public:
	/// 构造函数
	/// @param pSceneManager 场景管理器的指针
	/// @param pStageManager 舞台管理器的指针
	Stage(Ogre::SceneManager* sceneManager, StageManager* stageManager);

	/// 析构函数
	virtual ~Stage(void);

	/// 场景的运行逻辑
	/// @param timeSinceLastFrame 从上一帧到现在流逝的时间
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
	/// 跳转到下一个舞台，内部调用
	/// @param pNextStage 下一个舞台的指针
	void jumpToNextStage(Stage* nextStage);

	/// 场景管理类
	Ogre::SceneManager* mSceneManager;
	/// 持有场景管理器的指针，以便实现状态模式
	StageManager* mStageManager; 
	/// 摄像机
	Ogre::Camera* mCamera;
};


#endif

