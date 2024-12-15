#include <iostream>
#include <climits>
using namespace std;
class Node
{
public:
    int val;
    Node* right;
    Node* left;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
int MinVal(Node* root){
    if(root==NULL) return INT_MAX;
    int lmn=MinVal(root->left);
    int rmn=MinVal(root->right);
    return min(root->val,min(lmn,rmn));
}
void display(Node* root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    display(root->left);
    display(root->right);
}
int main()
{
    Node* a = new Node(12);
    Node* b = new Node(21);
    Node* c = new Node(13);
    Node* d = new Node(45);
    Node* e = new Node(15);
    Node* f = new Node(26);
    Node* g = new Node(17);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    display(a);
    cout<<endl;
    cout<<"Minimun valued node  is "<<MinVal(a);
    return 0;
}