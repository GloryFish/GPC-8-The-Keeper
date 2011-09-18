//
//  TextureManager.cpp
//  TheKeeper
//
//  Created by Jay Roberts on 9/18/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#include "TextureManager.hpp"
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"

namespace GFE {
    
    sf::Texture& TextureManager::GetTexture(std::string name) {
        if (textures.count(name)) {
            return textures[name];
        }
        
        sf::Texture texture;
        texture.LoadFromFile(ResourcePath() + name);
        
        textures[name] = texture;
        
        return GetTexture(name);
    }
    
}