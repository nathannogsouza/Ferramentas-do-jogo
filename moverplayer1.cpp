#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}
	auto director = Director::getInstance();
	auto tamtela = director->getVisibleSize();

	SpriteFrameCache* framecache = SpriteFrameCache::sharedSpriteFrameCache();
	framecache->addSpriteFramesWithFile("andando.plist");

	SpriteBatchNode* spritsheet = SpriteBatchNode::create("andando.png");
	this->addChild(spritsheet);

	Vector<SpriteFrame*> animationFrames;


	for (int i = 1; i <= 6; i++) {
		String* filename = String::createWithFormat("andando%d.png", i);
		SpriteFrame* frame = SpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(filename->getCString());
		animationFrames.pushBack(frame);
	}

	Animation* runAnim = Animation::createWithSpriteFrames(animationFrames, 1);
	Sprite* andar = Sprite::createWithSpriteFrameName("andando1.png");

	Size winsize = Director::sharedDirector()->getWinSize();
	andar->setPosition(Vec2(winsize.width / 2, winsize.height / 2));

	Action* action = RepeatForever::create(Animate::create(runAnim));

	andar->runAction(action);
	spritsheet->addChild(andar);


	return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif


}
