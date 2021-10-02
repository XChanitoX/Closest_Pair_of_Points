#ifndef CLOSEST_PAIR_OF_POINTS_LIBRERIAS_H
#define CLOSEST_PAIR_OF_POINTS_LIBRERIAS_H

#include <iostream>
#include <vector>
#include <queue> //Priority_queue
#include <cstdlib>
#include <cmath>
#include <unistd.h> //Libreria para el cronometro
#include <ctime>
#include <cstdio>
#include <limits>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <bits/stdc++.h>

#include "Point.h"
#include "Simulation.h"

using namespace sf;
using namespace std;

int numeroPuntos(){
    int numberOfPoints;
    cout << "========== Closest Pair of Points Simulator ==========\n";
    cout << "Choose the number of points:\n";
    cin >> numberOfPoints;
    return numberOfPoints;
}

#endif //CLOSEST_PAIR_OF_POINTS_LIBRERIAS_H