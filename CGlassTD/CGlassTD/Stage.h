#ifndef __Stage_h_
#define __Stage_h_


/// 舞台抽象类，负责场景的管理
/// @author: LiaoNanhao
#include "StageManager.h"

class Stage
{
public:
	Stage(Ogre::SceneManager* pSceneManager, StageManager* pStageManager);
	~Stage(void);

	/// 运行场景
	virtual bool run() = 0; 

	/// 对事件的响应
	virtual bool onKeyPressed(const OIS::KeyEvent &arg) = 0;
	virtual bool onMouseMoved(const OIS::MouseEvent &arg) = 0;
	virtual bool onMousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id) = 0;
	virtual bool onMouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id) = 0;

private:
	Ogre::SceneManager* mpSceneManager;
	StageManager* mpStageManager; // 持有场景管理器的指针，以便实现状态模式
};


#endif

