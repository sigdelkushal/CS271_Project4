#include <iostream>
#include "bst.cpp"
using namespace std;

int main()
{
    //this is the main function
    
    BST<int,int> tree;
    
    tree.insert(7,49);
    tree.insert(73,58);
    tree.insert(30,72);
    tree.insert(44,78);
    tree.insert(23,9);
    tree.remove(72);
    cout << tree.max_data() << endl;
    cout << tree.to_string() << endl;
    return 0;
}