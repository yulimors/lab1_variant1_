#include "PointGenerator.h"

PointGenerator::PointGenerator(const Point& start, const std::vector<Point>& bases)
    : current(start), basePoints(bases), gen(std::random_device{}())
{
    if (basePoints.empty())
        throw std::invalid_argument("The base point list cannot be empty.");

    dist = std::uniform_int_distribution<>(0, (int)basePoints.size() - 1);
}

Point PointGenerator::operator()() {
    int idx = dist(gen);          
    const Point& base = basePoints[idx];

    current.x = (current.x + base.x) / 2.0;
    current.y = (current.y + base.y) / 2.0;

    return current;
}

