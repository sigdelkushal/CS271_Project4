#ifndef BST_H
#define BST_H



#include <iostream>
#include <sstream>
#include <string>
using namespace std;

template <typename data_type,typename key_type>
class Node
{
    private:
        data_type data;
        key_type key;

    public:
        Node* left; 
        Node* right;
        Node* p;
        
        Node();
        Node(data_type d, key_type k); //no arg constructor. creates empty Node object.
        data_type get_data();
        key_type  get_key();
        
    
};

template <typename data_type,typename key_type>
class BST
{
    private:
        Node<data_type,key_type>* root;

        void transplant(Node<data_type,key_type>* u,Node<data_type,key_type>* v);
        Node<data_type,key_type> *min(Node<data_type,key_type> *m);
        Node<data_type, key_type> *get_node(key_type k);
        Node<data_type,key_type> *recursivetrim(Node<data_type,key_type> *x, key_type low, key_type high);
        data_type   max_data_help(Node<data_type,key_type>* x);
    public:
        BST(); //no arg constructor. creates empty Node object.
        bool empty(); //
        void insert(data_type d, key_type k); //
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
        //void toStringHelper(Node<data_type,key_type>* node,stringstream &result);
        void in_orderHelper(Node<data_type,key_type>* node,string &result);
        //~BST(); //destructor
};

#endif 