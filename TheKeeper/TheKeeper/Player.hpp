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

namespace Keeper {
    class Player : public sf::Drawable {
        sf::Texture spritesheet;
        sf::Sprite sprite;
        std::map<std::string, std::vector<sf::IntRect> > animations;
        sf::Rect<int> stand_frame;
        std::string current_animation_name;
        int current_animation_frame;
        float current_animation_duration;
        float animation_delay;
    public:
        
        Player(void);
        ~Player();
        void SetAnimation(std::string animation);
        void Update(float dt);
    private:
        void BuildAnimations(ConfigFile config);
        virtual void Render(sf::RenderTarget& target, sf::Renderer& renderer) const;
    };
}


#endif
