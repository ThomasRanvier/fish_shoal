#include "../headers/LittleFish.h"

LittleFish::LittleFish(double step, double x, double y, double dir)
        : Fish(step, x, y, dir) {}

void LittleFish::draw(sf::RenderWindow *window) {
    sf::RectangleShape fish(sf::Vector2f(LITTLE_FISH_SIZE, LITTLE_FISH_WEIGHT));
    double x2(this->x - this->step * this->vx), y2(this->y - this->step * this->vy);
    fish.rotate(atan2(y2 - this->y, x2 - this->x) * 180 / PI);
    fish.setPosition(sf::Vector2f(this->x, this->y));
    fish.setFillColor(FISH_COLOR);

    (*window).draw(fish);
}

void LittleFish::move(std::vector<Fish *> fish) {
    updateAngle(fish);
    goForward();
}

void LittleFish::updateAngle(std::vector<Fish *> fish) {
    if (!avoidWalls()) {
        if (!fearBigFish(fish)) {
            if (!avoidFish(fish)) {
                meanAngleLittleFish(fish);
            }
        }
    }
}
