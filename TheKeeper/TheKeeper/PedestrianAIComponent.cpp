//
//  PedestrianAIComponent.cpp
//  TheKeeper
//
//  Created by Jay Roberts on 10/1/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#include "PedestrianAIComponent.hpp"
#include "GFE/Entity.hpp"
#include "GFE/Logger.hpp"

namespace Keeper {
  
    PedestrianAIComponent::PedestrianAIComponent() : IAIComponent() {
      
    }
  
    PedestrianAIComponent::~PedestrianAIComponent() {
      
    }
  
    void PedestrianAIComponent::Update(float dt) {
        GFE::Logger::Log() << "PedestrianAIComponent Update";

    }


}