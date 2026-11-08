#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>

using namespace geode::prelude();

class $modify(MyPauseLayer, PauseLayer) {
    void customSetup() {
        PauseLayer::customSetup();

        auto menu = this->getChildByID("right-button-menu");
        if (!menu) return;

        auto spr = CircleButtonSprite::createWithSpriteName(
            "GJ_optionsBtn_001.png", 0.8f, CircleBaseColor::Green, CircleBaseStyle::Dark
        );
        
        auto btn = CCMenuItemSpriteExtra::create(
            spr,
            this,
            menu_selector(MyPauseLayer::onOpenOpacityMenu)
        );

        btn->setID("opacity-mod-button"_spr);

        menu->addChild(btn);
        menu->updateLayout();
    }

    void onOpenOpacityMenu(CCObject*) {
        FLAlertLayer::create(
            "Icon Opacity",
            "¡Hola! Botón funcional creado con éxito.",
            "OK"
        )->show();
    }
};