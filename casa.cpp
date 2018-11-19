#include "casa.h"
#include "ui/CocosGUI.h"
#include "SimpleAudioEngine.h"
#include "cenaprincipal.h"

USING_NS_CC;
using namespace ui;
using namespace CocosDenshion;

Scene * Casa::criaCena() {
	return Casa::create();
}

bool Casa::init() {
	if (!Scene::init())
		return false;

	auto director = Director::getInstance();
	auto tamtela = director->getVisibleSize();
	auto fundo = Sprite::create("cenario/quarto-1.png");
	auto button = Button::create("andar1.png");

	this->addChild(fundo, 1);
	this->addChild(button, 2);

	fundo->setPosition(Vec2(tamtela.width / 2, tamtela.height / 2));
	button->setScale(5);
	button->setPosition(Vec2(tamtela.width / 4, tamtela.height / 4));
	button->addTouchEventListener([&, director](Ref* sender, Widget::TouchEventType type) {
		switch (type) {
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			auto cena = CenaPrincipal::criaCena();
			director->replaceScene(TransitionFade::create(4, cena, Color3B::BLACK));
			break;

		}
	});
	







	return true;
}