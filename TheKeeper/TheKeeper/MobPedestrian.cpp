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

namespace Keeper {
    MobPedestrian::MobPedestrian(void) : animations("mobs") {
        
        std::string texture_file = animations.GetSpritesheetFilename();
        
        spritesheet = GFE::TextureManager::GetTexture(texture_file);
        sprite = sf::Sprite(spritesheet);
        int scale = 4;
        sprite.SetScale(scale, scale);
        
        sprite.SetOrigin(0.5 * 8, 1.0f * 8);
        
        
        SetAnimation("stand");
        
        SetPosition(350, 200);

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
    
    void MobPedestrian::Update(float dt) {
        GFE::Logger::Log() << "MobPedestrian::Update()";
        
        Animate(dt);
        
    }

    void MobPedestrian::SetAnimation(std::string animation) {
        if (animation == current_animation_name) {
            return;
        }
        
        current_animation = animations.GetAnimation("mob_pedestrian_0_" + animation);
        current_animation_name = animation;
        current_animation_frame = 0;
        current_animation_duration = 0;
        sprite.SetSubRect(current_animation[current_animation_frame].rect);
    }

    void MobPedestrian::Render(sf::RenderTarget& target, sf::Renderer& renderer) const {
        GFE::Logger::Log() << "MobPedestrian::Render()";
        target.Draw(sprite);
    }

    
}
