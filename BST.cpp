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
// in_order 
// Parameters: none
// Return:	
//=========================================================================
template <class D, class T>
string BST<D,T>::in_order() 
//preconditions: 
//postconditions:   
{
    Node *x = this->root;
    string out =  in_order_recursive(x, "");
    if (!out.empty() && out.back() == ' ') {
        out.pop_back();
    }
    return out;
}

//=========================================================================
// in_order_recursive 
// Parameters: 
//  elem - element to insert into the tree
// Return:	none
//=========================================================================
template <class D, class T>
string BST<D,T>::in_order_recursive(Node *x, string out) const
//preconditions: 
//postconditions: 
{
    if (x == nullptr) {
        return out;
    }

    string l = in_order_recursive(x->left, out);
    string root = std::to_string(x->item.get_key()) + " ";
    string r = in_order_recursive(x->right, out);

    return l + root + r;
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
    Node *x = findNode(this->root, k);
    
    if ( x->right !=  nullptr ){
        Node *z = minimum(x->right);
        return z->item.get_key();
    }
    else{
        Node *y = x->parent;
        while ( y != nullptr && x == y->right){
            x = y;
            y = x->parent;
    }
    if(y==nullptr)
        return T();
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
template <class D, class T>
typename BST<D,T>::Node* BST<D,T>::minimum(Node *x)
//preconditions: the tree object exists and contains the key k
//postconditions: the correct successor of the node with key k is returned 
{
    while (x->left != NULL){
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
template <class D, class T>
typename BST<D,T>::Node* BST<D,T>::findNode(Node* root, T key)
//preconditions: the tree object exists and contains the key k
//postconditions: 
{
    while (root != nullptr && root->item.get_key() != key) {
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
template <class D, class T>
void BST<D,T>::remove(const T k)
//preconditions: the tree object exists and contains the key k
//postconditions: 
{
   Node *x = findNode(this->root, k);

   if (x == nullptr){
    return;
   }

    //x has no left child, replace x with x.right
   if(x->left == nullptr){
    transplant(this, x, x->right);
   }

   //x has no right child, replace x with x.left
   else if(x->right == nullptr){
    transplant(this, x, x->left);
   }

   //x has both children
   else {
    Node *y = minimum(x->right);
    if(y->parent != x){
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
template <class D, class T>
void BST<D,T>::transplant(BST* tree, Node* u, Node* v)
//preconditions: 
//postconditions: 
{
    if(u->parent == nullptr)
        tree->root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else {
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
template <class D, class T>
void BST<D,T>::trim(T high, T low)
//preconditions: 
//postconditions: 
{
    trim_recursive(this->root, high, low);
}

//=========================================================================
// trim_recursive
// Parameters: 
//  
// Return:	
//  
//=========================================================================
template <class D, class T>
void BST<D,T>::trim_recursive(Node* root, T high, T low)
//preconditions: 
//postconditions: 
{
    if(root == nullptr)
        return;
    trim_recursive(root->left, high, low);
    trim_recurisve(root->right, high, low);

    if(root->item.get_key() < low || root->item.get_key() > high)
        remove(root->item.get_key());
}
