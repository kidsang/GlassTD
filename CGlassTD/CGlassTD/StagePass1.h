#ifndef StagePass1_h__
#define StagePass1_h__

#include "Stage.h"
#include "Bullet.h"
#include "Cannon.h"
#include "Maze.h"
#include "MonsterManager.h"
#include "BulletManager.h"

#include "List.hpp"

/// 第一关场景
class StagePass1 : public Stage
{
private:
	/// 炮
	Cannon* mCannon;
	/// 场景中存在的炮弹的列表
	//MyList<Bullet*> mBulletList;
	/// 迷宫
	Maze* mMaze;
	/// 怪物序列管理器
	MonsterManager* mMonsterManager;

	BulletManager mBulletManager;
	

	/// 环境重力
	Vector3 mGravity;

public:
	/// 构造函数
	/// @param pSceneManager 场景管理器的指针
	/// @param pStageManager 舞台管理器的指针
	StagePass1(Ogre::SceneManager* sceneManager, StageManager* stageManager);
	~StagePass1(void);

	// 对事件的响应
	/// 按下键盘触发此函数
	/// @param arg 事件的信息
	virtual void onKeyPressed(const OIS::KeyEvent &arg);

	/// 鼠标移动触发此函数
	/// @param arg 事件的信息
	virtual void onMouseMoved(const OIS::MouseEvent &arg);

	/// 按下鼠标触发此函数
	/// @param arg 事件的信息
	/// @param id 哪个按键
	virtual void onMousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id);

	/// 释放鼠标触发此函数
	/// @param arg 事件的信息
	/// @param id 哪个按键
	virtual void onMouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id);

	/// 场景的运行逻辑
	/// @param timeSinceLastFrame 从上一帧到现在流逝的时间
	virtual void run( float timeSinceLastFrame );

};

#endif // StagePass1_h__

