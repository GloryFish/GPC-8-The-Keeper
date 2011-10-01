//
//  PedestrianAIComponent.hpp
//  TheKeeper
//
//  Created by Jay Roberts on 10/1/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#ifndef TheKeeper_PedestrianAIComponent_hpp
#define TheKeeper_PedestrianAIComponent_hpp

#include "IAIComponent.hpp"
#include "GFE/Entity.hpp"

namespace Keeper {

    class PedestrianAIComponent : public GFE::IAIComponent {
        
        GFE::Entity* entity;
        
    public:
        PedestrianAIComponent();
        virtual ~PedestrianAIComponent();
        
        virtual void Update(float dt);

    private:
        
        
        
    };
    
    
}



#endif
