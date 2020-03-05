#include <iostream>

// Библиотека для получения максимальных и минимальных значений типов.
#include <limits> 


using namespace std;


int main()
{
  // `char` -- это символьный тип, который занимает в памяти 1 байт.
  // Его можно использовать для хранения букв английского алфавита и
  // других символов ASCII. Также `char` может использоваться, как 
  // целый тип. Диапазон значений `char`, как целового типа, -- от
  // -128 до 127.
  char a;

  // Кроме обычных целых типов есть беззнаковые типы, которые не 
  // могут принимать отрицательные значения. Для объявления 
  // беззнакового типа используется ключевое слово `unsigned`.
  unsigned char aa;
  short int b;
  unsigned short int bb;
  int c;
  unsigned int cc;

  // `long` и `long int` -- это один и тот же тип.
  long d;
  long int e;
  unsigned long dd;

  // `long long` и `long long int` -- это один и тот же тип.
  long long f;
  long long int g;
  unsigned long long ff;

  // Функция `sizeof()` возвращает количество байт, 
  // которое занимает в памяти тип данных.
  cout << "Size of `char`: " << sizeof(a) << endl;

  // В C/C++ запись `(variable_type)variable_name` означает приведение
  // переменной `variable_name` к типу `variable_type`. Например, в 
  // следующем выражении символьный тип `char` приводится к типу `int`,
  // так как по умолчании переменные типа `char` печатаются, как символы,
  // а не числа.
  cout << "`char` numeric range: [" 
      << (int)numeric_limits<char>::min() << ", " 
      << (int)numeric_limits<char>::max() << "]\n\n";

  cout << "Size of `unsigned char`: " << sizeof(aa) << " bytes\n";
  cout << "`unsigned char` numeric range: [" 
      << (int)numeric_limits<unsigned char>::min() << ", " 
      << (int)numeric_limits<unsigned char>::max() << "]\n\n";

  cout << "Size of `short int`: " << sizeof(b) << " bytes\n";
  cout << "`short int` numeric range: [" 
      << numeric_limits<short int>::min() << ", " 
      << numeric_limits<short int>::max() << "]\n\n";

  cout << "Size of `unsigned short int`: " << sizeof(bb) << " bytes\n'";
  cout << "`unsigned short int` numeric range: [" 
      << numeric_limits<unsigned short int>::min() << ", " 
      << numeric_limits<unsigned short int>::max() << "]\n\n";

  cout << "Size of `int`: " << sizeof(int) << " bytes\n";
  cout << "`int` value range: [" 
      << numeric_limits<int>::min() << ", " 
      << numeric_limits<int>::max() << "]\n\n";

  cout << "Size of `unsigned int`: " << sizeof(cc) << " bytes\n";
  cout << "`unsigned int` value range: [" 
      << numeric_limits<unsigned int>::min() << ", " 
      << numeric_limits<unsigned int>::max() << "]\n\n";

  cout << "Size of `long`: " << sizeof(long) << " bytes\n";
  cout << "`long` value range: [" 
      << numeric_limits<long>::min() << ", " 
      << numeric_limits<long>::max() << "]\n\n";

  cout << "Size of `unsigned long`: " << sizeof(dd) << " bytes\n";
  cout << "`long` value range: [" 
      << numeric_limits<unsigned long>::min() << ", " 
      << numeric_limits<unsigned long>::max() << "]\n\n";

  cout << "Size of `long long`: " << sizeof(g) << " bytes\n";
  cout << "`long long` value range: [" 
      << numeric_limits<long long>::min() << ", " 
      << numeric_limits<long long>::max() << "]\n\n";
  
  return 0;
}
