#include <iostream>

using namespace std;

struct BSTNode
{
    int data;
    BSTNode* left;
    BSTNode* right;
};


void deltree(BSTNode*& root)
{

    if(root==nullptr) return;
    deltree(root->left);
    deltree(root->right);
    delete root;
    root=nullptr;

}


void insertrec(BSTNode*& root, int data)
{

    if(root==nullptr)
    {
        BSTNode* newnode= new BSTNode;
        newnode->data=data;
        newnode->left=nullptr;
        newnode->right=nullptr;
        root=newnode;
        return;
    }
    if(data<=root->data)
    {
        insertrec(root->left,data);
    }
    else
    {
        insertrec(root->right,data);
    }

}

void inOrder(BSTNode* root)
{
  if (root==nullptr) return;
  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}


int main()
{
    BSTNode* root = nullptr;
    inOrder(root);
    while(true)
    {
        int i;
        cout << ":";
        cin >> i;
        if(i==0) break;
        insertrec(root,i);
        inOrder(root);
        cout << endl;

    }
    inOrder(root);
    cout << endl;
    deltree(root);
    cout << "The tree after deletion:";
    inOrder(root);


    return 0;
}
