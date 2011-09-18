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
        focus = sf::Vector2f(0, 0);
        bounds = sf::IntRect(0, 0, 100, 100);
        deadzone = 50;
    }
    
    void Camera::Reset(sf::FloatRect rect) {
        view.Reset(rect);
    }
    
    void Camera::SetFocus(sf::Vector2f theFocus) {
        focus = theFocus;
    }

    void Camera::SetBounds(sf::IntRect theBounds) {
        
        bounds = theBounds;
    }

    void Camera::Update(float dt) {
        // This particular implementation only pans left and right
        sf::Vector2f pos = view.GetCenter();
        
        if (GFE::VectorMath::Distance(view.GetCenter(), focus) > deadzone) {
            pos.x -= (pos.x - focus.x) * dt;
        }

        sf::Vector2f half_size = view.GetSize() / 2.0f;
        
        if (pos.x - half_size.x < bounds.Left) {
            pos.x = bounds.Left + half_size.x;
        }
        if (pos.x + half_size.x > bounds.Left + bounds.Width) {
            pos.x = bounds.Left + bounds.Width - half_size.x;
        }
        
        view.SetCenter(pos);
    }
    
    sf::View& Camera::GetView(void) {
        return view;
    }
    
}