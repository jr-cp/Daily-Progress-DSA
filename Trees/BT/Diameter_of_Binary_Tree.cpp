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
    int height_of_node(Node *node){
        if(!node)
            return 0;
        return 1 + max(height_of_node(node->left),height_of_node(node->right));
    }
    int dia_of_this_tree(Node *node){
        if(!node)
            return 0;
        int currD = height_of_node(node->left) + height_of_node(node->right);

        int leftD = dia_of_this_tree(node->left);
        int rightD = dia_of_this_tree(node->right);

        return max(currD, max(leftD, rightD));
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

        void diameter(){
            int res = dia_of_this_tree(this->root);
            cout << res << endl;
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
    bt->insert(6);
    bt->insert(7);

    bt->diameter();
    return 0;
}