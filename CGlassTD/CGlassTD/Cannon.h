#ifndef __Cannon_h_
#define __Cannon_h_

#include <vector>
#include "Bullet.h"
#include "OgreQuaternion.h"
#include <time.h>

/// ��̨��
/// @author: LiaoNanhao
class Cannon
{
	typedef std::vector<BulletFactory*> BulletFactoryList;

private:
	/// ��̨��ӵ�е������ڵ�
	BulletFactoryList mBulletFactoryList;
	/// ��ǰѡ��ĵ�ҩ����
	unsigned int mCurrentBullet;

	/// ���ڷ�������
	float mFireStrenth;

	/// ���ڵķ�����,�������
	float mColdDown;
	/// �ϴη����ʱ��
	clock_t mLastTime;

	/// ���ڵĽڵ�
	SceneNode* mNode;
	/// ���ڵ�ģ��
	Entity* mEntity;

public:
	Cannon(SceneNode* node, Entity* entity);
	~Cannon();

	/// ����̨����һ���ڵ�����
	/// @param bulletFactory Ҫ���ӵ��ڵ�����
	/// @note һ���ڵ�����ʵ���Ͼ���ĳ���ڵ���
	///		  ����Ϊ��������̨���Ӳ�ͬ������ڵ�
	void addBulletFactory(BulletFactory* bulletFactory);

	/// ���䵱ǰװ�����ڵ�
	/// @return ���ط�����ڵ����������ʧ��(����cd)�򷵻�NULL
	/// @note �ⲿ��ĳ��������Ӧ�ý��ַ����ȥ���ڵ��Ĺ�������
	///		  ���������fly()�������ͷ���Դ��
	Bullet* fire(SceneManager* mgr);

	/// ���ĵ�ǰװ�����ڵ�
	/// @param index �ڼ����ڵ�
	/// @note ������Ƿ�����ʱ���Ȳ��������Ҳ����ʾ�κδ���
	void changeBullet(unsigned int index);

	/// �л�����һ������
	/// @note ����ת
	void changeBullet();

	/// �޸���̨����
	void rotate(int yaw, int pitch);
};


#endif
