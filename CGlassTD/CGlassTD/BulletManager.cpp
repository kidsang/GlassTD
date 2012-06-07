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

std::vector<NameValueList> BulletManager::getAndRemoveExplodedBullets(float floor)
{
	std::vector<NameValueList> exploded;

	mBulletList.start();
	while (mBulletList.forward())
		if (mBulletList.getData()->getPosition().y < floor)
		{
			Bullet* bul = mBulletList.getData();
			// 将爆炸节点的信息储存
			NameValueList nvl;
			nvl.insert(std::make_pair("damage", convertToString(bul->getDamage())));
			nvl.insert(std::make_pair("range", convertToString(bul->getDamage())));
			nvl.insert(std::make_pair("spell", bul->getSpell()));
			nvl.insert(std::make_pair("position",
				convertToString(bul->getPosition().x)
				+ " " + convertToString(bul->getPosition().y)
				+ " " + convertToString(bul->getPosition().z)));
			exploded.push_back(nvl);
			// 删除爆炸的节点
			delete bul;
			mBulletList.deleteCurrentNode();
		}

	return exploded;
}
