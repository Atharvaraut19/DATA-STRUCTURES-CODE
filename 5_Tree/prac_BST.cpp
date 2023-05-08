#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* left;
    node* right;

    node (int d)
    {
        this->data=d;
        this->left = NULL;
        this->right = NULL;
    }

};
node* buildtree(node *root,int data)
{
if(root == NULL)
{
    return new node(data);
}
if(data>root->data)
{
    root->right = buildtree(root->right,data);
}
else if (data < root->data){
    root->left = buildtree(root->left,data);
}
return root;
}

void preorder(node* root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int heightofnode(node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    cout<<root->data<<" ";
    int h1 = heightofnode(root->left);
    int r1 = heightofnode(root->right);

    return max(h1, r1) + 1;
}

int count(node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    cout<<root->data<<" ";
    int h1 = heightofnode(root->left);
    int r1 = heightofnode(root->right);

    return (h1 + r1+1);
}

int main()
{
    node* root = NULL;
    root = buildtree(root, 4);
    root =buildtree(root,10);
    root =buildtree(root,1);
    root =buildtree(root,8);
    root =buildtree(root,15);
    
    preorder(root);
    int d = heightofnode(root);
    cout<<"HEIFH"<<d<<endl;
    int c = count(root);
    cout<<"count"<<c<<endl;

}