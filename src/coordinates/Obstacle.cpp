//
// Created by nevo on 01/12/16.
//

#include "Obstacle.h"

int Obstacle::getLength() const {
    return length;
}

int Obstacle::getWidth() const {
    return width;
}

void Obstacle::setLength(int length) {
    Obstacle::length = length;
}

void Obstacle::setWidth(int width) {
    Obstacle::width = width;
}
