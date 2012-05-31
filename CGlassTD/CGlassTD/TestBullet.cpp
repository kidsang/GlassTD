#include "TestBullet.h"
#include <OgreSceneNode.h>


TestBullet::TestBullet(SceneNode* node, Entity* entity)
	: Bullet(node, entity)
{
}


TestBullet::~TestBullet(void)
{
}

float TestBullet::getMass()
{
	throw std::exception("The method or operation is not implemented.");
}

TestBullet* TestBulletFactory::createInstance( SceneManager* mgr, NameValueList args )
{
	SceneNode* node = mgr->getRootSceneNode()->createChildSceneNode();
	node->setScale(0.1f, 0.1f, 0.1f);
	Entity* entity = mgr->createEntity("sphere10.mesh");
	node->attachObject((MovableObject*)entity);
	return new TestBullet(NULL, NULL);
}

std::string TestBulletFactory::getType()
{
	return "testbullet";
}
