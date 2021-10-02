#include <iostream>
using namespace std;

template <class T>
class set
{
    T* ptr;
    int size;

public:
    set(const set<T> &s); //copy constructor
    set() {}
    ~set(); //destructor
    friend istream &operator>>(istream &in, set<T> &s)
    {
    T a;
    int temps, i, j = 0;
    cout << "Enter the number of elements: ";
    in >> temps;
    s.ptr = new T[temps];
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

    friend ostream &operator<<(ostream &out, set<T> &s)
    {
        if(s.size == 0)
        {
            out<<" NULL SET "<<endl;
            return out;
        }
    out << "{ " << s.ptr[0];
    for (int i = 1; i < s.size; i++)
        out << ", " << s.ptr[i];
    out << " }" << endl;
    return out;
    }
    bool is_exsist(T &a);
    set<T> operator+(const set<T> &s);
    set<T> operator-(const set<T> &s);
    set<T> operator*(const set<T> &s);
    bool operator==(const set<T> &s);
    bool operator!=(const set<T> &s);
    bool operator<(const set<T> &s);
    bool operator<=(const set<T> &s);
    bool operator>(const set<T> &s);
    bool operator>=(const set<T> &s);
};

template <class T>
set<T>::set(const set<T> &s)
{
    size = s.size;
    ptr = new T[size];
    for (int i = 0; i < size; i++)
        ptr[i] = s.ptr[i];
}

template <class T>
set<T>::~set()
{
    delete[] ptr;
    delete &size;
}

template <class T>
bool set<T>::is_exsist(T &a)
{
    for (int i = 0; i < this->size; i++)
    {
        if (this->ptr[i] == a)
            return true;
    }
    return false;
}

template <class T>
set<T> set<T>::operator+(const set<T> &s)
{
    set<T> uni;
    uni.ptr = new T[size + s.size];
    int i, j = 0;
    uni.size = this->size + s.size;
    for (i = 0; i < this->size; i++)
    {
        if (!uni.is_exsist(ptr[i]))
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

template <class T>
set<T> set<T>::operator-(const set<T> &s)
{
    set<T> diff, temp = s;
    diff.ptr = new T[size];
    diff.size = this->size;
    int i, j = 0;
    for (i = 0; i < this->size; i++)
    {
        if (!temp.is_exsist(ptr[i]))
        {
            diff.ptr[j] = ptr[i];
            j++;
        }
    }
    diff.size = j;
    return diff;
}

template <class T>
set<T> set<T>::operator*(const set<T> &s)
{
    set<T> inter;
    inter.size = this->size;
    inter.ptr = new T[this->size];
    set<T> temp = s;
    int i, j = 0;
    for (i = 0; i < this->size; i++)
    {
        if (temp.is_exsist(ptr[i]))
        {
            inter.ptr[j] = ptr[i];
            j++;
        }
    }
    inter.size = j;
    return inter;
}

template <class T>
bool set<T>::operator==(const set<T> &s)
{
    if (this->size != s.size)
        return false;
    set<T> temp = s;
    int i;
    for (i = 0; i < this->size; i++)
    {
        if (!temp.is_exsist(this->ptr[i]))
           return false;
    }
    return true;
}

template <class T>
bool set<T>::operator!=(const set<T> &s)
{
    
    return !((*this) == s);
}

template <class T>
bool set<T>::operator<(const set<T> &s)
{
    if (this->size >= s.size)
        return false;
    set<T> temp = s;
    int i;
    for (i = 0; i < this->size; i++)
    {
        if (!temp.is_exsist(this->ptr[i]))
            return false;
    }
    return true;
}

template <class T>
bool set<T>::operator<=(const set<T> &s)
{
    if (*this < s || *this == s)
        return true;

    return false;
}

template <class T>
bool set<T>::operator>(const set<T> &s)
{
    if (size <= s.size)
        return false;
    int i, j = 0;
    for (i = 0; i < s.size; i++)
    {
        if (!(*this).is_exsist(s.ptr[i]))
            return false;
    }
    return true;
}

template <class T>
bool set<T>::operator>=(const set<T> &s)
{
    if (*this > s || *this == s)
        return true;

    return false;
}

int main()
{
    set<float> s1, s2;
    cin >> s1 >> s2;
    cout << "A = " << s1 << "B = " << s2;
    set<float> s3 = s1 + s2;
    cout << "A U B = " << s3;
    set<float> s4 = s1 - s2;
    cout << "A - B =" << s4;
    set<float> s5 = s1 * s2;
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