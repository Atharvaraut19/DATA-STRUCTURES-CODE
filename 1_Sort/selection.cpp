#include <iostream>
using namespace std;

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

  for (int i  = 0; i <n;i++)
  {
    for (int j = i;j<n;j++)
    {
        if(arr[j]<arr[i])
        {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        }
    }
  }
  cout<<"DISPLAY THE VALUES"<<endl;
    for(int i = 0; i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}