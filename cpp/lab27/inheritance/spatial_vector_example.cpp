#include <iostream>
#include <math.h>


using namespace std;


class vector
{
  protected:
    double x, y;
  public:
    vector(double x, double y) {this->x = x; this->y = y;}
    double abs() {return sqrt(x*x + y*y);}
    void info() {cout << "Модуль вектора равен " << abs() << endl;}
};

class spatial_vector: public vector
{
  protected:
    double z ;
  public :
    spatial_vector(double x, double y, double z);
    double abs () {return sqrt (x*x + y*y + z*z);}
};


spatial_vector::spatial_vector(double x, double y, double z): vector (x, y)
{
  this->z = z;
}


int main()
{
  cout << "Создаём вектор на плоскости с координатами 1,2\n";
  vector a(1, 2);
  a.info();
  cout << "Создаём пространственный вектор с координатами 1,2,3\n";
  spatial_vector b(1, 2, 3);
  b.info();
}
