#ifndef CENALUTA_H
#define CENALUTA_H


#include "cocos2d.h"
USING_NS_CC;


class CenaLuta : public Scene {
public:
	static Scene* criaCena();

	virtual bool init();


	CREATE_FUNC(CenaLuta);

};

#endif