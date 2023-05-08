#include <iostream>
using namespace std;

class stack {
public:
    int* arr;
    int top;
    int size;

    stack() {
        size = 50;
        arr = new int[size];
        top = -1;
    }

    void push(int x) {
        if (top == size - 1) {
            cout << "Stack full" << endl;
        }
        else {
            top++;
            arr[top] = x;
        }
    }

    int stacktop() {
        if (top == -1) {
            return -1;
        }
        else {
            return arr[top];
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Empty" << endl;
        }
        else {
            top--;
        }
    }


    void balance(string s) {
    string a = s;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == '(' ||  a[i] == '{'||  a[i] == '[') {
            push(a[i]);
        }
        else if (a[i] == ')' ||  a[i] == '}'||  a[i] == ']') //STACK EMPTY BUT STRING NOT
        {
            if (top == -1) {
                cout << "NOT BALANCED" << endl;
                return;
            }
            else if (a[i] == ')' && stacktop() == '(' ||
                     a[i] == '}' && stacktop() == '{' ||
                     a[i] == ']' && stacktop() == '[') {// IMP STEP
                pop();
            }
        }
    }
    if (top == -1) {
        cout << "BALANCED" << endl;
    }
    else {
        cout << "NOT BALANCED" << endl;
    }
}

};

int main() {
    stack st;
    st.balance("{2+3{2+3}}");
    return 0;
}
