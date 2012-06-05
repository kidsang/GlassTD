#ifndef TestBullet_h__
#define TestBullet_h__

#include "Bullet.h"

/// �������ڵ���
class TestBullet : public Bullet
{
public:
	/// ���캯��
	/// @param node �ӵ������ڵ�
	/// @param entity �ӵ�ģ��
	TestBullet(SceneNode* node, Entity* entity);
	~TestBullet(void);

	/// ��ȡ�������ӵ�������
	virtual const float getMass();

	/// ��ȡ�ڵ����˺�ֵ
	virtual const float getDamage();

	/// ��ȡ�ڵ��ı�ը�뾶
	virtual const float getRange();

	/// ��ȡ�ڵ���Ԫ������(��ͨ��������)
	virtual const std::string getSpell();
};

/// �����ڵ�������
class TestBulletFactory : public BulletFactory
{
public:
	/// ����һ���ӵ���ʵ��
	/// @param mgr ����������
	/// @param args ����������Ҫ�õ��Ĳ���
	/// @return ���ش����õ����࣬���ʧ���򷵻�NULL
	virtual TestBullet* createInstance(SceneManager* mgr);

	/// ���ع���������
	virtual std::string getType();

};

#endif // TestBullet_h__

