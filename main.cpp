#include "headers/Ocean.h"

void sleep(clock_t ms) {
    clock_t end(clock() + 1000 * ms);
    while (clock() <= end);
}

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 4;

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML window", sf::Style::Default, settings);
    Ocean ocean;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        ocean.update();
        ocean.draw(&window);

        sleep(SLEEP_TIME);

        window.display();
    }

    return 0;
}