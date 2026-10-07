#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int> pq;

    pq.push(60);
    pq.push(50);
    pq.push(40);
    pq.push(100);

    cout << pq.top() << '\n';
    pq.pop();

    return 0;
}