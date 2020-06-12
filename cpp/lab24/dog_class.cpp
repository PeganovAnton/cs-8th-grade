#include <iostream>
#include <string>


enum Mood {nice, angry};


class Dog
{
  private:
    Mood mood;
    std::string dog_name;
  public:

    // Это специальная функция, которая называется конструктором. 
    // Она вызывается при создании объекта и используется для инициализации 
    // признаков объекта.
    Dog(std::string dog_name_)
    {
      mood = nice;
      dog_name = dog_name_;
    }

    Dog()
    {
      mood = nice;
      dog_name = "Zhuchka";
    }

    void poke()
    {
      std::cout << "<You poked the dog with a stick>\n";
      mood = angry;
    }

    void say_gaw()
    {
      if (mood == nice)
        std::cout << "Gaw! :)\n";
      else
        std::cout << "GAWGAW!!!\n";
    }
    
    void feed()
    {
      std::cout << "<You fed the dog with a delicious stake>\n";
      mood = nice;
    }
 
    std::string what_is_your_name()
    {
      return dog_name;
    }
};


int main()
{
  Dog dog;
  dog.say_gaw();
  dog.poke();
  dog.say_gaw();
  dog.feed();
  dog.say_gaw();
  std::cout << "The dog name is " << dog.what_is_your_name() << std::endl;
  
  Dog dog2("Kashtanka");
  std::cout << "The 2nd dog name is " << dog2.what_is_your_name() << std::endl;

}
