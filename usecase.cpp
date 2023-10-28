#include "bst.cpp"
#include "bst.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;


template <typename data_type,typename key_type>
BST<data_type,key_type>* create_bst(string fname){

 /*
Takes file and creates a bst using data from file


Parameters:
string fname

Precondition: valid given file
Postcondition: BST with data from file

Return value: none
*/
    BST<data_type,key_type>* newBST = new BST<data_type,key_type>;

    string line;
    fstream file;
    string data;
    fstream key;
    file.open(fname, ios::in); //open file

     while (getline(file, line))
    {
        int comm_pos = line.find(',');
        data_type d = line.substr(0,comm_pos);
        key_type k = line.substr(comm_pos+1);
        newBST->insert(d,k);

    }
    file.close();
    return newBST;

}


template <typename data_type,typename key_type>
string convert(BST<data_type,key_type>* bst, string bin){

    /*
Converts binary keys into Hexadecimal values


Parameters:
BST<data_type,key_type>* bst
string bin

Precondition: BST is valid binary tree, bin is valid binary string
Postcondition:  converts binary keys into Hexadecimal values

Return value: none
*/

    string ans = "";
    // cout << "Enter binary number";
    // cin >> bin;
    // stringstream in;
    // in << bin;
    string chunk;
    

    int numofzeros = bin.length() % 4;
    for(int i = 0;i< numofzeros;i++){
        bin = "0" + bin;
    }
    //cout << bin << endl;
    for(int j = 0;j<bin.length();j+=4){
        chunk = bin.substr(j,4); // four bits of each 
        key_type result = bst->get(chunk);
        ans = ans + result;
    }
    
    cout << "Hexadecimal representation of "<< bin << " is "<< ans << endl;
    return ans;
}