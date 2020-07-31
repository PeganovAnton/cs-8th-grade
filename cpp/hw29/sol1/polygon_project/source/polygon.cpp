#include <cstddef>
#include <cstdint>
#include <iostream>
#include "polygon.hpp"


using namespace std;

Polygon::Polygon():n_vertices(0), vertices(nullptr){};
Polygon::Polygon(uint32_t n, const Point* vertices)
{
    n_vertices = n;
    this->vertices = new Point[n];
    for(int i = 0; i < n; i++)
        this->vertices[i] = vertices[i];
};
uint32_t Polygon::get_n_vertices()const{return n_vertices;};
Polygon::Polygon(const Polygon& pl)
{
    n_vertices = pl.n_vertices;
    this->vertices = new Point[pl.n_vertices];
    for(int i = 0; i < pl.n_vertices; i++)
        vertices[i] = pl[i];
};
Point& Polygon::operator[](size_t i)
{
    return vertices[i];
};
const Point& Polygon::operator[](size_t i)const
{
    return vertices[i];
};
void Polygon::print(bool b)
{
    cout << '[';
    for(int i = 0; i < n_vertices-1; i++)
    {
        vertices[i].print(false);
        cout << ", ";
    }
    vertices[n_vertices - 1].print(false);
    cout << ']' << endl;
};
