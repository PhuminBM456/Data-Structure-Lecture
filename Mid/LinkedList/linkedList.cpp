#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int id;
        Node* next;

        Node(int id){
            this->id = id;
            next = nullptr;
        }
};

class LinkedList{
    public:
        Node* head;
        Node* tail;

        LinkedList(){
            head = nullptr;
        }

        void printList(){
            if(head == nullptr){
                cout << "List is empty\n";
                return;
            }

            Node* temp = head;

            for(;temp != nullptr;temp = temp->next){
                cout << temp->id << ' ';
            }

            cout << endl;
        }

        void insertBack(int id){
            Node* newNode = new Node(id);

            if(head == nullptr){
                head = tail = newNode;
                return;
            }

            tail->next = newNode;
            tail = newNode;
        }

        void insertFront(int id){
            Node* newNode = new Node(id);

            if(head == nullptr){
                head = tail = newNode;
                return;
            }

            newNode->next = head;
            head = newNode;
        }

        void delNode(int tar){
            if(head == nullptr){
                cout << "List is empty" << endl;
                return;
            }

            if(head->id == tar){
                Node* delNode = head;
                head = head->next;

                delete delNode;
                return;
            }

            Node* prev = head;
            Node* curr = head->next;

            while(curr != nullptr){
                if(curr->id == tar){
                    Node* next = curr->next;
                    prev->next = next;

                    delete curr;
                    return;
                }

                prev = curr;
                curr = curr->next;
            }
        }

        bool search(int tar){
            Node* temp = head;
            for(;temp!=nullptr;temp = temp->next){
                if(temp->id == tar)
                    return true;
            }

            return false;
        }
};

int main(){
    LinkedList LL;
    LL.insertBack(1);
    LL.insertBack(2);
    LL.insertBack(3);
    LL.insertFront(4);
    cout << LL.search(3) << endl; // 1 = true
    LL.delNode(3);
    cout << LL.search(3) << endl; // 0 = false
    LL.printList(); // 4 1 2
    LL.delNode(4); // 1 2
    LL.delNode(2); // 1
    LL.delNode(1); // empty
    LL.printList(); // list is empty

    return 0;
}