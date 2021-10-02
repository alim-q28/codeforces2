#include <iostream>
using namespace std;
class complex
{
    double real, img;

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
        return img;
}
void complex ::operator=(const complex &c)
{
    real = c.real;
    img = c.img;
}
bool complex::operator==(const complex &c)
{
    if (real == c.real && img == c.img)
        return true;
    else
        return false;
}
bool complex::operator!=(const complex &c)
{
    if (real == c.real && img == c.img)
        return false;
    else
        return true;
}
complex complex::operator!()
{
    complex conj;
    conj.real = real;
    conj.img = -img;
    return conj;
}
complex complex::operator+(const complex &c)
{
    complex sum;
    sum.real = real + c.real;
    sum.img = img + c.img;
    return sum;
}
complex complex::operator-(const complex &c)
{
    complex sum;
    sum.real = real - c.real;
    sum.img = img - c.img;
    return sum;
}
complex complex::operator*(const complex &c)
{
    complex mult;
    mult.real = real * c.real - img * c.img;
    mult.img = real * c.img + img * c.real;
    return mult;
}
complex complex::operator/(const complex &c)
{
    complex div;
    div.real = (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img);
    div.img = (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img);
    return div;
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
    out << c.real << " + " << c.img << "i" << endl;
    return out;
}
int main()
{
    complex c1, c2, c3, c4, c5, c6, c7;
    cin >> c1;
    cout << "Your complex number: " << c1;
    cout << "Real part: " << c1[0] << " Imaginary part: " << c1[1] << endl;
    c7 = !c1;
    cout << "Conjugate: " << c7;
    cin >> c2;
    c3 = (c1 + c2);
    cout << "Sum of the complex numbers: " << c3;
    c4 = c1 - c2;
    cout << "Substraction is: " << c4;
    c5 = (c1 * c2);
    c6 = (c1 / c2);
    cout << "Multiplication is: " << c5 << "Division is: " << c6;
    cout << "Compareing: " << (c1 == c2) << " " << (c1 != c2);
    return 0;
}