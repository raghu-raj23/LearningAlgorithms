#include <bits/stdc++.h> 
using namespace std;

priority_queue<int, vector<int>, greater<int>> pqmin;
priority_queue<int, vector<int>> pqmax;

void insert(int x){
    if(pqmin.size() == pqmax.size()){
        if(pqmax.size() == 0){
            pqmax.push(x);
            return;
        }
        if(x <= pqmax.top()){
            pqmax.push(x);
        }
        else{
            pqmin.push(x);
        }
    }
    else{
        // size of maxHeap > minHeap
        if(pqmax.size() > pqmin.size()){
            if(x >= pqmax.top()){
                pqmin.push(x);
            }
            else{
                int temp = pqmax.top();
                pqmax.pop();
                pqmin.push(temp);
                pqmax.push(x);
            }
        }
        else{
            if(x<= pqmin.top()){
                pqmax.push(x);
            }
            else{
                int temp = pqmin.top();
                pqmin.pop();
                pqmax.push(temp);
                pqmin.push(x);
            }
        }
    }
}

double findMedian(){
    if(pqmin.size() == pqmax.size()){
        return ( pqmin.top() + pqmax.top() ) / 2.0;
    }
    else if(pqmin.size() < pqmax.size()){
        return pqmax.top();
    }
    else{
        return pqmin.top();
    }
}

int main()
{
    while(1){
        int x;
        cin >> x;
        if(x == -1){
            break;
        }
        insert(x);
        cout <<"The median is: "<< findMedian() << endl;
    }
    return 0;
}