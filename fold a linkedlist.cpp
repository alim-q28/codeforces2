#include <bits/stdc++.h>

using namespace std;

class node
{
    public :
    int data;
    node *next;
};

class linked_list
{
private:
    node *head, *tail;
    int size=0;
    
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }


  void addFirst(int val) {
      node* temp = new node();
      temp->data = val;
      temp->next = head;
      head = temp;

      if (size == 0) {
        tail = temp;
      }

      size++;
    }

    void add_node(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
        size++;
  
        
    }
     void display(){
      for(node* tmp = head; tmp != NULL; tmp = tmp->next){
        cout<<tmp->data<<" ";
      }
      cout<<endl;
     
    }
    
    node* pleft;
    int IsPalindromeHelper(node* right){
      if(right == NULL){
        return 1;
      }
      
      int rres = IsPalindromeHelper(right->next);
      if(rres == 0){
        return 0;
      } else if(pleft->data != right->data){
        return 0;
      } else {
        pleft = pleft->next;
        return 1;
      }
    }
    
    int isPalindrome(){
      pleft = head;
      return IsPalindromeHelper(head);
    }

      void foldhelper(node* right,int floor){
        if(right==NULL){
          return;
        }
        foldhelper(right->next,floor+1);
        if(floor>size/2){
         
          node* temp=left->next;
          left->next=right;
          right->next=temp;
          left=temp;

        }
        else if(floor==size/2){
          tail=right;
          tail->next=NULL;
        }

        
      }
    node* left;
     
     void  fold() {
       // write your code here
       left=head;
       foldhelper(head,0);
       

    }
}
  ;

int main()
{
    
    
    
     int b ;
    cin>>b;
        linked_list a;
        vector<int> arr(b,0);
        for(int i=0;i<b;i++)
        {
            
            cin>>arr[i];
            a.add_node(arr[i]);
        }
      int c;
      cin>>c;
      int d;
      cin>>d;
    a.display();
    a.fold();
    a.display();
    a.addFirst(c);
    a.add_node(d);
    a.display();

};
