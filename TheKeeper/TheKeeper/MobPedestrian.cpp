//
//  MobPedestrian.cpp
//  TheKeeper
//
//  Created by Jay Roberts on 10/19/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#include "MobPedestrian.hpp"
#include "GFE/Logger.hpp"
#include "GFE/TextureManager.hpp"
#include "GFE/VectorMath.hpp"
#include <sstream>

namespace Keeper {
    
    MobPedestrian::MobPedestrian(void) : animations("mobs") {
        flipped = false;
        speed = 75;
        bounds = sf::IntRect(0, 0, 0, 0);
        
        // Choose a random animation prefix
        std::stringstream prefix;
        int mob_id = rand() % 2; // We currently have 2 mobs defined in mobs.ani
        prefix << "mob_pedestrian_" << mob_id << "_";
        animation_prefix = prefix.str();
        
        GFE::Logger::Log() << "Using animation prefix: " << animation_prefix;
        GFE::Logger::Flush();
        
        std::string texture_file = animations.GetSpritesheetFilename();
        
        spritesheet = GFE::TextureManager::GetTexture(texture_file);
        sprite = sf::Sprite(spritesheet);
        int scale = 4;
        sprite.SetScale(scale, scale);
        
        sprite.SetOrigin(0.5 * 8, 1.0f * 8);
        
        SetAnimation("stand");
        
        SetPosition(350, 200);
        SetTarget(sf::Vector2f(350.0f, 200.0f));

    }
    
    MobPedestrian::~MobPedestrian() {
        
    }

    void MobPedestrian::Animate(float dt) {
        current_animation_duration += dt;
        
        if (current_animation_duration > current_animation[current_animation_frame].duration) {
            current_animation_duration = 0;
            current_animation_frame++;
            if (current_animation_frame == current_animation.size()) {
                current_animation_frame = 0;
            }
        }
        
        sprite.SetSubRect(current_animation[current_animation_frame].rect);
    }
    
    void MobPedestrian::SetTarget(sf::Vector2f theTarget) {
        // Don't let the target be too close to avoid
        if (GFE::VectorMath::Distance(avoid, theTarget) < 64) {
            return;
        }
        
        target = theTarget;
        
        // Don't let the Mob move up too high
        if (target.y < 185) {
            target.y = 185;
        }
        

    }

    void MobPedestrian::SetAvoid(sf::Vector2f theAvoid) {
        avoid = theAvoid;
    }

    void MobPedestrian::SetBounds(sf::IntRect theBounds) {
        bounds = theBounds;
    }
    
    void MobPedestrian::Update(float dt) {
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
            
            // Avoid 
            float avoid_dist = GFE::VectorMath::Distance(GetPosition(), avoid);
            float avoid_force = 100000 / (avoid_dist * avoid_dist);
            sf::Vector2f avoid_ment =  GetPosition() - avoid;
            avoid_ment = GFE::VectorMath::Normalize(avoid_ment);
            avoid_ment = avoid_ment * avoid_force * dt;
            
            movement = movement + avoid_ment;
            
            // Apply movement vector
            Move(movement);
            
            SetAnimation("walk");
            
            if (movement.x < 0) {
                flipped = true;
            } else {
                flipped = false;
            }
        } else { // Get a new random target
            int top_edge = 185; 
            
            sf::Vector2f newTarget(rand() % bounds.Width, top_edge + (rand() % (bounds.Height - top_edge)));

            SetTarget(newTarget);
        }
        
        sprite.FlipX(flipped);
    }

    void MobPedestrian::SetAnimation(std::string animation) {
        if (animation == current_animation_name) {
            return;
        }
        
        current_animation = animations.GetAnimation(animation_prefix + animation);
        current_animation_name = animation;
        current_animation_frame = 0;
        current_animation_duration = 0;
        sprite.SetSubRect(current_animation[current_animation_frame].rect);
    }

    void MobPedestrian::Render(sf::RenderTarget& target, sf::Renderer& renderer) const {
        target.Draw(sprite);
    }

    
}
