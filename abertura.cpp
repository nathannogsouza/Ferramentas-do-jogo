#include "Abertura.h"
#include "ui/CocosGUI.h"
#include "SimpleAudioEngine.h"
#include "cenaprincipal.h"

USING_NS_CC;
using namespace ui;
using namespace CocosDenshion;

Scene * Abertura::criaCena(){
	return Abertura::create();
}

bool Abertura::init(){
	if (!Scene::init())
		return false;

	auto director = Director::getInstance();
	auto tamTela = director->getVisibleSize();
	auto fundo = Sprite::create("imagens/telainicial1.png");//Colquei a imgem de fundo
	auto button =	Button::create("imagens/buttonstart1.png");//Colocar um Botão na tela.
	auto som = SimpleAudioEngine::getInstance();
	auto titulo = Label::createWithTTF("DeMorgam Production", "fonts/retro.ttf", 18);
	//botão de start mexendo
	auto aumentar = ScaleBy::create(1.5f, 1.5f);
	auto diminuir = ScaleBy::create(1 / 1.5f, 1 / 1.5f);
	auto seq = Sequence::createWithTwoActions(aumentar, diminuir);

	
	this->addChild(fundo, 1);
	this->addChild(button, 2);
	this->addChild(titulo, 3);
	
	

	button->addTouchEventListener([&, director](Ref* sender, Widget::TouchEventType type) {
		switch (type){
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			SimpleAudioEngine::getInstance()->playEffect("soco.mp3");
			auto cena = CenaPrincipal::criaCena();
			director->replaceScene(TransitionFade::create(4, cena, Color3B::BLACK));
			break;
		
		}
	});
	//musica de abertura
	som->playBackgroundMusic("musicaInicial.mp3", true);
	button->runAction(RepeatForever::create(seq));
	titulo->setColor(Color3B::GRAY);
	fundo->setPosition(tamTela.width / 2, tamTela.height * 0.7);
	director->setClearColor(Color4F::WHITE);
	fundo->setScale(0.7);
	button->setScale(1.5);
	//defini o bottão como filho da tela inicial para centralizar.
	button->setPosition(Vec2(tamTela.width / 2, tamTela.height / 3));
	titulo->setPosition(Vec2(tamTela.width / 2, tamTela.height / 9));
	

	
	
	return true;
}

