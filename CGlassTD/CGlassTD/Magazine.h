#ifndef __Magazine_h_
#define __Magazine_h_

/// ��ϻ�ĳ�����
/// @author: LiaoNanhao
class Magazine
{
public:
	Magazine(void);
	~Magazine(void);

	virtual Bullet* generateBullet() = 0;
};


#endif