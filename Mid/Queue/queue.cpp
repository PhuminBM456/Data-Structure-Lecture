#include<bits/stdc++.h>
#define SIZE 5
#define space ' '

using namespace std;

class Queue{
    private:
        int arr[SIZE],front,rear;

    public:
        Queue(){
            front = rear = -1;
        }

        bool isEmpty(){
            return front == -1;
        }

        bool isFull(){
            return (rear + 1) % SIZE == front;
        }

        void enqueue(int x){
            if(isFull()){
                cout << "Queue is full\n";
                return;
            }

            if(isEmpty())
                front = 0;

            rear = (rear + 1) % SIZE;

            arr[rear] = x;
        }

        void dequeue(){
            if(isEmpty()){
                cout << "Queue is empty\n";
                return;
            }

            cout << arr[front] << endl;

            if(front == rear){
                front = rear = -1;
                return;
            }

            front = (front + 1) % SIZE;
        }

        void display(){
            for(int i=0;i<SIZE;i++){
                cout << arr[i] << space;
            }

            cout << endl;
        }
};

int main(){
    Queue* queue = new Queue;

    queue->enqueue(1);
    queue->enqueue(2);
    queue->enqueue(3);
    queue->enqueue(4);
    queue->enqueue(5);
    queue->enqueue(6); // Queue is full

    queue->dequeue();
    queue->dequeue();
    
    queue->enqueue(6);

    queue->display();

    return 0;
}