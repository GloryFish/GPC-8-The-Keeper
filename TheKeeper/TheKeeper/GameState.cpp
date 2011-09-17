//
//  GameState.cpp
//  TheKeeper
//
//  Created by Jay Roberts on 9/16/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#include "GameState.hpp"
#include "GFE/Logger.hpp"
#include "assert.h"

namespace Keeper {
    
    GameState::GameState(GFE::Game* theGame) : IState("Game", theGame) {
    }
    
    GameState::~GameState(void) {
        
    }
    
    void GameState::HandleEvents(sf::Event theEvent) {
    }
    
    void GameState::DoInit(void) {
        GFE::Logger::Log() << "GameState Init";
        
        // First call our base class implementation
        IState::DoInit();
        
        // Check our App pointer
        assert(NULL != game && "GreenState::DoInit() bad app pointer");
    }
    
    void GameState::ReInit(void) {
        // Do nothing yet
    }
    
    void GameState::Update(float dt) {
        // Check our App pointer
        assert(NULL != game && "SplashState::UpdateVariable() bad app pointer, init must be called first");
        
        player.Update(dt);
        
        
    }
    
    void GameState::Draw(void) {
        // Check our App pointer
        assert(NULL != game && "SplashState::Draw() bad app pointer, init must be called first");
        
        game->window.Clear(sf::Color::Green);
        
        game->window.Draw(player);
    }
    
    void GameState::Cleanup(void) {
        // Last of all, call our base class implementation
        IState::Cleanup();
    }
    
}