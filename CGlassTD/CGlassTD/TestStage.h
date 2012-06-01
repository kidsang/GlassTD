#ifndef __TestStage_h_
#define __TestStage_h_

#include "Stage.h"

/// 用于测试的舞台类
/// @author: LiaoNanhao
class TestStage : public Stage
{
public:
	TestStage(Ogre::SceneManager* pSceneManager, StageManager* pStageManager);
	~TestStage(void);

	// 对事件的响应
	virtual void onKeyPressed(const OIS::KeyEvent &arg);
	virtual void onMouseMoved(const OIS::MouseEvent &arg);
	virtual void onMousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id);
	virtual void onMouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id);

};


#endif