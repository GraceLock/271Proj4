#include <iostream>
#include "usecase.cpp"

int main() {
    
    BST<string, string> *bst = create_bst<string,string>("binhex.txt");

    cout << "Enter a binary string: ";
    string binaryInput;
    cin >> binaryInput;
    for (char c : binaryInput) {
        if (c != '0' && c != '1') {
            cout << "ERROR: Input a Binary Number" << endl;
            return false;
        }
    }

    string hexOutput = convert<string,string>(bst, binaryInput);
    cout << "Hexadecimal conversion: " << hexOutput << endl;

    delete bst;
    return 0;
}
