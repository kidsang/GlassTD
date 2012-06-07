#ifndef __Maze_h_
#define __Maze_h_
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreEntity.h>
#include <vector>
using namespace Ogre;

class Cell;

class Maze
{
private:
	/// 场景管理指针
	SceneManager* mSceneManager;
	/// 地图的场景节点指针
	SceneNode* mSceneNode;
	/// 地图所拥有的空间一维数组
	Cell* pZones;
	/// 地图信息的一维数组
	int* pMapInfo;
	/// 地平线
	float horizon;
	/// 地图一位数组
	int* mMap;
	/// 地图的宽
	int mWidth;
	/// 地图的高
	int mHeight;
	/// 开始位置列表
	std::vector<Ogre::Vector3> startPos;
	/// 结束位置
	Ogre::Vector3 finalPos;
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
	Cell* getMazeInfo();
	/// 获取地板的y坐标
	float getHorizon();
	/// 获取怪兽出现的位置
	/// @return 返回二维坐标
	std::vector<Ogre::Vector3> getStartPos();
	/// 转换坐标：地图坐标-> 世界坐标
	/// @params pos 地图坐标
	/// @reutrn 世界坐标
	Ogre::Vector3* translatePos(Ogre::Vector3* pos);
	/// 通过世界坐标获取指定的Cell
	/// @params pos 世界坐标的Ogre::Vector3 指针
	/// @return 指定的Cell
	Cell* getCellByPos(Ogre::Vector3 pos);
	/// 获取地图的宽
	/// @return 地图的宽
	int getMapWidth();
	/// 获取地图的高
	/// @return 地图的高
	int getMapHeight();
	/// 获取飞碟目标的位置
	/// @return 返回飞碟的二维坐标
	Ogre::Vector3* getTargetPos();
	/// 增加开始位置
	void addStartPos(Ogre::Vector3 pos);
	/// 设置结束位置
	void setFinalPos(Ogre::Vector3 pos);
	/// 析构函数
	~Maze(void);
};
#endif
