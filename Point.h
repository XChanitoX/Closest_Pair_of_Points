#ifndef CLOSEST_PAIR_OF_POINTS_POINT_H
#define CLOSEST_PAIR_OF_POINTS_POINT_H

// A structure to represent a Point in 2D plane
struct Point
{
    double x, y;
    double radius = 0.3;
    int red = 255, green = 0, blue = 0;
    sf::CircleShape circle;

    Point(double x_, double y_){
        x = x_;
        y = y_;
    };

    Point(){};


    void draw(sf::RenderWindow *window) {
        circle.setRadius(radius*10);
        circle.setFillColor(sf::Color(this->red, this->green, this->blue,255));
        //circle.setPosition(x, y);
        circle.setOrigin(x, y);
        window->draw(circle);
    }
};


#endif //CLOSEST_PAIR_OF_POINTS_POINT_H