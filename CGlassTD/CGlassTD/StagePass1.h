#ifndef StagePass1_h__
#define StagePass1_h__

#include "Stage.h"
#include "Bullet.h"
#include "Cannon.h"

/// ��һ�س���
class StagePass1 : public Stage
{
	typedef std::deque<Bullet*> BulletList;

private:
	/// ��
	Cannon* mCannon;
	/// �����д��ڵ��ڵ����б�
	BulletList mBulletList;

public:
	StagePass1(Ogre::SceneManager* pSceneManager, StageManager* pStageManager);
	~StagePass1(void);

	virtual void onKeyPressed( const OIS::KeyEvent &arg );

	virtual void onMouseMoved( const OIS::MouseEvent &arg );

	virtual void onMousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id );

	virtual void onMouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id );

	virtual void run( float timeSinceLastFrame );

};

#endif // StagePass1_h__

