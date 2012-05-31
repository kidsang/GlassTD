#ifndef Bullet_h__
#define Bullet_h__

#include <OgreVector3.h>
#include <OgreSceneManager.h>
using namespace Ogre;

#include "Common.h"

/// �ӵ��Ļ���
/// �������͵������ӵ��̳��������
class Bullet
{
private:
	/// �ٶ�
	Vector3 mVelocity;
	/// λ��
	Vector3 mPosition;;
	/// �������ٶ�
	float mGravity;

	/// ���ڵ��Ľڵ�
	SceneNode* mNode;
	/// ���ڵ���ģ��
	Entity* mEntity;

public:
	/// ���캯��
	/// @param node �ӵ��Ľڵ�
	/// @param entity �ӵ���ʵ��
	Bullet(SceneNode* node, Entity* entity);
	virtual ~Bullet(void);

	/// �����ڵ�
	/// @param position �����ʼλ��
	/// @param velocity ������ٶ�
	/// @param gravity ��������
	void fire(Vector3 position, Vector3 velocity, float gravity)
	{

	}



	// Get/Set
public:
	/// ��ȡ�ڵ�����������
	/// �������ṩ
	virtual float getMass() = 0;

};


/// �ڵ�������
class BulletFactory
{
	/// ����һ���ӵ���ʵ��
	/// @param mgr ����������
	/// @param args ����������Ҫ�õ��Ĳ���
	/// @return ���ش����õ����࣬���ʧ���򷵻�NULL
	virtual Bullet* createInstance(SceneManager* mgr, NameValueList args) = 0;

	/// ���ع���������
	virtual std::string getType() = 0;
};


#endif // Bullet_h__