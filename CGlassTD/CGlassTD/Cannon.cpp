#include "Cannon.h"

Cannon::Cannon(SceneNode* node, Entity* entity)
	: mNode(node), mEntity(entity)
{

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
	// 计算发射方向
	Vector3 xAxis, yAxis, zAxis;
	mNode->getOrientation().ToAxes(xAxis, yAxis, zAxis);
	// 根据当前所选类型创建炮弹
	Bullet* bul = mBulletFactoryList.at(mCurrentBullet)->createInstance(mgr);
	bul->fire(mNode->getPosition(),zAxis * mFireStrenth);
	return bul;
}
