#ifndef TestBullet_h__
#define TestBullet_h__

#include "Bullet.h"

/// 测试用炮弹类
class TestBullet : public Bullet
{
public:
	/// 构造函数
	/// @param node 子弹场景节点
	/// @param entity 子弹模型
	TestBullet(SceneNode* node, Entity* entity);
	~TestBullet(void);

	/// 获取该类型子弹的质量
	virtual const float getMass();

};

/// 测试炮弹工厂类
class TestBulletFactory : public BulletFactory
{
public:
	/// 创建一个子弹的实例
	/// @param mgr 场景管理类
	/// @param args 创建子类需要用到的参数
	/// @return 返回创建好的子类，如果失败则返回NULL
	virtual TestBullet* createInstance( SceneManager* mgr, NameValueList args );

	/// 返回工厂的类型
	virtual std::string getType();

};

#endif // TestBullet_h__

