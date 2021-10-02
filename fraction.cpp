#include <iostream>
#include <cstdlib>
using namespace std;
class fraction
{
    int num, denom;

public:
    fraction(){};
    friend istream &operator>>(istream &in, fraction &f);
    friend ostream &operator<<(ostream &out, fraction &f);
    friend int gcd(int x, int y);
    int operator[](int i);
    void operator=(const fraction &f);
    bool operator==(const fraction &f);
    bool operator!=(const fraction &f);
    bool operator<(const fraction &f);
    bool operator>(const fraction &f);
    fraction operator*();
    fraction operator+(const fraction &f);
    fraction operator-(const fraction &f);
    fraction operator*(const fraction &f);
    fraction operator/(const fraction &f);
};
int gcd(int x, int y)
{
    int temp, a, b;
    x = labs(x);
    y = labs(y);
    if (x < y)
    {
        a = x;
        b = y;
    }
    else
    {
        a = y;
        b = x;
    }
    while (b % a != 0)
    {
        temp = a;
        a = b % a;
        b = temp;
    }
    return a;
}
int fraction ::operator[](int k)
{
    if (k == 0)
        return num;
    else
        return denom;
}
void fraction ::operator=(const fraction &f)
{
    num = f.num;
    denom = f.denom;
}
fraction fraction::operator*()
{
    fraction normal;
    int d = gcd(num, denom);
    if (num < 0 && denom < 0)
    {
        normal.denom = labs(denom / d);
        normal.num = labs(num / d);
    }
    else
    {
        normal.num = num / d;
        normal.denom = denom / d;
    }
    if (normal.denom < 0)
    {
        normal.num = -normal.num;
        normal.denom = -normal.denom;
    }

    return normal;
}
bool fraction::operator==(const fraction &f)
{
    fraction temp1, temp2;
    temp1 = *this;
    temp1 = *temp1;
    temp2 = f;
    temp2 = *temp2;
    if (temp1.num == temp2.num && temp1.denom == temp2.denom)
        return true;

    return false;
}
/*bool fraction::operator!=(const fraction &f)
{
    return !(*this == f);
}*/
bool fraction ::operator<(const fraction &f)
{
    fraction temp1, temp2;
    temp1 = *this;
    temp1 = *temp1;
    temp2 = f;
    temp2 = *temp2;
    if ((temp1.num * temp2.denom) < (temp2.num * temp1.denom))
        return true;
    else
        return false;
}
bool fraction ::operator>(const fraction &f)
{
    fraction temp1, temp2;
    temp1 = *this;
    temp1 = *temp1;
    temp2 = f;
    temp2 = *temp2;
    if (temp1.num * temp2.denom > temp2.num * temp1.denom)
        return true;
    else
        return false;
}
fraction fraction::operator+(const fraction &f)
{
    fraction sum;
    sum.num = num * f.denom + f.num * denom;
    sum.denom = denom * f.denom;
    sum = *sum;
    return sum;
}
fraction fraction::operator-(const fraction &f)
{
    fraction sub;
    sub.num = num * f.denom - f.num * denom;
    sub.denom = denom * f.denom;
    sub = *sub;
    return sub;
}
fraction fraction::operator*(const fraction &f)
{
    fraction mult;
    mult.num = num * f.num;
    mult.denom = denom * f.denom;
    mult = *mult;
    return mult;
}
fraction fraction::operator/(const fraction &f)
{
    fraction div;
    div.num = num * f.denom;
    div.denom = denom * f.num;
    div = *div;
    return div;
}

istream &operator>>(istream &in, fraction &f)
{
    cout << "Enter numerator : ";
    in >> f.num;
    cout << "Enter denominator : ";
    int a;
    in >> a;
    if (a != 0)
        f.denom = a;
    else
        exit(1);

    return in;
}
ostream &operator<<(ostream &out, fraction &f)
{
    out << "(" << f.num << ")/(" << f.denom << ")" << endl;
    return out;
}

int main()
{
    fraction f1, f2, f3, f4;
    cin >> f1 >> f2;
    cout << f1 << f2;
    cout << "Numerator: " << f1[0] << " Denominator: " << f1[1] << endl;
    f3 = (f1 + f2);
    f4 = f1 - f2;
    cout << "Sum: " << f3 << "Sub: " << f4;
    f3 = (f1 * f2);
    f4 = (f1 / f2);
    cout << "Mult: " << f3 << "Div: " << f4;
    cout << "Compairing equal to, not equal to, less than ,greater than: " << endl;
    cout << (f1 == f2) << " " << (f1 != f2) << " " << (f1 < f2) << " " << (f1 > f2) << endl;
    cout << "Enter the fraction to normalize: " << endl;
    cin >> f3;
    f4 = *f3;
    cout << f4;
    return 0;
}
