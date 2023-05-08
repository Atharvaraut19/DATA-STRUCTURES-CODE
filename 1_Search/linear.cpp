#include <iostream>
using namespace std;

void linearSearch(int arr[], int n, int key)

{
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == key)
    {
      cout << "Element found at index " << i << endl;
      return;
    }
  }
  cout << "Element not found" << endl;
}
void binarySearch(int arr[], int n, int key)
{
    int start = 0;
    int end = n-1;
    while(start<=end)
    {
        int mid = (start+end)/2;
        if(arr[mid]==key)
        {
            cout << "Element found" << endl;
            return;
        }
        else if(arr[mid>key])
        {
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
    }
    cout << "Element NOT found" << endl;
}

int main()
{
    
    int arr1 [7]= { 1, 2, 3, 4, 5, 6, 7};
    linearSearch(arr1,7,6);
}