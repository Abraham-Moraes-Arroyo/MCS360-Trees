/*
implementation of a binary tree object at its traversal
functiosn contianign an underscore, i.e, _h
denote helper functions which handle most of the 
actual work. The function with the same name, 
but without _h, are functions which call the helper
functions
*/
/*
BSTree for v={3,6,2,8,1,2,9,7}

        3
        /\
        2 6
       /\  /\
       N 2 N 8
        /\   /\
        N N  N N
N= NULL
*/

#include <iostream>
#include <vector>
using namespace std;
struct  Node
{
    // this is our smallest unit
    int data;
    Node *left;// Node pointer
    Node *right;
};
class BSTree{
    private:
        Node *root;// so we know where the root is 
        // this is the starting point, where we start looking
        void insert_h(int, Node * );
        // We want to keep this one private, but we will have
        // a public one too
    public:
        void insert(int);// this is so we can call on the 
        // private variation of insert() this is a helper
        // function
        void generateBST(vector<int>);

        BSTree(){// the constructor
            root= NULL;
        }
};

/*Node Insertion Functions*/
void BSTree::insert_h(int value, Node *leaf){
    if (value <= leaf->data){
        // here we will see if we put the next value to e
        // either the left or the right
        if(leaf->left != NULL)
        // if there is already a leaf is there, then 
        // we add that upcoming Node below that leaf
        // , and it becomes the "new" leaf
            insert_h(value, leaf->left);// this is the recusrive call 
        else{
            // Here is where insertion takes place
            // making the new Node
            leaf-> left= new Node;
            // we assign the new value/ Number as the number
            leaf -> left -> data= value;
            // on the new node we need to  make the poitner
            // equal to NULL, so it can represent that 
            // the Node we inserted become the leave, and 
            // the NULLs help us understand that there 
            // is no node ahead of the that one
            leaf -> left ->left= NULL;
            
            leaf -> left -> right=NULL; 
        }
    }
    // this is the case that the value is greater 
    // than the data of the leaf
    else if (value > leaf -> data){
        if (leaf-> right !=NULL)
            insert_h (value, leaf-> right);
        else{
            leaf-> right =new Node;
            leaf-> right-> data= value;
            leaf-> right -> left= NULL;
            leaf-> right -> right = NULL;
        }
    }
}// the root is actually a leaf that is pointing to NULL


void BSTree::insert(int value){
    if(root !=NULL)
    // if the root has a number in it already
        insert_h(value, root);
        // call the helper function 
        // and insert it below the root, or where 
        // there is no populated leaf.
    else{
        // if there are no roots,
        // we need to make it the root
        root= new Node;
        // we give that root the number that we understand
        root-> data=value;
        //we need to make the pointer become the NULL
        root-> left= NULL;
        // we need to make the pointer become the NULL
        root-> right=NULL;
        // that way we can make this now inserted value
        // become the leaf, so next time we want to insert
        // more values we insert it below this one
    }
}
int main(){
    vector<int> v= {3,6,2,8,1,2,9,7};
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
