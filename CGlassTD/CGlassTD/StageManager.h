#ifndef __StageManager_h_
#define __StageManager_h_


#include "BaseApplication.h"
class Stage;

/// ÎèÌ¨¹ÜÀíÆ÷
/// @author: LiaoNanhao
class StageManager
{
public:
	StageManager(Ogre::SceneManager* pSceneManager);
	~StageManager(void);

	void runStage();

	void setStage(Stage* pStage);
	Stage* getStage() const;

private:
	Stage* mpCurrentStage;
	Ogre::SceneManager* mpSceneManager;
};


#endif