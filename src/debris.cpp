#include "debris.h"

void Debris::Update() {
    x += dx;
    y += dy;
    dy += 0.5;
    health--;
}