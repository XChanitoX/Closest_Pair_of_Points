#ifndef CLOSEST_PAIR_OF_POINTS_SIMULATION_H
#define CLOSEST_PAIR_OF_POINTS_SIMULATION_H

#include "Point.h"

class Simulation{
private:
    std::vector<Point*> points;

    sf::Vertex line[2] =
            {
                    sf::Vertex(sf::Vector2f(600, 0)),
                    sf::Vertex(sf::Vector2f(600, 800))
            };

public:
    Simulation(std::vector<Point*> points_):points(points_){};

    void draw(sf::RenderWindow* window, int num){
        window->clear();

        for (auto & point : points)
            point->draw(window);

        window->draw(line,2,sf::Lines);
        window->display();
    }

    void simulate(sf::RenderWindow* window, int num){
        while(true){
            draw(window, num);


            sf::Event _e;
            while (window->pollEvent(_e))
            {
                if (_e.type == sf::Event::Closed)
                    window->close();
            }
        }
    }

};

#endif //CLOSEST_PAIR_OF_POINTS_SIMULATION_H