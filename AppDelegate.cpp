#include "AppDelegate.h"
#include "abertura.h"

// using namespace cocos2d
USING_NS_CC;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate() 
{
}

/*
	Pegar instancia do Director
	Pegar instancia do GLView
	Se não existir este, criamos a nossa própria janela (nesse caso 1280x720)
	Colocamos esse glview no nosso director
	Criamos a nossa cena inicial (nesse caso da classe HelloWorld)
	Rodamos a cena com o método runWithScene da classe director
*/
bool AppDelegate::applicationDidFinishLaunching()
{
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();

	if (glview == nullptr)
	{
		glview = GLViewImpl::create("Teste");
		glview->setFrameSize(800, 600);
		glview->setDesignResolutionSize(800, 600, ResolutionPolicy::NO_BORDER);
		director->setOpenGLView(glview);
	}

	auto scene = Abertura::criaCena();
	director->runWithScene(scene); // usar esse método apenas para a primeira cena

	return true;
}

void AppDelegate::applicationDidEnterBackground() {

}

void AppDelegate::applicationWillEnterForeground() {

}
