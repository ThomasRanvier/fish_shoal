#include "../headers/VariableFish.h"

VariableFish::VariableFish(double step, double x, double y, double dir)
        : Fish(step, x, y, dir) {
    this->size = 23 - 3 * this->step;
    this->weight = 4 - (this->step / 2);
}

void VariableFish::draw(sf::RenderWindow *window) {
    sf::RectangleShape fish(sf::Vector2f(this->size, this->weight));
    double x2(this->x - this->step * this->vx), y2(this->y - this->step * this->vy);
    fish.rotate(atan2(y2 - this->y, x2 - this->x) * 180 / PI);
    fish.setPosition(sf::Vector2f(this->x, this->y));
    fish.setFillColor(FISH_COLOR);

    (*window).draw(fish);
}

void VariableFish::move(std::vector<Fish *> fishes) {
    updateAngle(fishes);
    goForward();
}

void VariableFish::updateAngle(std::vector<Fish *> fishes) {
    if (!avoidWalls()) {
        if (!avoidFish(fishes)) {
            meanAngle(fishes);
        }
    }
}