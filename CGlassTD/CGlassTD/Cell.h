#ifndef __Cell_h_
#define __Cell_h_

#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreEntity.h>
#include "ObjectFactory.h"
#include "CellType.h"
using namespace std;
using namespace Ogre;


class Cell
{
private:
	/// 此空间的位置坐标
	Ogre::Vector2* pPos;
	/// 此空间的实体指针
	Entity* mEntity;
	/// 此空间的场景节点
	SceneNode* mSceneNode;
	/// 此空间的类型
	CellType mType;
	/// 伤害值 
	float mHarmValue;

public:
	Cell(void);
	/// Cell类的构造函数之一
	/// @param sceneManager 场景的指针
	/// @param parentNode 场景的父节点指针
	/// @param state 此空间的当前容量属性
	/// @param maxContain 此空间的最大容量属性
	/// @param pos 此空间的坐标值引用
	Cell(Ogre::SceneManager* sceneManager,Ogre::SceneNode* parentNode,Ogre::Vector2* pos,CellType type, float harmValue);
	Cell(Ogre::SceneManager* sceneManager,Ogre::SceneNode* parentNode,Ogre::Vector2* pos,int type, float harmValue);
	~Cell(void);
	/// 获取空间的类型
	CellType getCellType();
	/// 获取空间的高度
	float getHeight();
	/// 获取伤害值
	float getHarmValue();
};

#endif

