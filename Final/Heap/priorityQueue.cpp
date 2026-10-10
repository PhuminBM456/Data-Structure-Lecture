#include<bits/stdc++.h>
using namespace std;

int main(){
    //priority_queue<int> pq;
    priority_queue<int , vector<int> , greater<int> > pq;

    pq.push(60);
    pq.push(50);
    pq.push(40);
    pq.push(100);

    cout << pq.top() << '\n';
    pq.pop();

    cout << pq.size();

    return 0;
}