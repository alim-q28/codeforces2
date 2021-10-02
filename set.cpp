#include <iostream>
using namespace std;
class set
{
    int *ptr, size;

public:
    set(const set &s); //copy constructor
    set() {}
    ~set(); //destructor
    friend istream &operator>>(istream &in, set &s);
    friend ostream &operator<<(ostream &out, set &s);
    bool is_exsist(int a);
    set operator+(const set &s);
    set operator-(const set &s);
    set operator*(const set &s);
    bool operator==(const set &s);
    bool operator!=(const set &s);
    //bool operator<(const set &s);
    bool operator<=(const set &s);
    bool operator>(const set &s);
    bool operator>=(const set &s);
};
set ::set(const set &s)
{
    size = s.size;
    ptr = new int[size];
    for (int i = 0; i < size; i++)
        ptr[i] = s.ptr[i];
}
set ::~set()
{
    delete[] ptr;
    delete &size;
}
bool set ::is_exsist(int a)
{
    int i = 0;
    for (i = 0; i < this->size; i++)
    {
        if (this->ptr[i] == a)
            return true;
    }
    return false;
}
set set::operator+(const set &s)
{
    set uni;
    uni.ptr = new int[size + s.size];
    int i, j = 0;
    uni.size = size + s.size;
    for (i = 0; i < size; i++)
    {
        if (!uni.is_exsist(this->ptr[i]))
        {
            uni.ptr[j] = ptr[i];
            j++;
        }
    }
    for (i = 0; i < s.size; i++)
    {
        if (!uni.is_exsist(s.ptr[i]))
        {
            uni.ptr[j] = s.ptr[i];
            j++;
        }
    }
    uni.size = j;
    return uni;
}
set set::operator-(const set &s)
{
    set diff, temp = s;
    diff.ptr = new int[size];
    diff.size = size;
    int i, j = 0;
    for (i = 0; i < size; i++)
    {
        if (!temp.is_exsist(this->ptr[i]))
        {
            diff.ptr[j] = ptr[i];
            j++;
        }
    }
    diff.size = j;
    return diff;
}
set set::operator*(const set &s)
{
    set inter, temp = s;
    inter.size = size;
    inter.ptr = new int[size];
    int i, j = 0;
    for (i = 0; i < size; i++)
    {
        if (temp.is_exsist(this->ptr[i]))
        {
            inter.ptr[j] = ptr[i];
            j++;
        }
    }
    inter.size = j;
    return inter;
}
bool set::operator==(const set &s)
{
    if (size != s.size)
        return false;
    set temp = s;
    int i;
    for (i = 0; i < size; i++)
    {
        if (!temp.is_exsist(this->ptr[i]))
            return false;
    }
    return true;
}
bool set::operator!=(const set &s)
{
    return !((*this) == s);
}
bool set::operator<(const set &s)
{
    if (this->size >= s.size)
        return false;
    set temp = s;
    int i;
    for (i = 0; i < this->size; i++)
    {
        if (!temp.is_exsist(this->ptr[i]))
            return false;
    }
    return true;
}
bool set::operator<=(const set &s)
{
    if ((*this < s) || (*this == s))
        return true;

    return false;
}
bool set::operator>(const set &s)
{
    if (this->size <= s.size)
        return false;
    int i;
    for (i = 0; i < s.size; i++)
    {
        if (!(*this).is_exsist(s.ptr[i]))
            return false;
    }
    return true;
}
bool set::operator>=(const set &s)
{
    if ((*this > s) || (*this == s))
        return true;

    return false;
}
istream &operator>>(istream &in, set &s)
{
    int temps, a, i, j = 0;
    cout << "Enter the number of elements: ";
    in >> temps;
    s.ptr = new int[temps];
    s.size = temps;
    cout << "Enter the values: ";
    for (i = 0; i < temps; i++)
    {
        in >> a;
        if (!s.is_exsist(a))
        {
            s.ptr[j] = a;
            j++;
        }
    }
    s.size = j;
    return in;
}
ostream &operator<<(ostream &out, set &s)
{
    if (s.size == 0)
    {
        out << " " << endl;
        return out;
    }

    out << "{ " << s.ptr[0];
    for (int i = 1; i < s.size; i++)
        out << ", " << s.ptr[i];
    out << " }" << endl;
    return out;
}
int main()
{
    set s1, s2;
    cin >> s1 >> s2;
    cout << "A = " << s1 << "B = " << s2;
    set s3 = s1 + s2;
    cout << "A U B = " << s3;
    set s4 = s1 - s2;
    cout << "A - B =" << s4;
    set s5 = s1 * s2;
    cout << "A intersection B = " << s5;
    cout << "Subset , Superset testing: " << endl;
    cout << "A is proper-subset of B , A is subset of B ,";
    cout << "A is proper-superset of B , A is superset of B: " << endl;
    cout << (s1 < s2) << " " << (s1 <= s2) << " " << (s1 > s2) << " " << (s1 >= s2) << endl;
    cout << "Comparing sets: " << endl;
    cout << "A == B , A != B :" << endl;
    cout << (s1 == s2) << " " << (s1 != s2) << endl;
    return 0;
}
