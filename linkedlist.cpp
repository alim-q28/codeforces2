#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};

hgytdh.class sll
{
    Node *head;
    int size;

public:
    sll()
    { // constructor
        head = NULL;
    }
    sll(const sll &ll);
    ~sll(){}; // destructor
    friend istream &operator>>(istream &in, sll &ll);
    friend ostream &operator<<(ostream &out, sll &ll);
    sll operator!();
    
    
    void operator=(const sll &ll);
    sll operator+(const sll &ll);
    bool operator==(const sll &ll);
    int operator[](int i);
};
istream &operator>>(istream &in, sll &ll)
{
    cout << "Enter the size of list: ";
    in >> ll.size;
    Node *newnode = new Node();
    cout << "Enter the values: ";
    in >> newnode->data;
    newnode->next = NULL;
    ll.head = newnode;
    for (int i = 1; i < ll.size; i++)
    {
        Node *temp = new Node();
        in >> temp->data;
        temp->next = NULL;
        newnode->next = temp;
        newnode = temp;
    }
    return in;
}
ostream &operator<<(ostream &out, sll &ll)
{
    Node *temp = ll.head;
    out << "| " << temp->data << " |";
    for (int i = 1; i < ll.size; i++)
    {
        temp = temp->next;
        out << "-->| " << temp->data << " |";
    }
    out << endl;
    return out;
}
void sll ::operator=(const sll &ll)
{
    size = ll.size;
    Node *newnode = new Node();
    Node *traverse = new Node();
    traverse = ll.head;
    newnode->data = traverse->data;
    newnode->next = NULL;
    head = newnode;
   
}
sll ::sll(const sll &ll)

    {
        traverse = traverse->next;
        Node *temp = new Node();
        temp->data = traverse->data;
        temp->next = NULL;
        newnode->next = temp;
        newnode = temp;
    }
}
sll sll::operator+(const sll &ll)
{
    sll concat, templ;
    concat = *this;
    templ = ll;
    Node *temp = concat.head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = templ.head;
    concat.size = concat.size + ll.size;
    return concat;
}
bool sll ::operator==(const sll &ll)
{
    if (size != ll.size)
        return false;
    Node *temp1, *temp2;
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
int sll::operator[](int i)
{
    if (i >= size)
    {
        cout << endl
             << "Subscript is way to large." << endl;
        exit(1);
    }
    Node *temp = head;
    for (int j = 0; j < i; j++)
        temp = temp->next;

    return temp->data;
}
sll sll::operator!()
{
    sll rev;
    rev.size = size;
    sll temp = *this;
    Node *nextnode = NULL;
    Node *revnode = NULL;
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
    sll ll1, ll2, ll3, ll4;
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
