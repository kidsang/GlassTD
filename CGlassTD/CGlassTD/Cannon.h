#ifndef __Cannon_h_
#define __Cannon_h_

#include <vector>
#include "Bullet.h"
#include "OgreQuaternion.h"
#include <time.h>

/// 炮台类
/// @author: LiaoNanhao
class Cannon
{
	typedef std::vector<BulletFactory*> BulletFactoryList;

private:
	/// 炮台所拥有的所有炮弹
	BulletFactoryList mBulletFactoryList;
	/// 当前选择的弹药类型
	unsigned int mCurrentBullet;

	/// 大炮发射力度
	float mFireStrength;
	/// 炮口的位置偏移量
	Vector3 mFireOffset;
	/// 大炮的发射间隔,按秒计算
	float mColdDown;

	/// 上次发射的时间
	clock_t mLastTime;

	/// 大炮的节点
	SceneNode* mNode;
	/// 大炮的模型
	Entity* mEntity;

public:
	Cannon(SceneNode* node, Entity* entity);
	~Cannon();

	/// 向炮台增加一个炮弹工厂
	/// @param bulletFactory 要增加的炮弹工厂
	/// @note 一种炮弹工厂实际上就是某种炮弹，
	///		  可认为是在向炮台增加不同种类的炮弹
	void addBulletFactory(BulletFactory* bulletFactory);

	/// 发射当前装备的炮弹
	/// @return 返回发射的炮弹，如果发射失败(比如cd)则返回NULL
	/// @note 外部的某个管理类应该接手发射出去的炮弹的管理工作，
	///		  比如调用其fly()函数，释放资源等
	Bullet* fire(SceneManager* mgr);

	/// 更改当前装备的炮弹
	/// @param index 第几号炮弹
	/// @note 当传入非法参数时，既不会崩溃，也不提示任何错误
	void changeBullet(unsigned int index);

	/// 切换至下一个武器
	/// @note 会轮转
	void changeBullet();

	/// 修改炮台朝向
	void rotate(int yaw, int pitch);

	// Get/Set
public:
	/// 返回大炮发射力度
	const float getFireStrenth()
	{
		return mFireStrength;
	}

	/// 设置大炮发射力度
	void setFireStrength(float strength)
	{
		mFireStrength = strength;
	}

	/// 返回炮弹发射位置的偏移量(即炮口位置)
	const Vector3& getFireOffset()
	{
		return mFireOffset;
	}

	/// 设置炮弹发射位置的偏移量(即炮口位置)
	void setFireOffset(const Vector3& offset)
	{
		mFireOffset = offset;
	}

	/// 返回大炮发射间隔
	const float getColdDown()
	{
		return mColdDown;
	}

	/// 设置大炮发射间隔
	void setColdDown(float coldDown)
	{
		mColdDown = coldDown;
	}

};


#endif
