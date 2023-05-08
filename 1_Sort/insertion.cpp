#include <iostream>
using namespace std;

void insertion(int arr[],int n)
{
    for(int i = 1;i<n;i++)
    {int curr=arr[i];
    int j =i-1;
    while(arr[j]>curr && j>=0)
    {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = curr;
    }

}
int main()
{
    int n;
  cout << "Enter the number of elements in the array: ";
  cin >> n;

  int arr[n];

  cout << "Enter the elements of the array: ";

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

insertion(arr,n);

cout<<"DISPLAY THE VALUES"<<endl;
    for(int i = 0; i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
