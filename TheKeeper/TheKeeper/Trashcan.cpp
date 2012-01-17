//
//  Trashcan.cpp
//  TheKeeper
//
//  Created by Jay Roberts on 9/18/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#include "Trashcan.hpp"
#include "ResourcePath.hpp"
#include "ConfigFile.hpp"
#include "GFE/TextureManager.hpp"
#include "GFE/Logger.hpp"

namespace Keeper {
    Trashcan::Trashcan(void) : GFE::Entity() {
        ConfigFile config(ResourcePath() + "trashcan.ini");

        std::string texture_file = config.read<std::string>("filename", "spritesheet.png");
        
        spritesheet = GFE::TextureManager::GetTexture(texture_file);
        sprite = sf::Sprite(spritesheet);
        
        int scale = config.read<int>("scale", 4);
        sprite.SetScale(scale, scale);

        upright_frame = sf::IntRect(0, 8, 8, 8); 
        tipped_frame = sf::IntRect(8, 8, 16, 8); 
        
        Reset();
    }

    Trashcan::Trashcan(float x, float y) : GFE::Entity() {
        ConfigFile config(ResourcePath() + "trashcan.ini");
        
        std::string texture_file = config.read<std::string>("filename", "spritesheet.png");
        
        spritesheet = GFE::TextureManager::GetTexture(texture_file);
        sprite = sf::Sprite(spritesheet);
        
        int scale = config.read<int>("scale", 4);
        sprite.SetScale(scale, scale);
        
        upright_frame = sf::IntRect(0, 8, 8, 8); 
        tipped_frame = sf::IntRect(8, 8, 16, 8); 
        
        Reset();
        
        SetPosition(sf::Vector2f(x, y));
    }

    Trashcan::~Trashcan() {
        
    }
    
    void Trashcan::Tip(void) {
        tipped = true;
        sprite.SetTextureRect(tipped_frame);
        sprite.SetOrigin(1, 8);
    }
    
    bool Trashcan::IsTipped(void) {
        return tipped;
    }
    
    void Trashcan::Reset(void) {
        tipped = false;
        sprite.SetTextureRect(upright_frame);
        sprite.SetOrigin(4, 8);
    }
    
    void Trashcan::Update(float dt) {
    }
    
    sf::Vector2f Trashcan::GetPosition() {
        return sprite.GetPosition();
    }
    
    void Trashcan::SetPosition(sf::Vector2f position) {
        sprite.SetPosition(position);
    }
    
    void Trashcan::Draw(sf::RenderTarget& target, sf::RenderStates renderStates) const {
        target.Draw(sprite, renderStates);
    }

}