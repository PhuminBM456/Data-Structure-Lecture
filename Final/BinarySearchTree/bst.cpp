#include<bits/stdc++.h>
#define sp ' '
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            left = right = nullptr;
        }
};

class BST{
    public:
        Node* root;

        BST(){
            root = nullptr;
        }

        Node* findMin(Node* temp){
            // basecase
            if(temp->left == nullptr)
                return temp;

            // recursion
            return findMin(temp->left);
        }

        void insert(int data){
            Node* temp = root;

            while(true){
                if(data < temp->data && temp->left != nullptr){
                    temp = temp->left;
                }else if(data > temp->data && temp->right != nullptr){
                    temp = temp->right;
                }else if(data < temp->data && temp->left == nullptr){
                    temp->left = new Node(data);
                    break;
                }else if(data > temp->data && temp->right == nullptr){
                    temp->right = new Node(data);
                    break;
                }else{
                    break;
                }
            }
        }

        Node* delNode(Node* root,int data){
            if(root == nullptr) // not found
                return nullptr;

            if(data < root->data){
                root->left = delNode(root->left,data);
            }else if(data > root->data){
                root->right = delNode(root->right,data);
            }else{
                if(root->left == nullptr && root->right == nullptr){
                    return nullptr;
                }else if(root->left != nullptr && root->right == nullptr){
                    return root->left;
                }else if(root->left == nullptr && root->right != nullptr){
                    return root->right;
                }else{
                    Node* node = findMin(root->right);
                    
                    root->data = node->data;
                    root->right = delNode(root->right,root->data);
                }
            }
        }

        void preorder(Node* root){
            // basecase
            if(root == nullptr) return;

            cout << root->data << sp;
            preorder(root->left);
            inorder(root->right);
        }

        void inorder(Node* root){
            // basecase
            if(root == nullptr) return;

            preorder(root->left);
            cout << root->data << sp;
            inorder(root->right);
        }

        void postorder(Node* root){
            // basecase
            if(root == nullptr) return;

            preorder(root->left);
            inorder(root->right);
            cout << root->data << sp;
        }
};

int main(){
    return 0;
}