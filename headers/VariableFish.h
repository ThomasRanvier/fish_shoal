#ifndef FISH_SHOAL_VARIABLEFISH_H
#define FISH_SHOAL_VARIABLEFISH_H

#include "Fish.h"

class VariableFish : public Fish {
private:
    double size, weight;
public:
    VariableFish(double step, double x, double y, double dir);

    void draw(sf::RenderWindow *window);
    void move(std::vector<Fish *> vector);
    void updateAngle(std::vector<Fish *> vector);
};


#endif //FISH_SHOAL_VARIABLEFISH_H
