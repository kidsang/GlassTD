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
	SceneManager* mSceneManager;
	/// 地图的场景节点指针
	SceneNode* mSceneNode;
	/// 地图所拥有的空间一维数组
	Cell* pZones;
	/// 地图信息的一维数组
	int* pMapInfo;
	/// 地平线
	int horizon;
	/// 地图一位数组
	int* mMap;
	/// 地图的宽
	int mWidth;
	/// 地图的高
	int mHeight;

public:
	Maze(void);
	/// 构造函数
	/// @param sceneManager 场景管理类
	/// @
	Maze(SceneManager* sceneManager, int* map, int width, int height);
	/// 获取当前地图的信息
	/// @return 返回一维数组
	int* getMazeInfo();
	/// 获取地板的y坐标
	int getHorizon();
	/// 怪兽请求空间位置
	/// @param moster 指定的怪兽引用
	/// @return 返回true则表示请求成功，反之不成功
	bool isStep(Monster& monster);
	/// 怪兽占据制定空间
	/// @param moster 指定的怪兽引用
	/// @return 返回true表示成功，反之不成功
	bool step(Monster& monster);
	~Maze(void);
};



#endif

