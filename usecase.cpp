#include "BST.cpp"
#include <iostream> 
#include <string>   
#include <fstream>
#include <sstream>


using namespace std;

template <class D, class K>
string convert(BST<string, string> &bst, string binaryString);
BST<D, K>* create_bst(string fname);


int main() {
    
    BST<string, string> bst = create_bst("binhex.txt");

    cout << "Enter a binary string: ";
    string binaryInput;
    cin >> binaryInput;

    string hexOutput = convert(bst, binaryInput);
    cout << "Hexadecimal conversion: " << hexOutput << endl;

    delete bst;
    return 0;
}

template <class D, class K>
string convert(BST<string, string> &bst, string binaryString)
{
    string hexResult = "";
    // Ensure binaryString's length is a multiple of 4
    while (binaryString.length() % 4 != 0)
    {
        binaryString = "0" + binaryString;
    }
    // Convert each 4-bit chunk to hexadecimal
    for (int i = 0; i < binaryString.length(); i += 4)
    {
        string chunk = binaryString.substr(i, 4);
        hexResult += bst.get(chunk);
    }
    return hexResult;
}

template <class D, class K>
BST<D, K>* create_bst(string fname){
    BST<string, string> *bst = new BST<string, string>();
    fstream file;
    
    file.open(fname);
    string line;
    
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string hex, bin;
        std::getline(iss, hex, ',');
        std::getline(iss, bin, ',');

        bst->insert(hex, bin);
    }
    file.close();
    return bst;
}
