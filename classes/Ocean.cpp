#include "../headers/Ocean.h"

Ocean::Ocean() {
    srand (time(0));
    for (int i(0); i < NB_FISH; i++) {
        if (MODE) {
            if (i < NB_FISH / 2) {
                this->fish.push_back(new BigFish(BIG_FISH_STEP, rand() % WIDTH, rand() % HEIGHT,
                                                 (double(rand()) / double(RAND_MAX)) * 2 * PI));
            } else {
                this->fish.push_back(new LittleFish(LITTLE_FISH_STEP, rand() % WIDTH, rand() % HEIGHT,
                                                    (double(rand()) / double(RAND_MAX)) * 2 * PI));
            }
        } else {
            this->fish.push_back(new VariableFish((double(rand()) / double(RAND_MAX)) * MAX_STEP + MIN_STEP,
                                                  rand() % WIDTH, rand() % HEIGHT,
                                                  (double(rand()) / double(RAND_MAX)) * 2 * PI));
        }
    }
}

void Ocean::draw(sf::RenderWindow *window) {
    sf::RectangleShape background(sf::Vector2f(WIDTH, HEIGHT));
    background.setFillColor(sf::Color(175, 172, 254));

    (*window).draw(background);

    for(int i(0); i < this->fish.size(); i++) {
        this->fish[i]->draw(window);
    }
}

void Ocean::update() {
    for(int i(0); i < this->fish.size(); i++) {
        this->fish[i]->move(this->fish);
    }
}
