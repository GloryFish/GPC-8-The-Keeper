//
//  MobFactory.h
//  TheKeeper
//
//  Created by Jay Roberts on 10/1/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#ifndef TheKeeper_MobFactory_h
#define TheKeeper_MobFactory_h

#include "Mob.hpp"

namespace Keeper {
    
    enum MobType {
        MobTypePedestrian
    };
    
    class MobFactory {
        public:
        MobFactory();
        ~MobFactory();
        
        static Mob NewMob(MobType type);
        
        private: 
            
        
    };
    
    
}


#endif
