#include <cstddef>
#include <iostream>
#include <stdint.h>
#include "polygon.hpp"


using namespace std;


Polygon::Polygon() 
{
  n_vertices = 0;
  vertices = nullptr;
}


Polygon::Polygon(uint32_t n_vertices, const Point *vertices)
{
  this->n_vertices = n_vertices;
  this->vertices = new Point[n_vertices];
  for(size_t i=0; i<n_vertices; i++)
    this->vertices[i] = Point(vertices[i]);
}


Polygon::Polygon(const Polygon &p)
{
  n_vertices = p.n_vertices;
  vertices = new Point[n_vertices];
  for(size_t i=0; i<n_vertices; i++)
    vertices[i] = Point(p.vertices[i]);
}


Polygon::~Polygon()
{
  if(vertices)
    delete[] vertices;
}


Point& Polygon::operator[](size_t i) {return vertices[i];}


const Point& Polygon::operator[](size_t i) const {return vertices[i];}


void Polygon::print(bool newline)
{
  cout << "["; 
  for(size_t i=0; i<n_vertices-1; ++i) 
  {
    vertices[i].print(false);
    cout << ", ";
  }
  vertices[n_vertices-1].print(false);
  cout << "]";
  if (newline)
    cout << endl;
}
