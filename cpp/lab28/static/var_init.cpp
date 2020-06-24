#include <iostream>
#include <string>


using namespace std;


class CreationReporter
{
  string name;
  public:
    CreationReporter(string name): name(name) 
    {
      cout << "Creating variable \"" << this->name << "\"\n";
    }
};


CreationReporter global_var("global_var");


void foo()
{
  static CreationReporter static_var("static_var");
  CreationReporter local_var("local_var_in_foo");
}


int main()
{
  cout << "Started main\n";
  foo();
  CreationReporter local_var_in_main("local_var_in_main");
  foo();
  foo();
}
  
