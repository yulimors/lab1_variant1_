#pragma once
#include <vector>
#include <random>
#include <stdexcept>

struct Point {
    double x, y;
    Point(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}
};

class PointGenerator {
private:
    Point current;                  
    std::vector<Point> basePoints;  
    std::mt19937 gen;              
    std::uniform_int_distribution<> dist; 

public:
    PointGenerator(const Point& start, const std::vector<Point>& bases);

    Point operator()(); 
};
