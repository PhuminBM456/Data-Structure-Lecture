#include<bits/stdc++.h>
#define sp ' '
using namespace std;

class Heap{
    public:
        vector<int> arr;

        Heap(){}

        Heap(int size){
            arr.resize(size);
        }

        void insert(int data){
            arr.push_back(data);
            heapifyUp();
        }

        void delNode(){
            if(arr.empty())
                return;

            if(arr.size() == 1){
                arr.pop_back();
                return;
            }

            arr[0] = arr.back();
            arr.pop_back();

            heapifyDown();
        }

        void display(){
            int size = arr.size();

            for(int i=0;i<size;i++){
                cout << arr[i] << sp;
            }

            cout << '\n';
        }

        void position(int pos){
            cout << arr[pos] << '\n';
        }

        void heapifyUp(){
            int i = arr.size() - 1;

            while(true){
                int parent = (i-1) / 2;

                if(arr[parent] < arr[i]){
                    swap(arr[parent],arr[i]);
                }else{
                    break;
                }

                i = parent;
            }
        }

        void heapifyDown(){
            int i = 0;

            while(true){
                int largest = i;
                int left = 2*i+1;
                int right = 2*i+2;

                if(left < arr.size() && arr[left] > arr[largest])
                    largest = left;

                if(right < arr.size() && arr[right] > arr[largest])
                    largest = right;

                if(i == largest)
                    break;

                i = largest;
            }
        }
};

int main(){
    Heap heap;
    char cmd;

    while(true){
        cin >> cmd;

        if(cmd == 'a'){
            int temp;

            cin >> temp;

            heap.insert(temp);
        }else if(cmd == 'p'){
            heap.display();
        }else if(cmd == 'd'){
            heap.delNode();
        }else if(cmd == 'k'){
            int temp;

            cin >> temp;
            
            temp-=1;

            heap.position(temp);
        }else{
            break;
        }
    }

    return 0;
}