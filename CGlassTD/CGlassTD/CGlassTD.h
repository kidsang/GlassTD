#ifndef __CGlassTD_h_
#define __CGlassTD_h_

#include "BaseApplication.h"
#include "../res/resource.h"

/**
 * �ļ���CGlassTD
 * ���ڣ�2012/05/31
 * ���ߣ�kid
 */

class CGlassTD : public BaseApplication
{
public:
    CGlassTD(void);
    virtual ~CGlassTD(void);

protected:
    virtual void createScene(void);

	virtual bool frameRenderingQueued( const Ogre::FrameEvent& evt );

};

#endif // #ifndef __CGlassTD_h_
