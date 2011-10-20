//
//  StatDisplay.hpp
//  TheKeeper
//
//  Created by Jay Roberts on 10/19/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#ifndef TheKeeper_StatDisplay_hpp
#define TheKeeper_StatDisplay_hpp

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

namespace GFE {
    class StatDisplay {
        
        sf::Clock update_clock;
        sf::Clock render_clock;
        sf::Text ups;
        sf::Text fps;
        int frames;
        int updates;
    public:
        StatDisplay(void);
        ~StatDisplay();
        
        void Update(float dt);
        void Draw(sf::RenderWindow &window);
        
        
        
    };
}

#endif
