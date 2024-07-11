#include <iostream>
using namespace std;
struct Node
{
    int key;
    Node *left, *right;
};
Node *newNode(int item)
{
    Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
void kthLargest(Node *root, int k);
Node *insert(Node *node, int key)
{
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *root = NULL;
        int n;
        cin >> n;
        int a;
        cin >> a;
        root = insert(root, a);
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a;
            insert(root, a);
        }
        int k;
        cin >> k;
        kthLargest(root, k);
    }
    return 0;
}

void actualKthLargest(Node *root, int *k)
{
    if (*k < 0)
    {
        return;
    }
    if (root == NULL)
    {
        return;
    }
    actualKthLargest(root->right, k);
    *k -= 1;
    if (*k == 0)
    {
        cout << root->key << endl;
        *k -= 1;
        return;
    }
    actualKthLargest(root->left, k);
}

void kthLargest(Node *root, int k)
{
    actualKthLargest(root, &k);
}