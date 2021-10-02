#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
class matrix
{
    double **ptr;
    int row, col;

public:
    matrix() {}
    matrix(const matrix &m);
    friend istream &operator>>(istream &in, matrix &m);
    friend ostream &operator<<(ostream &out, matrix &m);
    void operator=(const matrix &m);
    double operator[](int i);
    bool operator==(const matrix &m);
    matrix operator+(const matrix &m);
    matrix operator-(const matrix &m);
    matrix operator*(const matrix &m);
    double determinant();
    matrix cofactor(int p, int q, int size);
    matrix adjoint();
    matrix operator!();
    matrix operator/(const matrix &m);
};

matrix matrix::cofactor(int p, int q, int size)
{
    int i = 0, j = 0;
    matrix cofact;
    cofact.row = size - 1;
    cofact.col = size - 1;
    cofact.ptr = new double *[size - 1];
    for (i = 0; i < cofact.row; i++)
        cofact.ptr[i] = new double[size - 1];
    i = 0;
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            if (row != p && col != q)
            {
                cofact.ptr[i][j++] = ptr[row][col];
                if (j == size - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
    return cofact;
}
istream &operator>>(istream &in, matrix &m)
{
    cout << "Enter size of row and column: ";
    in >> m.row;
    in >> m.col;
    m.ptr = new double *[m.row];
    for (int i = 0; i < m.row; i++)
        m.ptr[i] = new double[m.col];
    cout << "Enter the values: " << endl;
    for (int i = 0; i < m.row; i++)
        for (int j = 0; j < m.col; j++)
            in >> m.ptr[i][j];

    return in;
}

ostream &operator<<(ostream &out, matrix &m)
{
    for (int i = 0; i < m.row; i++)
    {
        for (int j = 0; j < m.col; j++)
            cout << setw(10) << m.ptr[i][j];
        cout << endl;
    }
    return out;
}
matrix::matrix(const matrix &m)
{
    ptr = new double *[m.row];
    for (int i = 0; i < m.row; i++)
        ptr[i] = new double[m.col];
    row = m.row;
    col = m.col;
    for (int i = 0; i < m.row; i++)
        for (int j = 0; j < m.col; j++)
            ptr[i][j] = m.ptr[i][j];
}
void matrix::operator=(const matrix &m)
{
    ptr = new double *[m.row];
    for (int i = 0; i < m.row; i++)
        ptr[i] = new double[m.col];
    row = m.row;
    col = m.col;
    for (int i = 0; i < m.row; i++)
        for (int j = 0; j < m.col; j++)
            ptr[i][j] = m.ptr[i][j];
}
double matrix::operator[](int i)
{
    int j;
    cout << "Enter the column : ";
    cin >> j;
    if (i >= row || j >= col)
    {
        cout << "Subscrits are out of range. " << endl;
        exit(1);
    }
    cout << "The value at subscript (" << i << " , " << j << " ) is: ";
    return ptr[i][j];
}
bool matrix::operator==(const matrix &m)
{
    if (row != m.row || col != m.col)
        return false;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            if (ptr[i][j] != m.ptr[i][j])
                return false;
        }
    return true;
}
matrix matrix::operator+(const matrix &m)
{
    if (row != m.row || col != m.col)
    {
        cout << "Addition not possible ." << endl;
        exit(1);
    }
    matrix add;
    add.row = row;
    add.col = col;
    add.ptr = new double *[row];
    for (int i = 0; i < row; i++)
        add.ptr[i] = new double[col];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            add.ptr[i][j] = ptr[i][j] + m.ptr[i][j];

    return add;
}
matrix matrix::operator-(const matrix &m)
{
    if (row != m.row || col != m.col)
    {
        cout << "Substraction not possible ." << endl;
        exit(1);
    }
    matrix sub;
    sub.row = row;
    sub.col = col;
    sub.ptr = new double *[row];
    for (int i = 0; i < row; i++)
        sub.ptr[i] = new double[col];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            sub.ptr[i][j] = ptr[i][j] - m.ptr[i][j];

    return sub;
}
matrix matrix::operator*(const matrix &m)
{
    if (col != m.row)
    {
        cout << "multiplication can't be performed" << endl;
        exit(1);
    }
    matrix mult;
    mult.row = row;
    mult.col = m.col;
    mult.ptr = new double *[row];
    for (int i = 0; i < row; i++)
        mult.ptr[i] = new double[m.col];
    int s = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < m.col; j++)
        {
            for (int k = 0; k < col; k++)
            {
                s += ptr[i][k] * m.ptr[k][j];
            }
            mult.ptr[i][j] = s;
            s = 0;
        }
    }
    return mult;
}

double matrix::determinant()
{
    if (row != col)
    {
        cout << "Not a square matrix. " << endl;
        exit(1);
    }
    int D = 0;
    if (row == 1)
        return ptr[0][0];
    matrix temp;
    int sign = 1;
    for (int f = 0; f < row; f++)
    {
        temp = this->cofactor(0, f, row);
        D += sign * ptr[0][f] * temp.determinant();
        sign = -sign;
    }
    return D;
}
matrix matrix::adjoint()
{
    matrix adj, temp;
    adj.row = row;
    adj.col = col;
    adj.ptr = new double *[row];
    for (int i = 0; i < row; i++)
        adj.ptr[i] = new double[col];
    if (row == 1)
    {
        adj.ptr[0][0] = 1;
        return adj;
    }
    int sign = 1;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            temp = this->cofactor(i, j, row);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj.ptr[j][i] = (sign) * (temp.determinant());
        }
    }
    return adj;
}
matrix matrix::operator!()
{
    double det = this->determinant();
    if (det == 0)
    {
        cout << "Singular matrix, can't find its inverse";
        exit(1);
    }
    matrix inv;
    inv = this->adjoint();
    for (int i = 0; i < row; i++)
        for (int j = 0; j < row; j++)
            inv.ptr[i][j] = inv.ptr[i][j] / float(det);

    return inv;
}
matrix matrix::operator/(const matrix &m)
{
    if (m.row != m.col)
    {
        cout << "Division not possible its not square matrix";
        exit(1);
    }
    matrix div, inv, temp;
    temp = m;
    inv = !temp;
    div = (*this) * inv;
    return div;
}
int main()
{
    matrix m1, m2, m3, m4, m5, m6;
    cin >> m1 >> m2;
    cout << "Matrix 1(M1) : " << endl
         << m1 << "Matrix 2(M2) :" << endl
         << m2;
    int a;
    cout << "To find value at subscript in M1 " << endl
         << "Enter the row : ";
    cin >> a;
    cout << m1[a] << endl;
    m3 = m1 + m2;
    cout << "M1 + M2 :" << endl
         << m3 << endl;
    m4 = m1 - m2;
    cout << "M1 - M2 :" << endl
         << m4 << endl;
    m5 = m1 * m2;
    cout << "M1 X M2 :" << endl
         << m5 << endl;
    m6 = m1 / m2;
    cout << "M1 / M2 :" << endl
         << m6 << endl;
    m3 = !m1;
    cout << "Inverse of M1 :" << endl
         << m3 << endl;
    cout << "Comparing M1 == M2 : " << (m1 == m2);
    return 0;
}