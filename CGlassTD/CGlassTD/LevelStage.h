#ifndef __LevelStage_h_
#define __LevelStage_h_

#include "Stage.h"

class LevelStage : public Stage
{
public:
	/// ���캯��
	LevelStage(Ogre::SceneManager* sceneManager, StageManager* stageManager);

	/// ��������
	virtual ~LevelStage();

	/// �����������߼�
	/// @param timeSinceLastFrame ����һ֡���������ŵ�ʱ��
	/// @note �������ÿһ֡���ã��������ÿһ֡���߼�
	void run(float timeSinceLastFrame);

	// ���¼�����Ӧ
	/// ���¼��̴����˺���
	/// @param arg �¼�����Ϣ
	void onKeyPressed(const OIS::KeyEvent &arg);

	/// ����ƶ������˺���
	/// @param arg �¼�����Ϣ
	void onMouseMoved(const OIS::MouseEvent &arg);

	/// ������괥���˺���
	/// @param arg �¼�����Ϣ
	/// @param id �ĸ�����
	void onMousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id);

	/// �ͷ���괥���˺���
	/// @param arg �¼�����Ϣ
	/// @param id �ĸ�����
	void onMouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id);


protected:
	/// ��ǰ�Ľ׶Σ�Ŀǰֻ�������׶Σ���һ�׶Σ����֣��͵ڶ��׶Σ���֣�
	static enum Step
	{
		FIRST_STEP, SECOND_STEP
	};
	int mCurrentStep;

	/// ���õ�ǰ�׶�
	void setCurrentStep(Step step);

	/// ��һ�׶ε�run����
	virtual void step1Run(float timeSinceLastFrame) = 0;

	/// ��һ�׶ε�onKeyPressed����
	virtual void step1OnKeyPressed(const OIS::KeyEvent &arg) = 0;

	/// ��һ�׶ε�onMouseMoved����
	virtual void step1OnMouseMoved(const OIS::MouseEvent &arg) = 0;

	/// ��һ�׶ε�onMousePressed����
	virtual void step1OnMousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id) = 0;

	/// ��һ�׶ε�onMouseReleased����
	virtual void step1OnMouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id) = 0;


	/// �ڶ��׶ε�run����
	virtual void step2Run(float timeSinceLastFrame) = 0;

	/// �ڶ��׶ε�onKeyPressed����
	virtual void step2OnKeyPressed(const OIS::KeyEvent &arg) = 0;

	/// �ڶ��׶ε�onMouseMoved����
	virtual void step2OnMouseMoved(const OIS::MouseEvent &arg) = 0;

	/// �ڶ��׶ε�onMousePressed����
	virtual void step2OnMousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id) = 0;

	/// �ڶ��׶ε�onMouseReleased����
	virtual void step2OnMouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id) = 0;
};


#endif