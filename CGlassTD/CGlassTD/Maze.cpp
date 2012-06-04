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

	int halfWidth = mWidth / 2;
	int halfHeight = mHeight / 2;
	for(int j = -halfWidth; j < halfWidth; ++j)
	{
		for(int i = -halfHeight; i < halfHeight; ++i)
		{
			this->pZones[(i + halfWidth) * mWidth + j + halfHeight] = Cell(sceneManager, mSceneNode, map[(i + halfWidth) * mWidth + j + halfHeight], 10, new Ogre::Vector2(Real(i),Real(j)) );
		}
	}
	mSceneNode->setScale(Ogre::Vector3(0.1f));
	this->horizon = this->pZones[0].getHeight() / 2;
}


Maze::~Maze(void)
{
	delete this->pMapInfo;
}

int* Maze::getMazeInfo()
{
	for(int i = 0; i < mWidth * mHeight; ++i)
	{
		this->pMapInfo[i] = this->pZones[i].getContain();
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
