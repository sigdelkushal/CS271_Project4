#include "bst.cpp"
#include "bst.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;


template <typename data_type,typename key_type>
BST<data_type,key_type>* create_bst(string fname){
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


// template <typename data_type,typename key_type>
// string convert(BSTd<data_type,key_type>* bst, string bin){


// }