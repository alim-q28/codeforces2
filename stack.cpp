#include <iostream>
using namespace std;
template <class t>
class stack
{
private:
    int top, size;
    t *a;

private:
    int isempty(void)
    {
        return (top == -1);
    }
    int isfull(void)
    {
        return (top == (size - 1));
    }

public:
    stack(int x)
    {
        cout << "Creating the stack size=" << x << endl;
        size = x;
        a = new t[size];
        top = -1;
    }
    ~stack(void)
    {
        cout << "The stack is no more:" << endl;
        delete[] a;
    }
    void create(int s)
    {
        if (s > size)
        {
            printf("\nError number of elements greater than stack size\n");
            return;
        }
        cout << "Enter the elements:" << endl;
        t ele;
        for (int i = 0; i < s; i++)
        {
            cin >> ele;
            a[++top] = ele;
        }
    }
    void push()
    {
        if (!isfull())
        {
            t ele;
            cin >> ele;
            a[++top] = ele;
        }
        else
        {
            cout << "\nStack Overflow\n";
        }
    }
    t pop(void)
    {
        if (!isempty())
        {
            t x = a[top--];
            return x;
        }
        else
        {
            cout << "\nStack Underflow\n";
            return -1;
        }
    }
    void display(void)
    {
        cout << "Displaying Stack: \n";
        for (int i = top; i > -1; i--)
        {
            cout << "		 " << a[i] << " " << endl;
            cout << "		__"
                 << "__" << endl;
        }
    }
};

int main(void)
{
    int x = 1, s, c, ele;
    cout << "Enter the size of the Stack: ";
    cin >> s;
    stack<float> s1(s);
    cout << "Choices are:\n"
         << "1. To enter elements\n"
         << "2. To push\n"
         << "3. To pop\n"
         << "4. To display\n"
         << "5. To terminate\n";
    do
    {
        cout << "Enter your choice: ";
        cin >> c;
        switch (c)
        {
        case 1:
            cout << "Enter no. of element: ";
            cin >> s;
            s1.create(s);
            break;
        case 2:
            cout << "Enter the element: ";
            s1.push();
            break;
        case 3:
            cout << "Pop out element: " << s1.pop() << endl;
            break;
        case 4:
            s1.display();
            break;
        case 5:
            x = 0;
            break;
        default:
            cout << "Invalid choice try again\n";
        }
    } while (x);
    return 0;
}
