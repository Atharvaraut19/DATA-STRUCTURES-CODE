//Implementation of Singly Linked List
/*
1. Display list
2. Insert at end
3. Insert at start  
4. Insert after node

5. Delete first node
6. Delete last node
7. Delete node with key

8. Exit*/
#include <iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }
};
//DISPLAY
void print(node* &head)
{
    node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;

    }
}

//At the HEAD

void insertAtHead(node* &head, int data)
{
    //new node
    node* temp = new node(data);
    
    temp->next = head;
    head = temp;
}
// At the TAIL
void insertAtEND(node* &tail, int data)
{
    //new node
    node* temp = new node(data);

    tail->next = temp;
    tail = temp;
 }


// At the position
void insertAtposition(node* &head,node* &tail,int p, int data)
{
    if(p == 1)
    {
        insertAtHead(head,data);
        return ;
    }
    
    //new node
    node* temp = head;
    int cnt = 1;
    while(cnt <p-1)
    {
temp=temp->next;
cnt++;
    }

    if(temp->next == NULL)
    {
        insertAtEND(tail,data);
        return;
    }

    node* nodetoinsert = new node(data);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;

}

void deleteNode(int position,node* &head)
{
if(position==1)// At start
{
node* temp = head;
head = head->next;

temp->next = NULL;
delete temp;
}
else{// any middle or last node

node* curr = head;
node* prev = NULL;
int cnt =1;
while(cnt<position)
{
    prev = curr;
    curr = curr->next;
    cnt++;
}
prev->next = curr->next;

curr->next = NULL;
delete curr;
}

}

int main()
{
    cout<<"enter the first element in the linked list"<<endl;
    int f;
    cin>>f;
    node* node1 = new node(f);
    int n = 1;
    node* head = node1;
    node* tail = node1;
    
    while(n!=0)
    {   cout<<"1  Display"<<endl;
        cout<<"2.Insert at top"<<endl;
        cout<<"3 Insert at bottom"<<endl;
        cout<<"4 Insert in middle"<<endl;
        cout<<"5 Delete a node"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Enter the options"<<endl;
        cin>>n;
        switch(n)
        {
        case 1:
            {
            print(head);
            break;
            }

        case 2:
            {
            int data;
            cout<<"Enter the data"<<endl;
            cin>>data;
            insertAtHead(head,data);
            break;
            
            }
            case 3:
            {
            int data;
            cout<<"Enter the data"<<endl;
            cin>>data;
            insertAtEND(tail,data);
            break;
            }

            case 4:
            {
            int data,p;
            cout<<"Enter the data"<<endl;
            cin>>data;
            cout<<"Enter the position of data"<<endl;
            cin>>p;
            insertAtposition(head,tail,p,data);
            break;
            }
            case 5:
            {
            int data,p;
            // cout<<"Enter the data"<<endl;
            // cin>>data;
            cout<<"Enter the position of data"<<endl;
            cin>>p;
            deleteNode(p,head);
            break;
            }
            
            case 0:
            {
            break;}

        }
    }

//node* head = node1;
//node* tail = node1;
// cout<<endl;
// print(head);
// cout<<endl;
// insertAtHead(head, 12);
// insertAtHead(head, 5);
// print(head);
// cout<<endl;
// cout<<"display"<<endl;
// insertAtEND(tail, 12);
// print(head);
}