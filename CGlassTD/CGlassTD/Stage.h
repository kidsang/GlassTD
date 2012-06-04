#ifndef __Stage_h_
#define __Stage_h_


#include "StageManager.h"
#include <OgreCamera.h>

/// ��̨�����࣬���𳡾��Ĺ���
/// @author: LiaoNanhao
class Stage
{
public:
	/// ���캯��
	/// @param pSceneManager ������������ָ��
	/// @param pStageManager ��̨��������ָ��
	Stage(Ogre::SceneManager* sceneManager, StageManager* stageManager);

	/// ��������
	virtual ~Stage(void);

	/// �����������߼�
	/// @param timeSinceLastFrame ����һ֡���������ŵ�ʱ��
	virtual void run(float timeSinceLastFrame) = 0;

	// ���¼�����Ӧ
	/// ���¼��̴����˺���
	/// @param arg �¼�����Ϣ
	virtual void onKeyPressed(const OIS::KeyEvent &arg) = 0;

	/// ����ƶ������˺���
	/// @param arg �¼�����Ϣ
	virtual void onMouseMoved(const OIS::MouseEvent &arg) = 0;

	/// ������괥���˺���
	/// @param arg �¼�����Ϣ
	/// @param id �ĸ�����
	virtual void onMousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id) = 0;

	/// �ͷ���괥���˺���
	/// @param arg �¼�����Ϣ
	/// @param id �ĸ�����
	virtual void onMouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id) = 0;

protected:
	/// ��ת����һ����̨���ڲ�����
	/// @param pNextStage ��һ����̨��ָ��
	void jumpToNextStage(Stage* nextStage);

	/// ����������
	Ogre::SceneManager* mSceneManager;
	/// ���г�����������ָ�룬�Ա�ʵ��״̬ģʽ
	StageManager* mStageManager; 
	/// �����
	Ogre::Camera* mCamera;
};


#endif

