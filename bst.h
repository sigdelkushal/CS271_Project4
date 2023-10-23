

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

template <typename data_type,typename key_type>
class Node
{
    public:
        Node *left; //is there a way to make these private? friend fct?
        Node *right;
        data_type d;
        key_type k;
        
        Node(data_type data, key_type key) //no arg constructor. creates empty Node object.
        {
            left = nullptr; 
            right = nullptr;
            k = data;
            d = key;
        };
    
};

template <typename data_type,typename key_type>
class BinarySearchTree
{
    Node* root;

    public:
        //BinarySearchTree(int i); //constructor
        void empty(); //inserts Element with data d and encrypted key -1 at slot hash
        void insert(data_type d, key_type k); //inserts Element with data d and key k into hash table
        void remove(key_type k); //deletes Element with key K from hash table
        bool get(key_type k); //indicate whether hash table contains Element with data d
        data_type max_data(); //
        key_type max_key(); //
        data_type min_data(); //
        key_type min_key(); //
        key_type successor(key_type k);
        string in_order();
        void trim(key_type low, key_type high);
        string to_string(); //converts hash table to string
        ~BinarySearchTree(); //destructor
};

