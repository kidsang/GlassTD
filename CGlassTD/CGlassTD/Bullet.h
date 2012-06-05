#ifndef Bullet_h__
#define Bullet_h__

/**
 * 文件：Bullet
 * 日期：2012/05/31
 * 作者：kid
 */

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
	Vector3 mPosition;
	/// 重力
	//Vector3 mGravity;
	/// 该炮弹是否已经被发射
	bool mIsFired;

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
	void fire(const Vector3& position, const Vector3& velocity);

	/// 炮弹飞行函数
	/// @param t 上一帧到这一帧的运行时间，now - last
	/// @note 该函数将由某个管理子弹的类在主循环中调用
	///		  调用一次就向前飞一点
	void fly(float t, const Vector3& gravity);

	// Get/Set
public:
	/// 获取炮弹的质量属性
	/// 由子类提供
	virtual const float getMass() = 0;

};


/// 炮弹工厂类
class BulletFactory
{
public:
	/// 创建一个子弹的实例
	/// @param mgr 场景管理类
	/// @param args 创建子类需要用到的参数
	/// @return 返回创建好的子类，如果失败则返回NULL
	virtual Bullet* createInstance(SceneManager* mgr) = 0;

	/// 返回工厂的类型
	virtual std::string getType() = 0;
};


#endif // Bullet_h__