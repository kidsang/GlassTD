#ifndef __Maze_h_
#define __Maze_h_

#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreEntity.h>
#include "Cell.h"
using namespace Ogre;

class Maze
{
private:
	/// ��ͼ�ĳ����ڵ�ָ��
	SceneNode* mSceneNode;
	const static int MAP_WIDTH;
	const static int MAP_LENGTH;
	/// ��ͼ��ӵ�еĿռ�һά����
	Cell* pZones;
	/// ��ͼ��Ϣ��һά����
	int* pMapInfo;
public:
	Maze(void);
	Maze(SceneManager* sceneManager, int* map);
	/// ��ȡ��ǰ��ͼ����Ϣ
	/// @return ����һά����
	int* getMazeInfo();
	/// ��������ռ�λ��
	/// @param moster ָ���Ĺ�������
	/// @return ����true���ʾ����ɹ�����֮���ɹ�
	bool isStep(Monster& monster);
	/// ����ռ���ƶ��ռ�
	/// @param moster ָ���Ĺ�������
	/// @return ����true��ʾ�ɹ�����֮���ɹ�
	bool step(Monster& monster);
	~Maze(void);
};



#endif

