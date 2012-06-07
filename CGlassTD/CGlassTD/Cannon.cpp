#include "Cannon.h"

Cannon::Cannon(SceneNode* node, Entity* entity)
	: mNode(node), mEntity(entity),
	mCurrentBullet(0),mFireOffset(Vector3(0.f)), mFireStrength(0), mColdDown(0)
{
	/// ��ת���ڳ���
	mNode->setOrientation(0, 0, 1, 0);
	/// ��ʼ����ʱ��
	mLastTime = clock();
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
	if (clock() < mLastTime + mColdDown * 1000)
		return NULL;
	// ���㷢�䷽��
	Vector3 xAxis, yAxis, zAxis;
	mNode->getOrientation().ToAxes(xAxis, yAxis, zAxis);
	// ���ݵ�ǰ��ѡ���ʹ����ڵ�
	Bullet* bul = mBulletFactoryList.at(mCurrentBullet)->createInstance(mgr);
	bul->fire(mNode->getPosition() + mFireOffset,zAxis * mFireStrength);
	mLastTime = clock();
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
