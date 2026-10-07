#include<bits/stdc++.h>
using namespace std;

class Heap{
    public:
        vector<int> arr;

        Heap(int size){
            arr.resize(size);
        }

        void insert(int data){
            arr.push_back(data);
        }

        void heapifyUp(){
            int i,parent;

            i = arr.size() - 1;
            
            while(true){
                if(i == 0)
                    break;

                parent = (i-1) / 2;

                if(arr[parent] < arr[i]){
                    int temp = arr[parent];

                    arr[parent] = arr[i];
                    arr[i] = temp;
                }else{
                    break;
                }

                i = parent;
            }
        }

        void heapifyDown(){
            int i,largest;

            i = largest = 0;

            while(true){
                int left = i*2 + 1;
                int right = i*2 + 2;

                if(left < arr.size() && arr[largest] < arr[left])
                    largest = left;

                if(right < arr.size() && arr[largest] < arr[right])
                    largest = right;

                if(i == largest)
                    break;

                swap(arr[i],arr[largest]);

                i = largest;
            }
        }
};

int main(){
    return 0;
}