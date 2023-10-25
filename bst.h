

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

template <typename data_type,typename key_type>
class Node
{
    public:
        Node* left; //is there a way to make these private? friend fct?
        Node* right;
        Node* p;
        data_type data;
        key_type key;
        
        Node(data_type d, key_type k); //no arg constructor. creates empty Node object.
        
    
};

template <typename data_type,typename key_type>
class BST
{
    Node<data_type,key_type>* root;

    public:
        BST(); //no arg constructor. creates empty Node object.
    
        bool empty(); //
        void insert(data_type data, key_type k); //
        data_type get(key_type key); //
        void remove(key_type key); //
        data_type max_data(); //
        key_type max_key(); //
        data_type min_data(); //
        key_type min_key(); //
        key_type successor(key_type key);
        string in_order();
        void trim(key_type low, key_type high);
        string to_string(); //
        //~BST(); //destructor
};

