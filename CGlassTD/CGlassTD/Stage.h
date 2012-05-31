#ifndef __Stage_h_
#define __Stage_h_


#include "StageManager.h"

/// ��̨�����࣬���𳡾��Ĺ���
/// @author: LiaoNanhao
class Stage
{
public:
	Stage(Ogre::SceneManager* pSceneManager, StageManager* pStageManager);
	virtual ~Stage(void);

	// ��̨�ĳ�ʼ����
	virtual void built() = 0;

	// ���¼�����Ӧ
	virtual void onKeyPressed(const OIS::KeyEvent &arg) = 0;
	virtual void onMouseMoved(const OIS::MouseEvent &arg) = 0;
	virtual void onMousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id) = 0;
	virtual void onMouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id) = 0;

protected:
	virtual void jumpToNextStage() = 0;

	Ogre::SceneManager* mpSceneManager;
	StageManager* mpStageManager; // ���г�����������ָ�룬�Ա�ʵ��״̬ģʽ
};


#endif
