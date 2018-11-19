#ifndef CENAPRINCI_H
#define CENAPRINCI_H

#include "cocos2d.h"
USING_NS_CC;

class CenaPrincipal : public Scene {
public:
	static Scene* criaCena();

	virtual bool init();
	

	CREATE_FUNC(CenaPrincipal);
};

#endif 