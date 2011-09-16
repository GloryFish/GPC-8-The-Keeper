//
//  KeeperGame.cpp
//  TheKeeper
//
//  Created by Jay Roberts on 9/16/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#include "KeeperGame.hpp"
#include <string>
#include "GFE/Logger.hpp"
#include "GameState.hpp"
namespace Keeper {
    
    KeeperGame::KeeperGame(const std::string theTitle) : GFE::Game(theTitle) {
        
    }
    
    KeeperGame::~KeeperGame(void) {
        
    }
    
    void KeeperGame::Init(void) {
        GFE::Logger::Log() << "SRG Init";
        stateManager.AddActiveState(new(std::nothrow) Keeper::GameState(this));
        stateManager.GetActiveState();
    }
    
}