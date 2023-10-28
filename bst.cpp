#include <iostream>
#include <sstream>
#include <iostream>
#include <queue>
#include "bst.h"
using namespace std;


template <typename data_type,typename key_type>
Node<data_type,key_type>::Node() // node constructor 
{
    /*
Constructor: creates Nodde object no parameters


Precondition: none
Postcondition: new Node object

Return value: none
*/
}

template <typename data_type,typename key_type>
Node<data_type,key_type>::Node(data_type d, key_type k) 
{
    /*
Constructor: creates Node object with data d and key k

Parameters:
d: data, data type
k: key, key type

Precondition: none
Postcondition: new Node object

Return value: none
*/
    left = nullptr; 
    right = nullptr;
    p = nullptr;
    key = k;
    data = d;
}


template <typename data_type,typename key_type>
data_type Node<data_type,key_type>::get_data(){
    /*
Gets Node object's template data

Parameters:
None

Precondition: existing Node object with a data attribute
Postcondition: returns data of the given node

Return value: none
*/
    return data;
}

template <typename data_type,typename key_type>
key_type Node<data_type,key_type>::get_key(){
    /*
Gets Node object's  key.

Parameters: none

Precondition: existing Node object with a key attribute
Postcondition: same as precondition

Return value: Node object's key_type key
*/

    return key;
}


template <typename data_type,typename key_type>
BST<data_type,key_type>:: BST()
{

    /*
Constructor. Creates a empty BST object

Parameters:
None

Precondition: none
Postcondition: new BST object with null root

Return value: none
*/
    root = nullptr;
}


template <typename data_type,typename key_type>
bool BST<data_type,key_type>:: empty(){
      /*
Indicate whether the binary search tree bst is empty.

Parameters:
None

Precondition: none
Postcondition: boolean of true or false depending if BST is empty or not

Return value: bool
*/

    if(root == nullptr){
        return true;
    }
    return false;
}

template <typename data_type,typename key_type>
Node<data_type,key_type> *BST<data_type, key_type>::get_node(key_type k){   //helper function for remove. Gets node with key_type k
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
void BST<data_type,key_type>::insert(data_type d, key_type k){

    /*
Inserts Node object with template data and integer key into BST

Parameters:
data: data_type data
key: key_type key

Precondition: key and data are valid and not null. Key is not already in BST
Postcondition: key-data pair is sucessfully inserted into hash table

Return value: none
*/

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

}
template <typename data_type,typename key_type>
data_type BST<data_type,key_type>:: get(key_type k){ 

     /*
Return the data associated with key k

Parameters:

k: key_type key

Precondition: key is valid
Postcondition: returns  the data associated with the key k

Return value: Data associated with the key
*/

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
Returns the data associated with the max key in the tree bst
Parameters:
None


Precondition: none
Postcondition: returns the data associated with the max key

Return value: Data associated with the MAX key
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

    /*
Returns the key associated with the max key in the tree bst
Parameters:



Precondition: none
Postcondition: returns the key associated with the max key

Return value: Key associated with the MAX key
*/

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
       /*
Returns the key associated with the MIN key in the tree bst
Parameters:



Precondition: none
Postcondition: returns the key associated with the max key

Return value: Key associated with the MIN key
*/

    Node<data_type,key_type> *x = min(root);
    return x->get_key();
}

template <typename data_type, typename key_type>
data_type BST<data_type,key_type>::min_data(){

       /*
Returns the data associated with the MIN key in the tree bst
Parameters:



Precondition: none
Postcondition: returns the data associated with the max key

Return value: Data associated with the MIN key
*/

    Node<data_type,key_type> *x = min(root);
    return x->get_data();
}

template <typename data_type,typename key_type>
void BST<data_type,key_type>:: transplant(Node<data_type,key_type>* u,Node<data_type,key_type>* v){


       /*

Parameters:
Node<data_type,key_type>* u
Node<data_type,key_type>* v

Precondition: none
Postcondition: Subtree rooted a u is replaced with subtree rooted at node v


*/

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
//==================
//remove
//pre-conditions: the key k must be valid
//post-condition: the node with key k is removed from bst
//==================
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
//================
//successor
//pre-condition: There must exist a initialized Binary Search Tree
//post-condition: returns a key of type key_type. If a successor exists for the provided key,
//                a valid key is returned. If no successor, deafult value of keytype() is returned.
//================
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
//================
//recursivetrim and trim
//Pre-condition : low should be less than or equal to high.
//Post-condition : The function trims the subtree rooted at the current node x based on
// the keys in the range [low, high]. trim trims entire BST based on the range [low,high] 
//
//================
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
    string s;
    in_orderHelper(root, s);
    return s.substr(0,s.size()-1);
}

template <typename data_type,typename key_type>
void BST<data_type,key_type>:: in_orderHelper(Node<data_type,key_type>* node,string &result)
/*
Helps in_order recusively

Parameters: node: where the subtree to be sorted is rooted

Precondition: There must be a initialized bst
Postcondition: returns a string of sorted keys in subtree rooted at node

Return value: none
*/
{


    if (node == nullptr) //ensure the bst has memory; empty string if not
    {
        return;
    }

    in_orderHelper(node->left,result);

    stringstream ss;
    ss << node->get_key() << " ";
    result += ss.str();

    in_orderHelper(node->right, result);
    
}

template <typename data_type, typename key_type> string BST<data_type, key_type>::to_string() {
// 
// Parameters: NONE
// pre-condition: there must be a initialized bst. 
//post-condition: returns a string representation of the nodes in a bst. 

  static Node<data_type, key_type> *const DELIMITER = NULL;
  stringstream ss;
  string s = ""; 

  if (root == NULL) { // check if bst is empty
    return s;         
  }

  queue<Node<data_type, key_type> *> bst_q; // intialize queue of type node pointer

  bst_q.push(root);
  bst_q.push(DELIMITER);

  while (true) { // while the root is not null
    Node<data_type, key_type> *curr = bst_q.front();

    bst_q.pop();

    if (curr != DELIMITER) {
      ss.str("");
      ss << curr->get_key() << " ";
      s = s + ss.str(); 

      if (curr->left != NULL) {
        bst_q.push(curr->left);
      }

      if (curr->right != NULL) {
        bst_q.push(curr->right);
      }
    }
 
    else {
      if (bst_q.empty()) {
        break;
      }
      bst_q.push(DELIMITER);
    }
  }

  return s.substr(0, s.size() - 1);
}