#ifndef StagePass1_h__
#define StagePass1_h__

#include "Stage.h"
#include "Bullet.h"
#include "Cannon.h"
#include "Maze.h"
#include "MonsterManager.h"
#include "BulletManager.h"

#include "List.hpp"

/// ��һ�س���
class StagePass1 : public Stage
{
private:
	/// ��
	Cannon* mCannon;
	/// �����д��ڵ��ڵ����б�
	//MyList<Bullet*> mBulletList;
	/// �Թ�
	Maze* mMaze;
	/// �������й�����
	MonsterManager* mMonsterManager;

	BulletManager mBulletManager;
	

	/// ��������
	Vector3 mGravity;

public:
	/// ���캯��
	/// @param pSceneManager ������������ָ��
	/// @param pStageManager ��̨��������ָ��
	StagePass1(Ogre::SceneManager* sceneManager, StageManager* stageManager);
	~StagePass1(void);

	// ���¼�����Ӧ
	/// ���¼��̴����˺���
	/// @param arg �¼�����Ϣ
	virtual void onKeyPressed(const OIS::KeyEvent &arg);

	/// ����ƶ������˺���
	/// @param arg �¼�����Ϣ
	virtual void onMouseMoved(const OIS::MouseEvent &arg);

	/// ������괥���˺���
	/// @param arg �¼�����Ϣ
	/// @param id �ĸ�����
	virtual void onMousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id);

	/// �ͷ���괥���˺���
	/// @param arg �¼�����Ϣ
	/// @param id �ĸ�����
	virtual void onMouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id);

	/// �����������߼�
	/// @param timeSinceLastFrame ����һ֡���������ŵ�ʱ��
	virtual void run( float timeSinceLastFrame );

};

#endif // StagePass1_h__

