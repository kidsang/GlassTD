#ifndef __BulletManager_h_
#define __BulletManager_h_

#include "Bullet.h"
#include "List.hpp"

class BulletManager
{
private:
	MyList<Bullet*> mBulletList;

public:
	BulletManager(void);
	~BulletManager(void);

	void add(Bullet* bullet);
	void fly(float timeSinceLastFrame, const Ogre::Vector3& gravity);
	std::vector<NameValueList> getAndRemoveExplodedBullets(float floor);
};


#endif

