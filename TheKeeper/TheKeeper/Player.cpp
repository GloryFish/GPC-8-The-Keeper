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
    
    Player::Player(void) : sf::Drawable() {
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

        
        BuildAnimations(config);
        
        SetAnimation("walk");

        SetPosition(64, 208);
        SetTarget(sf::Vector2f(64, 208));
    }
    
    Player::~Player() {
        
    }
    
    void Player::BuildAnimations(ConfigFile config) {
        GFE::Logger::Log() << "Loading Player animations:";
        sf::Vector2i frame_size(config.read<int>("width", 8),
                                config.read<int>("height", 8));
        
        animation_delay = config.read<float>("delay", 5.0f);
        
        // Build a vector of animation names
        std::string animationlist = config.read<std::string>("animations", "walk");
        std::vector<std::string> animation_names;
        boost::split(animation_names, animationlist, boost::is_any_of(","));
        
        // Load all of the frames for each animation
        for(std::vector<std::string>::iterator name = animation_names.begin(); name != animation_names.end(); ++name) {
            
            GFE::Logger::Log() << "- " + *name;
            
            // frameline
            std::string positionlist = config.read<std::string>(*name);

            // split into frame positions
            std::vector<std::string> positions;
            boost::split(positions, positionlist, boost::is_any_of("-"));
            
            std::vector<sf::IntRect> frames;
            
            for (std::vector<std::string>::iterator position = positions.begin(); position != positions.end(); ++position) {
                
                std::vector<std::string> pos;
                boost::split(pos, *position, boost::is_any_of(","));

                int x = boost::lexical_cast<int>(pos[0]);
                int y = boost::lexical_cast<int>(pos[1]);

                sf::IntRect frame(x * frame_size.x, 
                                  y * frame_size.y, 
                                  frame_size.x,
                                  frame_size.y);
                
                frames.push_back(frame);
            }

            animations[*name] = frames;
            
        }
    }
    
    void Player::SetAnimation(std::string animation) {
        if (animation == current_animation_name) {
            return;
        }
        
        current_animation_name = animation;
        current_animation_frame = 0;
        current_animation_duration = 0;
        sprite.SetSubRect(animations[current_animation_name][current_animation_frame]);
    }
    
    void Player::SetTarget(sf::Vector2f theTarget) {
        GFE::Logger::Log() << "New target: " << theTarget.x << ", " << theTarget.y;
        GFE::Logger::Log() << "Distance: " << GFE::VectorMath::Distance(GetPosition(), theTarget);
        
        target = theTarget;
        
        if (target.y < 185) {
            target.y = 185;
        }
    }
    
    void Player::Update(float dt) {
        // Process animation
        current_animation_duration += dt;
        
        if (current_animation_duration > animation_delay) {
            current_animation_duration = 0;
            current_animation_frame++;
            if (current_animation_frame == animations[current_animation_name].size()) {
                current_animation_frame = 0;
            }
        }
        
        sprite.SetSubRect(animations[current_animation_name][current_animation_frame]);
        
        
        sf::Vector2f movement(0, 0); 
        
        // Move to target
        if (GFE::VectorMath::Distance(GetPosition(), target) > 3) {
            // Get vector pointing at target
            movement = target - GetPosition();

            // Normalize
            movement = GFE::VectorMath::Normalize(movement);
            
            // Multiply by speed
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