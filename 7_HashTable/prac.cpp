#include <iostream>
using namespace std;
class Hash{
    public:
    int row;
    int col;
    int** arr;
    Hash()
    {
        this->row = 10;
        this->col = 4;
        this->arr = new int*[row]; // imp
    }
    void table(){
        for(int i = 0 ;i<row;i++)
        {
            arr[i] = new int[col];// imp
            for(int j = 0; j<col;j++)
            {
                arr[i][j] = -1;
            }
        }
    }
void print(){
    for(int i = 0 ;i<row;i++)
        {
            cout<<i<<"|"<<" ";
            for(int j = 0; j<col;j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
void inputValue(int value)
{
    int key = value % 8;
    for (int i = 0; i < row; i++)
    {
        int index = (key + i) % row;
        for (int j = 0; j < col; j++)
        {
            if (arr[index][j] == -1)
            {
                arr[index][j] = value;
                return;
            }
        }
    }
    cout << "Table is full!" << endl;
}

};
int main()
{
    Hash h;
    h.table();
    //h.print();
    h.inputValue(11);
     h.inputValue(19);
    h.inputValue(27);
    h.inputValue(35);
    h.inputValue(8);
    h.inputValue(16);
    h.inputValue(24);
    h.inputValue(32);
    h.inputValue(40);
    h.inputValue(5);
    h.inputValue(43);
    h.print();

}