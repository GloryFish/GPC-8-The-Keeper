//
//  Mob.cpp
//  TheKeeper
//
//  Created by Jay Roberts on 10/19/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#include "Mob.hpp"
#include "GFE/Entity.hpp"
#include "GFE/Logger.hpp"

namespace Keeper {

    Mob::Mob(void) : GFE::Entity() {
        
    }
    
    Mob::~Mob() {
        
    }
    
    void Mob::Update(float dt) {
        GFE::Logger::Log() << "Mob::Update()";   
    }

    void Mob::Render(sf::RenderTarget& target, sf::Renderer& renderer) const {
        GFE::Logger::Log() << "Mob::Render()";   
    }

}