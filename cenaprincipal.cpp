#include "cenaprincipal.h"
#include "ui/CocosGUI.h"
#include "SimpleAudioEngine.h"
#include "casa.h"
#include "cenaluta.h"

USING_NS_CC;
using namespace ui;
using namespace CocosDenshion;

Scene * CenaPrincipal::criaCena() {
	return CenaPrincipal::create();
}

bool CenaPrincipal::init() {
	if (!Scene::init())
		return false;

	auto director = Director::getInstance();
	auto tamtela = director->getVisibleSize();
	auto fundo = Sprite::create("cenario/princip.png");
	auto som = SimpleAudioEngine::getInstance();
	//auto boneco = Sprite::create("andar1.png");
	//fazendo teste
	auto button = Button::create("andar1.png");
	auto secondbutton = Button::create("andar1.png");

	this->addChild(fundo, 1);
	this->addChild(button, 2);
	this->addChild(secondbutton, 3);

	//boneco->setScale(1.5);
	button->setPosition(Vec2(tamtela.width / 4, tamtela.height / 4));
	fundo->setPosition(Vec2(tamtela.width / 2, tamtela.height /2));
	secondbutton->setPosition(Vec2(tamtela.width / 1.08, tamtela.height / 4));
	som->playBackgroundMusic("durante.mp3", true);
	//fazendo teste
	button->addTouchEventListener([&, director](Ref* sender, Widget::TouchEventType type) {
		switch (type) {
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			auto cena = Casa::criaCena();
			director->replaceScene(TransitionFade::create(2, cena, Color3B::BLACK));
			break;

		}
	});

	secondbutton->addTouchEventListener([&, director](Ref* sender, Widget::TouchEventType type) {
		switch (type) {
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			auto cena2 = CenaLuta::criaCena();
			director->replaceScene(TransitionFade::create(2, cena2, Color3B::MAGENTA));
			break;

		}
	});
	

	



	return true;
}