#ifndef Bullet_h__
#define Bullet_h__

/**
 * �ļ���Bullet
 * ���ڣ�2012/05/31
 * ���ߣ�kid
 */

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
	Vector3 mPosition;
	/// ����
	//Vector3 mGravity;
	/// ���ڵ��Ƿ��Ѿ�������
	bool mIsFired;

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
	void fire(const Vector3& position, const Vector3& velocity);

	/// �ڵ����к���
	/// @param t ��һ֡����һ֡������ʱ�䣬now - last
	/// @note �ú�������ĳ�������ӵ���������ѭ���е���
	///		  ����һ�ξ���ǰ��һ��
	void fly(float t, const Vector3& gravity);

	// Get/Set
public:
	/// ��ȡ�ڵ�����������
	/// �������ṩ
	virtual const float getMass() = 0;

};


/// �ڵ�������
class BulletFactory
{
public:
	/// ����һ���ӵ���ʵ��
	/// @param mgr ����������
	/// @param args ����������Ҫ�õ��Ĳ���
	/// @return ���ش����õ����࣬���ʧ���򷵻�NULL
	virtual Bullet* createInstance(SceneManager* mgr) = 0;

	/// ���ع���������
	virtual std::string getType() = 0;
};


#endif // Bullet_h__