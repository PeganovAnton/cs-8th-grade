#include <cstdlib>
#include <sstream>

// библиотека для создания функций с произвольным количеством параметров
#include <cstdarg>  

#include <stdint.h>
#include <string>
#include <iostream>


using namespace std;


// Преобразует целое число в строку.
string itos(int32_t a)
{
  ostringstream ss;
  ss << a;
  return ss.str();
}


// Подставляет аргументы, начиная со второго на место фигурных скобок. 
// Например, `format("{} + {} = {}", "1", "2", "3")` вернет `"1 + 2 = 3"`.
// Все аргументы функции должны быть строками.
string format(string tmpl, ...) 
{
  va_list args;
  va_start(args, tmpl);
  string result;
  size_t i;
  for(i=0; i<tmpl.size()-1; ++i) {
    if (tmpl[i] == '{' && tmpl[i+1] == '}'){
      result += va_arg(args, string);
      ++i;
    }
    else
      result += tmpl[i];
  }
  if (i < tmpl.size())
    result += tmpl[i];
  va_end(args);
  return result;
}


class Human
{
  private:
    const string unit_class;
    const string name;
    static const uint32_t velocity = 3;   
    static const uint32_t defence = 1;
    static const uint32_t max_health_points = 10;
  protected:
    int32_t health_points;
    int32_t x, y;
    bool alive;
  public:
    Human(string name, int32_t x, int32_t y): 
        name(name), unit_class("Human"), 
        health_points(Human::max_health_points), 
        x(x), y(y), alive(true) 
    {}

    void move(int32_t dx, int32_t dy) 
    {
      if (dx*dx + dy*dy > velocity*velocity){
        speak("Can not move so far.");
        return;
      }
      x += dx;
      y += dy;
      speak(format(
          "I moved to position with coords ({}, {})", itos(x), itos(y)));
    }

    void takeDamage(uint32_t enemy_attack)
    {
      set_health(get_health() - enemy_attack + get_defence());
      string tmps = itos(get_health());
      if (get_health() < 0){
        alive = false;
        speak("I am dying");
      }
      else
        speak(format(
            "I was hit and I have {}/{} health points left.", 
            tmps, itos(get_max_health())));
    }

    virtual void speak(string phrase) const
    {
      cout << unit_class << " " << name << ": " << phrase << endl;
    }

    virtual int32_t get_x() const {return x;}
    virtual int32_t get_y() const {return y;}
    string get_name() const {return name;} 
    virtual int32_t get_health() const {return health_points;}
    virtual void set_health(int32_t hp) {health_points = hp;}
    virtual uint32_t get_max_health() const {return max_health_points;}
    virtual uint32_t get_defence() const {return defence;}
};


class Militiaman: public Human
{
  private:
    const string unit_class;
    static const uint32_t velocity = 3;   
    static const uint32_t defence = 3;
    static const uint32_t attack = 5;
    static const uint32_t max_health_points = 12;
  protected:
    int32_t health_points;
    bool alive;
  public:
    Militiaman(string name, int32_t x, int32_t y) : Human(name, x, y),
        unit_class("Militiaman"), health_points(max_health_points), alive(true) 
    {}

    void speak(string phrase) const
    {
      cout << unit_class << " " << get_name() << ": " << phrase << endl;
    }

    // ОЧЕНЬ ВАЖНО
    // виртуальность метода проявляется, если его вызывать от ссылки 
    // или указателя
    void hitEnemy(Human& enemy)
    {
      if (abs(
            (enemy.get_x() - this->get_x()) 
            * (enemy.get_y() - this->get_y())) <=1){
        enemy.takeDamage(attack);
        speak("I hit the enemy");
      }else
        speak("Enemy is too far");
    } 
    int32_t get_x() const {return x;}
    int32_t get_y() const {return y;}
    int32_t get_health() const {return health_points;}
    virtual void set_health(int32_t hp) {health_points = hp;}
    uint32_t get_max_health() const {return max_health_points;}
    uint32_t get_defence() const {return defence;};
};


int main()
{
  Human human("John", 0, 0);
  Militiaman militiaman("Peter", 2, 3);
  Militiaman militiaman2("Frank", 1, 1);
  militiaman.move(2, 3);
  militiaman.move(-1, -1);
  militiaman.move(-1, -1);
  militiaman.hitEnemy(human);
  militiaman2.hitEnemy(militiaman);
}
