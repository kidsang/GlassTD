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
	/// ��ͼ�ĳ����ڵ�ָ��
	SceneNode* mSceneNode;
	/// ��ͼ��ӵ�еĿռ�һά����
	Cell* pZones;
	/// ��ͼ��Ϣ��һά����
	int* pMapInfo;
	/// ��ƽ��
	int horizon;
	/// ��ͼһλ����
	int* mMap;
	/// ��ͼ�Ŀ�
	int mWidth;
	/// ��ͼ�ĸ�
	int mHeight;

public:
	Maze(void);
	/// ���캯��
	/// @param sceneManager ����������
	/// @param map ��ͼ����ָ��
	/// @param width ��ͼ�Ŀ�
	/// @param height ��ͼ�ĸ�
	Maze(SceneManager* sceneManager, int* map, int width, int height);
	/// ��ȡ��ǰ��ͼ����Ϣ
	/// @return ����һά����
	int* getMazeInfo();
	/// ��ȡ�ذ��y����
	int getHorizon();
	/// ��������ռ�λ��
	/// @param moster ָ���Ĺ�������
	/// @return ����true���ʾ����ɹ�����֮���ɹ�
	bool isStep(Monster& monster);
	/// ����ռ���ƶ��ռ�
	/// @param moster ָ���Ĺ�������
	/// @return ����true��ʾ�ɹ�����֮���ɹ�
	bool step(Monster& monster);
	/// ��ȡ���޳��ֵ�λ��
	/// @return ���ض�ά����
	Ogre::Vector2* getMonsterPos();
	/// ת�����꣺��ͼ����-> ��������
	/// @params pos ��ͼ����
	/// @reutrn ��������
	Ogre::Vector2* translatePos(Ogre::Vector2* pos);
	/// ��ȡ��ͼ�Ŀ�
	/// @return ��ͼ�Ŀ�
	int getMapWidth();
	/// ��ȡ��ͼ�ĸ�
	/// @return ��ͼ�ĸ�
	int getMapHeight();
	/// ��������
	~Maze(void);
};
#endif
