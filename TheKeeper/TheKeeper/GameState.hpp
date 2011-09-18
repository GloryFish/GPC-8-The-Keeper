//
//  GameState.hpp
//  TheKeeper
//
//  Created by Jay Roberts on 9/16/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#ifndef TheKeeper_GameState_hpp
#define TheKeeper_GameState_hpp

#include <SFML/Graphics.hpp>
#include "GFE/IState.hpp"
#include "Player.hpp"
#include "Trashcan.hpp"
#include "Camera.hpp"
#include <SFML/Audio.hpp>

namespace Keeper {
    
    class GameState : public GFE::IState {
    
        Player player;
        Trashcan can;
        sf::Texture background_image;
        sf::Sprite background;
        GFE::Camera camera;
        sf::View view;
        sf::Music music;
        
        
    public:
        GameState(GFE::Game* theGame);
        
        virtual ~GameState(void);
        
        virtual void DoInit(void);
        
        virtual void ReInit(void);
        
        virtual void HandleEvents(sf::Event event);
        
        virtual void Update(float dt);
        
        virtual void Draw(void);
        
    protected:
        
        virtual void Cleanup(void);
        
    private:
        
    };
}

#endif
