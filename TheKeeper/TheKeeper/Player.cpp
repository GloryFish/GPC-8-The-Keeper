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
        
        std::string texture_file = config.read<std::string>("filename", "spritesheet.png");
        
        spritesheet = GFE::TextureManager::GetTexture(texture_file);
        sprite = sf::Sprite(spritesheet);
        scale = config.read<float>("scale", 4.0f);
        sprite.SetScale(scale, scale);
        
        sprite.SetOrigin(0.5 * config.read<int>("width", 8), 
                         1.0f * config.read<int>("height", 8));

        
        SetAnimation("stand");

        SetPosition(sf::Vector2f(64, 208));
        SetTarget(sf::Vector2f(64, 208));
    }
    
    Player::~Player() {
        
    }
    
    void Player::SetAnimation(std::string animation) {
        if (animation == current_animation_name) {
            return;
        }
        GFE::Logger::Log() << "Changed animation: " << animation;
        
        current_animation = animations.GetAnimation(animation);
        current_animation_name = animation;
        current_animation_frame = 0;
        current_animation_duration = 0;
        sprite.SetTextureRect(current_animation[current_animation_frame].rect);
    }
    
    void Player::SetTarget(sf::Vector2f theTarget) {
        if (GFE::VectorMath::Distance(target, theTarget) < 32) {
            return;
        }
        
        target = theTarget;
        
        // Don't let the player move up too high
        if (target.y < 185) {
            target.y = 185;
        }
    }
    
    
    void Player::Animate(float dt) {
        current_animation_duration += dt;
        
        if (current_animation_duration > current_animation[current_animation_frame].duration) {
            current_animation_duration = 0;
            current_animation_frame++;
            if (current_animation_frame == current_animation.size()) {
                current_animation_frame = 0;
            }
        }
        
        sprite.SetTextureRect(current_animation[current_animation_frame].rect);
    }
    
    void Player::Update(float dt) {
        Animate(dt);
        
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
            sprite.Move(movement);
            
            SetAnimation("walk");
            
            if (movement.x < 0) {
                sprite.SetScale(scale * -1, scale);
            } else {
                sprite.SetScale(scale, scale);
            }
        } else {
            SetAnimation("stand");
        }
    }
    
    sf::Vector2f Player::GetPosition() {
        return sprite.GetPosition();
    }
    
    void Player::SetPosition(sf::Vector2f position) {
        sprite.SetPosition(position);
    }
    
    void Player::Draw(sf::RenderTarget& target, sf::RenderStates renderStates) const {
        target.Draw(sprite);
    }
}