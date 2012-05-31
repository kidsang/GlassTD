#ifndef __CGlassTD_h_
#define __CGlassTD_h_

#include <hash_map>
#include <string>
#include "BaseApplication.h"
#include "../res/resource.h"
#include "Bullet.h"
#include "TestBullet.h"

/**
 * �ļ���CGlassTD
 * ���ڣ�2012/05/31
 * ���ߣ�kid
 */

class CGlassTD : public BaseApplication
{
public:
    CGlassTD(void);
    virtual ~CGlassTD(void);

	/// �ӵ��������б�
	/// ������
	typedef std::hash_map<std::string, BulletFactory*> BulletFactoryMap;
	BulletFactoryMap mBulletFactoryMap;
	/// �����ӵ�
	/// ������
	TestBullet* mTestBullet;
	/// �ӵ��б�
	/// ������
	typedef std::deque<TestBullet*> BulletList;
	BulletList mBulletList;

protected:
    virtual void createScene(void);

	virtual bool frameRenderingQueued( const Ogre::FrameEvent& evt );

};

#endif // #ifndef __CGlassTD_h_
