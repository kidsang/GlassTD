#include "BulletManager.h"


BulletManager::BulletManager(void)
{
}


BulletManager::~BulletManager(void)
{
	mBulletList.start();
	while (mBulletList.forward())
	{
		delete mBulletList.getData();
	}
	mBulletList.clear();
}

void BulletManager::add( Bullet* bullet )
{

}

void BulletManager::fly( float timeSinceLastFrame, const Ogre::Vector3& gravity )
{

}

std::vector<Bullet> BulletManager::getAndRemoveExplodedBullets(float floor)
{
	return std::vector<Bullet>();
}
