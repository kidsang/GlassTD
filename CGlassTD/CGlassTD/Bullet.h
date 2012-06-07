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
	Vector3 mPosition;;
	/// 该炮弹是否已经被发射
	bool mIsFired;

	/// 该炮弹的节点
	SceneNode* mNode;
	/// 该炮弹的模型
	Entity* mEntity;

	/// 炮弹的质量
	float mMass;
	/// 炮弹的伤害值
	float mDamage;
	/// 炮弹的伤害范围
	float mRange;
	/// 炮弹的元素类型
	std::string mSpell;

	/// 炮弹删除自己需要用到，真tmd蛋疼
	SceneManager* mSceneManager;

public:
	/// 构造函数
	/// @param node 子弹的节点
	/// @param entity 子弹的实体
	Bullet(SceneManager* manager, SceneNode* node, Entity* entity);
	~Bullet(void);

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
	/// 获取炮弹的元素类型
	const std::string& getSpell()
	{
		return mSpell;
	}

	/// 设置炮弹的元素类型
	void setSpell(const std::string& spell)
	{
		mSpell = spell;
	}

	/// 获取炮弹当前位置
	const Vector3& getPosition()
	{
		return mNode->getPosition();
	}

	/// 获取炮弹的质量属性
	const float getMass()
	{
		return mMass;
	}

	/// 设置炮弹的质量属性
	void setMass(float mass)
	{
		mMass = mass;
	}
	
	/// 获取炮弹的伤害值
	const float getDamage()
	{
		return mDamage;
	}

	/// 设置炮弹的伤害值
	void setDamage(float damage)
	{
		mDamage = damage;
	}

	/// 获取炮弹的爆炸半径
	const float getRange()
	{
		return mRange;
	}

	/// 设置炮弹的爆炸半径
	void setRange(float range)
	{
		mRange = range;
	}

	/// 获取炮弹的元素类型(普通，冰，火)
	//const std::string getSpell()
};


/// 炮弹工厂类
class BulletFactory
{
private:
	/// 工厂类所需要的参数列表
	NameValueList mParams;
	/// 工厂的类型，其实就是所生产的炮弹种类的名称
	std::string mType;
	/// 炮弹的余量。
	int mAmmo;

public:
	/// 构造函数
	/// @param params 构造子弹所需要的属性参数
	BulletFactory(NameValueList params);
	~BulletFactory()
	{
	}

	/// 创建一个子弹的实例
	/// @param mgr 场景管理类
	/// @return 返回创建好的子类，如果失败则返回NULL
	Bullet* createInstance(SceneManager* mgr);

	/// 返回工厂的类型
	const std::string& getType()
	{
		return mType;
	}

	/// 返回弹药余量
	int getAmmoCount()
	{
		return mAmmo;
	}

	/// 设置弹药余量
	void setAmmoCount(int ammo)
	{
		mAmmo = ammo;
	}
};


#endif // Bullet_h__