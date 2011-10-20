//
//  StatDisplay.cpp
//  TheKeeper
//
//  Created by Jay Roberts on 10/19/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#include "StatDisplay.hpp"
#include <sstream>

namespace GFE {
    
    StatDisplay::StatDisplay(void) : 
        update_clock(), 
        render_clock(), 
        ups(),
        fps(),
        updates(0),
        frames(0) {
            fps.SetColor(sf::Color(255, 255, 255, 175));
            fps.SetPosition(0, 30);
            fps.SetCharacterSize(16);
            fps.SetString("");
            
            ups.SetColor(sf::Color(255, 255, 255, 175));
            ups.SetPosition(0, 50);
            ups.SetCharacterSize(16);
            ups.SetString("");
    }
    
    StatDisplay::~StatDisplay() {
        
    }
    
    void StatDisplay::Update(float dt) {
        updates++;
        
        if (update_clock.GetElapsedTime() > 1000) {
            
            std::stringstream update_message; 
            
            update_message.precision(2);
            update_message.width(7);
            update_message << "UPS: " << std::fixed << updates;

            ups.SetString(update_message.str());
            
            updates = 0;
            update_clock.Reset();
        }
    }
    
    void StatDisplay::Draw(sf::RenderWindow &window) {
        frames++;
        
        if (render_clock.GetElapsedTime() > 1000) {
            
            std::stringstream frames_message; 
            
            frames_message.precision(2);
            frames_message.width(7);
            frames_message << "FPS: " << std::fixed << frames;
            
            fps.SetString(frames_message.str());
            
            frames = 0;
            render_clock.Reset();
        }
        
        window.Draw(fps);
        window.Draw(ups);
    }
    
}