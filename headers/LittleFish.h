#ifndef FISH_SHOAL_LITTLEFISH_H
#define FISH_SHOAL_LITTLEFISH_H

#include "Fish.h"

class LittleFish : public Fish {
public:
    LittleFish(double step, double x, double y, double dir);

    void draw(sf::RenderWindow *window);
    void move(std::vector<Fish *> fish);
    void updateAngle(std::vector<Fish *> fish);
};


#endif //FISH_SHOAL_LITTLEFISH_H
