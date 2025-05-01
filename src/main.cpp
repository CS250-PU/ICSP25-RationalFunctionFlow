//******************************************************************************
// File name:   main.cpp
// Author:      CS, Pacific University
// Date:        
// Class:       
// Assignment:  
// Purpose:     Simple driver to execute SampleClass class
// Hours:       
//******************************************************************************

#include <iostream>
#include "../include/SampleClass.h"
using namespace std;

class Rational {
  public:
    Rational () { cout << "ctor1" << endl; mNumerator = 0; mDenominator = 1;}
    Rational (int numerator, int denominator) {
      cout << "ctor2" << endl;
      mNumerator = numerator;
      mDenominator = denominator;
    } 
    Rational (const Rational &rational) {
      cout << "ctor3" << endl;
      mNumerator = rational.mNumerator;
      mDenominator = rational.mDenominator;
    }
    ~Rational () { cout << "dtor" << endl;}
    Rational &operator= (const Rational &rational) {
      cout << "op=" << endl;
      if (this != &rational) {
        mNumerator = rational.mNumerator;
        mDenominator = rational.mDenominator;
      }
      return *this;
    }
    friend ostream &operator<< (ostream &os, const Rational &rational) {
      os << rational.mNumerator << "/" << rational.mDenominator;
      return os;
    }

  private:
    int mNumerator;
    int mDenominator;
};

void foo (Rational cR) {
  cout << "foo" << endl;
}

Rational bar (const Rational &cR) {
  cout << "bar" << endl;
  return cR;
}

int main () {
  Rational cR1;
  Rational cR2(1, 2);
  Rational cR3(cR2);
  Rational cR4 = cR2;
  Rational cR5 (2, 3);;
  cout << "cR1: " << cR1 << endl;
  (cR1 = bar(cR2)) = cR5;
  cout << "cR1: " << cR1 << endl;

  std::cout << "Process Completed" << std::endl;

  return EXIT_SUCCESS;
}