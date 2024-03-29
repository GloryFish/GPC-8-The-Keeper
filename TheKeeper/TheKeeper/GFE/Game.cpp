//
//  Game.cpp
//  SpaceRoguelike
//
//  Created by Jay Roberts on 9/8/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#include "Game.hpp"
#include "Logger.hpp"
#include <iostream>
#include "ConfigFile.hpp"
#include "ResourcePath.hpp"
#include <assert.h>
#include "IState.hpp"

namespace GFE {
    
    Game::Game(const std::string theTitle) : stat_display() {
        running = false;
        update_rate = (Uint32)(1000.0f / 100.0f);
        title = theTitle;
    }
    
    int Game::Run(void) {
        running = true;
        Logger::Log() << "Running...";
        
        stateManager.RegisterGame(this);
        
        PreInit();
        
        // Initialize our application which might set our Running flag to false
        Init();
        
        // Loop if Running flag is still true
        Loop();
        
        // Cleanup our application
        Cleanup();
        
        // Make sure our Running flag is set to false before exiting
        running = false;
        
        return EXIT_SUCCESS;
    }
    
    bool Game::IsRunning(void) {
        return running;
    }
    
    void Game::Quit(int status_code) {
        exit_code = status_code;
        running = false;
    }
    
    sf::Vector2f Game::GetMousePosition(void) {
        return (sf::Vector2f)sf::Mouse::GetPosition(window);
    }

    sf::Vector2f Game::GetMousePositionRelative(void) {
        sf::Vector2i pos = sf::Mouse::GetPosition(window);
        return window.ConvertCoords(pos.x, pos.y);
    }

    void Game::SetView(sf::View& view) {
        window.SetView(view);
    }

    sf::FloatRect Game::GetDisplayRect(void) {
        return sf::FloatRect(0, 0, window.GetWidth(), window.GetHeight());
    }
    
    void Game::PreInit(void) {
        Logger::Log() << "PreInit()";
        
        ConfigFile config(ResourcePath() + "config.ini");
        
        int width = config.read<int>("width", DEFAULT_VIDEO_WIDTH);
        int height = config.read<int>("height", DEFAULT_VIDEO_HEIGHT);

        video_mode.Width = width;
        video_mode.Height = height;
        video_mode.BitsPerPixel = DEFAULT_VIDEO_BPP;

        
        // Create a RenderWindow object using VideoMode object above
        window.Create(video_mode, title, sf::Style::Titlebar | sf::Style::Close, context_settings);

        // Use Vertical Sync
        window.EnableVerticalSync(true);
    }

    void Game::Init(void) {
        Logger::Log() << "Init()";
        
    }

    void Game::Loop(void) {
        Logger::Log() << "Loop()";
        
        // Clock used in restricting Update loop to a fixed rate
        sf::Clock update_clock;
        update_clock.Reset();
        
        // Loop while IsRunning returns true
        while(IsRunning() && window.IsOpen()) {
            
            IState* currentState = stateManager.GetActiveState();
            
            // Check for corrupt state returned by our StateManager
            assert(NULL != currentState && "Game::Loop() received a bad pointer");
            
            if (update_clock.GetElapsedTime() > update_rate) {
             
                sf::Event event;

                while(window.PollEvent(event)) {
                    switch (event.Type) {
                        case sf::Event::Closed: // Window closed
                            Quit(EXIT_SUCCESS);
                            break;
                        case sf::Event::GainedFocus:  // Window gained focus
                            // resume state
                            currentState->Resume();
                            break;
                        case sf::Event::LostFocus:    // Window lost focus
                            // Pause state
                            currentState->Pause();
                            break;
                        case sf::Event::Resized:      // Window resized
                            break;
                        default:
                            // Allow state to handle events
                            currentState->HandleEvents(event);
                            break;
                    }
                    
                }

                // Update current state
                float dt = (float)update_clock.GetElapsedTime() / 1000;
                
                currentState->Update(dt);
                stat_display.Update(dt);
                update_clock.Reset();
                
                GFE::Logger::Flush();
            }
            
            // Draw current state
            currentState->Draw();

            stat_display.Draw(window);
            
            window.Display();
            
            // Cleanup state
        }
        
    }

    void Game::Cleanup(void) {
        Logger::Log() << "Cleanup()";
        
    }


}
