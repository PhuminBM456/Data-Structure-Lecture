#include<bits/stdc++.h>
using namespace std;

class Stack{
    private:
        int size;
        int* arr;
        int top;

    public:
        // Constructor
        Stack(int size){
            this->size = size;
            arr = new int[size];
            top = -1;
        }

        // Function
        bool isFull(){
            return top == size-1;
        }

        bool isEmpty(){
            return top == -1;
        }

        void push(int data){
            if(isFull()){
                cout << "Stack is Full" << endl;
                return;
            }

            ++top;
            *(arr + top) = data;
        }

        void pop(){
            if(isEmpty()){
                cout << "Stack is Empty" << endl;
                return;
            }

            cout << *(arr + top--) << endl;
        }

        void peek(){
            if(isEmpty()){
                cout << "Stack is Empty" << endl;
                return;
            }

            cout << *(arr + top) << endl;
        }
};

int main(){
    Stack* ptr = new Stack(5);
    
    ptr->push(1);
    ptr->push(2);
    ptr->push(3);
    ptr->push(4);
    ptr->push(5);
    ptr->push(6); // Full
    ptr->peek();
    ptr->pop();
    ptr->pop();

    return 0;
}