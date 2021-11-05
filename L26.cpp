/*
 - Implementation of a binary tree object and its traversal.
 - functions containing an underscore, ie. _h
   denote helper functions which handle most of the
   actual work. The function with the same name,
   but without _h, are functions which call the
   helper functions.
*/

#include<iostream>
#include<vector>

using namespace std;

struct Node {
       int data;
       Node *left;
       Node *right;
};

class BSTree {
      private:
        Node *root;
        void insert_h(int,  Node * );
        void preorder_h(Node *);
        void inorder_h(Node *);
        void postorder_h(Node *);
      public:
        void insert(int);
        void generateBST(vector<int>);
        void preorderTraverse();
        void inorderTraverse();
        void postorderTraverse();

      BSTree() {
         root = NULL;
      }
};


/*Node Insertion Functions*/
void BSTree::insert_h(int value, Node *leaf) {
           if(value <= leaf->data) {
              if(leaf->left != NULL)
                insert_h(value, leaf->left);
              else {
                leaf->left = new Node;
                leaf->left->data = value;
                leaf->left->left = NULL;    
                leaf->left->right = NULL;   
              }  
           }
           else if(value > leaf->data) {
                if(leaf->right != NULL)
                   insert_h(value, leaf->right);
                else {
                   leaf->right = new Node;
                   leaf->right->data = value;
                   leaf->right->left = NULL;  
                   leaf->right->right= NULL;
                 }
              }
      }

void BSTree::insert(int value){
           if(root != NULL)
              insert_h(value, root);
           else {
              root = new Node;
              root->data = value;
              root->left = NULL;
              root->right = NULL;
           }
      }

void BSTree::generateBST(vector<int> v){
           for (auto x = v.begin(); x != v.end(); ++ x)
                insert(*x); // placing elements of the vector into the BSTree
      }

void BSTree::preorder_h(Node *current) {
             if (current != NULL) {
                 //if there is a tree that we know
                 // go far left as you can then you go far right as you can
               cout<< current->data << endl;// see how we don't use the *current here,
               // we just have access to the data`
               preorder_h(current->left);
               preorder_h(current->right);
               /*
               we need to know which way we are going, because in this case it is preorder_h
               */
             }
      }
void BSTree::preorderTraverse(){
     preorder_h(root);
}

void BSTree::inorder_h(Node *current) {
             if (current != NULL) {
               // you need to keep in mind when we are going to be printing the "data"
               inorder_h(current->left);
               cout<< current->data << endl;
               inorder_h(current->right);
             }
      }
void BSTree::inorderTraverse(){
     inorder_h(root);
}
// you need to know when to print the data from the tree, because it plays a major role to your understanding
// when you need to write the code for the different orders
void BSTree::postorder_h(Node *current) {// Node *current is the argument that it takes in
             if (current != NULL) {
                 /*
                    If there is tree that we can traverse, the if(statement)
                 */
               postorder_h(current->left);
               postorder_h(current->right);
               cout<< current->data << endl;
             }
      }
      // we use scope resolution here
void BSTree::postorderTraverse(){
     postorder_h(root);
}


int main(){
    vector<int> v = {3,6,2,8,1,2,9,7};
    BSTree T;
    T.generateBST(v);
    cout << "---------" << endl;
    T.preorderTraverse();
    // cout << "---------" << endl;
    // T.inorderTraverse();
    // cout << "---------" << endl;
    // T.postorderTraverse();
    // return 0;
}

/*
BSTree for v = {3,6,2,8,1,2,9,7}
          (3)
         /   \
       (2)    (6)
      /  \    /  \
    (1)  (N) (N) (8)
    / \        /   \
   (N)(2)    (7)   (9)
      / \    / \   / \
    (N) (N)(N) (N)(N) (N)
N = NULL

preorder: 3,2,1,2,6,8,7,9
*/
