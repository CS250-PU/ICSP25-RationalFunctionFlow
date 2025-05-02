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
  Rational () {
    cout << "ctor1 *this: " << *this << endl;
    mNumerator = 0; mDenominator = 1;
  }

  Rational (int numerator, int denominator) {
    mNumerator = numerator;
    mDenominator = denominator;
    cout << "ctor2 *this: " << *this << endl;
  }

  Rational (const Rational& rcRational) {
    mNumerator = rcRational.mNumerator;
    mDenominator = rcRational.mDenominator;
    cout << "ctor3 *this: " << *this << endl;
  }

  ~Rational () {
    cout << "dtor *this: " << *this << endl;
  }

  Rational& operator= (const Rational& rcRational) {
    cout << "op= *this: " << *this << "rcRational: " << rcRational << endl;
    if (this != &rcRational) {
      mNumerator = rcRational.mNumerator;
      mDenominator = rcRational.mDenominator;
    }
    return *this;
  }

  friend ostream& operator<< (ostream& rcOutStream,
    const Rational& rcRational) {
    rcOutStream << rcRational.mNumerator << "/" << rcRational.mDenominator;
    return rcOutStream;
  }

private:
  int mNumerator;
  int mDenominator;
};

void foo (Rational cR) {
  cout << "foo" << endl;
}

Rational bar (const Rational& cR) {
  cout << "bar cR: " << cR << endl;
  return cR;
}

int main () {
  Rational cR1;
  Rational cR2 (1, 2);
  Rational cR3 (cR2);
  Rational cR4 = cR2;
  Rational cR5 (2, 3);;
  cout << "cR1: " << cR1 << endl;
  (cR1 = bar (cR2)) = cR5;
  cout << "cR1: " << cR1 << endl;

  std::cout << "Process Completed" << std::endl;

  return EXIT_SUCCESS;
}