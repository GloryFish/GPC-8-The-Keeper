//
//  Player.hpp
//  TheKeeper
//
//  Created by Jay Roberts on 9/16/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#ifndef TheKeeper_Player_hpp
#define TheKeeper_Player_hpp

#include <SFML/Graphics.hpp>
#include "ConfigFile.hpp"
#include "GFE/Entity.hpp"
#include "GFE/AnimationStore.hpp"

namespace Keeper {
    class Player : public GFE::Entity {
        sf::Texture spritesheet;
        sf::Sprite sprite;
        
        GFE::AnimationStore animations;

        std::vector<GFE::Frame> current_animation;
        std::string current_animation_name;
        int current_animation_frame;
        float current_animation_duration;

        sf::Vector2f target;
        float speed;
        float scale;

    public:
        
        Player(void);
        ~Player();
        void SetAnimation(std::string animation);
        void SetTarget(sf::Vector2f theTarget);
        virtual void Update(float dt);
        virtual void SetPosition(sf::Vector2f position);
        virtual sf::Vector2f GetPosition(void);
    private:
        void Animate(float dt);

        virtual void Draw(sf::RenderTarget& target, sf::RenderStates renderStates) const;
    };
}


#endif
