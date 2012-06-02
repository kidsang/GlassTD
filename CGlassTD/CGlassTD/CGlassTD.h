#ifndef __CGlassTD_h_
#define __CGlassTD_h_

#include <hash_map>
#include <string>
#include "BaseApplication.h"
#include "../res/resource.h"
#include "Bullet.h"
#include "StageManager.h"
#include "MonsterManager.h"
#include "OrdinaryMonster.h"
/**
 * 文件：CGlassTD
 * 日期：2012/05/31
 * 作者：kid
 */

class CGlassTD : public BaseApplication
{
public:
    CGlassTD(void);
    virtual ~CGlassTD(void);

	/// 子弹工厂类列表
	/// 测试用
	typedef std::hash_map<std::string, BulletFactory*> BulletFactoryMap;
	BulletFactoryMap mBulletFactoryMap;

protected:
    virtual void createScene(void);

	// 帧消息
	virtual bool frameRenderingQueued( const Ogre::FrameEvent& evt );
/*
	// 键盘鼠标消息
	virtual bool keyPressed( const OIS::KeyEvent &arg );
    virtual bool keyReleased( const OIS::KeyEvent &arg );
    virtual bool mouseMoved( const OIS::MouseEvent &arg );
    virtual bool mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
    virtual bool mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
*/
private:
	StageManager* mpStageManager;

};

#endif // #ifndef __CGlassTD_h_
