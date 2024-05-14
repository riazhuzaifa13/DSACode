#include <iostream>
#include <stdlib.h>
using namespace std;

struct BST
{
  int data;
  BST *left;
  BST *right;
};

BST *insert(BST *root, int data)
{
  if (root == NULL)
  {
    BST *node = (BST *)malloc(sizeof(BST));
    node->data = data;
    node->left = node->right = NULL;
    return node;
  }
  if (data < root->data)
  {
    root->left = insert(root->left, data);
  }
  else if (data > root->data)
  {
    root->right = insert(root->right, data);
  }
}


bool search(BST *root, int toSearch)
{
  if (root == NULL)
  {
    return false;
  }
  if (toSearch == root->data)
  {
    return true;
  }
  if (toSearch < root->data)
  {
    search(root->left, toSearch);
  }
  else if (toSearch > root->data)
  {
    search(root->right, toSearch);
  }
}


void inOrderTraversial(BST *root)
{
  if (root == NULL)
  {
    return;
  }
  inOrderTraversial(root->left);
  cout << root->data << " ";
  inOrderTraversial(root->right);
}

void preOrderTraversial(BST *root)
{
  if (root == NULL)
  {
    return;
  }
  cout << root->data << " ";
  preOrderTraversial(root->left);
  preOrderTraversial(root->right);
}

void postOrderTraversial(BST *root)
{
  if (root == NULL)
  {
    return;
  }
  postOrderTraversial(root->left);
  postOrderTraversial(root->right);
  cout << root->data << " ";
}

BST *min(BST *root)
{
  if (root == NULL)
  {
    return NULL;
  }
  if (root->left == NULL)
  {
    return root;
  }
  min(root->left);
}

BST *max(BST *root)
{
  if (root == NULL)
  {
    return NULL;
  }
  if (root->right == NULL)
  {
    return root;
  }
  max(root->right);
}

BST *deleteNode(BST *root, int toDelete)
{
  if (root == NULL)
  {
    cout << " not Found !" << endl;
    return root;
  }
  if (toDelete < root->data)
  {
    root->left = deleteNode(root->left, toDelete);
  }
  else if (toDelete > root->data)
  {
    root->right = deleteNode(root->right, toDelete);
  }
  else
  {
    if (root->left == NULL)
    {
      BST *tmp = root->right;
      free(root);
      cout << "Deleted " << endl;
      return tmp;
    }
    if (root->right == NULL)
    {
      BST *tmp = root->left;
      free(root);
      cout << "Deleted " << endl;
      return tmp;
    }
    BST *minNode = min(root->right);
    root->data = minNode->data;
    root->right = deleteNode(root->right, minNode->data);
  }
}

int main()
{
  BST *root = NULL;

  int a;
  do
  {
    cout << "Enter 1 to Insert" << endl
         << "Enter 2 to Search" << endl
         << "enter 3 to print in In Order Traversial" << endl
         << "Enter 4 to print in PreOrder Traversial" << endl
         << "Enter 5 to Print in Post Order Traversial " << endl
         << "Enter 6 to find Min Node " << endl
         << "Enter 7 to Find Max Node" << endl
         << "Enter 8 to Delete a Node " << endl
         << "Enter 9 to Quit " << endl;
    cin >> a;
    if (a == 1)
    {
      int data;
      cout << "Enter value to Insert : ";
      cin >> data;
      root = insert(root, data);
    }
    else if (a == 2)
    {
      int toSearch;
      cout << "Enter value to Search : ";
      cin >> toSearch;
      bool isAvailable = search(root, toSearch);
      isAvailable ? cout << "Value found" << endl : cout << " not Found " << endl;
    }
    else if (a == 3)
    {
      inOrderTraversial(root);
      cout << endl;
    }
    else if (a == 4)
    {
      preOrderTraversial(root);
      cout << endl;
    }
    else if (a == 5)
    {
      postOrderTraversial(root);
      cout << endl;
    }
    else if (a == 6)
    {
      BST *minNode = min(root);
      if (minNode == NULL)
      {
        cout << "Empty" << endl;
      }
      else
      {
        cout << minNode->data << endl;
      }
    }
    else if (a == 7)
    {
      BST *maxNode = max(root);
      if (maxNode == NULL)
      {
        cout << "Empty" << endl;
      }
      else
      {
        cout << maxNode->data << endl;
      }
    }
    else if (a == 8)
    {
      int toDelete;
      cout << "Enter value you want to Delete : ";
      cin >> toDelete;
      root = deleteNode(root, toDelete);
    }
    else if (a == 9)
    {
      cout << "Quit" << endl;
    }
    else
    {
      cout << "Invalid Number " << endl;
    }
  } while (a != 9);
}
