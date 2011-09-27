//
//  Pedestrian.hpp
//  TheKeeper
//
//  Created by Jay Roberts on 9/18/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#ifndef TheKeeper_Pedestrian_hpp
#define TheKeeper_Pedestrian_hpp

#include <SFML/Graphics.hpp>
#include "ConfigFile.hpp"
#include "GFE/Entity.hpp"

namespace Keeper {
    
    class Pedestrian : public GFE::Entity {
        sf::Texture spritesheet;
        sf::Sprite sprite;
        std::map<std::string, std::vector<sf::IntRect> > animations;
        std::string current_animation_name;
        int current_animation_frame;
        float current_animation_duration;
        float animation_delay;
        float speed;
        bool flipped;
        
    public:
        Pedestrian(void);
        ~Pedestrian();
        void SetAnimation(std::string animation);
        void Update(float dt);
    private:
        void BuildAnimations(ConfigFile config);
        virtual void Render(sf::RenderTarget& target, sf::Renderer& renderer) const;
    };
}

#endif
