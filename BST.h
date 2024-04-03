#include <iostream>
#include <string>
#include <sstream>
#include "element.cpp"

using namespace std;

#ifndef BST_H
#define BST_H

template <class D, class K>
class BST
{
private:
    struct Node
    {
        Element<D,K> item;
        Node *parent;
        Node *left;
        Node *right;
    };
    
    Node *root;          

public:
    BST( void );
    ~BST();
    void deleteTree(Node* node);
    void insert( const D data, const K key );
    void remove(const K k );
    string to_string( void ) const; 
    string in_order();
    void in_order_recursive(Node *x, std::ostringstream& oss) const;
    bool empty( void );
    Node* minimum(Node *x);
    D get( const K k );
    Node* findNode(Node* x, K key);
    D max_data(void);
    K max_key(void);
    D min_data(void);
    K min_key(void);
    K successor( const K k);
    void trim(K low, K high);
    void trim_recursive(Node* root, K low, K high);
    void transplant( BST* tree, Node* u, Node* v);
};

#endif
