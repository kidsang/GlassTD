#include "Maze.h"
#include "Cell.h"

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
	this->startPos = std::vector<Ogre::Vector3>();
	this->mSceneNode->setPosition(Ogre::Vector3(-mWidth / 2.0f * 100, 0, -mHeight / 2.0f * 100));

	for(int j = 0; j < width; ++j)
	{
		for(int i = 0; i < height; ++i)
		{
			this->pZones[j * width + i] = Cell(sceneManager, mSceneNode, new Ogre::Vector2(Real(i),Real(j)), map[j * width + i], 0.1f);
		}
	}
	this->horizon = this->pZones[1].getHeight() / 2.0f;
}


Maze::~Maze(void)
{
	delete this->pMapInfo;
}

Cell* Maze::getMazeInfo()
{
	return this->pZones;
}

float Maze::getHorizon()
{
	return this->horizon;
}

std::vector<Ogre::Vector3> Maze::getStartPos()
{
	return this->startPos;
}

int Maze::getMapWidth()
{
	return this->mWidth;
}

int Maze::getMapHeight()
{
	return this->mHeight;

}

Ogre::Vector3* Maze::translatePos( Ogre::Vector3* pos )
{
	return new Ogre::Vector3(Real(pos->x - (this->mWidth / 2.0f * 100)),Real(0),Real(pos->y - (this->mHeight / 2.0f * 100)));
}

void Maze::addStartPos( Ogre::Vector3 pos )
{
	this->startPos.push_back(pos);
}

void Maze::setFinalPos( Ogre::Vector3 pos )
{
	this->finalPos = pos;
}

Cell* Maze::getCellByPos( Ogre::Vector3 pos )
{
	Cell* cell;
	return cell;
}
