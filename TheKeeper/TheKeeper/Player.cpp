//
//  Player.cpp
//  TheKeeper
//
//  Created by Jay Roberts on 9/16/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#include "Player.hpp"
#include "ResourcePath.hpp"
#include "ConfigFile.hpp"
#include <string>
#include "GFE/Logger.hpp"
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <map>

namespace Keeper {
    
    Player::Player(void) : sf::Drawable() {
        // player.ini file contains information about the player's sprites
        ConfigFile config(ResourcePath() + "player.ini");
        
        std::string texture_file = config.read<std::string>("filename", "spritesheet.png");
        
        spritesheet = sf::Texture();
        spritesheet.LoadFromFile(ResourcePath() + texture_file);
        sprite = sf::Sprite(spritesheet);
        
        int scale = config.read<int>("scale", 4);
        sprite.SetScale(scale, scale);
        BuildAnimations(config);
        
        stand_frame = sf::IntRect(0, 0, 8, 8);
        sprite.SetSubRect(stand_frame);
    }
    
    Player::~Player() {
        
    }
    
    void Player::BuildAnimations(ConfigFile config) {
        GFE::Logger::Log() << "Loading Player animations:";
        sf::Vector2i frame_size(config.read<int>("width", 8),
                                config.read<int>("height", 8));        
        
        // Build a vector of animation names
        std::string animationlist = config.read<std::string>("animations", "walk");
        std::vector<std::string> animation_names;
        boost::split(animation_names, animationlist, boost::is_any_of(","));
        
        // Load all of the frames for each animation
        for(std::vector<std::string>::iterator name = animation_names.begin(); name != animation_names.end(); ++name) {
            
            GFE::Logger::Log() << "- " + *name;
            
            // frameline
            std::string positionlist = config.read<std::string>(*name);

            // split into frame positions
            std::vector<std::string> positions;
            boost::split(positions, positionlist, boost::is_any_of("-"));
            
            std::vector<sf::IntRect> frames;
            
            for (std::vector<std::string>::iterator position = positions.begin(); position != positions.end(); ++position) {
                
                std::vector<std::string> pos;
                boost::split(pos, *position, boost::is_any_of(","));

                int x = boost::lexical_cast<int>(pos[0]);
                int y = boost::lexical_cast<int>(pos[1]);

                sf::IntRect frame(x, y, x * frame_size.x, frame_size.y);
                
                frames.push_back(frame);
            }

            animations[*name] = frames;
            
        }

        
        
    }
    
    void Player::Render(sf::RenderTarget& target, sf::Renderer& renderer) const {
        target.Draw(sprite);
    }
    
    
    
}