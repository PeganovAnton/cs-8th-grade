#include <iostream>


using namespace std;


class A
{
  // При объявлении класса нельзя инициализировать не константные статические
  // переменные.
  static int foo;
  
  public:
    // Константные переменные можно инициализировать прямо здесь, но только
    // если они целые.
    static const int bar = -3;

    // Если переменная не целая (например массив), то она инициализируется
    // вне класса.
    static const int spam[3];
    
    static int arr[3];
  
    int get_foo() {return foo;}
};


// Инициализация статической переменной.
int A::foo = 10;

const int A::spam[3] = {0, 1, 2};
int A::arr[3] = {0, 1, 2};


int main()
{
  A a;
  cout << a.get_foo() << endl;

  // Статические переменные доступны по имени класса и одинаковые у всех 
  // объектов.
  cout << A::bar << endl;

  A b;
  // Меняя переменную у одного его объекта, я меняю ее у всех объектов, включая
  // сам класс. 
  b.arr[1] = -5;

  for(size_t i=0; i<3; i++)
    cout << b.arr[i] << ' ';
  cout << endl;

  for(size_t i=0; i<3; i++)
    cout << A::arr[i] << ' ';
  cout << endl;
}
