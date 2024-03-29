#include <iostream>
#include "BST.cpp" 

int main() {
    // Create a triplinkedlist
    BST<int, int> bst;

    // Test insert function
    bst.insert(10, 15);
    bst.insert(5, 7);
    bst.insert(15, 25);
    bst.insert(3, 3);
    bst.insert(7, 9);
    bst.insert(12, 17);
    bst.insert(17, 50);
    bst.to_string();

    

}