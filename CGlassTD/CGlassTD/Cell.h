#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreEntity.h>
#include "ObjectFactory.h"
#include "Monster.h"
#include "CellType.h"
using namespace std;
using namespace Ogre;

#ifndef __Cell_h_
#define __Cell_h_

class Cell
{
private:
	/// �˿ռ��λ������
	Ogre::Vector2* pPos;
	/// �˿ռ��ʵ��ָ��
	Entity* mEntity;
	/// �˿ռ�ĳ����ڵ�
	SceneNode* mSceneNode;
	/// �˿ռ������
	CellType mType;

public:
	Cell(void);
	/// Cell��Ĺ��캯��֮һ
	/// @param sceneManager ������ָ��
	/// @param parentNode �����ĸ��ڵ�ָ��
	/// @param state �˿ռ�ĵ�ǰ��������
	/// @param maxContain �˿ռ�������������
	/// @param pos �˿ռ������ֵ����
	Cell(Ogre::SceneManager* sceneManager,Ogre::SceneNode* parentNode,Ogre::Vector2* pos,CellType type);
	Cell(Ogre::SceneManager* sceneManager,Ogre::SceneNode* parentNode,Ogre::Vector2* pos,int type);
	~Cell(void);
	/// ��ȡ�ռ������
	CellType getCellType();
	/// ��ȡ�ռ�ĸ߶�
	int getHeight();
};

#endif

