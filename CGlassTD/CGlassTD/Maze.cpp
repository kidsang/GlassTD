#include "Maze.h"
Maze::Maze(void)
{
}

Maze::Maze(SceneManager* sceneManager, int* map, int width, int height)
	: mWidth(width), mHeight(height), mSceneManager(sceneManager), 
	mMap(0)
{	
	this->mSceneNode = sceneManager->getRootSceneNode()->createChildSceneNode("mapSenenNode");
	this->pZones = new Cell[mWidth * mHeight];
	this->pMapInfo = new int[mWidth * mHeight];

	this->mSceneNode->setPosition(Ogre::Vector3(-mWidth / 2.0f * 100, 0, -mHeight / 2.0f * 100));

	for(int j = 0; j < width; ++j)
	{
		for(int i = 0; i < height; ++i)
		{
			this->pZones[j * width + i] = Cell(sceneManager, mSceneNode, new Ogre::Vector2(Real(i),Real(j)), map[j * width + i]);
		}
	}
	this->horizon = this->pZones[1].getHeight() / 2;
}


Maze::~Maze(void)
{
	delete this->pMapInfo;
}

int* Maze::getMazeInfo()
{
	for(int i = 0; i < mWidth * mHeight; ++i)
	{
		this->pMapInfo[i] = this->mMap[i];
	}
	return pMapInfo;
}

bool Maze::isStep( Monster& monster )
{
	return true;
}

int Maze::getHorizon()
{
	return this->horizon;
}

Ogre::Vector2* Maze::getMonsterPos()
{
	return new Vector2(Real(3),Real(0));
}

int Maze::getMapWidth()
{
	return this->mWidth;
}

int Maze::getMapHeight()
{
	return this->mHeight;

}

Ogre::Vector2* Maze::translatePos( Ogre::Vector2* pos )
{
	return new Ogre::Vector2(Real(pos->x - (this->mWidth / 2.0f * 100)), Real(pos->y - (this->mHeight / 2.0f * 100)));
}
