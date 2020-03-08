#include <iostream>
#include <map>
#include <string>


using namespace std;


int main()
{
  // При создании ассоциативного массива необходимо указать, какому типу 
  // данных принадлежат ключи и значения массива. Это делается с помощью
  // угловых скобок, как в следующей строчке кода.
  //
  // Если строковый литерал слишком длинный, то нужно закрыть кавычки и 
  // продолжить его с новой строки.
  map<string,string> en_ru_dict; // { {"cat", "кошка"}, {"dog", "собака"} }
  cout << "Размер ассоциативного массива сразу после создания.\n"
      "en_ru_dict.size() = " << en_ru_dict.size() << endl << endl;

  // Квадратные скобки возвращают ссылку на элемент ассоциативного массива.
  // Если элемента с таким ключом нет в массиве, то он создается со значением,
  // равным значению по умолчанию. В случае, если значения массива -- строки,
  // значение по умолчанию -- пустая строка.
  //
  // Если внутри строки встречаются кавычки, то перед ними нужно ставить 
  // обратный слеш.
  cout << "Получаем значение элемента с ключом \"cat\". В настоящий момент "
      "такого элемента нет в массиве. \nen_ru_dict[\"cat\"] = " 
      << en_ru_dict["cat"] << endl;
  cout << "Размер ассоциативного массива после попытки получения значения "
      "элемента с помощью оператора `[]`.\n"\
      "en_ru_dict.size() = " << en_ru_dict.size() << endl << endl;

  // Подсчет количества элементов с данным значением ключа. Так как в 
  // ассоциативном массиве каждому ключу соответствует 1 элемент, то метод
  // `count()` возвращает 0 или 1. 
  // 
  // Это простейший способ проверить, если в массиве элемент с некоторым 
  // ключом.
  // 
  // В предыдущем выражении мы попытались получить значении элемента с ключом
  // "cat" с помощью оператора `[]`. Это привело к созданию элемента со 
  // значением, равным пустой строке.
  cout << "Количество элементов с ключом \"cat\" в `en_ru_dict`:\n"
      "en_ru_dict.count(\"cat\") = " << en_ru_dict.count("cat") 
      << endl << endl;

  // Это добавление нового элемента в массив. Таким же способом можно менять
  // уже имеющиеся в массиве элементы.
  en_ru_dict["cow"] = "корова";
  cout << "Размер ассоциативного массива после добавления в массив элемента "
      "с ключом \"cow\".\nen_ru_dict.size() = " << en_ru_dict.size() << endl; 
  cout << "en_ru_dict[\"cow\"] = " << en_ru_dict["cow"] << endl << endl;

  // Удаляем элемент с ключом "cat" из ассоциативного массива.
  en_ru_dict.erase("cat");
  cout << "Количество элементов с ключом \"cat\" после удаления элемента:\n"
      << "en_ru_dict.count(\"cat\") = " << en_ru_dict.count("cat") << endl;
}