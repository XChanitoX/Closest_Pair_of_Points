// Closest Pair of Points using Divide and Conquer

#include "Librerias.h"

int main()
{
    int num = numeroPuntos();
    std::vector<Point*> points;

    for(int i = 0; i < num; i++){
        auto* point = new Point((double) (rand()%100)/100, (double) (rand()%100)/100,
                                 255, 255, 0);
        points.push_back(point);
    }

    auto* window = new RenderWindow (VideoMode(1200,800), "Closest Pair of Points Simulator");
    window->setFramerateLimit(60);
    Simulation test(points);
    test.simulate(window);

    //Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    //int n = sizeof(P) / sizeof(P[0]);

    return 0;
}
