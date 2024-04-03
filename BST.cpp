#include <iostream>
#include <string>
#include "BST.h"
#include <queue>

using namespace std;

//=========================================================================
// Constructor

// Parameters: none
// Return:	none
// Preconditions: none
// Postconditions: BST object is created
//=========================================================================
template <class D, class K>
BST<D, K>::BST()
{
    root = nullptr; // initialize the root to null
}

//=========================================================================
// Deconstructor

// Parameters: none
// Return:	none
// Preconditions: None
// Postconditions: The BST object is deleted
//=========================================================================
template <class D, class K>
BST<D, K>::~BST()
{
    Node *x = this->root; // set x to the root of the tree
    if (x)
    {
        deleteTree(x->left);  // delete the left subtree
        deleteTree(x->right); // delete the right subtree
        delete x;             // delete the root
    }
}

//=========================================================================
// DeleteTree

// Parameters: A pointer to the root node of the tree to be deleted
// Return: None
// Preconditions: The tree exists
// Postconditions: The tree is deleted
//=========================================================================
template <class D, class K>
void BST<D, K>::deleteTree(Node *node)
{
    if (node != nullptr) // if the node is not null
    {
        deleteTree(node->left);  // delete the left subtree
        deleteTree(node->right); // delete the right subtree

        delete node; // delete the node
    }
}

//=========================================================================
// To string

// Parameters: The tree
// Return: A string representation of the tree
// Preconditions: The tree exists
// Postconditions: The tree is printed in a string format
//=========================================================================
template <class D, class K>
string BST<D, K>::to_string() const
{
    ostringstream out; // create an output stream

    if (this->root == nullptr) // if the tree is empty
        return "";             // return an empty string

    std::queue<Node *> q;    // create a queue of nodes
    q.push(root);            // push the root node to the queue
    bool isFirstNode = true; // set the first node to true

    while (!q.empty()) // while the queue is not empty
    {
        int levelSize = q.size(); // get the size of the queue

        for (int i = 0; i < levelSize; ++i) // iterate through the queue
        {
            Node *current = q.front(); // get the front of the queue
            q.pop();                   // pop the front of the queue
            if (isFirstNode)           // if this is the first node
            {
                out << current->item.get_key(); // add the key to the output stream
                isFirstNode = false;            // set the first node to false
            }
            else
                out << " " << current->item.get_key(); // add the key to the output stream

            if (current->left != nullptr)  // if the left child is not null
                q.push(current->left);     // push the left child to the queue
            if (current->right != nullptr) // if the right child is not null
                q.push(current->right);    // push the right child to the queue
        }
    }
    return out.str();
}

//=========================================================================
// In order

// Parameters: None
// Return: The tree in in-order traversal
// Preconditions: The tree exists
// Postconditions: The tree is printed in in-order traversal
//=========================================================================
template <class D, class K>
string BST<D, K>::in_order()
{
    Node *x = this->root;                  // set x to the root of the tree
    std::ostringstream oss;                // create an output stream
    in_order_recursive(x, oss);            // call the recursive in order function
    string out = oss.str();                // get the string from the output stream
    if (!(out == "") && out.back() == ' ') // if the last character is a space
    {
        out.pop_back(); // remove the space
    }
    return out; // return the string
}

//=========================================================================
// In order recursive

// Parameters: The root node of the tree and an output stream
// Return: The tree in in-order traversal
// Preconditions: The tree exists
// Postconditions: Returns a string with the in-order data of the tree
//=========================================================================
template <class D, class K>
void BST<D, K>::in_order_recursive(Node *x, std::ostringstream &oss) const
{
    if (x == nullptr) // if the node is null
    {
        return;
    }

    in_order_recursive(x->left, oss);  // call the function on the left child
    oss << x->item.get_key() << +" ";  // add the key to the output stream
    in_order_recursive(x->right, oss); // call the function on the right child
}

//=========================================================================
// Insert

// Parameters: The data and key to be inserted
// Return: None
// Preconditions: The function is called with valid data and key.
// Postconditions: The data and key are inserted into the tree
//=========================================================================
template <class D, class K>
void BST<D, K>::insert(const D data, const K key)
{
    Element<D, K> elem(data, key); // create a new element

    Node *newNode = new Node(); // create a new node
    newNode->item = elem;       // set the item of the node to the element
    Node *y = nullptr;          // create a new node
    Node *x = root;             // set x to the root of the tree

    if (this->root == nullptr) // if the tree is empty
        this->root = newNode;  // set the root to the new node

    else
    {
        while (x != nullptr) // while x is not null
        {
            y = x;
            if (elem.get_key() < x->item.get_key()) // if the key is less than the current node
                x = x->left;                        // set x to the left child
            else
                x = x->right; // set x to the right child
        }

        newNode->parent = y; // set the parent of the new node to y
        if (y == nullptr)    // if y is null
        {
            root = newNode; // set the root to the new node
        }
        else if (elem.get_key() < y->item.get_key()) // if the key is less than the parent
        {
            y->left = newNode; // set the left child to the new node
        }
        else
        {
            y->right = newNode; // set the right child to the new node
        }
    }
}

//=========================================================================
// Empty

// Parameters: none
// Return: A boolean value indicating if the tree is empty
// Preconditions: None
// Postconditions: Returns true if the tree has no nodes otherwise its false
//=========================================================================
template <class D, class K>
bool BST<D, K>::empty(void) // check if the tree is empty
{
    return (root == nullptr); // return true if the root is null
}

//=========================================================================
// Max key

// Parameters: none
// Return:
// Preconditions:
// Postconditions:
//=========================================================================
template <class D, class K>
K BST<D, K>::max_key()
{
    Node *x = this->root; // start from the node root
    if (x == nullptr)
        return K();         // return default value
    Node *max = this->root; // Initialize max node
    while (x != NULL)
    {
        max = x;      // update max node
        x = x->right; // move to the right subtree
    }
    return max->item.get_key(); // return the maximum key
}

//=========================================================================
// max_data 
// Parameters: none
// Return:
//  the data value associated with the largest key in the tree
//=========================================================================
template <class D, class K>
D BST<D, K>::max_data()
// preconditions: the tree object exists and is not empty
// postconditions: the data value associated with the largest key in the tree is correctly returned
{
    Node *x = this->root;
    if (x == nullptr)
        return D();
    Node *max = this->root;
    while (x != NULL)
    {
        max = x;
        x = x->right;
    }
    return max->item.get_data();
}

//=========================================================================
// min_key
// Parameters: none
// Return:
//  the key associated with the minimum key in the tree
//=========================================================================
template <class D, class K>
K BST<D, K>::min_key()
// preconditions: the tree object exists and is not empty
// postconditions: the key associated with the minimum key in the tree is correctly returned
{
    Node *x = this->root;
    if (x == nullptr)
        return K();
    Node *min = this->root;
    while (x != NULL)
    {
        min = x;
        x = x->left;
    }
    return min->item.get_key();
}

//=========================================================================
// min_data
// Parameters: none
// Return:
//  the data value associated with the minimum key in the tree
//=========================================================================
template <class D, class K>
D BST<D, K>::min_data()
// preconditions: the tree object exists and is not empty
// postconditions: the data value associated with the minimum key in the tree is correctly returned
{
    Node *x = this->root;
    if (x == nullptr)
        return D();
    Node *min = this->root;
    while (x != NULL)
    {
        min = x;
        x = x->left;
    }
    return min->item.get_data();
}

//=========================================================================
// get
// Parameters:
//  k - key of a node to find its data
// Return:
//  the data associated with the key k
//=========================================================================
template <class D, class K>
D BST<D, K>::get(const K k)
// preconditions: the tree object exists and contains the key k
// postconditions: the data associated with the key k is correctly returned and NULL if k is not in the tree
{
    Node *x = this->root;
    while (x != nullptr)
    {
        if (x->item.get_key() == k)
            return x->item.get_data();
        else if (k < x->item.get_key())
            x = x->left;
        else
            x = x->right;
    }
    return D();
}

//=========================================================================
// successor
// Parameters:
//  k - the key of the node to find successor for
// Return:
//  the node that has the next largest key after k in the tree
//=========================================================================
template <class D, class K>
K BST<D, K>::successor(const K k)
// preconditions: the tree object exists and contains the key k
// postconditions: the correct successor of the node with key k is returned
{
    Node *x = findNode(this->root, k);

    if (x == nullptr)
        return K();

    if (x->right != nullptr)
    {
        Node *z = minimum(x->right);
        return z->item.get_key();
    }
    else
    {
        Node *y = x->parent;
        while (y != nullptr && x == y->right)
        {
            x = y;
            y = x->parent;
        }
        if (y == nullptr)
            return K();
        return y->item.get_key();
    }
}

//=========================================================================
// minimum
// Parameters:
//  k - the key of the node to find successor for
// Return:
//  the node that has the next largest key after k in the tree
//=========================================================================
template <class D, class K>
typename BST<D, K>::Node *BST<D, K>::minimum(Node *x)
// preconditions: the tree object exists and contains the key k
// postconditions: the correct successor of the node with key k is returned
{
    while (x->left != NULL)
    {
        x = x->left;
    }
    return x;
}

//=========================================================================
// findNode
// Parameters:
//  x - root node of a BST
// Return:
//
//=========================================================================
template <class D, class K>
typename BST<D, K>::Node *BST<D, K>::findNode(Node *root, K key)
// preconditions: the tree object exists and contains the key k
// postconditions:
{
    while (root != nullptr && root->item.get_key() != key)
    {
        if (key < root->item.get_key())
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

//=========================================================================
// remove
// Parameters:
//
// Return:
//
//=========================================================================
template <class D, class K>
void BST<D, K>::remove(const K k)
// preconditions: the tree object exists and contains the key k
// postconditions:
{
    Node *x = findNode(this->root, k);

    if (x == nullptr)
    {
        return;
    }
    // x has no left child, replace x with x.right
    if (x->left == nullptr)
    {
        transplant(this, x, x->right);
    }

    // x has no right child, replace x with x.left
    else if (x->right == nullptr)
    {
        transplant(this, x, x->left);
    }

    // x has both children
    else
    {
        Node *y = minimum(x->right);
        if (y->parent != x)
        {
            transplant(this, y, y->right);
            y->right = x->right;
            y->right->parent = y;
        }
        transplant(this, x, y);
        y->left = x->left;
        y->left->parent = y;
    }
    delete x;
}

//=========================================================================
// transplant
// Parameters:
//  x - root node of a BST
// Return:
//
//=========================================================================
template <class D, class K>
void BST<D, K>::transplant(BST *tree, Node *u, Node *v)
// preconditions:
// postconditions:
{
    if (u->parent == nullptr)
        tree->root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
    {
        u->parent->right = v;
    }
    if (v != nullptr)
        v->parent = u->parent;
}

//=========================================================================
// trim
// Parameters:
//
// Return:
//
//=========================================================================
template <class D, class K>
void BST<D, K>::trim(K low, K high)
// preconditions:
// postconditions:
{
    trim_recursive(this->root, low, high);
}

//=========================================================================
// trim_recursive
// Parameters:
//
// Return:
//
//=========================================================================
template <class D, class K>
void BST<D, K>::trim_recursive(Node *root, K low, K high)
// preconditions:
// postconditions:
{
    if (root == nullptr)
        return;

    trim_recursive(root->left, low, high);
    trim_recursive(root->right, low, high);

    if (root->item.get_key() < low)
    {
        remove(root->item.get_key());
    }
    else if (root->item.get_key() > high)
    {
        remove(root->item.get_key());
    }
}
