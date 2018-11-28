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
	getAnimation(std::string path, std::string filename, int start, int end, float time) {

		std::string pListFile = path + filename + ".plist";

		std::string pngFile = path + filename + ".png";


		auto frameCache = SpriteFrameCache::sharedSpriteFrameCache();

		frameCache->addSpriteFramesWithFile(pListFile);


		Vector<SpriteFrame*> animationFrames;

		std::stringstream ss;


		for (int i = start; i <= end; i++) {

			ss.str("");

			ss << filename << i << ".png";


			auto frame = SpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(ss.str());

			animationFrames.pushBack(frame);

		}



		Animation* animationSeq = Animation::createWithSpriteFrames(animationFrames, time);

		return Animate::create(animationSeq);

	}



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
