#include<bits/stdc++.h>
#define CAP 100
#define sp ' '
using namespace std;

class Vertex{
    public:
        // field
        int vertex,weight;
        Vertex* next;

        // constructor
        Vertex(int vertex,int weight){
            this->vertex = vertex;
            this->weight = weight;
            next = nullptr;
        }
};

class Linkedlist{
    public:
        // field
        Vertex* head;
        Vertex* tail;

        // constructor
        Linkedlist(){
            head = tail = nullptr;
        }

        // method
        void insertSorted(Vertex* vertex){
            Vertex* temp = nullptr;

            if(head == nullptr){
                head = tail = vertex;
                return;
            }
            
            if(vertex->vertex < head->vertex){
                vertex->next = head;
                head = vertex;
                return;
            }

            temp = head;

            while(temp->next != nullptr && vertex->vertex > temp->next->vertex){
                temp = temp->next;
            }

            vertex->next = temp->next;
            temp->next = vertex;

            if(vertex->next == nullptr)
                tail = vertex;
        }
};

class Queue{
    public:
        int arr[CAP];
        int front,rear;

        Queue(){
            front = rear = -1;
        }

        bool isEmpty(){
            return front == -1;
        }

        bool isFull(){
            return (rear+1) % CAP == front;
        }

        void enqueue(int data){
            if(isFull())
                return;

            if(front == -1)
                front = 0;

            rear = (rear+1) % CAP;

            arr[rear] = data;
        }

        void dequeue(){
            if(isEmpty())
                return;

            int temp = arr[front];

            cout << temp << sp;

            if(front == rear){
                front = rear = -1;
                return;
            }

            front = (front+1) % CAP;
        }
};

class AdjList{
    public:
        Linkedlist* arr;
        int size;

        AdjList(int size){
            this->size = size;

            arr = new Linkedlist[this->size];
        }

        void insertVertex(int index,int vertex){
            if( !(index >= 0 && index < size) )
                return;

            Vertex* v = new Vertex(vertex,1);
            arr[index].insertSorted(v);
        }

        void BFS(int start){
            Queue q;
            vector<bool> visited(false);
            
            visited.resize(size);
            q.enqueue(start);

            while(!q.isEmpty()){
                int curr = q.front;

                q.dequeue();

                for(Vertex* temp = arr[curr].head; temp != nullptr ; temp = temp->next){
                    if(visited[temp->vertex] == false){
                        visited[temp->vertex] = true;
                        q.enqueue(temp->vertex);
                    }
                }
            }
        }
};

int main(){
    AdjList graph(5);

    graph.insertVertex(0,1);
    graph.insertVertex(0,4);
    graph.insertVertex(1,2);
    graph.insertVertex(1,3);
    graph.insertVertex(1,4);
    graph.insertVertex(2,3);
    graph.insertVertex(3,4);

    graph.BFS(0);

    return 0;
}

/*
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
*/