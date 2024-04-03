#include "BST.cpp"
#include <iostream> // For std::cout and std::cin
#include <string>   // For std::string

using namespace std;

// Assuming BST<string, string> is correctly implemented with insert and get methods.

BST<string, string> create_bst()
{
    BST<string, string> bst;
    // Directly insert binary-hex pairs into the BST
    bst.insert("0000", "0");
    bst.insert("0001", "1");
    bst.insert("0010", "2");
    bst.insert("0011", "3");
    bst.insert("0100", "4");
    bst.insert("0101", "5");
    bst.insert("0110", "6");
    bst.insert("0111", "7");
    bst.insert("1000", "8");
    bst.insert("1001", "9");
    bst.insert("1010", "A");
    bst.insert("1011", "B");
    bst.insert("1100", "C");
    bst.insert("1101", "D");
    bst.insert("1110", "E");
    bst.insert("1111", "F");
    return bst;
}

string convert(BST<string, string> &bst, string binaryString)
{
    string hexResult = "";
    // Ensure binaryString's length is a multiple of 4
    while (binaryString.length() % 4 != 0)
    {
        binaryString = "0" + binaryString;
    }
    // Convert each 4-bit chunk to hexadecimal
    for (size_t i = 0; i < binaryString.length(); i += 4)
    {
        string chunk = binaryString.substr(i, 4);
        hexResult += bst.get(chunk);
    }
    return hexResult;
}

int main() {
    BST<string, string> bst = create_bst();

    // Debug: Test insertion and retrieval directly
    cout << "Debug: Testing insertion and retrieval...\n";
    cout << "Manual test for 0001: " << bst.get("0001") << " (Expected: 1)\n";
    cout << "Manual test for 0010: " << bst.get("0010") << " (Expected: 2)\n";
    // Add more tests as needed

    // Proceed with original logic
    cout << "Enter a binary string: ";
    string binaryInput;
    cin >> binaryInput;

    string hexOutput = convert(bst, binaryInput);
    cout << "Hexadecimal conversion: " << hexOutput << endl;

    return 0;
}


// g++ -std=c++11 element.cpp BST.cpp usecase.cpp -o usecase
// ./usecase
