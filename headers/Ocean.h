#ifndef FISH_SHOAL_OCEAN_H
#define FISH_SHOAL_OCEAN_H

#include "BigFish.h"
#include "LittleFish.h"
#include "VariableFish.h"
#include <vector>

class Ocean {
private:
    std::vector<Fish *> fish;
public:
    Ocean();

    void draw(sf::RenderWindow *window);
    void update();
};

#endif //FISH_SHOAL_OCEAN_H
