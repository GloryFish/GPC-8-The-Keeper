//
//  AnimationStore.cpp
//  TheKeeper
//
//  Created by Jay Roberts on 9/27/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#include "AnimationStore.hpp"
#include <string>
#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "ResourcePath.hpp"
#include "Logger.hpp"

namespace GFE {
    
    AnimationStore::AnimationStore(const std::string &groupName) {
        // Load porpoert tree for the supplied group name
        // This is a file in the project named <groupname>.ani
        boost::property_tree::ptree pt;
        
        std::string filename = ResourcePath() + groupName + ".ani";
        
        try {
            read_json(filename, pt);
        } catch (std::exception &e) {
            Logger::Log() << "[AnimationStore] Error loading <" << groupName << "> " << e.what();
            Logger::Flush();
        }

        BOOST_FOREACH(boost::property_tree::ptree::value_type &a, pt.get_child("animations")) {
            std::string animationName = a.first;
            
            std::vector<Frame> frames;
            
            BOOST_FOREACH(boost::property_tree::ptree::value_type &f, a.second) {
                Frame frame;
                frame.duration = f.second.get("duration", 1.0f);
                
                frame.rect = sf::IntRect(
                                 f.second.get<int>("rect.x"),
                                 f.second.get<int>("rect.y"),
                                 f.second.get<int>("rect.width"),
                                 f.second.get<int>("rect.height")
                            ); 
                frames.push_back(frame);
            }
            
            animations[animationName] = frames;
        }
        
    }
    
    AnimationStore::~AnimationStore() {
        
    }
    
    
    std::vector<Frame> AnimationStore::GetAnimation(std::string animationName) {
        return animations[animationName];
    }
    
}

