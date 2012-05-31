#include "Bullet.h"


Bullet::Bullet(SceneNode* node, Entity* entity)
	: mNode(node), mEntity(entity),
	mIsFired(false)
{
}


Bullet::~Bullet(void)
{
}

void Bullet::fire(const Vector3& position, const Vector3& velocity)
{
	mIsFired = true;
	mPosition = position;
	mVelocity = velocity;
}

void Bullet::fly(float t, const Vector3& gravity)
{
	if (!mIsFired)
		return;

	// ¸üÐÂÅÚµ¯Î»ÖÃ
	mVelocity += gravity / getMass() * t;
	mPosition += mVelocity * t;
	mNode->setPosition(mPosition);
}
