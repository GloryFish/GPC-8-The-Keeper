//
//  Player.cpp
//  TheKeeper
//
//  Created by Jay Roberts on 9/16/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#include "Player.hpp"
#include "ResourcePath.hpp"
#include "ConfigFile.hpp"
#include <string>
#include "GFE/Logger.hpp"
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <map>
#include "VectorMath.hpp"
#include "GFE/TextureManager.hpp"

namespace Keeper {
    
    Player::Player(void) : GFE::Entity(), animations("player") {
        // player.ini file contains information about the player's sprites
        ConfigFile config(ResourcePath() + "player.ini");
        
        speed = config.read<float>("speed", 100);
        flipped = false;
        
        std::string texture_file = config.read<std::string>("filename", "spritesheet.png");
        
        spritesheet = GFE::TextureManager::GetTexture(texture_file);
        sprite = sf::Sprite(spritesheet);
        int scale = config.read<int>("scale", 4);
        sprite.SetScale(scale, scale);
        
        sprite.SetOrigin(0.5 * config.read<int>("width", 8), 
                         1.0f * config.read<int>("height", 8));

        
        SetAnimation("stand");

        SetPosition(64, 208);
        SetTarget(sf::Vector2f(64, 208));
    }
    
    Player::~Player() {
        
    }
    
    void Player::SetAnimation(std::string animation) {
        if (animation == current_animation_name) {
            return;
        }
        
        current_animation = animations.GetAnimation(animation);
        current_animation_name = animation;
        current_animation_frame = 0;
        current_animation_duration = 0;
        sprite.SetSubRect(current_animation[current_animation_frame].rect);
    }
    
    void Player::SetTarget(sf::Vector2f theTarget) {
        GFE::Logger::Log() << "New target: " << theTarget.x << ", " << theTarget.y;

        if (GFE::VectorMath::Distance(target, theTarget) < 16) {
            return;
        }
        
        target = theTarget;
        
        // Don't let the player move up too high
        if (target.y < 185) {
            target.y = 185;
        }
    }
    
    void Player::Update(float dt) {
        // Process animation
        current_animation_duration += dt;
        
        if (current_animation_duration > current_animation[current_animation_frame].duration) {
            current_animation_duration = 0;
            current_animation_frame++;
            if (current_animation_frame == current_animation.size()) {
                current_animation_frame = 0;
            }
        }
        
        sprite.SetSubRect(current_animation[current_animation_frame].rect);
        
        sf::Vector2f movement(0, 0); 
        
        // Move to target
        if (GFE::VectorMath::Distance(GetPosition(), target) > 16) {
            // Get vector pointing at target
            movement = target - GetPosition();

            // Normalize
            movement = GFE::VectorMath::Normalize(movement);
            
            // Multiply by speed
            
            // speed scaled by target distance
            movement = movement * speed * dt;

            // Apply movement vector
            Move(movement);
            
            SetAnimation("walk");
            
            if (movement.x < 0) {
                flipped = true;
            } else {
                flipped = false;
            }
        } else {
            SetAnimation("stand");
        }
        
        sprite.FlipX(flipped);
    }
    
    void Player::Render(sf::RenderTarget& target, sf::Renderer& renderer) const {
        target.Draw(sprite);
    }
}