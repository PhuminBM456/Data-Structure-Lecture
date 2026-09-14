#include<iostream>
#include<vector>
using namespace std;

class Heap{
    public:
    	vector<int> heap;
    	
        void insert(int data){
            heap.push_back(data);
            heapifyUp();
        }

        void del(){
            if(heap.size() == 0){
                cout << "Heap is empty\n";
                return;
            }

            cout << heap[0] << ' ';

            heap[0] = heap.back();
            heap.pop_back();

            heapifyDown();
        }

        void heapifyUp(){
            int i = heap.size()-1;

            while(i > 0){
                int parent = (i-1) / 2;

                if(heap[parent] < heap[i]){
                //if(heap[parent] > heap[i]){
                    int temp = heap[parent];
                    heap[parent] = heap[i];
                    heap[i] = temp;
                }else{
                    break;
                }

                i = parent;
            }
        }

        void heapifyDown(){
            int i = 0;

            while(true){
                int left = 2 * i + 1;
                int right = 2 * i + 2;
                int largest = i;

                if(left < heap.size() && heap[left] > heap[largest]){
                    largest = left;
                }

                if(right < heap.size() && heap[right] > heap[largest]){
                    largest = right;
                }

                // if(left < heap.size() && heap[left] < heap[largest]){
                //     largest = left;
                // }

                // if(right < heap.size() && heap[right] < heap[largest]){
                //     largest = right;
                // }

                if(largest == i){
                    break;
                }

                int temp = heap[i];
                heap[i] = heap[largest];
                heap[largest] = temp;

                i = largest;
            }
        }

        void display(){
            for(int i=0;i<heap.size();i++){
                cout << "index = " << i << " value = " << heap[i] << endl;
            }
        }
};

int main(){
    Heap heap;

    heap.insert(-1);
    heap.insert(2);
    heap.insert(100);
    heap.insert(5);

    heap.del();
    heap.del();
    heap.del();
    heap.del();
    
    return 0;
}
