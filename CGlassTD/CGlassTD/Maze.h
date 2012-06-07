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
	/// ��������ָ��
	SceneManager* mSceneManager;
	/// ��ͼ�ĳ����ڵ�ָ��
	SceneNode* mSceneNode;
	/// ��ͼ��ӵ�еĿռ�һά����
	Cell* pZones;
	/// ��ͼ��Ϣ��һά����
	int* pMapInfo;
	/// ��ƽ��
	float horizon;
	/// ��ͼһλ����
	int* mMap;
	/// ��ͼ�Ŀ�
	int mWidth;
	/// ��ͼ�ĸ�
	int mHeight;
	/// ��ʼλ���б�
	std::vector<Ogre::Vector3> startPos;
	/// ����λ��
	Ogre::Vector3 finalPos;
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
	Cell* getMazeInfo();
	/// ��ȡ�ذ��y����
	float getHorizon();
	/// ��ȡ���޳��ֵ�λ��
	/// @return ���ض�ά����
	std::vector<Ogre::Vector3> getStartPos();
	/// ת�����꣺��ͼ����-> ��������
	/// @params pos ��ͼ����
	/// @reutrn ��������
	Ogre::Vector3* translatePos(Ogre::Vector3* pos);
	/// ͨ�����������ȡָ����Cell
	/// @params pos ���������Ogre::Vector3 ָ��
	/// @return ָ����Cell
	Cell* getCellByPos(Ogre::Vector3* pos);
	/// ��ȡ��ͼ�Ŀ�
	/// @return ��ͼ�Ŀ�
	int getMapWidth();
	/// ��ȡ��ͼ�ĸ�
	/// @return ��ͼ�ĸ�
	int getMapHeight();
	/// ��ȡ�ɵ�Ŀ���λ��
	/// @return ���طɵ��Ķ�ά����
	Ogre::Vector3* getTargetPos();
	/// ���ӿ�ʼλ��
	void addStartPos(Ogre::Vector3 pos);
	/// ���ý���λ��
	void setFinalPos(Ogre::Vector3 pos);
	/// ��������
	~Maze(void);
};
#endif
