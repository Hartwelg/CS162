#ifndef MYCOMPLEX_H
#define MYCOMPLEX_H

#include <iostream>

class MyComplex
{
public:
    MyComplex();
    MyComplex(double theReal);
    MyComplex(double theReal, double theImaginary);
    double getRealPart();
    double getComplexPart();
    MyComplex operator+(const MyComplex &other) const;
    MyComplex operator*(const MyComplex &other) const;
    MyComplex operator/(const MyComplex &other) const;
    MyComplex operator-(const MyComplex &other) const;
    MyComplex operator-() const;
    MyComplex& operator+=(const MyComplex &other);
    MyComplex& operator*=(const MyComplex &other);
    MyComplex& operator/=(const MyComplex &other);
    MyComplex& operator-=(const MyComplex &other);
    MyComplex& operator++();
    MyComplex& operator--();
    MyComplex operator++(int dum);
    MyComplex operator--(int dum);
    bool operator==(const MyComplex &other) const;
    bool operator!=(const MyComplex &other) const;
    friend std::ostream& operator<<(std::ostream& outStream, const MyComplex& other);
    friend std::istream& operator>>(std::istream& inStream, MyComplex& other);
private:
    double real;
    double imaginary;
};
#endif // MYCOMPLEX_H
