//
//  MobPedestrian.hpp
//  TheKeeper
//
//  Created by Jay Roberts on 10/19/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#ifndef TheKeeper_MobPedestrian_hpp
#define TheKeeper_MobPedestrian_hpp

#include <SFML/Graphics.hpp>
#include "ConfigFile.hpp"
#include "GFE/Entity.hpp"
#include "GFE/AnimationStore.hpp"
#include "Mob.hpp"

namespace Keeper {
    class MobPedestrian : public Mob {
        sf::Texture spritesheet;
        sf::Sprite sprite;
        
        GFE::AnimationStore animations;
        
        std::vector<GFE::Frame> current_animation;
        std::string current_animation_name;
        int current_animation_frame;
        float current_animation_duration;
        
        
        
    public:
        MobPedestrian(void);
        ~MobPedestrian();
        
        void SetAnimation(std::string animation);

        virtual void Update(float dt);
        
    private:
        void Animate(float dt);
        
        virtual void Render(sf::RenderTarget& target, sf::Renderer& renderer) const;
    };
}



#endif
