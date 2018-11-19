#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class Abertura : public Scene{
public:
	static Scene* criaCena();

	virtual bool init();
	//void fechaJogo(Ref* pSender);

	CREATE_FUNC(Abertura);
};

#endif // __HELLOWORLD_SCENE_H__
