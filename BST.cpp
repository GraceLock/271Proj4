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
// Return: The largest key in the tree
// Preconditions: None
// Postconditions: The largest key in the tree is returned
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
// Max data

// Parameters: None
// Return:
// Preconditions: None
// Postconditions: The largest data value in the tree is returned
//=========================================================================
template <class D, class K>
D BST<D, K>::max_data()
{
    Node *x = this->root;   // start from the node root
    if (x == nullptr)       // if the tree is empty
        return D();         // return default value
    Node *max = this->root; // Initialize max node
    while (x != NULL)
    {
        max = x;      // update max node
        x = x->right; // move to the right subtree
    }
    return max->item.get_data(); // return the maximum data
}

//=========================================================================
// Min key

// Parameters: None
// Return: The smallest key in the tree
// Preconditions: None
// Postconditions: The smallest key in the tree is returned
//=========================================================================
template <class D, class K>
K BST<D, K>::min_key()
{
    Node *x = this->root;   // start from the node root
    if (x == nullptr)       // if the tree is empty
        return K();         // return default value
    Node *min = this->root; // Initialize min node
    while (x != NULL)
    {
        min = x;     // update min node
        x = x->left; // move to the left subtree
    }
    return min->item.get_key(); // return the minimum key
}

//=========================================================================
// Min data

// Parameters: None
// Return: The smallest data value in the tree
// Preconditions: None
// Postconditions: The smallest data value in the tree is returned
//=========================================================================
template <class D, class K>
D BST<D, K>::min_data()
{
    Node *x = this->root;   // start from the node root
    if (x == nullptr)       // if the tree is empty
        return D();         // return default value
    Node *min = this->root; // Initialize min node
    while (x != NULL)
    {
        min = x;     // update min node
        x = x->left; // move to the left subtree
    }
    return min->item.get_data(); // return the minimum data
}

//=========================================================================
// Get

// Parameters: The key of the node to get
// Return: The data of the node with the key
// preconditions:The tree object exists and contains the key k
// postconditions:The data of the node with key k is returned
//=========================================================================
template <class D, class K>
D BST<D, K>::get(const K k)
{
    Node *x = this->root; // start from the root
    while (x != nullptr)
    {
        if (x->item.get_key() == k)     // if the key is found
            return x->item.get_data();  // return the data
        else if (k < x->item.get_key()) // if the key is less than the current node
            x = x->left;                // move to the left child
        else
            x = x->right; // move to the right child
    }
    return D(); // return default value
}

//=========================================================================
// Successor

// Parameters: The key of the node to find successor for
// Return: The key of the node that has the next largest key after k in the tree
// Preconditions: The tree object exists and contains the key k
// Postconditions: The correct successor of the node with key k is returned
//=========================================================================
template <class D, class K>
K BST<D, K>::successor(const K k)
{
    Node *x = findNode(this->root, k); // find the node with the key

    if (x == nullptr)
        return K(); // return default value

    if (x->right != nullptr)
    {
        Node *z = minimum(x->right); // find the minimum of the right subtree
        return z->item.get_key();    // return the key
    }
    else
    {
        Node *y = x->parent; // set y to the parent of x
        while (y != nullptr && x == y->right)
        {
            x = y;         // set x to y
            y = x->parent; // set y to the parent of x
        }
        if (y == nullptr) // if y is null
            return K();
        return y->item.get_key(); // return the key
    }
}

//=========================================================================
// Minimum

// Parameters: The root node of a BST
// Return: The node with the smallest key in the tree
// Preconditions: The tree object exists
// Postconditions: The node with the smallest key is returned
//=========================================================================
template <class D, class K>
typename BST<D, K>::Node *BST<D, K>::minimum(Node *x)

{
    while (x->left != NULL)
    {
        x = x->left; // move to the left subtree
    }
    return x; // return the minimum node
}

//=========================================================================
// Find Node

// Parameters: The root node of a BST and a key
// Return: The node with the key
// Preconditions: The tree object exists
// Postconditions:The node with the key is returned
//=========================================================================
template <class D, class K>
typename BST<D, K>::Node *BST<D, K>::findNode(Node *root, K key)

{
    while (root != nullptr && root->item.get_key() != key) // while the root is not null and the key is not found
    {
        if (key < root->item.get_key()) // if the key is less than the current node
            root = root->left;          // move to the left child
        else
            root = root->right; // move to the right child
    }
    return root; // return the node
}

//=========================================================================
// Remove

// Parameters: The key of the node to remove
// Return: None
// Preconditions: The tree object exists and contains the key k
// Postconditions: The node with key k is removed from the tree
//=========================================================================
template <class D, class K>
void BST<D, K>::remove(const K k)

{
    Node *x = findNode(this->root, k); // find the node with the key

    if (x == nullptr)
    {
        return; // return if the node is not found
    }

    if (x->left == nullptr)
    {
        transplant(this, x, x->right); // transplant the right child
    }

    else if (x->right == nullptr)
    {
        transplant(this, x, x->left); // transplant the left child
    }

    else
    {
        Node *y = minimum(x->right); // find the minimum of the right subtree
        if (y->parent != x)
        {
            transplant(this, y, y->right); // transplant the right child
            y->right = x->right;           // set the right child of y to the right child of x
            y->right->parent = y;          // set the parent of the right child of y to y
        }
        transplant(this, x, y); // transplant the node
        y->left = x->left;      // set the left child of y to the left child of x
        y->left->parent = y;    // set the parent of the left child of y to y
    }
    delete x; // delete the node
}

//=========================================================================
// Transplant

// Parameters: The tree, and two nodes
// Return: None
// Preconditions: The tree object exists
// Postconditions: The two nodes are swapped
//=========================================================================
template <class D, class K>
void BST<D, K>::transplant(BST *tree, Node *u, Node *v)
{
    if (u->parent == nullptr)      // if the parent is null
        tree->root = v;            // set the root to v
    else if (u == u->parent->left) // if u is the left child
        u->parent->left = v;       // set the left child to v
    else
    {
        u->parent->right = v; // set the right child to v
    }
    if (v != nullptr)          // if v is not null
        v->parent = u->parent; // set the parent of v to the parent of u
}

//=========================================================================
// Trim

// Parameters: The low and high keys
// Return: None
// Preconditions: The tree object exists
// Postconditions: The tree is trimmed to only contain keys between low and high
//=========================================================================
template <class D, class K>
void BST<D, K>::trim(K low, K high)
{
    trim_recursive(this->root, low, high); // call the recursive trim function
}

//=========================================================================
// Trim recursive

// Parameters: The root node of the tree and the low and high keys
// Return: None
// Preconditions: The tree object exists
// Postconditions: The tree is trimmed to only contain keys between low and high
//=========================================================================
template <class D, class K>
void BST<D, K>::trim_recursive(Node *root, K low, K high)
{
    if (root == nullptr) // if the root is null
        return;

    trim_recursive(root->left, low, high);  // call the function on the left child
    trim_recursive(root->right, low, high); // call the function on the right child

    if (root->item.get_key() < low) // if the key is less than the low
    {
        remove(root->item.get_key()); // remove the node
    }
    else if (root->item.get_key() > high) // if the key is greater than the high
    {
        remove(root->item.get_key()); // remove the node
    }
}
