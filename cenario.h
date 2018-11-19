#ifndef __CENARIO_SCENE_H__
#define __CENARIO_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class Cenario : public Scene
{
public:
	static Scene* criaCena();

	virtual bool init();
	//void fechaJogo(Ref* pSender);

	CREATE_FUNC(Cenario);
};
#endif
