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
    ~BST(void);
    void deleteTree(Node* node);
    void insert( const D data, const T key );
    //void remove(const Node<D, T> &node );
    string to_string( void ) const; 
    bool empty( void );
    D get( const T k );
    D max_data(void);
    T max_key(void);
    D min_data(void);
    T min_key(void);
    T successor( const T k);
    string in_order(void);
    void trim(T high, T low);
    //Node* triplinkedlist<T>::findNode(const triplinkedlist& tree, const T k);
    void transplant( Node u, Node v);
};

#endif
