#include <iostream>
#include <sstream>
#include <iostream>
#include "bst.h"
using namespace std;

template <typename data_type,typename key_type>
Node<data_type,key_type>:: Node(data_type d, key_type k) // creates empty Node object.
{
    left = nullptr; 
    right = nullptr;
    p = nullptr;
    key = k;
    data = d;
}

template <typename data_type,typename key_type>
BST<data_type,key_type>:: BST() // creates empty tree object.
{
    root = nullptr;
}


template <typename data_type,typename key_type>
bool BST<data_type,key_type>:: empty(){
    if(root == nullptr){
        cout << "true" << endl;
        return true;

    }
    cout << "false" << endl;
    return false;

}

template <typename data_type,typename key_type>
void BST<data_type,key_type>:: insert(data_type d, key_type k){

    Node<data_type,key_type>* newNode = new Node<data_type,key_type>(d,k);
    Node<data_type,key_type>* y = nullptr;
    Node<data_type,key_type>* x = root;
    
    while (x != nullptr)
    {
        y = x;
        if (k < x->key){
            x = x->left;
        }
        else{
            x = x->right;
        }

    }
    newNode->p = y;
    if (y == nullptr){
        root = newNode;

    }
    else if (newNode->key < y->key)
    {
        y->left = newNode;
    
    }
    else{
        y->right = newNode;
    }
   // cout << newNode->key << endl;
}
template <typename data_type,typename key_type>
data_type BST<data_type,key_type>:: get(key_type k){ // write for case that key is not in bst
    Node<data_type,key_type>* x = root;
    
    while (x != nullptr)
    {
        
        if (k == x->key){
            return x->data;
        }
        else if (k < x->key)
    {
        x = x->left;
    
    }
    else{
        x = x->right;
    }

    }
    return data_type();
}
template <typename data_type,typename key_type>
Node<data_type,key_type>* BST<data_type,key_type>:: min(Node<data_type,key_type>* m){ // returns min node in subtree
    Node<data_type,key_type>* x = m;
    
    if (x == nullptr or x.left == nullptr){
        return x;
    }
    return min(x.left);
}


template <typename data_type,typename key_type>
void BST<data_type,key_type>:: transplant(Node<data_type,key_type>* u,Node<data_type,key_type>* v){
    if (u->p == nullptr){
        root = v;
    }
    elif(u == u->p->left){
        u->p->left = v;
    }
    else{
        u->p->right = v;
    }
    if(v != nullptr){
        v->p = u->p;
    }
}


template <typename data_type,typename key_type>
void BST<data_type,key_type>:: remove(key_type k){
    Node<data_type,key_type>* x = root;
    while (x != nullptr){
        if(x->key == k){
            if(x->left == nullptr){
                transplant(x,x->right);
            }
            else if (x->right == nullptr)
            {
                transplant(x,x->left);
            }
            else{
               Node<data_type,key_type>* y = min(x.right); //might be wrong function
                if (y != x->right)
                {
                    transplant(y,y->right);
                    y->right = x->right;
                    y->right->p = y;
                }
                transplant(x,y);
                y->left = x->left;
                y->left->p = y;
                
            
            }
    } 
    }
}


