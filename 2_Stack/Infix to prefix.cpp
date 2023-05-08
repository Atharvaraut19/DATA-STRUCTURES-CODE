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
string reverse(string s)
{
    string a = s;
    string r;
     for (int i = a.length() ;i>=0;i--)
    {
        if(a[i]=='(')
        {
        r = r + ")";
        }
        else if(a[i]==')')
        {
        r = r + "(";
        }
        else{
            r = r + a[i];
        }
    }
    return r; 

}
int pre(char a)
{
    if(a == '^')
    {
        return 4;
    }
    else if(a == '*' || a == '/')
    {
        return 3;
    }
    else if(a == '+' || a == '-')
    {
        return 2;
    }
    else{
        return -1;
    }
}

void infixtoprefix(string s)
{
    string r  = reverse(s);
    string res;

    for (int i = 0; i<r.length();i++)
    {
        if (r[i] >= 'A' && r[i] <= 'Z'||r[i] >= 'a' && r[i] <= 'z') 
        { 
                res  = res + r[i];// IIMP STEP
            }
            else if(r[i]=='(')
            {
            push(r[i]);
            }
            else if(r[i]==')')
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
            else{
            while(top!=-1 && pre(stacktop())>=pre(r[i]))
            {
                res = res+ stacktop();
                pop();
            }
            push(r[i]);
            }
    }
             while(top!= -1)
            {
                res = res + stacktop();
                pop();
            }
        string res1 = reverse(res);
    cout<<"INFIX TO POSTFIX = "<<endl;
cout<<res1<<endl;
}

};
int main()
{
    stack st;
    st.infixtoprefix("A*B+C/D"); // (a-b/c)*(a/k-l)
}