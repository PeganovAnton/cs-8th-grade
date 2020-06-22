#include <iostream>
#include <stdint.h>
#include <stdexcept>


using namespace std;


class Fraction
{
  private:
    int32_t numerator;
    uint32_t denominator;
  public:
    Fraction(int numerator, int denominator)
    {
      if (denominator == 0)
        throw overflow_error("Divide by zero exception");
      this->numerator = numerator;
      if (denominator < 0){
        this->numerator *= -1;
        this->denominator = -1 * denominator;
      }
      else 
        this->denominator = denominator;
    }

    int32_t get_numerator() const
    {
       return numerator;
    }

    uint32_t get_denominator() const
    {
       return denominator;
    }

    Fraction operator-(const Fraction& b) const
    {
      return Fraction(
          b.get_denominator() * this->get_numerator() 
            - this->get_denominator() * b.get_numerator(),
          this->get_denominator() * b.get_denominator());
    }

    Fraction reverse() const
    {
      int32_t num = denominator;
      uint32_t den = 0;
      if (numerator > 0)
        den = numerator;
      else if (numerator < 0) {
        den = -1 * numerator;
        num *= -1;
      }
      else
        throw overflow_error("Divide by zero exception");
      return Fraction(num, den);
    }
    
    void print() const
    {
      cout << numerator << "/" << denominator << endl;
    }
};


int main()
{
  (Fraction(1, 2) - Fraction(1, 3)).print();
  Fraction(2, 3).reverse().print();
}
