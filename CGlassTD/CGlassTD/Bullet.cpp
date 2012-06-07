#include "Bullet.h"
#include <OgreEntity.h>

Bullet::Bullet(SceneManager* manager, SceneNode* node, Entity* entity)
	: mSceneManager(manager), mNode(node), mEntity(entity),
	mIsFired(false),
	mMass(1), mDamage(0), mRange(0), mSpell("normal")
{
}


Bullet::~Bullet(void)
{
	// É¾³ýÅÚµ¯mesh
	mNode->detachObject(mEntity);
	delete mEntity;
	// É¾³ýÅÚµ¯µÄ³¡¾°½Úµã
	mNode->getParentSceneNode()->removeAndDestroyChild(mNode->getName());
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

	Bullet* bullet = new Bullet(mgr, node, entity);

	if (mParams.find("mass") != mParams.end())
		bullet->setMass((float)atof(mParams["mass"].c_str()));

	if (mParams.find("damage") != mParams.end())
		bullet->setDamage((float)atof(mParams["damage"].c_str()));

	if (mParams.find("range") != mParams.end())
		bullet->setRange((float)atof(mParams["range"].c_str()));

	if (mParams.find("spell") != mParams.end())
		bullet->setSpell(mParams["spell"]);

	return bullet;
}

BulletFactory::BulletFactory( NameValueList params ) :mParams(params), mType("NormalBullet"), mAmmo(0)
{
	if (params.find("name") != params.end())
		mType = params["name"];
	if (params.find("ammo") != params.end())
		mAmmo = atoi(params["ammo"].c_str());
}
