#ifndef __LevelStage_h_
#define __LevelStage_h_

#include <vector>
using std::vector;
#include "Stage.h"
#include "Step.h"

class LevelStage : public Stage
{
public:
	/// ���캯��
	LevelStage(Ogre::SceneManager* sceneManager, StageManager* stageManager);

	/// ��������
	virtual ~LevelStage();

	/// ��ؿ�����Ӳ���
	/// @note Step�����ⲿ�����������ⲿ����Ҫ�ͷ����ǣ���������ʱ���ͷ���ЩStep
	void pushStep(Step* step);

	/// ���õ�i������Ϊ��ʼ����
	/// @note Ӧ��ֻ�ɿ�ܵ���
	void setStartStep(unsigned i);

	/// �����������߼�
	/// @param timeSinceLastFrame ����һ֡���������ŵ�ʱ��
	/// @note �������ÿһ֡���ã��������ÿһ֡���߼�
	/// @note Ӧ��ֻ�ɿ�ܵ���
	void run(float timeSinceLastFrame);

	// ���¼�����Ӧ
	/// ���¼��̴����˺���
	/// @param arg �¼�����Ϣ
	/// @note Ӧ��ֻ�ɿ�ܵ���
	void onKeyPressed(const OIS::KeyEvent &arg);

	/// ����ƶ������˺���
	/// @param arg �¼�����Ϣ
	/// @note Ӧ��ֻ�ɿ�ܵ���
	void onMouseMoved(const OIS::MouseEvent &arg);

	/// ������괥���˺���
	/// @param arg �¼�����Ϣ
	/// @param id �ĸ�����
	/// @note Ӧ��ֻ�ɿ�ܵ���
	void onMousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id);

	/// �ͷ���괥���˺���
	/// @param arg �¼�����Ϣ
	/// @param id �ĸ�����
	/// @note Ӧ��ֻ�ɿ�ܵ���
	void onMouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id);


protected:
	/// ������i������
	void jumpToStep(unsigned i);

protected:
	unsigned mCurrentStep;
	vector< Step* > mSteps;
};


#endif