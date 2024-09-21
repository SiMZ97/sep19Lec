// Siavash Mehrabani
// CS136

#include <iostream>
#include <sstream>
using namespace std;

//max size
const int MAX_SIZE = 1000;

// an element in the queue
struct Elem {
    int data;
};

// queue struct
struct Queue {
    Elem elems[MAX_SIZE];
    int front;
    int rear;
};

void printQueue(const Queue& q);
int rear(const Queue& q);

//init an empty queue
void initQueue(Queue& q) {
    q.front = -1;
    q.rear = -1;
}

// check if queue is empty
bool isEmpty(const Queue& q) {
    return (q.front == -1);
}

// check if queue is full
bool isFull(const Queue& q) {
    return (q.rear == MAX_SIZE - 1);
}

//enqueue (put an element in the back)
void enqueue(Queue& q, int value) {
    if (isFull(q)) {
        cout << "Queue us full" << endl;
    } else {
        if (isEmpty(q)) {
            q.front = 0;
        }
        q.rear = q.rear + 1;
        q.elems[q.rear].data = value;
    }
}

//dequeue (remove an element from the front queue)
void dequeue(Queue& q) {
    if (isEmpty(q))
        cout << "Queue is empty" << endl;
    else {
        if (q.front == q.rear) {
            q.front = -1;
            q.rear = -1;
        }
        else {
            q.front++;
            // q.front = (q.front  + 1)
        }
    }
}

//get the front
int front(const Queue& q) {
    if (isEmpty(q)) {
        cout << "Queue is empty." << endl;
        return -1; // an error
    }
    return q.elems[q.front].data;
}



int main () {
    Queue myQue;
    initQueue(myQue);

    enqueue(myQue, 100);
    enqueue(myQue, 200);
    enqueue(myQue, 300);

    cout << "Front element: " <<front(myQue) << endl;
    dequeue(myQue);

    cout << "After deque, Front : " << front(myQue) << endl;
    enqueue(myQue, 500);
    cout << "Front after enque: " << front(myQue) << endl;
    printQueue(myQue);
    return 0;
}

void printQueue(const Queue& q) {
    if (isEmpty(q))
    cout << "empty que." << endl;
    else {
        for (int i = q.front; i <= q.rear; ++i) {
            cout << q.elems[i].data << " ";
        }
        cout << endl;
    }
}