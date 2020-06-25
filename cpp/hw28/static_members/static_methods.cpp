#include <iostream>


using namespace std;


class A
{
  public:
    static void print_class_name() // У статических методов нет `const`
    {
      // Внутри статических методов недоступен указатель `this` и у них нет 
      // доступа к нестатическим признакам и методам.
      cout << "Class name is `A`\n";
    }
};


int main()
{
  A a;
  // Статические методы связаны с классом, а не с объектом и их можно 
  // вызывать как от объекта, так и от класса.
  A::print_class_name();
  a.print_class_name();
}
