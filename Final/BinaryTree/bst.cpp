#include<bits/stdc++.h>
#define CAP 100
#define sp ' '
using namespace std;

class Node{
    public:
        // field
        int data;
        Node* left;
        Node* right;

        // constructor
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

class Tree{
    public:
        // Field
        Node* root;

        // Constructor
        Tree(int data){
            root = new Node(data);
        }

        // Operation

        void insert(int data){
            Node* temp = root;

            while(true){
                if(temp->data > data && temp->left != nullptr){
                    temp = temp->left;
                }else if(temp->data <= data && temp->right != nullptr){
                    temp = temp->right;
                }else if(temp->data > data && temp->left == nullptr){
                    temp->left = new Node(data);
                    break;
                }else if(temp->data <= data && temp->right == nullptr){
                    temp->right = new Node(data);
                    break;
                }else{ // safety
                    break;
                }
            }
        }

        bool search(int data){
            Node* temp = root;

            while(true){
                if(temp->data > data && temp->left != nullptr){
                    temp = temp->left;
                }else if(temp->data < data && temp->right != nullptr){
                    temp = temp->right;
                }else if(temp->data == data){
                    return true;
                }else{ // safety
                    return false;
                }
            }
        }

        void preorder(Node* root){ // root left right
			// basecase
			if(root == nullptr)
				return;
			
			// recursion
			cout << root->data << sp;
			preorder(root->left);
			preorder(root->right);
		}
		
		void inorder(Node* root){ // left root right
			// basecase
			if(root == nullptr)
				return;
			
			// recursion
			inorder(root->left);
			cout << root->data << sp;
			inorder(root->right);
		}
		
		void postorder(Node* root){ // left right root
			// basecase
			if(root == nullptr)
				return;
			
			// recursion
			postorder(root->left);
			postorder(root->right);
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
        
        int height(Node* root){
            if(root == nullptr)
                return 0;

            return max(height(root->left),height(root->right)) + 1;
        }

        Node* findMin(Node* curr){
            // basecase
            if(curr->left == nullptr)
                return curr;

            // recursion
            return findMin(curr->left);
        }

        Node* delNode(Node* root,int tar){
            if(root == nullptr)
                return nullptr;

            if(tar < root->data){
                root->left = delNode(root->left,tar);
            }else if(tar > root->data){
                root->right = delNode(root->right,tar);
            }else{
                if(root->left == nullptr && root->right == nullptr){ // case 1
                    return nullptr;
                }else if(root->left == nullptr && root->right != nullptr){ // case 2
                    return root->right;
                }else if(root->left != nullptr && root->right == nullptr){ // case 3
                    return root->left;
                }else{ // case 4
                    Node* temp = findMin(root->right);

                    root->data = temp->data;
                    root->right = delNode(root->right,temp->data);
                }
            }
        }
};

int main(){
    /*
        10
       /  \
      5    15
     / \     \
    3   7     18
    */

    int arr[5] = {5,15,3,7,18};
    Tree bst(10);
    Node* temp = nullptr;

    // input
    for(int i=0;i<5;i++){
        bst.insert(arr[i]);
    }

    temp = bst.findMin(bst.root);
    
    // output
    cout << "Traversal" << '\n';
    cout << "Breadth First Search : ";
    bst.BFS(bst.root);
    cout << '\n';
    cout << "Preorder : ";
    bst.preorder(bst.root);
    cout << '\n';
    cout << "Ineorder : ";
    bst.inorder(bst.root);
    cout << '\n';
    cout << "Postorder : ";
    bst.postorder(bst.root);
    cout << '\n';
    cout << "Height : " << bst.height(bst.root) << '\n';
    cout << "Adge : " << bst.height(bst.root) - 1 << '\n';
    cout << "Min is " << temp->data << '\n' << '\n';
    cout << "Delete 15\n";
    bst.delNode(bst.root,15);
    bst.BFS(bst.root);
    cout << '\n' << '\n';
    cout << "Delete 5\n";
    bst.delNode(bst.root,5);
    bst.BFS(bst.root);

    return 0;
}