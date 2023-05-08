#include <iostream>
using namespace std;
void ternary(int arr[],int l,int r, int x)
{
    while(l<=r)
    {
        int mid1 = l + (r-l)/3;
        int mid2 = r - (r-l)/3;
        if(arr[mid1]==x)
        {
            cout<<"FOUND";
            return; 
        }
        else if(arr[mid2]==x)
        {
            cout<<"FOUND";
            return; 
        }
        else if(arr[mid1]>x)
        {
            r= mid1-1;
        }
        else if(arr[mid2]<x)
        {
            l= mid2+1;
        }
        else
        {
            l = mid1+1;
            r = mid2-1;
        }     
}
 cout<<"NOT FOUND";
}
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = 9;
    int x = 11;
    ternary(arr, 0, n-1, x);
    return 0;
}