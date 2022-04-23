#include <iostream>
using namespace std;
#define N 100
class queue
{
    int *arr;
    int front, back;

public:
    queue()
    {
        arr = new int[N];
        front = -1;
        back = -1;
    }
    void push(int x)
    {
        if (back == N - 1)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        back++;
        arr[back] = x;
        if (front == -1)
        {
            front++;
        }
    }
    void pop()
    {
        if (front == -1 || front > back)
        {
            cout << "Queue Underflow" << endl;
        }
        front++;
    }
    int peek()
    {
        if (front == -1 || front > back)
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        return arr[front];
    }
    bool empty()
    {
        if (front == -1 || front > back)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout << q.peek()<<endl;
    q.pop();
    cout << q.peek()<<endl;
    cout << q.empty()<<endl;


    return 0;
}