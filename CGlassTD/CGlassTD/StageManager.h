#ifndef __StageManager_h_
#define __StageManager_h_


#include "BaseApplication.h"
#include "Stage.h"

/// ÎèÌ¨¹ÜÀíÆ÷
/// @author: LiaoNanhao
class StageManager
{
public:
	StageManager(void);
	~StageManager(void);

	bool runStage();

	bool setStage( Stage* pStage );

private:
	Stage* mpCurrentStage;
};


#endif