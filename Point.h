#ifndef CLOSEST_PAIR_OF_POINTS_POINT_H
#define CLOSEST_PAIR_OF_POINTS_POINT_H

// A structure to represent a Point in 2D plane
struct Point
{
    double x, y;
    double radius = 0.5;
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

// Needed to sort array of points according to X coordinate
int compareX(const void* a, const void* b)
{
    auto *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->x != p2->x) ? (p1->x - p2->x) : (p1->y - p2->y);
}
// Needed to sort array of points according to Y coordinate
int compareY(const void* a, const void* b)
{
    auto *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->y != p2->y) ? (p1->y - p2->y) : (p1->x - p2->x);
}

#endif //CLOSEST_PAIR_OF_POINTS_POINT_H