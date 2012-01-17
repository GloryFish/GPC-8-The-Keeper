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


    void Entity::Update(float dt) {
        GFE::Logger::Log() << "Entity::Update";
    }

    void Entity::SetPosition(sf::Vector2f position) {
        GFE::Logger::Log() << "Entity::SetPosition()";
    }

    sf::Vector2f Entity::GetPosition() {
        GFE::Logger::Log() << "Entity::GetPosition()";
        return sf::Vector2f(0, 0);
    }

    void Entity::Draw(sf::RenderTarget& target, sf::RenderStates renderStates) const {
        //        GFE::Logger::Log() << "Entity::Render";
    }

    bool SortEntities(GFE::Entity* a, GFE::Entity* b) {
        return a->GetPosition().y < b->GetPosition().y;
    }

}
