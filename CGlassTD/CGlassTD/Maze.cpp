#include "Maze.h"

const int Maze::MAP_WIDTH = 20;
const int Maze::MAP_LENGTH = 20;

Maze::Maze(void)
{
}

Maze::Maze( SceneManager* sceneManager, int* map)
{	
	this->mSceneNode = sceneManager->getRootSceneNode()->createChildSceneNode("mapSenenNode");
	this->pZones = new Cell[MAP_WIDTH * MAP_LENGTH];
	this->pMapInfo = new int[MAP_WIDTH * MAP_LENGTH];
	for(int i = -10; i < 10; ++i)
	{
		for(int j = -10; j < 10; ++j)
		{
			this->pZones[(i + 10) * 20 + j + 10] = Cell(sceneManager,sceneManager->getRootSceneNode(),map[(i + 10) * 20 + j + 10],8,Position(i,j));
		}
	}
}


Maze::~Maze(void)
{
	delete this->pMapInfo;
}

int* Maze::getMazeInfo()
{
	for(int i = 0; i < MAP_WIDTH * MAP_LENGTH; ++i)
	{
		this->pMapInfo[i] = this->pZones[i].getContain();
	}
	return pMapInfo;
}

bool Maze::isStep( Monster& monster )
{
	return true;
}
