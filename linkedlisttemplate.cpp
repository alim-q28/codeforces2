#include <iostream>
using namespace std;
template <class t=int>
class Node
{
public:
    t data;
    Node *next;
};

template <class t=int>
class sll
{
    Node<t> *head;
    int size;

public:
    sll()
    { // constructor
        head = NULL;
    }
    sll(const sll<t> &ll);
    ~sll(){}; // destructor
    friend istream &operator>>(istream &in, sll<t> &ll)
    {
        cout << "Enter the size of list: ";
        in >> ll.size;
        Node<t> *newnode = new Node<t>();
        cout << "Enter the values: ";
        in >> newnode->data;
        newnode->next = NULL;
        ll.head = newnode;
        for (int i = 1; i < ll.size; i++)
        {
            Node<t> *temp = new Node<t>();
            in >> temp->data;
            temp->next = NULL;
            newnode->next = temp;
            newnode = temp;
        }
        return in;
    }
    friend ostream &operator<<(ostream &out, sll<t> &ll)
    {
        Node<t> *temp = ll.head;
        out << "| " << temp->data << " |";
        for (int i = 1; i < ll.size; i++)
        {
            temp = temp->next;
            out << "-->| " << temp->data << " |";
        }
        out << endl;
        return out;
    }
    void operator=(const sll<t> &ll);
    sll<t> operator+(const sll<t> &ll);
    bool operator==(const sll<t> &ll);
    sll<t> operator!();
    t operator[](int i);
};

template <class t>
void sll<t>::operator=(const sll<t> &ll)
{
    size = ll.size;
    Node<t> *newnode = new Node<t>();
    Node<t> *traverse = new Node<t>();
    traverse = ll.head;
    newnode->data = traverse->data;
    newnode->next = NULL;
    head = newnode;
    for (int i = 1; i < size; i++)
    {
        traverse = traverse->next;
        Node<t> *temp = new Node<t>();
        temp->data = traverse->data;
        temp->next = NULL;
        newnode->next = temp;
        newnode = temp;
    }
}

template <class t>
sll<t>::sll(const sll<t> &ll)
{
    size = ll.size;
    Node<t> *newnode = new Node<t>();
    Node<t> *traverse = new Node<t>();
    traverse = ll.head;
    newnode->data = traverse->data;
    newnode->next = NULL;
    head = newnode;
    for (int i = 1; i < size; i++)
    {
        traverse = traverse->next;
        Node<t> *temp = new Node<t>();
        temp->data = traverse->data;
        temp->next = NULL;
        newnode->next = temp;
        newnode = temp;
    }
}

template <class t>
sll<t> sll<t>::operator+(const sll<t> &ll)
{
    sll<t> concat = *this, templ = ll;
    Node<t> *temp = concat.head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = templ.head;
    concat.size = concat.size + ll.size;
    return concat;
}

template <class t>
bool sll<t>::operator==(const sll<t> &ll)
{
    if (size != ll.size)
        return false;
    Node<t> *temp1, *temp2;
    temp1 = head;
    temp2 = ll.head;
    for (int i = 0; i < size; i++)
    {
        if (temp1->data != temp2->data)
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

template <class t>
t sll<t>::operator[](int i)
{
    if (i >= size)
    {
        cout << endl
             << "Subscript is way to large." << endl;
        exit(1);
    }
    Node<t> *temp = head;
    for (int j = 0; j < i; j++)
        temp = temp->next;

    return temp->data;
}

template <class t>
sll<t> sll<t>::operator!()
{
    sll<t> rev;
    rev.size = size;
    sll<t> temp = *this;
    Node<t> *nextnode = NULL;
    Node<t> *revnode = NULL;
    while (temp.head != NULL)
    {
        rev.head = temp.head;
        nextnode = temp.head->next;
        temp.head->next = revnode;
        revnode = temp.head;
        temp.head = nextnode;
    }
    return rev;
}

int main()
{
    sll<> ll1, ll2, ll3, ll4;
    int i;
    cin >> ll1 >> ll2;
    cout << "List 1 is: " << endl
         << ll1 << "List 2 is: " << endl
         << ll2;
    ll3 = !ll1;
    cout << "Reverse of List 1 is: " << endl
         << ll3;
    ll4 = ll1 + ll2;
    cout << "Concatenating two lists we get : " << endl
         << ll4;
    cout << "Comparing List 1 equal to List 2: " << (ll1 == ll2) << endl;
    cout << "Enter the subscript for finding a value in List 1: ";
    cin >> i;
    cout << "The value at subscript " << i << " is : " << ll1[i] << endl;
    return 0;
}