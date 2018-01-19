#ifndef FISH_SHOAL_FISH_H
#define FISH_SHOAL_FISH_H

#include "config.hpp"

class Fish {
protected:
    int step;
    double x, y, vx, vy;
public:
    Fish(double step, double x, double y, double dir);

    virtual void draw(sf::RenderWindow *window) =0;

    virtual void move(std::vector<Fish *> fishes) =0;

    virtual void updateAngle(std::vector<Fish *> fish) =0;

    double dist2(Fish *f);

    void goForward();

    bool avoidWalls();

    bool avoidFish(std::vector<Fish *> fish);

    bool avoidBigFish(std::vector<Fish *> fish);

    bool meanAngle(std::vector<Fish *> fish);

    bool meanAngleBigFish(std::vector<Fish *> fish);

    bool meanAngleLittleFish(std::vector<Fish *> fish);

    bool fearBigFish(std::vector<Fish *> fish);

    bool isNear(Fish *f);

    double distFromWalls();

    void normalize();
};

#endif //FISH_SHOAL_FISH_H
