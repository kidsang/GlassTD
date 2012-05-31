#ifndef __AbstractMagazine_h_
#define __AbstractMagazine_h_

/// µ¯Ï»µÄ³éÏóÀà
/// @author: LiaoNanhao
class AbstractMagazine
{
public:
	AbstractMagazine(void);
	~AbstractMagazine(void);

	virtual Bullet generateBullet() = 0;
};


#endif