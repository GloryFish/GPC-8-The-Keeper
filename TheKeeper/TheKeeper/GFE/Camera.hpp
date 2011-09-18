//
//  Camera.hpp
//  TheKeeper
//
//  Created by Jay Roberts on 9/17/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#ifndef TheKeeper_Camera_hpp
#define TheKeeper_Camera_hpp

#include <SFML/Graphics.hpp>

namespace GFE {
    
    class Camera {
        
        sf::View view;
        sf::Vector2f target;
        float speed;
        
    public:
        Camera();
        void Reset(sf::FloatRect rect);
        void SetTarget(sf::Vector2f theTarget);
        void Update(float dt);
        sf::View& GetView(void);
    };
    
}

#endif
