#include "Position.h"


Position::Position(void)
{
}

Position::Position( int x, int z )
	:mX(x),mZ(z)
{
	
}


Position::~Position(void)
{
	
}

int Position::getX()
{
	return this->mX;
}

int Position::getZ()
{
	return this->mZ;
}

void Position::setX( int x )
{
	this->mX = x;
}

void Position::setZ( int z )
{
	this->mZ = z;
}
