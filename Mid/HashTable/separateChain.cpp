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

class Linkedlist{
    public:
        Node* head;
        Node* tail;

        Linkedlist(){
            head = tail = nullptr;
        }

        void printList(){
            Node* temp = head;

            for(;temp!=nullptr;temp = temp->next){
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
};

class HashTable{
    public:
        vector<Linkedlist> v;
        int cap;

        HashTable(int cap){
            this->cap = cap;
            v.resize(cap);
        }

        int hashFunc(int value){
            return value % cap;
        }

        void insert(int value){
            int key = hashFunc(value);

            v[key].insertBack(value);
        }

        void print(int value){
            int key = hashFunc(value);
            v[key].printList();
        }

        void printAll(){
            for(int i=0;i<cap;i++){
                cout << "slot " << i << endl;

                if(v[i].head == nullptr){
                    cout << "-" << endl;
                    continue;
                }

                v[i].printList();
            }
        }
};

int main(){
    int arr[8] = {15,28,33,42,17,25,38,12};
    HashTable ht(8);
    
    for(int i=0;i<8;i++){
        ht.insert(arr[i]);
    }

    ht.printAll();

    return 0;
}