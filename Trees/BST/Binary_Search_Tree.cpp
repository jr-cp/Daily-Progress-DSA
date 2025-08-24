#include<bits/stdc++.h>
using namespace std;

class Node{
    private:
        int data;
    public:
        Node *left;
        Node *right;
    
    Node(int val){
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }

    int getData(){
        return this->data;
    }
};

class BinarySearchTree{
    public:
        Node *root;

        BinarySearchTree(){
            this->root = nullptr;
        }

        void insert(Node *&root,int val){
            if(root == nullptr){
                root = new Node(val);
                return;
            }

            if(val < root->getData()){
                insert(root->left, val);
            }
            else if(val > root->getData()){
                insert(root->right, val);
            }

        }

        void inorder(Node *root){
            if(root == nullptr)
                return;
            Node *curr = this->root;
                       

            inorder(root->left);
            cout << root->getData() << " ";
            inorder(root->right);
    }


};

int main()
{
    BinarySearchTree *bst = new BinarySearchTree();
    bst->insert(bst->root, 20);
    bst->insert(bst->root, 40);
    bst->insert(bst->root, 60);
    bst->insert(bst->root, 80);
    bst->insert(bst->root, 10);
    bst->insert(bst->root, 200);
    bst->insert(bst->root, 100);

    bst->inorder(bst->root);
    return 0;
}