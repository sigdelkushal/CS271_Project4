#include <iostream>
#include "bst.cpp"
using namespace std;

int main()
{
    //this is the main function
    
    BST<int,int> tree;
    
    tree.empty();
    tree.insert(1,1);
    tree.empty();
    cout << tree.get(1) << endl;
    return 0;
}