#include "Bullet.h"
#include <OgreEntity.h>

Bullet::Bullet(SceneNode* node, Entity* entity)
	: mNode(node), mEntity(entity),
	mIsFired(false),
	mMass(1), mDamage(0), mRange(0)
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

Bullet* BulletFactory::createInstance( SceneManager* mgr )
{
	SceneNode* node = mgr->getRootSceneNode()->createChildSceneNode();
	node->setScale(0.1f, 0.1f, 0.1f);
	Entity* entity = mgr->createEntity(mParams["mesh"]);
	if (mParams.find("material") != mParams.end())
		entity->setMaterialName(mParams["material"]);
	node->attachObject((MovableObject*)entity);

	Bullet* bullet = new Bullet(node, entity);

	if (mParams.find("mass") != mParams.end())
		bullet->setMass((float)atof(mParams["mass"].c_str()));

	if (mParams.find("damage") != mParams.end())
		bullet->setDamage((float)atof(mParams["damage"].c_str()));

	if (mParams.find("range") != mParams.end())
		bullet->setRange((float)atof(mParams["range"].c_str()));

	return bullet;
}

std::string BulletFactory::getType()
{
	return mType;
}
