#ifndef __TempStage_h_
#define __TempStage_h_

#include "Stage.h"
#include "Cell.h"
#include "Position.h"
#include "Maze.h"

class TempStage : public Stage
{
public:
	TempStage(Ogre::SceneManager* pSceneManager, StageManager* pStageManager);
	~TempStage(void);

	// 舞台的初始构建
	virtual void built();

	// 对事件的响应
	virtual void onKeyPressed(const OIS::KeyEvent &arg);
	virtual void onMouseMoved(const OIS::MouseEvent &arg);
	virtual void onMousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id);
	virtual void onMouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id);

protected:
	virtual void jumpToNextStage();
};
#endif
