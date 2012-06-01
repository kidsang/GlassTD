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

	// ��̨�ĳ�ʼ����
	virtual void built();

	// ���¼�����Ӧ
	virtual void onKeyPressed(const OIS::KeyEvent &arg);
	virtual void onMouseMoved(const OIS::MouseEvent &arg);
	virtual void onMousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id);
	virtual void onMouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id);

protected:
	virtual void jumpToNextStage();
};
#endif
