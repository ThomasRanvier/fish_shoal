#include "../headers/Fish.h"

Fish::Fish(double step, double x, double y, double dir)
        : step(step), x(x), y(y) {
    this->vx = cos(dir);
    this->vy = sin(dir);
}

void Fish::goForward() {
    this->x += this->vx * this->step;
    this->y += this->vy * this->step;
}

bool Fish::avoidWalls() {
    if (this->x < 0) {
        this->x = 0;
    } else if (this->y < 0) {
        this->y = 0;
    } else if (this->x > WIDTH) {
        this->x = WIDTH;
    } else if (this->y > HEIGHT) {
        this->y = HEIGHT;
    }

    double dist(distFromWalls());

    bool updated(false);

    if (dist < MIN_DIST) {
        updated = true;
        if (dist == this->x - 0) {
            this->vx += ROTATE_SPEED;
        } else if (dist == this->y - 0) {
            this->vy += ROTATE_SPEED;
        } else if (dist == WIDTH - this->x) {
            this->vx -= ROTATE_SPEED;
        } else if (dist == HEIGHT - this->y) {
            this->vy -= ROTATE_SPEED;
        }
        normalize();
    }
    return updated;
}

double Fish::distFromWalls() {
    double min(std::min(this->x - 0, this->y - 0));
    min = std::min(min, WIDTH - this->x);
    min = std::min(min, HEIGHT - this->y);
    return min;
}

bool Fish::avoidBigFish(std::vector<Fish *> fish) {
    Fish *f;
    int index(0);
    std::string s;
    do {
        f = fish[index++];
    } while ((s = typeid(*f).name()).find("BigFish") == std::string::npos || f == this);

    double memDist2(dist2(f));
    for (int i(0); i < fish.size(); i++) {
        if ((s = typeid(*f).name()).find("BigFish") != std::string::npos) {
            double newDist2(dist2(fish[i]));
            if (newDist2 < memDist2 && fish[i] != this) {
                f = fish[i];
                memDist2 = newDist2;
            }
        }
    }

    bool updated(false);

    if (memDist2 < MIN_DIST * MIN_DIST) {
        double dist = sqrt(memDist2);
        double diffX = (f->x - this->x) / dist;
        double diffY = (f->y - this->y) / dist;
        this->vx -= diffX / 4;
        this->vy -= diffY / 4;
        normalize();
        updated = true;
    }
    return updated;
}

bool Fish::avoidFish(std::vector<Fish *> fish) {
    Fish *f;

    if (fish[0] != this) {
        f = fish[0];
    } else {
        f = fish[1];
    }

    double memDist2(dist2(f));
    for (int i(0); i < fish.size(); i++) {
        double newDist2(dist2(fish[i]));
        if (newDist2 < memDist2 && fish[i] != this) {
            f = fish[i];
            memDist2 = newDist2;
        }
    }

    bool updated(false);

    if (memDist2 < MIN_DIST * MIN_DIST) {
        double dist = sqrt(memDist2);
        double diffX = (f->x - this->x) / dist;
        double diffY = (f->y - this->y) / dist;
        this->vx -= diffX / 4;
        this->vy -= diffY / 4;
        normalize();
        updated = true;
    }
    return updated;
}

double Fish::dist2(Fish *f) {
    return pow(f->x - this->x, 2) + pow(f->y - this->y, 2);
}

bool Fish::meanAngle(std::vector<Fish *> fish) {
    double totalVX(0);
    double totalVY(0);
    int nbTotal(0);
    for (int i(0); i < fish.size(); i++) {
        if (isNear(fish[i])) {
            totalVX += fish[i]->vx;
            totalVY += fish[i]->vy;
            nbTotal++;
        }
    }
    if (nbTotal >= 1) {
        this->vx = (totalVX / nbTotal + this->vx) / 2;
        this->vy = (totalVY / nbTotal + this->vy) / 2;
        normalize();
    }
}

bool Fish::meanAngleBigFish(std::vector<Fish *> fish) {
    double totalVX(0);
    double totalVY(0);
    int nbTotal(0);
    std::string s;
    for (int i(0); i < fish.size(); i++) {
        if ((s = typeid(*fish[i]).name()).find("BigFish") != std::string::npos && isNear(fish[i])) {
            totalVY += fish[i]->vy;
            totalVX += fish[i]->vx;
            nbTotal++;
        }
    }
    if (nbTotal >= 1) {
        this->vx = (totalVX / nbTotal + this->vx) / 2;
        this->vy = (totalVY / nbTotal + this->vy) / 2;
        normalize();
    }
}

bool Fish::isNear(Fish *f) {
    double dist(dist2(f));
    return (dist < MAX_DIST * MAX_DIST && dist > MIN_DIST * MIN_DIST);
}

void Fish::normalize() {
    double length = sqrt(this->vx * this->vx + this->vy * this->vy);
    this->vx /= length;
    this->vy /= length;
}

bool Fish::fearBigFish(std::vector<Fish *> fish) {
    Fish *f;
    int index(0);
    std::string s;
    do {
        f = fish[index++];
    } while ((s = typeid(*f).name()).find("BigFish") == std::string::npos);

    double memDist2(dist2(f));
    for (int i(0); i < fish.size(); i++) {
        if ((s = typeid(*fish[i]).name()).find("BigFish") != std::string::npos) {
            double newDist2(dist2(fish[i]));
            if (newDist2 < memDist2) {
                f = fish[i];
                memDist2 = newDist2;
            }
        }
    }

    bool updated(false);
    if (memDist2 < FEAR_DIST * FEAR_DIST) {
        double dist = sqrt(memDist2);
        double diffX = (f->x - this->x) / dist;
        double diffY = (f->y - this->y) / dist;
        this->vx -= diffX / 2;
        this->vy -= diffY / 2;
        normalize();
        updated = true;
    }
    return updated;
}

bool Fish::meanAngleLittleFish(std::vector<Fish *> fish) {
    double totalVX(0);
    double totalVY(0);
    int nbTotal(0);
    std::string s;
    for (int i(0); i < fish.size(); i++) {
        if ((s = typeid(*fish[i]).name()).find("BigFish") == std::string::npos && isNear(fish[i])) {
            totalVY += fish[i]->vy;
            totalVX += fish[i]->vx;
            nbTotal++;
        }
    }
    if (nbTotal >= 1) {
        this->vx = (totalVX / nbTotal + this->vx) / 2;
        this->vy = (totalVY / nbTotal + this->vy) / 2;
        normalize();
    }
}
