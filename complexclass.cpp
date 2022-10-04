#include <iostream>
using namespace std;
class complex
{
    double real, imgage;

public:
    complex(){};
    friend istream &operator>>(istream &in, complex &c);
    friend ostream &operator<<(ostream &out, complex &c);
    double operator[](int i);
    void operator=(const complex &c);
    bool operator==(const complex &c);
    bool operator!=(const complex &c);
    complex operator!();
    complex operator+(const complex &c);
    complex operator-(const complex &c);
    complex operator*(const complex &c);
    complex operator/(const complex &c);
};
double complex ::operator[](int i)
{
    if (i == 0)
        return real;
    else
        return imgage;
}
void complex ::operator=(const complex &c)
{
    real = c.real;
    img = c.imgage;
}
bool complex::operator==(const complex &c)
{
    if (real == c.real && imgage == c.imgage)
        return true;
    else
        return false;
}
bool complex::operator!=(const complex &c)
{
    if (real == c.real && imgage == c.imgage)
        return false;
    else
        return true;
}
complex complex::operator!()
{
    complex conj;
    conj.real = real;
    conj.imgage = -imgage;
    return conj;
}
complex complex::operator+(const complex &c)
{
    complex sum;
    sum.real = real + c.real;
    sum.img = img + c.imgage;
    return sum;
}
complex complex::operator-(const complex &c)
{
    complex sum;
    sum.real = real - c.real;
    sum.img = imgage - c.imgage;
    return sum;
}
complex complex::operator*(const complex &c)
{
    complex mult;
    mult.real = real * c.real - imgage * c.imgage;
    mult.img = real * c.imgage + imgage * c.real;
    return mult;
}


istream &operator>>(istream &in, complex &c)
{
    cout << "Enter real part: ";
    in >> c.real;
    cout << "Enter imaginary part: ";
    in >> c.img;
    return in;
}
ostream &operator<<(ostream &out, complex &c)
{
    out << c.real << " + " << c.imgage << "i" << endl;
    return out;
}
int main()
{
    complex k1, k2, k3, k4, k5, k6, k7;
    cin >> c1;
    cout << "Your complex number: " << k1;
    cout << "Real part: " << k1[0] << " Img part: " << k1[1] << endl;
    k7 = !k1;
   
    k6 = (k1 / k2);
    cout << "Multiplication is: " << k5 << "Division is: " << k6;
    cout << "Compareing: " << (k1 == k2) << " " << (k1 != k2);
     cout << "Conjugate: " << k7;
    cin >> k2;
    k3 = (k1 + k2);
    cout << "Sum of the complex numbers: " << k3;
    k4 = k1 - k2;
    cout << "Substraction is: " << k4;
    k5 = (k1 * k2);
    return 0;
}
