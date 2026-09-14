#include<bits/stdc++.h>
#define MAX_SIZE 100
using namespace std;

struct Process{
    int pid,arvTime,bstTime;
    bool done = false;
};

class Queue{
    public:
        Process arr[MAX_SIZE];
        int front,rear;

        Queue(){
            front = rear = -1;
        }

        bool isEmpty(){return front == -1;}

        bool isFull(){return (rear + 1) % MAX_SIZE == front;}

        void enqueue(Process ps){
            if(isFull()) return;

            if(front == -1)
                front = 0;

            rear = (rear + 1) % MAX_SIZE;

            arr[rear] = ps;
        }

        Process dequeue(){
            Process temp;

            if(isEmpty()) return {-1,-1,-1,false};

            temp = arr[front];

            if(front == rear){
                front = rear = -1;
            }else{
                front = (front + 1) % MAX_SIZE;
            }

            return temp;
        }
};

int main(){
    Queue queue;
    Process curr;
    vector<Process> arr;
    int n,q,finished,currTime,runTime;

    cin >> n >> q;

    finished = currTime = 0;
    arr.resize(n);

    for(int i=0;i<n;i++){
        int pid,arvTime,bstTime;

        cin >> pid >> arvTime >> bstTime;

        arr[i].pid = pid;
        arr[i].arvTime = arvTime;
        arr[i].bstTime = bstTime;
    }

    while(finished < n){
        for(int i=0;i<n;i++){
            if(arr[i].done == false && arr[i].arvTime <= currTime){
                arr[i].done = true;
                queue.enqueue(arr[i]);
            }
        }

        if(queue.isEmpty()){
            ++currTime;
            continue;
        }

        curr = queue.dequeue();

        cout << curr.pid << ' ';

        runTime = min(q,curr.bstTime);
        curr.bstTime -= runTime;
        currTime += runTime;

        for(int i=0;i<n;i++){
            if(arr[i].done == false && arr[i].arvTime <= currTime){
                arr[i].done = true;
                queue.enqueue(arr[i]);
            }
        }

        if(curr.bstTime == 0){
            ++finished;
        }else{
            queue.enqueue(curr);
        }
    }

    return 0;
}