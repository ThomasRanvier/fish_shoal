#include <iostream>
#include <cmath>
#include <typeinfo>
#include <algorithm>
#include <SFML/Graphics.hpp>

const bool MODE = true;//False : variable fish, true big and little

const int SLEEP_TIME = 10;

const double PI = 3.14159265359;

const int WIDTH = 1000;
const int HEIGHT = 500;

const int NB_FISH = 200;

const int BIG_FISH_SIZE = 20;
const int BIG_FISH_WEIGHT = 3;
const int BIG_FISH_STEP = 1;
const int LITTLE_FISH_SIZE = 15;
const int LITTLE_FISH_WEIGHT = 2;
const int LITTLE_FISH_STEP = 4;

const double MIN_STEP = 1;
const double MAX_STEP = 4;

const int FEAR_DIST = 50;

const int MIN_DIST = 10;
const int MAX_DIST = 80;
const double ROTATE_SPEED = 0.3;

const sf::Color FISH_COLOR = sf::Color::Black;

