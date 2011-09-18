//
//  Camera.cpp
//  TheKeeper
//
//  Created by Jay Roberts on 9/17/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#include "Camera.hpp"
#include "VectorMath.hpp"

namespace GFE {
    
    Camera::Camera() {
        target = sf::Vector2f(0, 0);
        speed = 150;
    }
    
    void Camera::Reset(sf::FloatRect rect) {
        view.Reset(rect);
    }
    
    void Camera::SetTarget(sf::Vector2f theTarget) {
        target = theTarget;
    }
    
    void Camera::Update(float dt) {
        sf::Vector2f movement(0, 0); 
        
        // Move to target
        if (GFE::VectorMath::Distance(view.GetCenter(), target) > 3) {
            // Get vector pointing at target
            movement = target - view.GetCenter();
            
            // Normalize
            movement = GFE::VectorMath::Normalize(movement);
            
            // Multiply by speed
            movement = movement * speed * dt;
            
            // Apply movement vector
            view.Move(movement);
        }
    }
    
    sf::View& Camera::GetView(void) {
        return view;
    }
    
}