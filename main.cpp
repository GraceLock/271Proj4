#include <iostream>
#include "usecase.cpp"

int main() {
    
    BST<string, string> *bst = create_bst<string,string>("binhex.txt");

    cout << "Enter a binary string: ";
    string binaryInput;
    cin >> binaryInput;

    string hexOutput = convert<string,string>(bst, binaryInput);
    cout << "Hexadecimal conversion: " << hexOutput << endl;

    delete bst;
    return 0;
}
