#include "TestBullet.h"


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

Bullet* TestBulletFactory::createInstance( SceneManager* mgr, NameValueList args )
{
	throw std::exception("The method or operation is not implemented.");
}

std::string TestBulletFactory::getType()
{
	return "testbullet";
}
