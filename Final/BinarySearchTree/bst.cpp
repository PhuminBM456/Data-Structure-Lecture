#include<bits/stdc++.h>
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

        Node* findMin(Node* root){
            // basecase
            if(root->left == nullptr)
                return root;

            // recursion
            return findMin(root->left);
        }

        void Insert(Node* root,int data){
            if(root == nullptr){
                root = new Node(data);
                return;
            }

            while(1){
                if(data < root->data && root->left != nullptr){
                    root = root->left;
                }else if(data > root->data && root->right != nullptr){
                    root = root->right;
                }

                else if(data < root->data && root->left == nullptr){
                    root->left = new Node(data);
                    break;
                }else if(data > root->data && root->right == nullptr){
                    root->right = new Node(data);
                    break;
                }

                else{
                    break;
                }
            }
            
        }

        Node* Delete(Node* root,int tar){
            if(root == nullptr)
                return nullptr;

            if(tar < root->data){
                root->left = Delete(root->left,tar);
            }else if(tar > root->data){
                root->right = Delete(root->right,tar);
            }

            else{
                if(root->left == nullptr && root->right == nullptr){
                    return nullptr;
                }else if(root->left != nullptr && root->right == nullptr){
                    return root->left;
                }else if(root->left == nullptr && root->right != nullptr){
                    return root->right;
                }

                else{
                    int min = findMin(root->right);

                    root->data = min;
                    root->right = Delete(root->right,min);
                }
            }
        }

        Node* Preorder(Node* root){
            // basecase
            if(root == nullptr)
                return nullptr;

            // recursion
            cout << root << data << ' ';
            Preorder(root->left);
            Preorder(root->right);
        }

        Node* Inorder(Node* root){
            // basecase
            if(root == nullptr)
                return nullptr;

            // recursion
            Inorder(root->left);
            cout << root << data << ' ';
            Inorder(root->right);
        }

        Node* Postorder(Node* root){
            // basecase
            if(root == nullptr)
                return nullptr;

            // recursion
            Postorder(root->left);
            cout << root << data << ' ';
            Postorder(root->right);
        }
};

int main(){
    return 0;
}