#include <iostream>

using namespace std;

struct Node
{
    int data;
    char color;
    Node *left;
    Node *right;
    Node(int a) : data(a), color('r'), left(new Node()), right(new Node()) {}
    Node() : data(0), color('b'), left(NULL), right(NULL) {}
};

bool cc(Node *root, int data)
{
    if (root->left == NULL)
        return true;
    if (root->left->color == 'r' && root->right->color == 'r')
    {
        root->color = 'r';
        root->left->color = 'b';
        root->right->color = 'b';
        return false;
    }
    if (root->data >= data)
        return cc(root->left, data);
    else if (root->data < data)
        return cc(root->right, data);
    return true;
}
Node *ll(Node *root)
{
    Node *a = root, *b = root->left, *c = root->left->right;
    root = b;
    b->right = a;
    a->left = c;
    root->color = 'b';
    root->right->color = 'r';
    return root;
}
Node *lr(Node *root)
{
    Node *a = root, *b = root->left, *c = root->left->right, *d = root->left->right->left, *e = root->left->right->right;
    root = c;
    c->left = b;
    c->right = a;
    b->right = d;
    a->left = e;
    root->color = 'b';
    root->right->color = 'r';
    return root;
}
Node *rl(Node *root)
{
    Node *a = root, *b = root->right, *c = root->right->left, *d = root->right->left->left, *e = root->right->left->right;
    root = c;
    c->left = a;
    c->right = b;
    a->right = d;
    b->left = e;
    root->color = 'b';
    root->left->color = 'r';
    return root;
}
Node *rr(Node *root)
{
    Node *a = root, *b = root->right, *c = root->right->left;
    root = b;
    b->left = a;
    a->right = c;
    root->color = 'b';
    root->left->color = 'r';
    return root;
}

Node *r(Node *root)
{
    //1
    if (root->left->left == NULL && root->right->left == NULL)
    {
        return root;
    }
    if (root->left->left != NULL)
    {
        root->left = r(root->left);
    }
    if (root->right->left != NULL)
    {
        root->right = r(root->right);
    }
    //2
    // if (root->left->left->left == NULL && root->left->right->left == NULL && root->right->left->left == NULL && root->right->right->left == NULL)
    //     return root;
    //3
    // root->left = r(root->left);
    // root->right = r(root->right);
    if (root->left->color == 'r' && root->left->left->color == 'r')
    {
        return ll(root);
    }
    if (root->left->color == 'r' && root->left->right->color == 'r')
    {
        return lr(root);
    }
    if (root->right->color == 'r' && root->right->left->color == 'r')
    {
        return rl(root);
    }
    if (root->right->color == 'r' && root->right->right->color == 'r')
    {
        return rr(root);
    }
    return root;
}

void ins(Node *root, int data)
{
    if (root->left == NULL)
    {
        root->data = data;
        root->color = 'r';
        root->left = new Node();
        root->right = new Node();
    }
    else if (root->data >= data)
        ins(root->left, data);
    else if (root->data < data)
        ins(root->right, data);
}

void print(Node *root)
{
    if (root->left != NULL)
    {
        cout << root->data << "_" << root->color << "(";
        print(root->left);
        cout << ")(";
        print(root->right);
        cout << ")";
    }
}

int main()
{
    string cmd;
    int data;
    Node *root = NULL;
    while (cin >> cmd)
    {
        if (cmd == "I")
        {
            cin >> data;
            if (root == NULL)
                root = new Node(data);
            else
            {
                // cc(root, data);
                while(!cc(root, data));
                root=r(root);
                ins(root, data);
                root = r(root);
            }
            root->color = 'b';
        }
        else
        {
            print(root);
            cout << endl;
        }
    }
}