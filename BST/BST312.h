

#ifndef BST_312_H
#define BST_312_H

#include <cstdlib>  // Provides size_t
#include <iostream>
#include <vector>

using namespace std;

template<class T>
class BST_312 {
public:

    BST_312();

    //Copy constructor
    BST_312(const BST_312 & src);

    ~BST_312();

/****************************
makeEmpty

Function: Removes all the items from the BST.
Preconditions: BST has been initialized
Postconditions: All the items have been removed
*****************************/
    void makeEmpty();

/****************************
isEmpty

Function: Checks to see if there are any items in the BST.
Preconditions: BST has been initialized
Postconditions: Returns true if there are no items in the BST, else false.
*****************************/
    bool isEmpty() const;

/****************************
isFull

Function: Determines if you have any more room to add items to the BST
Preconditions: BST has been initialized
Postconditions: Returns true if there is no more room to add items, else false
*****************************/
    bool isFull() const;

/****************************
insertItem

Function: Adds newItem to the BST.
Preconditions: BST has been initialized and is not full.
Postconditions: newItem is in the proper position for a BST.
*****************************/
    void insertItem(const T &);

/****************************
deleteItem

Function: Removes target from BST.
Preconditions: BST has been initialized.
Postconditions: If found, element has been removed from BST.
*****************************/
    void deleteItem(const T& newItem);

/****************************
countNodes
Function: Counts the number of nodes in the BST
Preconditions: BST has been initialized.
Postconditions: returns the number of nodes in the BST
*****************************/
    int countNodes();

/****************************
preOrderTraversal

Function: Returns the preOder (Node, Left, Right) as a vector of Ts
Preconditions: BST has been initialized.
Postconditions: none
*****************************/
    vector<T> preOrderTraversal();

/****************************
inOrderTraversal

Function: Returns the inOder (Left, Node, Right) as a vector of Ts
Preconditions: BST has been initialized.
Postconditions: none
*****************************/
    vector<T> inOrderTraversal();

/****************************
postOrderTraversal

Function: returns the postOder (Left, Right, Node) as a vector of Ts
Preconditions: BST has been initialized.
Postconditions: none
*****************************/
    vector<T> postOrderTraversal();

/********************
 isItemInTree

Function: Determines if a given Item is in tree.
Preconditions: BST has been initialized.
Postconditions: none
*****************************/

    bool isItemInTree(const T& item);


private:
    struct TreeNode {
        T data;
        TreeNode *left;
        TreeNode *right;
    };

    TreeNode * root;


    void insertItem(TreeNode*& t, const T& newItem);
    void inOrderTraversal(TreeNode* t,vector<T>& result) const;
    int countNodes(TreeNode* t) const;
    void deleteNode(TreeNode*& t);
    void makeEmpty(TreeNode*& t);
    void deleteItem(TreeNode*& t, const T& newItem);
    void getPredecessor(TreeNode* t, T& data);
    void preOrderTraversal(TreeNode* t,vector<T>& result) const;
    void postOrderTraversal(TreeNode* t,vector<T>& result) const;
    void copyTree(TreeNode*& copy, const TreeNode *originalTree);
    bool isItemInTreeHelper(const T& item,TreeNode* t);

};

/*******************************
//Function implementations
********************************/

template<class T>
BST_312<T>::BST_312 ()
{
    root = NULL;
}

template<class T>
BST_312<T>::BST_312(const BST_312 & src)
{
    copyTree(root, src.root);
}

template<class T>
BST_312<T>::~BST_312()
{
    makeEmpty();

}


template<class T>
void BST_312<T>::copyTree(TreeNode*& copy, const TreeNode* originalTree)
{
    if (originalTree == NULL)
        copy = NULL;
    else
    {
        copy = new TreeNode;
        copy->data = originalTree->data;

        copyTree(copy->left, originalTree->left);
        copyTree(copy->right, originalTree->right);
    }
}


template<class T>
void BST_312 <T>::deleteNode(TreeNode*& t)
{
    T info;
    TreeNode *tempPtr;

    tempPtr = t;

    if (t->left == NULL)
    {
        t = t->right;
        delete tempPtr;
    }
    else if (t->right == NULL)
    {
        t = t->left;
        delete tempPtr;
    }
    else
    {
        getPredecessor(t->left, info);
        t->data = info;
        deleteItem(t->left, info);
    }
}



//find largest in left subtree
template<class T>
void BST_312 <T>::getPredecessor(TreeNode* t, T& data)
{

    while (t->right != NULL)
        t = t->right;

    data = t->data;

}


template<class T>
void BST_312 <T>::deleteItem(TreeNode*& t, const T& newItem)
{
    if (t == NULL)
        return;
    else if (newItem < t->data)
        deleteItem(t->left, newItem);
    else if (newItem > t->data)
        deleteItem(t->right, newItem);
    else
        deleteNode(t);
}


template<class T>
void BST_312 <T>::deleteItem(const T& newItem)
{
    deleteItem(root, newItem);

}

template<class T>
void BST_312 <T>::makeEmpty(TreeNode*& t)
{
    deleteNode(root);
}

template<class T>
void BST_312 <T>::makeEmpty()
{
    makeEmpty(root);
    root = NULL;
}

template<class T>
bool BST_312 <T>::isEmpty() const
{
    return root == NULL;
}


template<class T>
bool BST_312 <T>::isFull() const
{
    try
    {
        TreeNode *temp = new TreeNode;
        delete temp;
        return false;
    }
    catch (std::bad_alloc)
    {
        return true;
    }

}


template<class T>
void BST_312 <T>::insertItem(TreeNode*& t, const T& newItem) {

    if(root == NULL){
        TreeNode* temp = new TreeNode;
        root = temp;
        root->data = newItem;
        root->left = NULL;
        root->right = NULL;
    }
    if (newItem < t->data) {
        if (t->left != NULL) {
            insertItem(t->left, newItem);
        } else {
            TreeNode* temp = new TreeNode;
            t->left = temp;
            t->left->data = newItem;
            t->left->left = NULL;
            t->left->right = NULL;
        }
    } else if (newItem > t->data){
        if(t->right != NULL) {
            insertItem(t->right, newItem);
        } else {
            TreeNode* temp = new TreeNode;
            t->right = temp;
            t->right->data = newItem;
            t->right->left = NULL;
            t->right->right = NULL;
        }
    } else{
        return;
    }
}

template<class T>
void BST_312 <T>::insertItem(const T& newItem)
{
    insertItem(root, newItem);
}

template<class T>
int BST_312 <T>::countNodes(TreeNode* t) const
{
    if(t == NULL){
        return 0;
    }
    return (1 + countNodes(t->left) + countNodes(t->right));
}

template<class T>
int BST_312 <T>::countNodes()
{
    return (countNodes(root));
}

template<class T>
void BST_312 <T>::preOrderTraversal(TreeNode* t,vector<T>& result) const
{
    if(t != NULL){
        result.push_back(t->data);
        preOrderTraversal(t->left, result);
        preOrderTraversal(t->right, result);
    }
}


template<class T>
vector<T> BST_312 <T>::preOrderTraversal()
{
    vector<T> preResult;
    preOrderTraversal(root, preResult);
    return preResult;

}

template<class T>
void BST_312 <T>::inOrderTraversal(TreeNode* t,vector<T>& result) const
{
    if(t != NULL){
        inOrderTraversal(t->left, result);
        result.push_back(t->data);
        inOrderTraversal(t->right, result);
    }
}

template<class T>
vector<T> BST_312 <T>::inOrderTraversal()
{
    vector<T> inResult;
    inOrderTraversal(root, inResult);
    return inResult;
}

template<class T>
void BST_312 <T>::postOrderTraversal(TreeNode* t,vector<T>& result) const
{
    if(t != NULL){
        postOrderTraversal(t->left, result);
        postOrderTraversal(t->right, result);
        result.push_back(t->data);
    }
}

template<class T>
vector<T> BST_312 <T>::postOrderTraversal()
{
    vector<T> postResult;
    postOrderTraversal(root, postResult);
    return postResult;
}

template<class T>
bool BST_312 <T>::isItemInTreeHelper(const T& item, TreeNode* t){
    if(t == NULL){
        return false;
    }
    if(item < t->data){
        isItemInTreeHelper(item, t->left);
    } else if(item > t->data){
        isItemInTreeHelper(item, t->right);
    } else {
        return true;
    }
}

template<class T>
bool BST_312 <T>::isItemInTree(const T& item)
{
    return (isItemInTreeHelper(item, root));
}
#endif

