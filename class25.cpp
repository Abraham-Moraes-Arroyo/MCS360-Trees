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


void BSTree::inorder_h(Node *current) {
             if (current != NULL) {
               inorder_h(current->left);
               cout<< current->data << endl;
               inorder_h(current->right);
             }
      }


int main(){
    vector<int> v = {3,6,2,8,1,2,9,7};
    BSTree T;
    T.generateBST(v);
    
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
*/
