#include <iostream>
using namespace std;

class stack {
public:
    char* arr;
    int top;
    int size;

    stack() {
        size = 50;
        arr = new char[size];
        top = -1;
    }

    void push(char x) {
        if (top == size - 1) {
            cout << "Stack full" << endl;
        }
        else {
            top++;
            arr[top] = x;
        }
    }

    char stacktop() {
        if (top == -1) {
            cout << "Stack Empty" << endl;
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

    void Disp() {
        if (top == -1) {
            cout << "Stack Empty" << endl;
        }
        else {
            cout << "Data " << endl;

            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " " << endl;
            }
        }
    }
    int pre(char c)
    {
        if (c =='^')
        {
            return 3;
        }
        else if (c =='*'|| c =='/')
        {
            return 2;
        }
        else if (c =='+'|| c =='-')
        {
            return 1;
        }
        else
        {
            return -1; //for paranthesis
        }
    }
    
    void infixtopostfix(string s) {
        string a = s;
        string res;
        for (int i = 0; i < a.length(); i++) {
            
            if (a[i] >= 'A' && a[i] <= 'Z'||a[i] >= 'a' && a[i] <= 'z') {
                res  = res + a[i];// IIMP STEP
            }
            else if(a[i]=='(')
            {
            push(a[i]);
            }
            else if(a[i]==')')
            {
                while(top!= -1 && stacktop() != '(') //&& imp he
                {
                    res  = res + stacktop();
                    pop();
                }
                if(top!=-1)
                {
                    pop();
                }
            }
            
            else {
                while(top!=-1 && pre(stacktop())>=pre(a[i]))
                {
                    res = res + stacktop();
                    pop();
                }
                push(a[i]);
                }
        }
            while(top!= -1)
            {
                res = res + stacktop();
                pop();
            }
        cout<<"INFIX TO POSTFIX = "<<endl;
        cout<<res<<endl;
        }
};

int main()
{
stack st;
st.infixtopostfix("(a-b/c)*(a/k-l)");
}