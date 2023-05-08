#include<iostream>
using namespace std;
class Hash{
  public:
  int row ;
  int col;
  int** arr;
  Hash()
  {
    this->row = 10;
    this->col = 4;
    this->arr = new int*[row];

    for(int i = 0;i<row;i++)
    {
      arr[i] = new int[col];
      for(int j = 0;j<col;j++)
      {
        arr[i][j]=-1;
      }
    }
  }
void print()
{
  for(int i = 0;i<row;i++)
    {
      cout<<i<< " | ";
      for(int j = 0;j<col;j++)
      {
        cout<<arr[i][j]<< " ";
      }
      cout<<endl;
    }
  }
  void del(int n)
{
  for(int i = 0;i<row;i++)
  {
    for(int j = 0;j<col;j++)
    {
      if(arr[i][j]==n)
      {
        arr[i][j]=-1;
        return;
      }
    }
  }
}

void search(int n)
{
  int f =0;
  for(int i = 0;i<col;i++)
  {
    for(int j = 0;j<row;j++)
    {
      if(arr[i][j]==n)
      {
        f=1;
        break;
      }
      }
      break;
    }
    if(f==1)
    {
      cout<<"FOUND"<<endl;
    }
    else{
      cout<<"NOT FOUND"<<endl;
    }
  }


void inputValue(int n)
{
  int key = n%8;
  for(int i = 0;i<row;i++)
  {
    int index = (key+i)%row;
    for(int j = 0;j<col;j++)
    {
      if(arr[index][j]==-1)
      {
        arr[index][j]=n;
        return;
      }
    }
  }
  cout<<"TABLE FULL"<<endl;
}

};
int main()
{
  Hash h;
  // h.print();
  h.inputValue(8);
  h.inputValue(16);
  h.inputValue(32);
  h.inputValue(320);
  h.del(32);
  h.inputValue(3233);
  h.inputValue(321);
  h.inputValue(322);
  h.print();
  h.search(322);
  //   h.inputValue(5);
  //   h.inputValue(24);
  //   h.inputValue(32);
  //   h.inputValue(40);
  //   h.print();
  //   h.del(8);
  //   h.del(40);
  //   cout<<endl;
  //   h.print();
  //   cout<<endl;
  //   h.search(16);
    
}