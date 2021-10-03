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

    void draw(sf::RenderWindow* window, int num, bool alerta){
        window->clear();

        for (auto & point : points){
            if (!alerta){
                point->red = 0;
                point->green = 255;
            } else{
                point->red = 255;
                point->green = 0;
            }
            point->draw(window);
        }

        window->draw(line,2,sf::Lines);
        window->display();
    }

    void simulate(sf::RenderWindow* window, int num){
        sf::Time t = sf::milliseconds(1000);
        bool alerta = true;

        while(true){
            sf::sleep(t);
            alerta = !alerta;
            draw(window, num, alerta);

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