#ifndef CLOSEST_PAIR_OF_POINTS_SIMULATION_H
#define CLOSEST_PAIR_OF_POINTS_SIMULATION_H

#include "Point.h"

class Simulation{
private:
    std::vector<Point*> points;


public:
    Simulation(std::vector<Point*> points_):points(points_){};

    void draw(sf::RenderWindow* window){
        window->clear();

        for (auto & point : points){
            point->draw(window);
        }

        //window->draw(line,2,sf::Lines);
        window->display();
    }

    void simulate(sf::RenderWindow* window){
        //sf::Time t = sf::milliseconds(1000);
        //bool alerta = true;

        while(true){
            //sf::sleep(t);
            //alerta = !alerta;
            draw(window);

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