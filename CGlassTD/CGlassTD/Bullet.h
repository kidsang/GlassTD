#ifndef Bullet_h__
#define Bullet_h__

#include <OgreVector3.h>
#include <OgreSceneManager.h>
using namespace Ogre;

#include "Common.h"

/// 子弹的基类
/// 其他类型的奇葩子弹继承自这个类
class Bullet
{
private:
	/// 速度
	Vector3 mVelocity;
	/// 位移
	Vector3 mPosition;;
	/// 重力加速度
	float mGravity;

	/// 该炮弹的节点
	SceneNode* mNode;
	/// 该炮弹的模型
	Entity* mEntity;

public:
	/// 构造函数
	/// @param node 子弹的节点
	/// @param entity 子弹的实体
	Bullet(SceneNode* node, Entity* entity);
	virtual ~Bullet(void);

	/// 发射炮弹
	/// @param position 发射初始位置
	/// @param velocity 发射初速度
	/// @param gravity 环境重力
	void fire(Vector3 position, Vector3 velocity, float gravity)
	{

	}



	// Get/Set
public:
	/// 获取炮弹的质量属性
	/// 由子类提供
	virtual float getMass() = 0;

};


/// 炮弹工厂类
class BulletFactory
{
	/// 创建一个子弹的实例
	/// @param mgr 场景管理类
	/// @param args 创建子类需要用到的参数
	/// @return 返回创建好的子类，如果失败则返回NULL
	virtual Bullet* createInstance(SceneManager* mgr, NameValueList args) = 0;

	/// 返回工厂的类型
	virtual std::string getType() = 0;
};


#endif // Bullet_h__