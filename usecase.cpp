#include "BST.cpp"
#include <iostream> 
#include <string>   
#include <fstream>
#include <sstream>


using namespace std;


template <class D, class K>
string convert(BST<string, string> *bst, string binaryString)
{
    string hex = "";
    while (binaryString.length() % 4 != 0)
    {
        binaryString = "0" + binaryString;
    }
    for (int i = 0; i < binaryString.length(); i += 4)
    {
        string chunk = binaryString.substr(i, 4);
        hex += bst->get(chunk);
    }
    return hex;
}

template <class D, class K>
BST<D, K>* create_bst(const string fname){
    BST<string, string> *bst = new BST<string, string>();
    fstream file;
    
    file.open(fname);
    string line;
    
    while (getline(file, line)) {
        istringstream iss(line);
        string hex, bin;
        getline(iss, hex, ',');
        getline(iss, bin, ',');

        bst->insert(hex, bin);
    }
    file.close();
    return bst;
}

