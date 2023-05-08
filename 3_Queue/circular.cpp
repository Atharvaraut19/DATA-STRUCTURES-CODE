#include <iostream>
using namespace std;

class queue{

    public:
    int front;
    int rear;
    int size;
    int* arr;
    queue(int n)
    {
        this->size = n;
        this->front = -1;
        this->rear = -1;
        this->arr = new int[n];
    }
void enqueue(int n)
{
    if(front== 0 && rear == size-1 || (front-1) ==rear)
    {
        cout<<"QUEUE FULL"<<endl;
        return;
    }
    if(front== -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        arr[rear] = n;
    }
    else if(front!=0 && rear==size-1)
    {
        rear = 0;
        arr[rear] = n;
    }
    else
    {
        rear++;
        arr[rear]=n;
    }
    
}
void dequeue()
{
    if(rear == -1 && front == -1 )
    {
        cout<<"QUEUE empty"<<endl;
        return;
    }
    else if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if(front== size-1 && rear<size-1)
    {
        front  = 0;
    }
    else{
    front++;
    }
}
void disp()
{
    if (front == -1 && rear ==-1)
        {
            cout << "QUEUE is EMPTY" << endl;
            return;
        }
    
   else if(front>rear)
   {
    for (int i = front; i < size; i++)
            {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
    }
   
    else{
    for(int i = front ; i<=rear;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    }
}
};
int main()

{
    queue q = queue(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.disp();
    
    q.dequeue();// 1
    q.disp();
    q.dequeue();// 2
    q.disp();
    q.dequeue();// 3
    q.disp();
    q.enqueue(69);
    q.disp();

}