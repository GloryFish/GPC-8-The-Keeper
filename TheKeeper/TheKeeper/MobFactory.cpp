//
//  MobFactory.cpp
//  TheKeeper
//
//  Created by Jay Roberts on 10/1/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#include "MobFactory.hpp"
#include "PedestrianAIComponent.hpp"
#include "GFE/Logger.hpp"

namespace Keeper {
    
    MobFactory::MobFactory() {
        
    }
    
    MobFactory::~MobFactory() {
        
    }
    
    
    Mob MobFactory::NewMob(MobType type) {
        Mob mob;
        
        if (type == MobTypePedestrian) {
            GFE::Logger::Log() << "Creating a Pedestrian mob";
            PedestrianAIComponent* ai = new PedestrianAIComponent();
            mob.SetAIComponent(ai);
        }
        
        return mob;
    }
    
}