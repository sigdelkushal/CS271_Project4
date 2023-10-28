#include <iostream>
#include <sstream>
#include <iostream>
#include "bst.h"
using namespace std;


template <typename data_type,typename key_type>
Node<data_type,key_type>::Node()
{}

template <typename data_type,typename key_type>
Node<data_type,key_type>::Node(data_type d, key_type k) 
{
    left = nullptr; 
    right = nullptr;
    p = nullptr;
    key = k;
    data = d;
}


template <typename data_type,typename key_type>
data_type Node<data_type,key_type>::get_data(){
    return data;
}

template <typename data_type,typename key_type>
key_type Node<data_type,key_type>::get_key(){
    return key;
}


template <typename data_type,typename key_type>
BST<data_type,key_type>:: BST() // creates empty tree object.
{
    root = nullptr;
}


template <typename data_type,typename key_type>
bool BST<data_type,key_type>:: empty(){
    if(root == nullptr){
        return true;
    }
    return false;
}

template <typename data_type,typename key_type>
Node<data_type,key_type> *BST<data_type, key_type>::get_node(key_type k){   //helper function for remove. 
    if(root == NULL)
    {
        return NULL;
    }
    Node<data_type,key_type> *current = root;
    while((current != NULL) & (k != current->get_key())){
        if (k > current->get_key()){
            current = current->right;
        }
        else{
            current = current->left;
        }
    }

    if (current != NULL){
        return current;
    }
    else{
        return NULL;
    }
}





template <typename data_type,typename key_type>
void BST<data_type,key_type>:: insert(data_type d, key_type k){

    Node<data_type,key_type>* newNode = new Node<data_type,key_type>(d,k);
    Node<data_type,key_type>* y = nullptr;
    Node<data_type,key_type>* x = root;
    
    while (x != nullptr)
    {
        y = x;
        if (k < x->get_key()){
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
    else if (newNode->get_key() < y->get_key())
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
        
        if (k == x->get_key()){
            return x->get_data();
        }
        else if (k < x->get_key())
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
    
    if (x == nullptr or x->left == nullptr){
        return x;
    }
    return min(x->left);
}


template <typename data_type, typename key_type>
data_type BST<data_type, key_type>::max_data(){
  /*
  Parameters:
  None
  */
  if (root == NULL) {
    return data_type();
  }
  Node<data_type, key_type> *current = root;
  while (current->right != NULL) {
    current = current->right;
  }
  return current->get_data(); 
}



template <typename data_type, typename key_type>
key_type BST<data_type,key_type>::max_key(){

  if (root == NULL) {
    return key_type();
  }
  Node<data_type, key_type> *current = root;
  while (current->right != NULL) {
    current = current->right;
  }
  return current->get_key();    
} 

template <typename data_type, typename key_type>
key_type BST<data_type,key_type>::min_key(){
    Node<data_type,key_type> *x = min(root);
    return x->get_key();
}

template <typename data_type, typename key_type>
data_type BST<data_type,key_type>::min_data(){
    Node<data_type,key_type> *x = min(root);
    return x->get_data();
}

template <typename data_type,typename key_type>
void BST<data_type,key_type>:: transplant(Node<data_type,key_type>* u,Node<data_type,key_type>* v){
    if (u->p == nullptr){
        root = v;
    }
    else if(u == u->p->left){
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
    
    if (root == NULL){
        return;
    }

    Node<data_type,key_type> *x = get_node(k);
    Node<data_type,key_type> *y = NULL;

    if (x->left == NULL){
        transplant(x, x->right);
    }
    else if (x->right == NULL){
        transplant(x, x->left);
    }
    else{
        y = min(x->right); //successor

        if (y->p != x){
            transplant(y, y->right);
            y->right = x->right;
            y->right->p = y;
        }

        transplant (x,y);
        y->left = x->left;
        y->left->p = y; 
    }
}


template <typename data_type,typename key_type>
string BST<data_type,key_type>::to_string()
/*
Converts a bst to a string representing its contents.

Parameters: none

Precondition: 
Postcondition: 

Return value: none
*/
{
    stringstream ss;
    if (root != nullptr) {  // Check if the tree is empty
        toStringHelper(root, ss);
    }
    return ss.str();

}

template <typename data_type,typename key_type>
void BST<data_type,key_type>::toStringHelper(Node<data_type,key_type>* node,stringstream& result)
/*
Helps so string recusively

Parameters: none

Precondition: 
Postcondition: ble

Return value: none
*/
{


    if (node == nullptr) //ensure the bst has memory; empty string if not
    {
        return;
    }

    toStringHelper(node->left,result);

    result << " " << node->get_key() << " " << endl;

    toStringHelper(node->right,result);
    
}

/*
template <typename data_type,typename key_type>
Node<data_type,key_type> *BST<data_type,key_type>::treemin(Node<data_type,key_type> *x){

    if (root == NULL){
        return NULL;
    }

    Node<data_type,key_type> *current = x;
    while (current->left != NULL){
        current = current->left;
    } 

    return current;
}
*/

template <typename data_type,typename key_type>
key_type BST<data_type,key_type>::successor(key_type key){

    if (root == NULL){
        return key_type();
    }

    Node<data_type,key_type> *x = get_node(key);
    Node<data_type,key_type> *y;

    if (x != NULL){
        if (x->right != NULL){
            Node<data_type,key_type> *z = min(x->right);
            return z->get_key();
        }
        y = x->p;
        while ((y != NULL) && (x == y->right)){
            x = y;
            y = y->p;
        }
        if (y != NULL){
            return y->get_key();
        }
    }

    return key_type();
}

template <typename data_type,typename key_type>
Node<data_type,key_type>* BST<data_type,key_type>::recursivetrim(Node<data_type,key_type> * x,key_type low, key_type high){
    if (x == NULL){
        return x;
    }
    x->left = recursivetrim(x->left, low, high);
    x->right = recursivetrim(x->right, low,high);

  if (x->get_key() < low || x->get_key() > high) {
    if (x->left == NULL) {
      return x->right;
    }
    if (x->right == NULL) {
      return x->left;
    }
  }

  return x;
}

template <typename data_type,typename key_type>
void BST<data_type,key_type>::trim(key_type low, key_type high){
    root = recursivetrim(root,low,high);
}

template <typename data_type,typename key_type>
string BST<data_type,key_type>:: in_order()
/*
Converts a bst to a string representing its contents.

Parameters: none

Precondition: 
Postcondition: 

Return value: none
*/
{
    stringstream ss;
    if (root != nullptr) {  // Check if the tree is empty
        in_orderHelper(root, ss);
    }
    return ss.str();

}

template <typename data_type,typename key_type>
void BST<data_type,key_type>:: in_orderHelper(Node<data_type,key_type>* node,stringstream& result)
/*
Helps so string recusively

Parameters: none

Precondition: 
Postcondition: ble

Return value: none
*/
{


    if (node == nullptr) //ensure the bst has memory; empty string if not
    {
        return;
    }

    in_orderHelper(node->left,result);

    result << " " << node->get_key() << " " << endl;

    in_orderHelper(node->right,result);
    
}
