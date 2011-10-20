//
//  AnimationStore.hpp
//  TheKeeper
//
//  Created by Jay Roberts on 9/27/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#ifndef TheKeeper_AnimationStore_hpp
#define TheKeeper_AnimationStore_hpp

#include <string>
#include <boost/property_tree/ptree.hpp>
#include <SFML/Graphics.hpp>

namespace GFE {
    
    struct Frame {
        float duration;
        sf::IntRect rect;
    };
    
    class AnimationStore {
        
        std::map<std::string, std::vector<Frame> > animations;
        std::string spritesheet_filename;
    public:
        explicit AnimationStore(const std::string &groupName);
        ~AnimationStore();
        
        std::vector<Frame> GetAnimation(std::string animationName);
        std::string GetSpritesheetFilename();
    private:
        void LoadFrames(boost::property_tree::ptree);
        
    };
    
}

#endif
