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
  int star = 0;
  int end = n - 1;

  while (star <= end)
  {
    int mid = (star + end) / 2;
    if (arr[mid] == key)
    {
      cout << "Key found at index: " << mid << endl;
      return;
    }
    else if (arr[mid] > key)
    {
      end = mid - 1;
    }
    else
    {
      star = mid + 1;
    }
  }

  cout << "Key not found" << endl;
}

// fibonacci search

void fibonacci(int arr[], int n, int key)
{
  int fib1 = 0;
  int fib2 = 1;
  int fib = fib1 + fib2;

  while (fib < n)
  {
    fib1 = fib2;
    fib2 = fib;
    fib = fib1 + fib2;
  }

  int offset = -1;

  while (fib > 1)
  {
    int i = min(offset + fib1, n - 1);

    if (arr[i] < key)
    {
      fib = fib2;
      fib2 = fib1;
      fib1 = fib - fib2;
      offset = i;
    }
    else if (arr[i] > key)
    {
      fib = fib1;
      fib2 = fib2 - fib1;
      fib1 = fib - fib2;
    }
    else
    {
      cout << "Key found at index: " << i << endl;
      return;
    }
  }

  if (fib2 && arr[offset + 1] == key)
  {
    cout << "Key found at index: " << offset + 1 << endl;
    return;
  }

  cout << "Key not found" << endl;
}

int main()
{
  int n;

  cout << "Enter the size of the array: ";
  cin >> n;

  int arr[n];
  cout << "Enter the elements of the array: " << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  linearSearch(arr, n, 1);
  binarySearch(arr, n, 4);
  fibonacci(arr, n, 2);
}
