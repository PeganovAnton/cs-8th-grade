#include <stdint.h>
#include "point.hpp"


using namespace std;


class Polygon
{
  uint32_t n_vertices;
  Point *vertices;
  public:
    Polygon();
    Polygon(uint32_t, const Point*);
    Polygon(const Polygon&);
    Point& operator[](size_t);
    const Point& operator[](size_t) const;
    void print(bool = true);
    ~Polygon();
};
