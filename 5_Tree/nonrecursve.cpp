#include<iostream>
#include <stack>
using namespace std;

// Define the structure of the BST node
class node
{
    public:
    int data;
    node* left;
    node* right;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }

};
node* buildtree(int d,node* root)
{
    if(root == NULL)
    {
        return new node(d);
    }
    else if(d>root->data)
    {
        root->right = buildtree(d,root->right);
    }
    else{
     root->left = buildtree(d,root->left);
}
return root;
}
void inorderTraversal(node* root) {
    stack<node*> st;
    node* curr = root;
    while (curr != NULL || !st.empty()) 
    {

        while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}
void preorderTraversal(node* root) {
    if (root == NULL) return;
    stack<node*> st;
    st.push(root);
    while (!st.empty()) {
        node* curr = st.top();
        st.pop();
        cout << curr->data << " ";
        if (curr->right != NULL) st.push(curr->right);
        if (curr->left != NULL) st.push(curr->left);
    }
}


void postorderTraversal(node* root) {
    stack<node*> st1, st2;
    st1.push(root);
    while (!st1.empty()) {
        node* curr = st1.top();
        st1.pop();
        st2.push(curr);
        if (curr->left != NULL) 
        st1.push(curr->left);
        if (curr->right != NULL) 
        st1.push(curr->right);
    }
    while (!st2.empty()) {
        node* curr = st2.top();
        st2.pop();
        cout << curr->data << " ";
    }
}

int main()
{

    node* root  = new node(10);
    buildtree(20,root);
    buildtree(30,root);
    buildtree(8,root);
    buildtree(5,root);
    buildtree(11,root);
    buildtree(9,root);
    preorderTraversal(root);
    cout<<endl;
    inorderTraversal(root);
    cout<<endl;
    postorderTraversal(root);
}


