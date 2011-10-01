//
//  NameGenerator.cpp
//  TheKeeper
//
//  Created by Jay Roberts on 9/29/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#include "NameGenerator.hpp"

#include <string>
#include <fstream>
#include "ResourcePath.hpp"
#include "GFE/Logger.hpp"

namespace Keeper {
    
    NameGenerator::NameGenerator(void) {
        GetLines(ResourcePath() + "male-names-unique.txt", maleFirstnames);
        GetLines(ResourcePath() + "female-names-unique.txt", femaleFirstnames);
        GetLines(ResourcePath() + "last-names.txt", lastnames);
    }
    
    NameGenerator::~NameGenerator() {
        
    }

    std::string NameGenerator::GetRandomName(Gender gender) {
        if (gender == GenderBoth) {
            gender = static_cast<Gender>(rand() % 2);
        }
        
        std::string name;

        // Firstname
        if (gender == GenderMale) {
            int index = static_cast<int>(rand() % maleFirstnames.size());
            name = maleFirstnames[index];
        } else {
            int index = static_cast<int>(rand() % femaleFirstnames.size());
            name = femaleFirstnames[index];
        }

        name += " ";
        
        // Get lastname
        int index = static_cast<int>(rand() % lastnames.size());
        name += lastnames[index];
        
        
        return name;
    }

    
    
    void NameGenerator::GetLines(std::string fileName, std::vector<std::string> &lines) {
        std::string line;
        
        std::ifstream file;
        file.open(fileName.c_str(), std::ios::out);
        
        if (file.is_open()) {
            while (file.good()) {
                getline(file, line);

                if (!line.empty()) {
                    lines.push_back(line);
                }
            }
        }
        file.close();
    }

    
}
