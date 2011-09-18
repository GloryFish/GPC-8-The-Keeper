//
//  TextureManager.hpp
//  TheKeeper
//
//  Created by Jay Roberts on 9/18/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#ifndef TheKeeper_TextureManager_hpp
#define TheKeeper_TextureManager_hpp

#include <SFML/Graphics.hpp>

namespace GFE {
    
    static std::map<std::string, sf::Texture> textures;
    
    class TextureManager {
    public:
        static sf::Texture& GetTexture(std::string name);  
    private:
        /**
         * StateManager copy constructor is private because we do not allow copies
         * of our class
         */
        TextureManager(const TextureManager&); // Intentionally undefined
        
        /**
         * Our assignment operator is private because we do not allow copies
         * of our class
         */
        TextureManager& operator=(const TextureManager&); // Intentionally
    };
}

#endif
