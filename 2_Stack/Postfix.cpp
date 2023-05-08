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
        if (top == (size - 1)) {
            cout << "Stack full" << endl;
        }
        else {
            top++;
            arr[top] = x;
        }
    }

    int stacktop() {
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


    void postfixevaluation(string s) {
        
        string a = s;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] >= '0' && a[i] <= '9') {
                push(a[i] - '0');// IIMP STEP
            }
            else {
                
                switch (a[i]) {
                case '+': {
                    int opt2;
                int opt1;
                opt2 = stacktop();
                pop();
                opt1 = stacktop();
                pop();
                    push(opt2 + opt1);
                    break;
                }
                case '-': {
                    int opt2;
                int opt1;
                opt2 = stacktop();
                pop();
                opt1 = stacktop();
                pop();
                    push(opt1 - opt2);
                    break;
                }
                case '*': {
                    int opt2;
                int opt1;
                opt2 = stacktop();
                pop();
                opt1 = stacktop();
                pop();
                    push(opt1 * opt2);
                    break;
                }
                case '/': {
                    int opt2;
                int opt1;
                opt2 = stacktop();
                pop();
                opt1 = stacktop();
                pop();
                    push(opt1 / opt2);
                    break;
                }
                }
            }
        }
    }



};

int main() {
    stack st;
    st.postfixevaluation("231*+9-");
    int result = st.stacktop();
    cout << "Postfix Evaluation: " << result << endl;
    return 0;
}