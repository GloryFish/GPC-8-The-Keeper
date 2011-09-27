//
//  Pedestrian.cpp
//  TheKeeper
//
//  Created by Jay Roberts on 9/18/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#include "Pedestrian.hpp"
#include "ResourcePath.hpp"
#include "ConfigFile.hpp"
#include "GFE/TextureManager.hpp"

namespace Keeper {
    
    Pedestrian::Pedestrian(void) : GFE::Entity() {
        // pedestrian.ini file contains information about the player's sprites
        ConfigFile config(ResourcePath() + "pedestrian.ini");
        speed = config.read<float>("speed", 100);
        flipped = false;

        std::string texture_file = config.read<std::string>("filename", "spritesheet.png");
        
        spritesheet = GFE::TextureManager::GetTexture(texture_file);
        sprite = sf::Sprite(spritesheet);
        int scale = config.read<int>("scale", 4);
        sprite.SetScale(scale, scale);
        
        sprite.SetOrigin(0.5 * config.read<int>("width", 8), 
                         1.0f * config.read<int>("height", 8));
        
        
//        BuildAnimations(config);
        
//        SetAnimation("stand");
        
        SetPosition(64, 208);

    }
    
    Pedestrian::~Pedestrian() {
        
    }
 
    void Pedestrian::Render(sf::RenderTarget& target, sf::Renderer& renderer) const {
        
    }
}
