//
//  test_bst_example.cpp
//  CS 271 BST Project: Example Test File
//
//  Created by Dr. Stacey Truex
//

#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "BST.cpp"
//#include "usecase.cpp"

using namespace std;

void test_empty() {
    try
    {
        BST<string, int> bst;
        if(!bst.empty()) {
            cout << "Incorrect empty result0." << endl;
        }
        bst.insert("one",1);
        if(bst.empty()) {
            cout << "Incorrect empty result1." << endl;
        }
        bst.remove(1);
        if(!bst.empty()) {
            cout << "Incorrect empty result2." << endl;
        }
        BST<string, string> bst1;
        if(!bst1.empty()) {
            cout << "Incorrect empty result3." << endl;
        }
        bst1.insert("one", "one");
        if(bst1.empty()) {
            cout << "Incorrect empty result4." << endl;
        }
        bst1.insert("hi", "hello");
        if(bst1.empty()) {
            cout << "Incorrect empty result5." << endl;
        }
        bst1.remove("hello");
        if(bst1.empty()) {
            cout << "Incorrect empty result6." << endl;
        }
        bst1.remove("one");
        if(!bst1.empty()) {
            cout << "Incorrect empty result7." << endl;
        }
    }
    catch(exception& e)
    {
        cerr << "Error in determining if BST is empty : " << e.what() << endl;
    }
}

void test_insert() {
    try {
        BST<string, int> bst;
        bst.insert("one", 1);
        string bst_str = bst.to_string();
        if(bst_str != "1") {
            cout << "Incorrect result of inserting (\"one\", 1). Expected 1 but got : " << bst_str << endl;
        }
        for(int i = 2; i <= 10; i++) {
            bst.insert("some data", i);
        }
        bst_str = bst.to_string();
        if(bst_str != "1 2 3 4 5 6 7 8 9 10") {
            cout << "Incorrect result of inserting keys 1-10 in order. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << bst_str << endl;
        }
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert("some data", vals[i]);
        }
        bst_str = balanced_bst.to_string();
        if(bst_str != "5 2 7 1 3 6 9 4 8 10") {
            cout << "Incorrect result of inserting keys {5, 2, 7, 1, 3, 4, 6, 9, 8, 10}. Expected 5 2 7 1 3 6 9 4 8 10 but got : " << bst_str << endl;
        }
        BST<int, int> bst1;
        string bst_str1 = bst1.to_string();
        if(bst_str1 != "") {
            cout << "Incorrect result of to_string. Expected empty string but got : " << bst_str << endl;
        }
        bst1.insert(4, 5);
        bst1.insert(4, 5);
        bst1.insert(5, 6);
        bst1.insert(7, 8);
        string bst_str2 = bst1.to_string();
        if(bst_str2 != "5 5 6 8") {
            cout << "Incorrect result of to_string. Expected empty string but got : " << bst_str << endl;
        }
        BST<string, float> bst3;
        bst3.insert("hi", 4.5);
        string bst_str3 = bst3.to_string();
        if(bst_str3 != "4.5") {
            cout << "Incorrect result of to_string. Expected 4.5 but got : " << bst_str << endl;
        }
        bst3.insert("world", 100.1);
        bst3.insert("dog", 6.9);
        bst3.insert("apple", 6.9);
        bst3.insert("apple", 101.999);
        bst3.insert("", 0.1);
        bst3.insert("boy", -2.45);
        bst_str3 = bst3.to_string();
        if(bst_str3 != "4.5 0.1 100.1 -2.45 6.9 101.999 6.9") {
            cout << "Incorrect result of to_string. Expected 4.5 but got : " << bst_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error inserting into bst : " << e.what() << endl;
    }
}

void test_get() {
    try {
        BST<string, int> bst;
        string val = bst.get(0);
        if(val!="") {
            cout << "Incorrect get result from empty bst. Expected 0 but got " << val << endl;
        }
        bst.insert("one",1);
        val = bst.get(1);
        if(val != "one") {
            cout << "Incorrect get result. Expected \"one\" but got : " << val << endl;
        } 
        bst.insert("hi", 89);
        bst.insert("apple", 100);
        bst.insert("girl", 2);
        bst.insert("cs", -12);
        val = bst.get(-12);
        if(val != "cs") {
            cout << "Incorrect get result. Expected \"cs\" but got : " << val << endl;
        } 
        val = bst.get(2);
        if(val != "girl") {
            cout << "Incorrect get result. Expected \"girl\" but got : " << val << endl;
        } 
        val = bst.get(100);
        if(val != "apple") {
            cout << "Incorrect get result. Expected \"apple\" but got : " << val << endl;
        } 
        bst.insert("world", 100);
        val = bst.get(100);
        if(val != "apple") {
            cout << "Incorrect get result. Expected \"apple\" but got : " << val << endl;
        } 
        BST<float, float> bst1;
        float val1 = bst1.get(2.9);
        if(val1 != 0.0 ) {
            cout << "Incorrect get result. Expected \"0.0\" but got : " << val1 << endl;
        } 
        bst1.insert(9.9, 9.9);
        bst1.insert(100.100, 3.14);
        bst1.insert(-12.2, 12);
        val1 = bst1.get(12);
        if(val1 != -12.2) {
            cout << "Incorrect get result. Expected -12.2 but got : " << val1 << endl;
        } 
    } catch(exception& e) {
        cerr << "Error in getting data from bst : " << e.what() << endl;
    }
}

void test_remove() {
    try {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert("some data", vals[i]);
        }
        balanced_bst.remove(7);
        string bst_str = balanced_bst.to_string();
        if(bst_str != "5 2 8 1 3 6 9 4 10") {
            cout << "Incorrect result of removing 7. Expected 5 2 8 1 3 6 9 4 10 but got : " << bst_str << endl;
        }
        
        BST<int, int> bst1;
        bst1.remove(1);
        string bst_str1 = bst1.to_string();
        if(bst_str1 != "") {
            cout << "Incorrect result of removing 1. Expected empty tree but got : " << bst_str1 << endl;
        }
        bst1.insert(5, 6);
        bst1.remove(6);
        bst_str1 = bst1.to_string();
        if(bst_str1 != "") {
            cout << "Incorrect result of removing 6. Expected empty tree but got : " << bst_str1 << endl;
        }
        bst1.insert(9, 10);
        bst1.insert(10, 2);
        bst1.remove(2);
        bst_str1 = bst1.to_string();
        if(bst_str1 != "10") {
            cout << "Incorrect result of removing 2. Expected 10 but got : " << bst_str1 << endl;
        }
        bst1.insert(11, 23);
        bst1.insert(22, 100);
        bst1.remove(10);
        bst_str1 = bst1.to_string();
        if(bst_str1 != "23 100") {
            cout << "Incorrect result of removing 10. Expected 23 100 but got : " << bst_str1 << endl;
        }
        bst1.insert(11, 2);
        bst1.insert(22, 1);
        bst1.insert(11, 5);
        bst1.insert(22, 103);
        bst1.remove(2);
        bst_str1 = bst1.to_string();
        if(bst_str1 != "23 5 100 1 103") {
            cout << "Incorrect result of removing 2. Expected 23 5 100 1 103 but got : " << bst_str1 << endl;
        }
        bst1.remove(23);
        bst_str1 = bst1.to_string();
        if(bst_str1 != "100 5 103 1") {
            cout << "Incorrect result of removing 2. Expected 100 5 103 1 but got : " << bst_str1 << endl;
        }
    } catch(exception& e) {
        cerr << "Error in removing node from bst : " << e.what() << endl;
    }
}

void test_max_data() {
    try {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        string max_str = balanced_bst.max_data();
        if(max_str != "10 data") {
            cout << "Incorrect result of max_data. Expected \"10 data\" but got : " << max_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining data of max node in bst : " << e.what() << endl;
    }
}

void test_max_key() {
    try {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        int max_k = balanced_bst.max_key();
        if(max_k != 10) {
            cout << "Incorrect result of max_key. Expected 10 but got : " << max_k << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining key of max node in bst : " << e.what() << endl;
    }
}

void test_min_data() {
    try {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        string min_str = balanced_bst.min_data();
        if(min_str != "1 data") {
            cout << "Incorrect result of min_data. Expected \"1 data\" but got : " << min_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining data of min node in bst : " << e.what() << endl;
    }
}

void test_min_key() {
    try {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        int min_k = balanced_bst.min_key();
        if(min_k != 1) {
            cout << "Incorrect result of min_key. Expected 10 but got : " << min_k << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining key of min node in bst : " << e.what() << endl;
    }
}

void test_successor() {
    try {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        int succ = balanced_bst.successor(4);
        if(succ != 5) {
            cout << "Incorrect result of successor of 4. Expected 5 but got : " << succ << endl;
        }
        succ = balanced_bst.successor(7);
        if(succ != 8) {
            cout << "Incorrect result of successor of 7. Expected 8 but got : " << succ << endl;
        }
        succ = balanced_bst.successor(10);
        if(succ != 0) {
            cout << "Incorrect result of successor of 10. Expected 0 but got : " << succ << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining successor in bst : " << e.what() << endl;
    }
}

void test_in_order() {
    try {
        BST<string, int> bst;
        for(int i = 1; i <= 10; i++) {
            bst.insert("some data", i);
        }
        string bst_str = bst.in_order();
        if(bst_str != "1 2 3 4 5 6 7 8 9 10") {
            cout << "Incorrect in_order result after inserting keys 1-10 in order. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << bst_str << endl;
        }
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert("some data", vals[i]);
        }
        bst_str = balanced_bst.in_order();
        if(bst_str != "1 2 3 4 5 6 7 8 9 10") {
            cout << "Incorrect in_order result after inserting keys {5, 2, 7, 1, 3, 4, 6, 9, 8, 10}. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << bst_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error getting keys in_order from bst : " << e.what() << endl;
    }
}
/*
void test_trim() {
    try {
        BST<string,int> bst;
        int vals[3] = {1, 0, 2};
        for(int i = 0; i < 3; i++) {
            bst.insert(to_string(vals[i])+" data", vals[i]);
        }
        bst.trim(1,2);
        string bst_str = bst.to_string();
        if(bst_str != "1 2") {
            cout << "Incorrect tree after trimming 1 0 2 with low=1, high=2. Expected 1 2 but got : " << bst_str << endl;
        }
        BST<string, int> bst2;
        int vals2[5] = {3, 0, 4, 2, 1};
        for(int i = 0; i < 5; i++) {
            bst2.insert(to_string(vals2[i])+" data", vals2[i]);
        }
        bst2.trim(1,3);
        bst_str = bst2.to_string();
        if(bst_str != "3 2 1") {
            cout << "Incorrect tree after trimming 3 0 4 2 1 with low=1, high=3. Expected 3 2 1 but got : " << bst_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in trimming the bst : " << e.what() << endl;
    }
}

void test_binhex(){
    try {
        BST<string,string>* bst1 = create_bst<string,string>("binhex.txt");
        string bin1 = "111010100101";
        string expected_hex1 = "EA5";

        string hex1 = convert<string,string>(bst1, bin1);
        delete bst1;

        if(hex1!=expected_hex1) {
            cout << "Incorrect result converting " << bin1 << " to hex. Expected : " << expected_hex1 << ", but got : " << hex1 << endl;
        }
       
    } catch(exception& e) {
        cerr << "Error converting binary to hex : " << e.what() << endl;
    }

    try {
        BST<string,string>* bst2 = create_bst<string,string>("binhex.txt");
        string bin2 = "110101";
        string expected_hex2 = "35";

        string hex2 = convert<string,string>(bst2, bin2);
        delete bst2;

        if(hex2!=expected_hex2) {
            cout << "Incorrect result converting " << bin2 << " to hex. Expected : " << expected_hex2 << ", but got : " << hex2 << endl;
        }
       
    } catch(exception& e) {
        cerr << "Error converting binary to hex : " << e.what() << endl;
    }
}
*/

int main() {
    
    test_empty();
    test_insert();
    test_get(); 
    test_remove();
    test_max_data();
    test_max_key();
    test_min_data();
    test_min_key();
    test_successor();
    test_in_order();
    //test_trim();
    //test_binhex();

    cout << "Testing completed" << endl;
    
    return 0;
}
