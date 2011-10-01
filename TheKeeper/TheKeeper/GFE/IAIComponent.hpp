//
//  IAIComponent.hpp
//  TheKeeper
//
//  Created by Jay Roberts on 10/1/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#ifndef TheKeeper_IAIComponent_hpp
#define TheKeeper_IAIComponent_hpp

#include "Entity.hpp"

namespace GFE {
    
    class IAIComponent {
        Entity* entity;
        
        
    public:
        IAIComponent() {
            
        }
        
        virtual ~IAIComponent() {
            
        }
        
        virtual void Update(float dt) = 0;
        
        void SetEntity(Entity* theEntity) {
            entity = theEntity;
        }
    };
    
    
}

#endif
