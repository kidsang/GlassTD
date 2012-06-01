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
	/// �˿ռ䵱ǰ�ı�ռ����
	int mState;
	/// �˿ռ��������
	int mMaxContain;
	/// �˿ռ��λ������
	Position mPos;
	/// �˿ռ��ʵ��ָ��
	Entity* mEntity;
	/// �˿ռ�ĳ����ڵ�
	SceneNode* mSceneNode;
	/// �˿ռ������
	int type;

public:
	Cell(void);
	/// Cell��Ĺ��캯��֮һ
	/// @param sceneManager ������ָ��
	/// @param parentNode �����ĸ��ڵ�ָ��
	/// @param state �˿ռ�ĵ�ǰ��������
	/// @param maxContain �˿ռ�������������
	/// @param pos �˿ռ������ֵ����
	Cell(Ogre::SceneManager* sceneManager,Ogre::SceneNode* parentNode,int state,int maxContain,Position& pos);
	~Cell(void);
	/// ��ȡ�������ɵĿռ�ֵ
	/// @note ÿ��ʵ�屾������Զ�����һ���ռ�ֵ
	int getContain();
	/// �ڴ˿ռ�����һ������
	/// @param monster Ҫ���ӹ��޵�����
	/// @return ����true��ʾ���ӳɹ�����֮���ɹ�
	bool AddMonitor(Monster& monster);
	/// ѯ�ʴ˿ռ��Ƿ������ɹ���
	/// @param monster Ҫ���ɹ��޵�����
	/// @note ����true��ʾ�����ɣ���֮����
	bool isContain(Monster& monster);
	/// ��ȡ�ռ�ĸ߶�
	int getHeight();
};

#endif

