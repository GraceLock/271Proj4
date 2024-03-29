#include <iostream>
#include <string>
#include "BST.h"

using namespace std;

//=========================================================================
// constructor 
// Parameters: none
// Return:	none
//=========================================================================
template <class D, class T>
BST<D,T>::BST()
//preconditions: none
//postconditions: BST object is created 
{
    root = nullptr;
}

//=========================================================================
// deconstructor 
// Parameters: none
// Return:	none
//=========================================================================
template <class D, class T>
BST<D,T>::~BST()
//preconditions: BST object exists
//postconditions: BST object is deleted  
{
    Node *x = this->root;
    if (x)
    {
        deleteTree(x->left);
        deleteTree(x->right);
        delete x;
    }
}

//=========================================================================
// deleteTree 
// Parameters: none
// Return:	none
//=========================================================================
template <class D, class T>
void BST<D,T>::deleteTree(Node* node)
//preconditions: BST object exists
//postconditions: BST object is deleted  
{
    if (node != nullptr){
        deleteTree(node->left);
        deleteTree(node->right);
    
        delete node;
    }
}

//=========================================================================
// to_string 
// Parameters: none
// Return:	
//=========================================================================
template <class D, class T>
string BST<D,T>::to_string() const
//preconditions: 
//postconditions:   
{
    Node *x = root;
    string s = "";
    inOrder(root, s);
    return s;
}

//=========================================================================
// inOrder 
// Parameters: none
// Return:	
//=========================================================================
template <class D, class T>
string BST<D,T>::inOrder(Node* r, string s) const
//preconditions: 
//postconditions:   
{
    Node *x = root;
    if (x == nullptr)
        return "";

    inOrder(x->left, s);
    s = s + std::to_string(x->item.get_key()) + " ";
    inOrder(x->right, s);
}

//=========================================================================
// insert 
// Parameters: 
//  elem - element to insert into the tree
// Return:	none
//=========================================================================
template <class D, class T>
void BST<D,T>::insert( const D data, const T key )
//preconditions: triply linked list exists 
//postconditions: triply linked list now includes the element to insert in the correct spot 
{
    Element<D, T> elem( data, key );

    //if empty, construct
    Node *newNode = nullptr;
    newNode -> item = elem;
    Node *y = nullptr;
    Node *x = root;

    while ( x != nullptr){
        y = x;
        if (elem.get_key() < x->item.get_key())
            x = x->left;
        else
            x = x->right;
    }
    
    newNode->parent = y;
    if (y == nullptr) {
        root = newNode;
    } else if (elem.get_key() < y->item.get_key()) {
        y->left = newNode;
    } else {
        y->right = newNode;
    }
}

//=========================================================================
// empty 
// Parameters: none
// Return:	
//  true - if the tree is empty
//  false - if the tree has at least one node
//=========================================================================
template <class D, class T>
bool  BST<D,T>::empty( void )
//preconditions: the tree object exists
//postconditions: the boolean value returned correctly describes the tree 
{
    return root == nullptr;
}