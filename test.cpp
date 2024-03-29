#include <iostream>
#include "BST.cpp" 

int main() {
    // Create a triplinkedlist
    bst<int, string> bst;

    // Test insert function
    Element<int, std::string> elem1(10, "Apple");
    Element<int, std::string> elem2(5, "Banana");
    Element<int, std::string> elem3(15, "Orange");
    Element<int, std::string> elem4(3, "Grapes");
    Element<int, std::string> elem5(7, "Mango");
    Element<int, std::string> elem6(12, "Peach");
    Element<int, std::string> elem7(17, "Kiwi");

    // Test insert function
    bst.insert(elem1);
    bst.insert(elem2);
    bst.insert(elem3);
    bst.insert(elem4);
    bst.insert(elem5);
    bst.insert(elem6);
    bst.insert(elem7);

    

}