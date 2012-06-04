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

	for(int j = 0; j < width; ++j)
	{
		for(int i = 0; i < height; ++i)
		{
			this->pZones[j * width + i] = Cell(sceneManager, mSceneNode, new Ogre::Vector2(Real(i),Real(j)), map[j * width + i]);
		}
	}
	mSceneNode->setScale(Ogre::Vector3(0.1f));
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
		this->pMapInfo[i] = 4;
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
