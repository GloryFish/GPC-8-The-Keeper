//
//  KeeperGame.hpp
//  TheKeeper
//
//  Created by Jay Roberts on 9/16/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#ifndef TheKeeper_KeeperGame_hpp
#define TheKeeper_KeeperGame_hpp

#include "GFE/Game.hpp"

namespace Keeper {
    class KeeperGame : public GFE::Game {
        
    public:
        KeeperGame(const std::string theTitle = "The Keeper");
        virtual ~KeeperGame();
        
    protected:
        virtual void Init(void);
    private:
    };
}




#endif
