#ifndef TestBullet_h__
#define TestBullet_h__

#include "Bullet.h"

/// 测试用炮弹类
class TestBullet : public Bullet
{
public:
	TestBullet(SceneNode* node, Entity* entity);
	~TestBullet(void);

	virtual float getMass();

};

/// 测试炮弹工厂类
class TestBulletFactory : public BulletFactory
{
public:
	virtual Bullet* createInstance( SceneManager* mgr, NameValueList args );

	virtual std::string getType();

};

#endif // TestBullet_h__

