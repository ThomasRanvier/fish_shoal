#ifndef FISH_SHOAL_BIGFISH_H
#define FISH_SHOAL_BIGFISH_H

#include "Fish.h"

class BigFish : public Fish {
public:
    BigFish(double step, double x, double y, double dir);

    void draw(sf::RenderWindow *window);
    void move(std::vector<Fish *> vector);
    void updateAngle(std::vector<Fish *> fish);
};

#endif //FISH_SHOAL_BIGFISH_H
