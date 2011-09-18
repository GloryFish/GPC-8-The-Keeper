//
//  Entity.cpp
//  TheKeeper
//
//  Created by Jay Roberts on 9/18/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#include "Entity.hpp"
#include "Logger.hpp"

namespace GFE {
    
    Entity::Entity(void) : sf::Drawable() {
        
    }
    
    Entity::~Entity() {
        
    }

    void Entity::Render(sf::RenderTarget& target, sf::Renderer& renderer) const {
        GFE::Logger::Log() << "Entity render";
        return;
    }
    
    bool SortEntities(const Entity* a, const Entity* b) {
        return a->GetPosition().y < b->GetPosition().y;
    }

}
