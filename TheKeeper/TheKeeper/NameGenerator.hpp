//
//  NameGenerator.h
//  TheKeeper
//
//  Created by Jay Roberts on 9/29/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#ifndef TheKeeper_NameGenerator_h
#define TheKeeper_NameGenerator_h

#include <string>
#include <vector>

namespace Keeper {
    
    enum Gender { GenderMale, GenderFemale, GenderBoth };
    
    class NameGenerator {

        std::vector<std::string> maleFirstnames;
        std::vector<std::string> femaleFirstnames;
        std::vector<std::string> lastnames;
    
    public:
        
        NameGenerator(void);
        ~NameGenerator();
        
        std::string GetRandomName(Gender gender);
        
    private:
        void GetLines(std::string fileName, std::vector<std::string> &lines);
    };
    
    
}

#endif
