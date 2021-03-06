#include "Librerias.h"

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

// A utility function to find the distance between two points
float dist(Point p1, Point p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
    );
}

// A Brute Force method to return the smallest distance between two points
// in P[] of size n
float bruteForce(Point P[], int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);

    return min;
}

// A utility function to find a minimum of two float values
float min(float x, float y)
{
    return (x < y)? x : y;
}


// A utility function to find the distance between the closest points of
// strip of a given size. All points in strip[] are sorted according to
// y coordinate. They all have an upper bound on minimum distance as d.
// Note that this method seems to be a O(n^2) method, but it's a O(n)
// method as the inner loop runs at most 6 times
float stripClosest(Point strip[], int size, float d, sf::RenderWindow* window)
{
    float min = d; // Initialize the minimum distance as d
    Point p1;
    Point p2;
    // Pick all points one by one and try the next points till the difference
    // between y coordinates is smaller than d.
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i],strip[j]) < min){
                min = dist(strip[i], strip[j]);
                p1 = strip[i];
                p2 = strip[j];
            }

    //DRAW
    p1.blue = 255;
    p1.red = 0;
    p1.green = 0;
    p2.blue = 255;
    p2.red = 0;
    p2.green = 0;
    p1.draw(window);
    p2.draw(window);

    window->display();
    sf::Time t = sf::milliseconds(1000);
    sf::sleep(t);


    sf::Event _e;
    while (window->pollEvent(_e))
    {
        if (_e.type == sf::Event::Closed)
            window->close();
    }

    return min;
}

// A recursive function to find the smallest distance. The array Px contains
// all points sorted according to x coordinates and Py contains all points
// sorted according to y coordinates
float closestUtil(Point Px[], Point Py[], int n, sf::RenderWindow* window, std::vector<Point*> P)
{
    // If there are 2 or 3 points, then use brute force
    /// BRUTE FORCE
    if (n <= 3){
        //DRAW
        for (auto & point : P){
            point->draw(window);
        }

        //window->draw(line,2,sf::Lines);
        for (int i = 0; i < n; ++i) {
            Px[i].green = 255;
            Px[i].red = 0;
            Px[i].blue = 0;
            Px[i].draw(window);
        }

        window->display();

        sf::Event _e;
        while (window->pollEvent(_e))
        {
            if (_e.type == sf::Event::Closed)
                window->close();
        }
        return bruteForce(Px, n);
    }

    /// START DIVIDE
    // Find the middle point
    int mid = n/2;
    Point midPoint = Px[mid];

    sf::Vertex linea[2] =
            {
                    sf::Vertex(sf::Vector2f((float) -midPoint.x, 0)),
                    sf::Vertex(sf::Vector2f((float) -midPoint.x, 800))
            };

    window->draw(linea,2,sf::Lines);
    window->display();

    sf::Event _e;
    while (window->pollEvent(_e))
    {
        if (_e.type == sf::Event::Closed)
            window->close();
    }


    // Divide points in y sorted array around the vertical line.
    // Assumption: All x coordinates are distinct.
    Point Pyl[mid]; // y sorted points on left of vertical line
    Point Pyr[n-mid]; // y sorted points on right of vertical line
    int li = 0, ri = 0; // indexes of left and right subarrays
    for (int i = 0; i < n; i++)
    {
        if ((Py[i].x < midPoint.x || (Py[i].x == midPoint.x && Py[i].y < midPoint.y)) && li<mid)
            Pyl[li++] = Py[i];
        else
            Pyr[ri++] = Py[i];
    }
    /// END DIVIDE

    // Consider the vertical line passing through the middle point
    // calculate the smallest distance dl on left of middle point and
    // dr on right side

    /// START CONQUER
    // Closest pair of points in Pyl
    float dl = closestUtil(Px, Pyl, mid, window, P);
    // Closest pair of points in Pyr
    float dr = closestUtil(Px + mid, Pyr, n-mid, window, P);

    // Find the smaller of two distances
    float d = min(dl, dr);
    /// END CONQUER

    // Build an array strip[] that contains points close (closer than d)
    // to the line passing through the middle point
    /// COMBINE
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(Py[i].x - midPoint.x) < d)
            strip[j] = Py[i], j++;

    return stripClosest(strip, j, d, window);
    /// COMBINE
}

// The main function that finds the smallest distance
// This method mainly uses closestUtil()
float closest(std::vector<Point*> P, int n, sf::RenderWindow* window)
{

    for (auto & point : P){
        point->draw(window);
    }

    Point Px[n];
    Point Py[n];
    for (int i = 0; i < n; i++)
    {
        Px[i].x = P[i]->x;
        Px[i].y = P[i]->y;

        Py[i].x = P[i]->x;
        Py[i].y = P[i]->y;
    }

    qsort(Px, n, sizeof(Point), compareX);
    qsort(Py, n, sizeof(Point), compareY);

    // Use recursive function closestUtil() to find the smallest distance
    return closestUtil(Px, Py, n, window, P);
}


int main()
{
    int num;
    cin >> num;

    vector<Point*> points;
    unordered_set<double> numerosSinRepetir;


    srand(time(NULL));

    double posX = -(rand()%1500);
    numerosSinRepetir.insert(posX);
    unordered_set<double>::const_iterator found;

    for(int i = 0; i < num; i++){
        found = numerosSinRepetir.begin();
        while(found != numerosSinRepetir.end()){
            posX = -(rand()%1500);
            found = numerosSinRepetir.find(posX);
        }
        numerosSinRepetir.insert(posX);

        double posY = -(rand()%800);
        auto* point = new Point(posX, posY);

        points.push_back(point);
    }

    auto* window = new RenderWindow (VideoMode(1500,800), "Closest Pair of Points Simulator");
    window->setFramerateLimit(60);

    cout << "The smallest distance is " << closest(points, num, window);

    return 0;
}