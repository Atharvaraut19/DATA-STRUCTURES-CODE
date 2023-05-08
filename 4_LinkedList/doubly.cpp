
#include <iostream>
using namespace std;
class node
{
    public:
    int data;
    node* prev;
    node* next;
    node(int data)
    {
        this -> data = data;
        this -> prev = NULL;
        this -> next = NULL;
    }
    
};
void displaynode(node* &head)
{
    node* temp  = head;
    cout<<"DATA"<<endl;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp= temp->next;
    }
}
void insertathead(int d,node* &head)
{
    node* temp = new node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}
void insertattail(int d,node* &tail)
{
    node* temp = new node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}
void insertatposition(int d,int p, node* &head,node* &tail)
{
    if(p==1)
    {
    insertathead(d,head);
    return;
    }
    node *temp = head;
    int cnt = 1;
    while(cnt<p-1)
    {
        temp = temp->next;
        cnt++;
    }
    if(temp->next==NULL)
    {
        insertattail(d,tail);
        return;

    }
    node* newnode = new node(d);
    newnode->next = temp->next;
    temp->next->prev =newnode; 
    temp->next = newnode;
    newnode->prev = temp;
}

void deletenode(int p,node* &head)
{
    if(p==1)
    {
        node* temp = head;

       temp->next->prev = NULL;
       head = temp->next;
       temp->next = NULL;
 
        delete temp;

    }
    else{
    int cnt=1;
    node* prev1 = NULL;
    node* curr = head;
    while(cnt<p)
    {
        prev1 =curr;
        curr = curr->next;
        cnt++;
    }
    curr->prev =NULL;
    prev1->next = curr->next;
    curr->next = NULL;
    delete(curr); 
}
}
int main()
{
    node* n  = new node(1);
    node* head = n;
    node* tail = n;
    displaynode(head);
    insertathead(69,head);
    displaynode(head);

    insertattail(6969,tail);
    displaynode(head);
    insertattail(696969,tail);
    displaynode(head);
    insertatposition(67,3,head,tail);
    displaynode(head);

   deletenode(1,head);
    displaynode(head);
    
    deletenode(4,head);
    displaynode(head);
}