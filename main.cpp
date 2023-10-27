#include <iostream>
//#include "bst.cpp"
#include "usecase.cpp"
using namespace std;

int main()
{
    //111010100101
    //this is the main function
    
    // BST<int,int> tree;
    
    // tree.insert(7,49);
    // tree.insert(73,58);
    // tree.insert(30,72);
    // tree.insert(44,78);
    // tree.insert(23,9);
    //tree.remove(72);
    //cout << tree.max_data() << endl;
    //cout << tree.to_string() << endl;
    BST<string,string>* newBst = create_bst<string,string>("binhex.txt");
    string bin;
    cout << "Enter binary number: ";
    cin >> bin;
    stringstream in;
    in << bin;
    convert(newBst,bin);
    //cout << newBst->in_order() << endl;
    return 0;
}


