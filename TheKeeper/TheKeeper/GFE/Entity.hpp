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
        virtual void SetPosition(sf::Vector2f position);
        virtual sf::Vector2f GetPosition(void);
    private:
        virtual void Draw(sf::RenderTarget& target, sf::RenderStates renderStates) const;
    };
    
    bool SortEntities(GFE::Entity* a, GFE::Entity* b);
}

#endif
