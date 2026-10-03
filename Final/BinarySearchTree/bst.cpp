#include<bits/stdc++.h>
#define CAP 100
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

class Queue{
    public:
        Node* arr[CAP];
        int front,rear;

        Queue(){
            front = rear = -1;
        }

        bool isFull(){
            return (rear+1) % CAP == front;
        }

        bool isEmpty(){
            return front == -1;
        }

        void enqueue(Node* node){
            if(isFull())
                return;

            if(front == -1)
                front = 0;

            rear = (rear+1) % CAP;
            arr[rear] = node;
        }

        Node* dequeue(){
            if(isEmpty())
                return nullptr;

            Node* temp = arr[front];

            if(front == rear){
                front = rear = -1;
                return temp;
            }

            front = (front+1) % CAP;

            return temp;
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

        int height(Node* root){
            if(root == nullptr)
                return 0;

            return max(height(root->left),height(root->right)) + 1;
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

        void BFS(Node* root){
            Queue queue;

            queue.enqueue(root);
            
            cout << root->data << sp;

            while(!queue.isEmpty()){
                Node* temp = queue.dequeue();

                if(temp->left != nullptr){
                    queue.enqueue(temp->left);
                    cout << temp->left->data << sp;
                }

                if(temp->right != nullptr){
                    queue.enqueue(temp->right);
                    cout << temp->right->data << sp;
                }
            }
        }
};

int main(){
    return 0;
}