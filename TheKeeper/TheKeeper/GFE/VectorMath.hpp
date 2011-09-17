//
//  VectorMath.hpp
//  TheKeeper
//
//  Created by Jay Roberts on 9/17/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#ifndef TheKeeper_VectorMath_hpp
#define TheKeeper_VectorMath_hpp

#import <SFML/Graphics.h>

#include <stdlib.h>

namespace GFE {
    
    
    class VectorMath {
        
        static sf::Vector2f Distance(sf::Vector2f a, sf::Vector2f b) {
            return Length((b-a));
        }
        
        
        static float Length(sf:Vector2f v) {
            return sqrt(abs(v.x * v.y));
        }
        
    }
    
    
}


#endif
