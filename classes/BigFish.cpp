#include "../headers/BigFish.h"

BigFish::BigFish(double step, double x, double y, double dir)
        : Fish(step, x, y, dir) {}

void BigFish::draw(sf::RenderWindow *window) {
    sf::RectangleShape fish(sf::Vector2f(BIG_FISH_SIZE, BIG_FISH_WEIGHT));
    double x2(this->x - this->step * this->vx), y2(this->y - this->step * this->vy);
    fish.rotate(atan2(y2 - this->y, x2 - this->x) * 180 / PI);
    fish.setPosition(sf::Vector2f(this->x, this->y));
    fish.setFillColor(FISH_COLOR);

    (*window).draw(fish);
}

void BigFish::move(std::vector<Fish *> fishes) {
    updateAngle(fishes);
    goForward();
}

void BigFish::updateAngle(std::vector<Fish *> fish) {
    if (!avoidWalls()) {
        if (!avoidBigFish(fish)) {
            meanAngleBigFish(fish);
        }
    }
}
