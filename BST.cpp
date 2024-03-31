#include <iostream>
#include <string>
#include "BST.h"
#include <queue>

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
    ostringstream out;

    if (this->root == nullptr)
        return "";

    std::queue<Node*> q;
    q.push(root);
    bool isFirstNode = true;

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; ++i) {
            Node* current = q.front();
            q.pop();
            if (isFirstNode){
                out << current->item.get_key();
                isFirstNode = false;
            }
            else 
            out << " " << current->item.get_key();

            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);
        }
    }
    return out.str();
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

    Node *newNode = new Node();
    newNode -> item = elem;
    Node *y = nullptr;
    Node *x = root;

    if (this->root == nullptr)
        this->root = newNode;

    else{
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
    return (root == nullptr);
}

//=========================================================================
// max_key 
// Parameters: none
// Return:	
//  the key associated with the max key in the tree 
//=========================================================================
template <class D, class T>
T BST<D,T>::max_key()
//preconditions: the tree object exists and is not empty
//postconditions: the largest key in the tree is returned
{
    Node *x = this->root;
    Node *max = this->root;
    while (x != NULL){
        max = x;
        x = x->right;
    }
    return max->item.get_key();
}

//=========================================================================
// max_data 
// Parameters: none
// Return:
//  the data value associated with the largest key in the tree
//=========================================================================
template <class D, class T>
D BST<D,T>::max_data()
//preconditions: the tree object exists and is not empty
//postconditions: the data value associated with the largest key in the tree is correctly returned
{
    Node *x = this->root;
    Node *max = this->root;
    while (x != NULL){
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
template <class D, class T>
T BST<D,T>::min_key()
//preconditions: the tree object exists and is not empty
//postconditions: the key associated with the minimum key in the tree is correctly returned
{
   Node *x = this->root;
    Node *min = this->root;
    while (x != NULL){
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
template <class D, class T>
D BST<D,T>::min_data()
//preconditions: the tree object exists and is not empty
//postconditions: the data value associated with the minimum key in the tree is correctly returned
{
    Node *x = this->root;
    Node *min = this->root;
    while (x != NULL){
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
template <class D, class T>
D BST<D,T>::get(const T k)
//preconditions: the tree object exists and contains the key k
//postconditions: the data associated with the key k is correctly returned and NULL if k is not in the tree
{
    Node *x = this->root;
    while (x != nullptr ) {
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
template <class D, class T>
T BST<D,T>::successor(const T k)
//preconditions: the tree object exists and contains the key k
//postconditions: the correct successor of the node with key k is returned 
{
    Node *x = findNode(this, k);
    
    if ( x->right !=  nullptr )
        return min(x->right);
    Node *y = x->parent;
    while ( y != nullptr && x == y->right){
        x = y;
        y = x->parent;
    }
    return y;
}

//=========================================================================
// minimum 
// Parameters: 
//  k - the key of the node to find successor for
// Return:	
//  the node that has the next largest key after k in the tree
//=========================================================================
template <class D, class T>
T BST<D,T>::minimum(Node *x)
//preconditions: the tree object exists and contains the key k
//postconditions: the correct successor of the node with key k is returned 
{
    Node *y = x.parent;
    while (x != NULL){
        y = x;
        x = x->left;
    }
    return y->item.get_key();
}