#include <iostream>


using namespace std;


class VectorInt;


class VectorFloat
{
  private:
    float x, y;
  public:
    VectorFloat(float x, float y): x(x), y(y) {}
    VectorFloat(): x(0), y(0) {}
    void print()
    {
      cout << "{" << x << ", " << y << "}\n";
    }
    friend VectorFloat operator+(const VectorInt &a, const VectorFloat &b);
};


class VectorInt
{
  private:
    int x, y;
    friend VectorFloat operator+(const VectorInt &a, const VectorFloat &b);
  public:
    VectorInt(int x, int y): x(x), y(y) {}
    VectorInt(): x(0), y(0) {}
    void print()
    {
      cout << "{" << x << ", " << y << "}\n";
    }
};


VectorFloat operator+(const VectorInt &a, const VectorFloat &b)
{
  return VectorFloat(a.x + b.x, a.y + b.y);
}


int main()
{
  VectorInt vi(1, 2);
  VectorFloat vf(-1, 1), s;
  s = vi + vf;
  s.print();
}
