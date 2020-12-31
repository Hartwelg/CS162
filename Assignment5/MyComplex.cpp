#include "MyComplex.h"
using namespace std;

MyComplex::MyComplex()
{
    real = 0;
    imaginary = 0;
}
MyComplex::MyComplex(double theReal)
{
    real = theReal;
    imaginary = 0;
}
MyComplex::MyComplex(double theReal, double theImaginary)
{
    real = theReal;
    imaginary = theImaginary;
}
double MyComplex::getRealPart()
{
    return real;
}
double MyComplex::getComplexPart()
{
    return imaginary;
}
MyComplex MyComplex::operator+(const MyComplex &other) const
{
    double realPart = real + other.real;
    double imaginaryPart = imaginary + other.imaginary;
    return MyComplex(realPart, imaginaryPart);
}
MyComplex MyComplex::operator-(const MyComplex &other) const
{
    double realPart = real - other.real;
    double imaginaryPart = imaginary - other.imaginary;
    return MyComplex(realPart, imaginaryPart);
}
MyComplex MyComplex::operator-() const
{
    return MyComplex(-real, -imaginary);
}
MyComplex MyComplex::operator*(const MyComplex &other) const
{
    MyComplex num;
    double realPart = real * other.real - imaginary * other.imaginary;
    double imaginaryPart = real * other.imaginary + imaginary * other.real;
    return MyComplex(realPart, imaginaryPart);
}
MyComplex MyComplex::operator/(const MyComplex &other) const
{
    double divisor = (other.real * other.real) + (other.imaginary * other.imaginary);
    MyComplex temp;
    temp.real = (real * other.real) + (imaginary * other.imaginary);
    temp.real /= divisor;
    temp.imaginary = (imaginary * other.real) - (real * other.imaginary);
    temp.imaginary /= divisor;
    return temp;
}
MyComplex& MyComplex::operator+=(const MyComplex &other)
{
    double realPart = real + other.real;
    double imaginaryPart = imaginary + other.imaginary;
    real = realPart;
    imaginary = imaginaryPart;
    return *this;
}
MyComplex& MyComplex::operator -=(const MyComplex &other)
{
    double realPart = real - other.real;
    double imaginaryPart = imaginary - other.imaginary;
    real = realPart;
    imaginary = imaginaryPart;
    return *this;
}
MyComplex& MyComplex::operator *=(const MyComplex &other)
{
    double realPart = real * other.real - imaginary * other.imaginary;
    double imaginaryPart = real * other.imaginary + imaginary * other.real;
    real = realPart;
    imaginary = imaginaryPart;
    return *this;
}
MyComplex& MyComplex::operator/=(const MyComplex &other)
{
    double divisor = (other.real * other.real) + (other.imaginary * other.imaginary);
    double realPart = (real * other.real) + (imaginary * other.imaginary);
    realPart /= divisor;
    double imaginaryPart = (imaginary * other.real) - (real * other.imaginary);
    imaginaryPart /= divisor;
    real = realPart;
    imaginary = imaginaryPart;
    return *this;
}
bool MyComplex::operator==(const MyComplex &other) const
{
    if (real == other.real && imaginary == other.imaginary)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool MyComplex::operator!=(const MyComplex &other) const
{
    if (real == other.real && imaginary == other.imaginary)
    {
        return false;
    }
    else
    {
        return true;
    }
}
MyComplex& MyComplex::operator++()
{
    double realPart = real + 1;
    real = realPart;
    return *this;
}
MyComplex& MyComplex::operator--()
{
    double realPart = real - 1;
    real = realPart;
    return *this;
}
MyComplex MyComplex::operator++(int dum)
{
    MyComplex temp(real, imaginary);
    real = real + 1;
    return temp;
}
MyComplex MyComplex::operator--(int dum)
{
    MyComplex temp(real, imaginary);
    real = real - 1;
    return temp;
}
std::ostream& operator <<(std::ostream& outStream, const MyComplex& other)
{
    if (other.imaginary  < 0)
    {
        outStream << other.real << " - " << other.imaginary * -1.0<< "i";
        return outStream;
    }
    else
    {
        outStream << other.real << " + " << -other.imaginary * -1.0 << "i";
        return outStream;
    }

}
std::istream& operator >>(std::istream& inStream, MyComplex& other)
{
    double realPart, imaginaryPart;
    char sign, i;
    inStream >> realPart;
    inStream >> sign;
    inStream >> imaginaryPart;
    inStream >> i;
    if (sign == '-')
    {
        imaginaryPart = imaginaryPart * -1.0;
    }
    other.real = realPart;
    other.imaginary = imaginaryPart;
    return inStream;
}
