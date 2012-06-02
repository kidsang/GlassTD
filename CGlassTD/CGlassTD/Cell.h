#include "Position.h"
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreEntity.h>
#include "ObjectFactory.h"
#include "Monster.h"
using namespace std;
using namespace Ogre;

#ifndef __Cell_h_
#define __Cell_h_

class Cell
{
private:
	/// 此空间当前的被占容量
	int mState;
	/// 此空间最大容量
	int mMaxContain;
	/// 此空间的位置坐标
	Position mPos;
	/// 此空间的实体指针
	Entity* mEntity;
	/// 此空间的场景节点
	SceneNode* mSceneNode;
	/// 此空间的类型
	int type;

public:
	Cell(void);
	/// Cell类的构造函数之一
	/// @param sceneManager 场景的指针
	/// @param parentNode 场景的父节点指针
	/// @param state 此空间的当前容量属性
	/// @param maxContain 此空间的最大容量属性
	/// @param pos 此空间的坐标值引用
	Cell(Ogre::SceneManager* sceneManager,Ogre::SceneNode* parentNode,int state,int maxContain,Position& pos);
	~Cell(void);
	/// 获取可以容纳的空间值
	/// @note 每个实体本身的属性都会有一个空间值
	int getContain();
	/// 在此空间增加一个怪兽
	/// @param monster 要增加怪兽的引用
	/// @return 返回true表示增加成功，反之不成功
	bool AddMonitor(Monster& monster);
	/// 询问此空间是否能容纳怪兽
	/// @param monster 要容纳怪兽的引用
	/// @note 返回true表示能容纳，反之不能
	bool isContain(Monster& monster);
	/// 获取空间的高度
	int getHeight();
};

#endif

