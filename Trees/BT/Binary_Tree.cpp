#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;
        Node(int val)
        {
            this->data = val;
            this->left = NULL;
            this->right = NULL;
        }
};

class BinaryTree{
    private:
    void inorder_trav(Node *node){
        if(!node)
            return;
        inorder_trav(node->left);
        cout << node->data << " ";
        inorder_trav(node->right);
    }

    int maximum_depth(Node *node){
        if(!node)
            return 0;
        return 1 + max(maximum_depth(node->left), maximum_depth(node->right));
    }

    
    bool isBalanced(Node *node){
        if(!node)
            return true;

        // I used Maximum_Depth as Height of the root node is equal to the maximum depth as they both are same i used it.

        if (abs(maximum_depth(node->left) - maximum_depth(node->right)) <= 1 && isBalanced(node->left) && isBalanced(node->right)){
            return true;
        }
        return false;
    }
    public:
        Node *root;

        BinaryTree(){
            this->root = NULL;
        }

        void insert(int val){
            if(!root){
                Node *newNode = new Node(val);
                root = newNode;
                return;
            }else{
                queue<Node *> que;
                que.push(root);

                while(!que.empty()){
                    Node *curr = que.front();
                    que.pop();

                    if(!curr->left){
                        Node *newNode = new Node(val);
                        curr->left = newNode;
                        return;
                    }else{
                        que.push(curr->left);
                    }

                    if(!curr->right){
                        Node *newNode = new Node(val);
                        curr->right = newNode;
                        return;
                    }else{
                        que.push(curr->right);
                    }
                }
            }
        }

        void inorder(){
            inorder_trav(this->root);
            return;
        }

        int maxDepth(){
            int dep = maximum_depth(this->root);
            return dep;
        }

        void checkBalance(){
            bool res = isBalanced(this->root);
            string op = (res ? "Balanced" : "Not Balanced");
            cout << op << endl;
        }
};

int main()
{
    BinaryTree *bt = new BinaryTree();
    bt->insert(1);
    bt->insert(2);
    bt->insert(3);
    bt->insert(4);
    bt->insert(5);

    bt->inorder();
    cout << endl;
    cout << bt->maxDepth() << endl;
    bt->checkBalance();
    return 0;
}