#include "TestBullet.h"
#include <OgreSceneNode.h>


TestBullet::TestBullet(SceneNode* node, Entity* entity)
	: Bullet(node, entity)
{
}


TestBullet::~TestBullet(void)
{
}

const float TestBullet::getMass()
{
	return 1;
}

TestBullet* TestBulletFactory::createInstance(SceneManager* mgr)
{
	SceneNode* node = mgr->getRootSceneNode()->createChildSceneNode();
	node->setScale(0.1f, 0.1f, 0.1f);
	Entity* entity = mgr->createEntity("sphere10.mesh");
	node->attachObject((MovableObject*)entity);
	return new TestBullet(node, entity);
}

std::string TestBulletFactory::getType()
{
	return "testbullet";
}
