#include "Cannon.h"

Cannon::Cannon(SceneNode* node, Entity* entity)
	: mNode(node), mEntity(entity),
	mCurrentBullet(0),mFireOffset(Vector3(0.f)), mFireStrength(0), mColdDown(0)
{
	/// 翻转大炮朝向
	mNode->setOrientation(0, 0, 1, 0);
	/// 初始化计时器
	mLastTime = clock();
}

Cannon::~Cannon()
{
	// 清空炮弹工厂列表
	for (auto iter = mBulletFactoryList.begin(); iter != mBulletFactoryList.end(); ++iter)
		delete (*iter);
}

void Cannon::addBulletFactory( BulletFactory* bulletFactory )
{
	mBulletFactoryList.push_back(bulletFactory);
}

Bullet* Cannon::fire(SceneManager* mgr)
{
	if (clock() < mLastTime + mColdDown * 1000)
		return NULL;
	// 计算发射方向
	Vector3 xAxis, yAxis, zAxis;
	mNode->getOrientation().ToAxes(xAxis, yAxis, zAxis);
	// 获取当前类型的炮弹工厂
	BulletFactory* bf = mBulletFactoryList.at(mCurrentBullet);
	// 判断当前弹药是否还有余量
	if (bf->getAmmoCount() <= 0)
		return NULL;
	// 根据当前所选类型创建炮弹
	Bullet* bul = bf->createInstance(mgr);
	bul->fire(mNode->getPosition() + mFireOffset,zAxis * mFireStrength);

	mLastTime = clock();
	bf->setAmmoCount(bf->getAmmoCount() - 1);

	return bul;
}

void Cannon::changeBullet( unsigned int index )
{
	if (index >= mBulletFactoryList.size())
		return;
	mCurrentBullet = index;
}

void Cannon::changeBullet()
{
	mCurrentBullet = (mCurrentBullet + 1) % mBulletFactoryList.size();
}

void Cannon::rotate( int yaw, int pitch )
{
	mNode->yaw(Ogre::Radian(yaw / 400.f), Ogre::Node::TS_WORLD);
	mNode->pitch(Ogre::Radian(pitch / 400.f), Ogre::Node::TS_WORLD);
}
