#ifndef __Stage_h_
#define __Stage_h_


/// ��̨�����࣬���𳡾��Ĺ���
/// @author: LiaoNanhao
#include "StageManager.h"

class Stage
{
public:
	Stage(Ogre::SceneManager* pSceneManager, StageManager* pStageManager);
	~Stage(void);

	/// ���г���
	virtual bool run() = 0; 

	/// ���¼�����Ӧ
	virtual bool onKeyPressed(const OIS::KeyEvent &arg) = 0;
	virtual bool onMouseMoved(const OIS::MouseEvent &arg) = 0;
	virtual bool onMousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id) = 0;
	virtual bool onMouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id) = 0;

private:
	Ogre::SceneManager* mpSceneManager;
	StageManager* mpStageManager; // ���г�����������ָ�룬�Ա�ʵ��״̬ģʽ
};


#endif

