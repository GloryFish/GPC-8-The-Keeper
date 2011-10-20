//
//  Entity.hpp
//  TheKeeper
//
//  Created by Jay Roberts on 9/18/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#ifndef TheKeeper_Entity_hpp
#define TheKeeper_Entity_hpp

#include <SFML/Graphics.hpp>

namespace GFE {
    
    class Entity : public sf::Drawable {
    public:
        Entity(void);
        ~Entity();

        virtual void Update(float dt);
        
    private:
        virtual void Render(sf::RenderTarget& target, sf::Renderer& renderer) const;
    };
    
    bool SortEntities(const sf::Drawable* a, const sf::Drawable* b);
}

#endif
