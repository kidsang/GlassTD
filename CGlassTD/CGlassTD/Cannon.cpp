#include "Cannon.h"

Cannon::Cannon(SceneNode* node, Entity* entity)
	: mNode(node), mEntity(entity),
	mCurrentBullet(0), mFireStrenth(10)
{

}

Cannon::~Cannon()
{
	// ����ڵ������б�
	for (auto iter = mBulletFactoryList.begin(); iter != mBulletFactoryList.end(); ++iter)
		delete (*iter);
}

void Cannon::addBulletFactory( BulletFactory* bulletFactory )
{
	mBulletFactoryList.push_back(bulletFactory);
}

Bullet* Cannon::fire(SceneManager* mgr)
{
	// ���㷢�䷽��
	Vector3 xAxis, yAxis, zAxis;
	mNode->getOrientation().ToAxes(xAxis, yAxis, zAxis);
	// ���ݵ�ǰ��ѡ���ʹ����ڵ�
	Bullet* bul = mBulletFactoryList.at(mCurrentBullet)->createInstance(mgr);
	bul->fire(mNode->getPosition(),zAxis * mFireStrenth);
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
