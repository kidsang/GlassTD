#ifndef TestBullet_h__
#define TestBullet_h__

#include "Bullet.h"

/// �������ڵ���
class TestBullet : public Bullet
{
public:
	TestBullet(SceneNode* node, Entity* entity);
	~TestBullet(void);

	virtual float getMass();

};

/// �����ڵ�������
class TestBulletFactory : public BulletFactory
{
public:
	virtual Bullet* createInstance( SceneManager* mgr, NameValueList args );

	virtual std::string getType();

};

#endif // TestBullet_h__

