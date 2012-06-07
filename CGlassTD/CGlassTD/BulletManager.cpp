#include "BulletManager.h"


BulletManager::BulletManager(void)
{
}


BulletManager::~BulletManager(void)
{
	mBulletList.start();
	while (mBulletList.forward())
		delete mBulletList.getData();
	mBulletList.clear();
}

void BulletManager::add( Bullet* bullet )
{
	mBulletList.insertAhead(bullet);
}

void BulletManager::fly( float timeSinceLastFrame, const Ogre::Vector3& gravity )
{
	mBulletList.start();
	while (mBulletList.forward())
		mBulletList.getData()->fly(timeSinceLastFrame, gravity);
}

std::vector<Bullet> BulletManager::getAndRemoveExplodedBullets(float floor)
{
	std::vector<Bullet> exploded;

	mBulletList.start();
	while (mBulletList.forward())
		if (mBulletList.getData()->getPosition().y < floor)
		{
			//exploded.push_back(*mBulletList.getData());
			// Todo:×ª»¯Îªnamevaluelist
			delete mBulletList.getData();
			mBulletList.deleteCurrentNode();
		}

	return exploded;
}
