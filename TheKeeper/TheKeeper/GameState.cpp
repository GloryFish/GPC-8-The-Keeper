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
#include <SFML/Audio.hpp>
#include "NameGenerator.hpp"

namespace Keeper {
    
    GameState::GameState(GFE::Game* theGame) : IState("Game", theGame) {
        mouse_down = false;
        gender = GenderBoth;
        
        background_image.LoadFromFile(ResourcePath() + "scene.png");
        background = sf::Sprite(background_image);
        background.SetScale(4, 4);
        background.SetOrigin(0, 0);
        background.SetPosition(0, 0);
        
        camera.Reset(game->GetDisplayRect());
        game->SetView(camera.GetView());
        
        // Open it from an audio file
        music.OpenFromFile(ResourcePath() + "fruit_fly.ogg");
        
        // Change some parameters
        music.SetVolume(50);
        music.SetLoop(true);
        
        // Play it
        music.Play();
        
        // Add player to scene list
        objects.push_back(&player);

        // Create trashcans
        for (int x = 100; x <= 1200; x += 200) {
            Trashcan* can = new Trashcan(x, 220);
            cans.push_back(can);
            objects.push_back(can);
        }
        
        // Create mobs
        for (int x = 0; x <= 5;  x++) {
            MobPedestrian* mob = new MobPedestrian();
            mobs.push_back(mob);
            objects.push_back(mob);
        }
        
    }
    
    GameState::~GameState(void) {
        // delete Trashcans
        for (std::vector<GFE::Entity*>::iterator iter = cans.begin(); iter < cans.end(); ++iter) {
            delete *iter;
        }

        // delete Mobs
        for (std::vector<Mob*>::iterator iter = mobs.begin(); iter < mobs.end(); ++iter) {
            delete *iter;
        }
    }
    
    void GameState::HandleEvents(sf::Event event) {
        switch (event.Type) {
            case (sf::Event::KeyPressed):
                if (event.Key.Code == sf::Keyboard::Escape) {
                    game->Quit();
                }
                if (event.Key.Code == sf::Keyboard::M) {
                    gender = GenderMale;
                }
                if (event.Key.Code == sf::Keyboard::F) {
                    gender = GenderFemale;
                }
                if (event.Key.Code == sf::Keyboard::B) {
                    gender = GenderBoth;
                }
                if (event.Key.Code == sf::Keyboard::N) {
                    GFE::Logger::Log() << nameGenerator.GetRandomName(gender);
                }
                break;
            case (sf::Event::MouseButtonPressed):
                mouse_down = true;
                break;
            case (sf::Event::MouseButtonReleased):
                player.SetTarget(player.GetPosition());
                mouse_down = false;
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
        
        if (mouse_down) {
            player.SetTarget(game->GetMousePositionRelative());
        }
        
        // Update objects
        for (std::vector<GFE::Entity*>::iterator iter = objects.begin(); iter < objects.end(); ++iter) {
            (*iter)->Update(dt);
        }
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

        std::sort(objects.begin(), objects.end(), GFE::SortEntities);
        
        for (std::vector<GFE::Entity*>::iterator iter = objects.begin(); iter < objects.end(); ++iter) {
            game->window.Draw(**iter);
        }
        
    }
    
    void GameState::Cleanup(void) {
        // Last of all, call our base class implementation
        IState::Cleanup();
    }
    
}