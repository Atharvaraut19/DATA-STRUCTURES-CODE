#include <iostream>
using namespace std;

void swap(int &a , int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void bubblesort(int arr[],int n)
{
    // cout<<"ENTER THE VALUES"<<endl;
    // for(int i = 0; i<n;i++)
    // {
    //     cin>>arr[i];
    // }
    for(int i = 0; i<n;i++)
    {
    for(int j = 0; j<n -i-1;j++)
    {
        if(arr[j+1]<arr[j])
        {
            swap(arr[j+1],arr[j]);
        }
    }
    }

}
int main()
{
    int ar[] = {41, 25, 96, 0, 12, 21, 3, 1};
    int n = 8;
    bubblesort(ar,n);
    cout<<"DISPLAY THE VALUES"<<endl;
    for(int i = 0; i<n;i++)
    {
        cout<<ar[i]<<" ";
    }
 }