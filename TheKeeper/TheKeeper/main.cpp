#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ResourcePath.hpp"
#include "KeeperGame.hpp"
#include "GFE/Logger.hpp"

int main (int argc, const char * argv[]) {
    
    Keeper::KeeperGame game;
    
    int returnCode = game.Run();
    
    GFE::Logger::Flush();
    
	return returnCode;

}
