#include <iostream>
#include <string>
#include <sstream>
#include "element.cpp"

using namespace std;

#ifndef BST_H
#define BST_H

template <class D, class T>
class BST
{
private:
    struct Node
    {
        Element<D,T> item;
        Node *parent;
        Node *left;
        Node *right;
    };
    
    Node *root;          

public:
    BST( void );
    ~BST();
    void deleteTree(Node* node);
    void insert( const D data, const T key );
    void remove(const T k );
    string to_string( void ) const; 
    string in_order();
    void in_order_recursive(Node *x, std::ostringstream& oss) const;
    bool empty( void );
    Node* minimum(Node *x);
    D get( const T k );
    Node* findNode(Node* x, T key);
    D max_data(void);
    T max_key(void);
    D min_data(void);
    T min_key(void);
    T successor( const T k);
    void trim(T low, T high);
    void trim_recursive(Node* root, T low, T high);
    //Node* triplinkedlist<T>::findNode(const triplinkedlist& tree, const T k);
    void transplant( BST* tree, Node* u, Node* v);
};

#endif
