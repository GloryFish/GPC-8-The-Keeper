//
//  Trashcan.h
//  TheKeeper
//
//  Created by Jay Roberts on 9/18/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#ifndef TheKeeper_Trashcan_h
#define TheKeeper_Trashcan_h

#include <SFML/Graphics.hpp>
#include "ConfigFile.hpp"
#include "GFE/Entity.hpp"

namespace Keeper {
    class Trashcan : public sf::Drawable {
        sf::Texture spritesheet;
        sf::Sprite sprite;
        sf::IntRect upright_frame;
        sf::IntRect tipped_frame;
        bool tipped;
        
    public:
        Trashcan(void);
        Trashcan(float x, float y);
        ~Trashcan();
        void Tip(void);
        bool IsTipped(void);
        void Reset(void);
    
    private:
        virtual void Render(sf::RenderTarget& target, sf::Renderer& renderer) const;
    };
}



#endif
