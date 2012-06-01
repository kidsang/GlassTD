#ifndef __TestStage_h_
#define __TestStage_h_

#include "Stage.h"

/// ���ڲ��Ե���̨��
/// @author: LiaoNanhao
class TestStage : public Stage
{
public:
	TestStage(Ogre::SceneManager* pSceneManager, StageManager* pStageManager);
	~TestStage(void);

	// ���¼�����Ӧ
	virtual void onKeyPressed(const OIS::KeyEvent &arg);
	virtual void onMouseMoved(const OIS::MouseEvent &arg);
	virtual void onMousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id);
	virtual void onMouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id);

};


#endif