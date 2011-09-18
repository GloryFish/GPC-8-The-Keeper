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
#include "ResourcePath.hpp"

namespace Keeper {
    
    GameState::GameState(GFE::Game* theGame) : IState("Game", theGame) {
        background_image.LoadFromFile(ResourcePath() + "scene.png");
        background = sf::Sprite(background_image);
        background.SetScale(4, 4);
        background.SetOrigin(0, 0);
        background.SetPosition(0, 0);
        
        camera.Reset(game->GetDisplayRect());
        game->SetView(camera.GetView());
    }
    
    GameState::~GameState(void) {
        
    }
    
    void GameState::HandleEvents(sf::Event event) {
        switch (event.Type) {
            case (sf::Event::KeyPressed):
                if (event.Key.Code == sf::Keyboard::Escape) {
                    game->Quit();
                }
                break;
            case (sf::Event::MouseButtonPressed):
                player.SetTarget(game->GetMousePosition());
                break;
            default:
                break;
        }
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
        
        sf::IntRect bounds(sf::Vector2i(0, 0), sf::Vector2i(background.GetSize().x, background.GetSize().y));
        
        camera.SetBounds(bounds);
        camera.SetFocus(player.GetPosition());
        camera.Update(dt);
        game->SetView(camera.GetView());

    }
    
    void GameState::Draw(void) {
        // Check our App pointer
        assert(NULL != game && "SplashState::Draw() bad app pointer, init must be called first");
        
        game->window.Clear(sf::Color(64, 64, 64, 255));
        game->window.Draw(background);
        game->window.Draw(player);
    }
    
    void GameState::Cleanup(void) {
        // Last of all, call our base class implementation
        IState::Cleanup();
    }
    
}