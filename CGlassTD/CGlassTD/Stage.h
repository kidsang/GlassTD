#ifndef __Stage_h_
#define __Stage_h_


#include "StageManager.h"

/// 舞台抽象类，负责场景的管理
/// @author: LiaoNanhao
class Stage
{
public:
	Stage(Ogre::SceneManager* pSceneManager, StageManager* pStageManager);
	virtual ~Stage(void);

	// 对事件的响应
	virtual void onKeyPressed(const OIS::KeyEvent &arg) = 0;
	virtual void onMouseMoved(const OIS::MouseEvent &arg) = 0;
	virtual void onMousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id) = 0;
	virtual void onMouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id) = 0;

protected:
	void jumpToNextStage(Stage* pNextStage);

	Ogre::SceneManager* mpSceneManager;
	StageManager* mpStageManager; // 持有场景管理器的指针，以便实现状态模式
};


#endif

