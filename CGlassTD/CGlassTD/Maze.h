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
	/// @param map 地图数组指针
	/// @param width 地图的宽
	/// @param height 地图的高
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
	/// 获取怪兽出现的位置
	/// @return 返回二维坐标
	Ogre::Vector2* getMonsterPos();
	/// 转换坐标：地图坐标-> 世界坐标
	/// @params pos 地图坐标
	/// @reutrn 世界坐标
	Ogre::Vector2* translatePos(Ogre::Vector2* pos);
	/// 获取地图的宽
	/// @return 地图的宽
	int getMapWidth();
	/// 获取地图的高
	/// @return 地图的高
	int getMapHeight();
	/// 析构函数
	~Maze(void);
};
#endif
