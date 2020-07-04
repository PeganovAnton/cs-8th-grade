#include <iostream>


using namespace std;


class CompanyMember
{
    private:
    const string name;
    int age;
    void introduceYourself()const
    {
        cout << "My name is " << name << " and I am " << age << " years old.\n";
    };
    public:
    CompanyMember()
    {
        cin >> age;
    }
    string set_name()
    {
        string s;
        cin >> s;
        return s;
    }
    int get_age()const
    {
        return age;
    };
    string get_name()const
    {
        return name;
    };
    void IY()const
    {
        introduceYourself();
    }
};

class Boss:public CompanyMember
{
private:
    string department;
public:
    Boss()
    {
        CompanyMember:set_name();
        cin >> department;
    }
    void fireInferior(string fired)
    {
        cout <<  fired << ", you are fired!\n";
    }
};
