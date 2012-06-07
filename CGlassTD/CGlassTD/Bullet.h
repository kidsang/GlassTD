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
	Vector3 mPosition;;
	/// ���ڵ��Ƿ��Ѿ�������
	bool mIsFired;

	/// ���ڵ��Ľڵ�
	SceneNode* mNode;
	/// ���ڵ���ģ��
	Entity* mEntity;

	/// �ڵ�������
	float mMass;
	/// �ڵ����˺�ֵ
	float mDamage;
	/// �ڵ����˺���Χ
	float mRange;
	/// �ڵ���Ԫ������
	std::string mSpell;

	/// �ڵ�ɾ���Լ���Ҫ�õ�����tmd����
	SceneManager* mSceneManager;

public:
	/// ���캯��
	/// @param node �ӵ��Ľڵ�
	/// @param entity �ӵ���ʵ��
	Bullet(SceneManager* manager, SceneNode* node, Entity* entity);
	~Bullet(void);

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
	/// ��ȡ�ڵ���Ԫ������
	const std::string& getSpell()
	{
		return mSpell;
	}

	/// �����ڵ���Ԫ������
	void setSpell(const std::string& spell)
	{
		mSpell = spell;
	}

	/// ��ȡ�ڵ���ǰλ��
	const Vector3& getPosition()
	{
		return mNode->getPosition();
	}

	/// ��ȡ�ڵ�����������
	const float getMass()
	{
		return mMass;
	}

	/// �����ڵ�����������
	void setMass(float mass)
	{
		mMass = mass;
	}
	
	/// ��ȡ�ڵ����˺�ֵ
	const float getDamage()
	{
		return mDamage;
	}

	/// �����ڵ����˺�ֵ
	void setDamage(float damage)
	{
		mDamage = damage;
	}

	/// ��ȡ�ڵ��ı�ը�뾶
	const float getRange()
	{
		return mRange;
	}

	/// �����ڵ��ı�ը�뾶
	void setRange(float range)
	{
		mRange = range;
	}

	/// ��ȡ�ڵ���Ԫ������(��ͨ��������)
	//const std::string getSpell()
};


/// �ڵ�������
class BulletFactory
{
private:
	/// ����������Ҫ�Ĳ����б�
	NameValueList mParams;
	/// ���������ͣ���ʵ�������������ڵ����������
	std::string mType;
	/// �ڵ���������
	int mAmmo;

public:
	/// ���캯��
	/// @param params �����ӵ�����Ҫ�����Բ���
	BulletFactory(NameValueList params);
	~BulletFactory()
	{
	}

	/// ����һ���ӵ���ʵ��
	/// @param mgr ����������
	/// @return ���ش����õ����࣬���ʧ���򷵻�NULL
	Bullet* createInstance(SceneManager* mgr);

	/// ���ع���������
	const std::string& getType()
	{
		return mType;
	}

	/// ���ص�ҩ����
	int getAmmoCount()
	{
		return mAmmo;
	}

	/// ���õ�ҩ����
	void setAmmoCount(int ammo)
	{
		mAmmo = ammo;
	}
};


#endif // Bullet_h__