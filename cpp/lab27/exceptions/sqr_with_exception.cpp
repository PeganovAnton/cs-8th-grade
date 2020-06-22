#include <cstdlib>
#include <exception>
#include <sstream>
#include <stdint.h>
#include <string>
#include <iostream>


using namespace std;


class WrongNumberOfArgsException: public exception
{
  uint32_t required_nargs, actual_nargs;
  string msg;
  public:
    WrongNumberOfArgsException(uint32_t required_nargs, uint32_t actual_nargs)
    {
      // this имеет тип WrongNumberOfArgsException* и указывает на текущий
      // объект. Оператор `->` -- это сокращенная запись разыменование и 
      // одновременного получения члена объекта. Запись
      // `this->required_nargs` равносильна
      // `(*this).required_nargs`.
      this->required_nargs = required_nargs;
      this->actual_nargs = actual_nargs;
      // Целые числа преобразуются в строку.
      stringstream strs;
      strs << "The number of app args is " << this->actual_nargs << 
          " whereas " << this->required_nargs << " arguments are required.";
      msg = strs.str();
    }

    // `what()` -- специальная функция для, которая возвращает сообщение об
    // ошибке. Она должна быть определена в каждом из наследников класса
    // `exception`. 
    // `throw()` позволяет показывает, какие исключения могут выбрасываться
    // внутри функции. В данном случае при появлении любого исключения внутри
    // функции будет брошено исключение `std::unexpected`.
    const char* what() const throw()
    {
      // Возвращаем C-строку (массив символов)
      return msg.c_str();
    }

    // Этот деструктор пришлось имплементрировать, так как в `exception` он
    // виртуальный со спецификатором `throw()`, а значит, чтобы указать 
    // спецификатор, его нужно определить в этом классе.
    ~WrongNumberOfArgsException() throw() {};
};


int main(int argc, char *argv[])
{
  // `argc` -- количество аргументов приложения. Принимает значения >0
  // `argv` -- аргументы приложения. Представляют собой список C-строк 
  // (массивов символов)
  //
  // Нулевой аргумент приложения -- это всегда название исполняемог файла
  cout << "app name: " << argv[0] << endl;

  // Конструкция `try{}catch(ExType ex){}` используется для работы с 
  // исключениями.
  // Если внутри блока `try` произошло исключение, то оно может быть поймано
  // блоком `catch`, если тип исключения совпадет с `ExType`. Если исключение
  // поймано, то выполняется блок `catch`. Пойманное исключение в блоке `catch`
  // можно бросить повторно, после того, как оно было обработано.
  // В данном случае try..catch используется для проверки того, что на вход
  // было подано нужное количество аргументов.
  try {
    if (argc != 2)
      // Бросаем специальное исключение, которое сообщает о том, что 
      // приложение получило неправильное количество аргументов.
      throw WrongNumberOfArgsException(1, argc-1);
  }catch(const WrongNumberOfArgsException &ex) {
    cerr << ex.what() << endl;
    throw;
  }

  int num = 0;
  num = atoi(argv[1]);
  cout << num * num << endl;
  
}
