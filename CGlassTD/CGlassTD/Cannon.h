#ifndef __Cannon_h_
#define __Cannon_h_

#include "Bullet.h"

/// ≈⁄Ã®¿‡
/// @author: LiaoNanhao
class Cannon
{
public:
	Cannon(void);
	~Cannon(void);

	static const int FIRSET_KIND = 1;
	static const int SECOND_KIND = 2;
	static const int THIRD_KIND = 3;

private:
	int mCurrentKind;
};


#endif
