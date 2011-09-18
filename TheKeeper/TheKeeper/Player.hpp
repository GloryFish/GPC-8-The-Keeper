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

namespace Keeper {
    class Player : public GFE::Entity {
        sf::Texture spritesheet;
        sf::Sprite sprite;
        std::map<std::string, std::vector<sf::IntRect> > animations;
        std::string current_animation_name;
        int current_animation_frame;
        float current_animation_duration;
        float animation_delay;
        sf::Vector2f target;
        float speed;
        bool flipped;
    public:
        
        Player(void);
        ~Player();
        void SetAnimation(std::string animation);
        void SetTarget(sf::Vector2f theTarget);
        void Update(float dt);
    private:
        void BuildAnimations(ConfigFile config);
        virtual void Render(sf::RenderTarget& target, sf::Renderer& renderer) const;
    };
}


#endif
