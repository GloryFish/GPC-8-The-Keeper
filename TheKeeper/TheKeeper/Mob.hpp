//
//  Mob.hpp
//  TheKeeper
//
//  Created by Jay Roberts on 10/19/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#ifndef TheKeeper_Mob_hpp
#define TheKeeper_Mob_hpp

#include "GFE/Entity.hpp"

namespace Keeper {
    class Mob : public GFE::Entity {

    public:
        Mob(void);
        ~Mob();
        virtual void Update(float dt);
    private:
        virtual void Draw(sf::RenderTarget& target, sf::RenderStates renderStates) const;
    };
}

#endif
