//
//  Mob.hpp
//  TheKeeper
//
//  Created by Jay Roberts on 10/1/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#ifndef TheKeeper_Mob_hpp
#define TheKeeper_Mob_hpp

#include "GFE/Entity.hpp"
#include "IAIComponent.hpp"
#include <SFML/Graphics.hpp>
#include "GFE/AnimationStore.hpp"

namespace Keeper {
    
    class Mob : public GFE::Entity {

        sf::Texture spritesheet;
        sf::Sprite sprite;

        GFE::AnimationStore animations;

        
        GFE::IAIComponent* aiComponent;

    public:
        Mob();
        ~Mob();
        void Update(float dt);
        
    private:

        virtual void Render(sf::RenderTarget& target, sf::Renderer& renderer) const;

        
    };
    
    
}

#endif
