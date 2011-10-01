//
//  Mob.cpp
//  TheKeeper
//
//  Created by Jay Roberts on 10/1/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#include "Mob.hpp"
#include "GFE/Logger.hpp"

namespace Keeper {

    
    Mob::Mob() : GFE::Entity() , animations("mobs") {
        
    }

    Mob::~Mob() {
        delete aiComponent;
    }

    void Mob::SetAIComponent(GFE::IAIComponent* theAIComponent) {
        GFE::Logger::Log() << "Set AI Component";
        GFE::Logger::Flush();
        
        aiComponent = theAIComponent;
        aiComponent->SetEntity(this);
    }
    
    void Mob::Update(float dt) {
//        GFE::Logger::Log() << "Mob Update";
        GFE::Logger::Flush();
        aiComponent->Update(dt);
    }
    
    void Mob::Render(sf::RenderTarget& target, sf::Renderer& renderer) const {
    }

}
