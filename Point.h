#ifndef CLOSEST_PAIR_OF_POINTS_POINT_H
#define CLOSEST_PAIR_OF_POINTS_POINT_H

#include "Librerias.h"

// A structure to represent a Point in 2D plane
struct Point
{
    double position_x, position_y;
    double radius;
    int red, green, blue;
    sf::CircleShape circle;

    Point(double position_x_, double position_y_, int red_, int green_, int blue_):
            position_x(position_x_), position_y(position_y_),radius(0.5),
            red(red_), green(green_), blue(blue_){};

    void draw(sf::RenderWindow* window);
};

void Point::draw(sf::RenderWindow *window) {
    // establecimiento de parametros para dibujar y posicionar cada particula
    circle.setRadius(radius*10);
    circle.setFillColor(sf::Color(this->red, this->green, this->blue,255));
    circle.setPosition(position_x*window->getSize().x, position_y*window->getSize().y);
    circle.setOrigin(radius*10, radius*10);
    window->draw(circle);
}

#endif //CLOSEST_PAIR_OF_POINTS_POINT_H