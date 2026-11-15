#include <iostream>
#include <string>
using namespace std;

template <class T>
class Queue
{
    T arr[100];
    int frontIndex, rear, count;

public:
    Queue()
    {
        frontIndex = 0;
        rear = -1;
        count = 0;
    }

    void enqueue(T value)
    {
        if (count == 100)
        {
            cout << "Queue is full!" << endl;
            return;
        }

        rear = (rear + 1) % 100;
        arr[rear] = value;
        count++;
    }

    void dequeue()
    {
        if (count == 0)
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        frontIndex = (frontIndex + 1) % 100;
        count--;
    }

    T front()
    {
        if (count == 0)
        {
            throw runtime_error("Queue is empty!");
        }

        return arr[frontIndex];
    }
};

int main()
{
    Queue<string> q;

    q.enqueue("Apple");
    q.enqueue("Banana");
    q.enqueue("Mango");

    cout << "Front element: " << q.front() << endl;

    q.dequeue();

    cout << "Front after dequeue: " << q.front() << endl;

    return 0;
}
