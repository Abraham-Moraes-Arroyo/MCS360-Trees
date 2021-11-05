#include <iostream>
#include <vector>
using namespace std;

struct Node{
    //
    int data;// node pointer to the "number" that we see
    Node *left; // node pointer to the left
    Node *right;// node pointer to the right
};
class BSTree{
    private: 
        Node *root; // so we know where the root is 
        // this is the starting pointer, where we 
        // start looking in the list and start organizing
        // the nodes by their value 

        void insert_h(int, Node * );
        // we want to keep this one function private,
        // but we are also going to have a public function
        // that should help us
        void preorder_h(Node *);
    public:
         void insert(int); 
         // this is so we can call on the private variation
         // of insert this is a helper function
         void generateBST(vector<int>);
    BSTree(){// the constructor
        root= NULL;
    }
};

/*Node Insertion Function*/
void BSTree::insert_h(int value, Node *leaf){
    if(value <= leaf-> data){
        // here we will see if we put the next value to
        // either the left or the right
        if(leaf-> left !=NULL)
        // if there is already a leaf is there , then
        // we add that upcoming Node below that leaf
        // and it becomes that "new" leaf
            insert_h(value, leaf-> left);
            // this is the recursive call
        else {
            // Here is where insertion takes place
            // making the new Node
            leaf-> left= new Node;
            // we assign the new value/ Number as the number
            leaf-> left-> data=value;
            // on the new node we need to make the pointer
            // eqaul to NULL, so it can represent that 
            // the Node we inserted become the leave, and 
            // the NULL help us understnad that there is 
            // no node ahead of the that one
            leaf-> left-> left =NULL;
            leaf->left-> right= NULL; 
        }
    }
    // this is the case that the value is greater
    // than the data of the leaf
    else if(value > leaf-> data){
        if(leaf-> right != NULL)
            insert_h(value, leaf-> right);
        else{
            leaf-> right=new Node;
            leaf-> right-> data= value;
            leaf-> right -> left= NULL;
            leaf-> right -> right = NULL;
    }
}// the oot is actually a leaf that is pointing to NULL
}

void BSTree::insert(int value){
        if(root != NULL)
        // if the root has a number in it already
            insert_h(value, root);
            // call the helper function
            // and insert it below the root, or 
            // where there is no population leaf
        else{
            // if there are no roots, we need to 
            // make it the root
            root= new Node;
            // we give that root the number that we 
            // understand
            root-> data= value;
            // we need to make the pinter become the NULL
            root-> left= NULL;
            // we need to make the pointer become the NULL
            root-> right = NULL;
            // that way we can make this now inserted value 
            // become the leaf, so next time we want to 
            // insert more vlaues we insert it below this
            // one
        }
}
void BSTree:: generateBST(vector<int> v){
    for (auto x=v.begin(); x != v.end(); ++ x)
        insert(*x);
}


int main(){
    vector<int> v={3,6,2,8,1,2,9,7};
    BSTree T;
    T.generateBST(v);
    return 0;
}
