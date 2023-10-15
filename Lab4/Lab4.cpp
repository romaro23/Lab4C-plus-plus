
#include <iostream>
using namespace std;
struct Node {
    int n;
    Node* next;
    Node(int _n) : n(_n), next(nullptr){}
};
struct Queue {
    Node* head;
    Node* tail;
    Queue(): head(nullptr), tail(nullptr){}
    void enqueue(int _n) {      
        Node* node = new Node(_n);
        if (head == nullptr && tail == nullptr) {        
            head = node;
            tail = node;
        }
        else {    
            tail->next = node;
            tail = node;
        }
    }
    void dequeue() {
        Node* current = head;
        head = head->next;
        delete current;
    }
    void swap() {
        Node* current = head;
        while (current->next->next) {
            current = current->next;
        }
        Node* tempHead = head;
        Node* tempTail = tail;
        tail = current;
        tempTail->next = head->next;
        head = tempTail;
        tail->next = tempHead;
        tail = tempHead;
        tail->next = nullptr;  
    }
    void reverse() {
        Queue tempQueue;   
        while (head) {
            Node* current = head;
            Node* previous = nullptr;
            while (current->next) {
                previous = current;
                current = current->next;
            }
            tempQueue.enqueue(current->n);
            if (previous) {
                previous->next = nullptr;
            }
            else {
                head = tail = nullptr;
            }
            delete current;
            
        }
        head = tempQueue.head;
        tail = tempQueue.tail;
    }
    bool ifBelongs(int _n) {
        Node* current = head;
        while (current) {
            if (current->n == _n) {
                cout << _n << " belongs to this queue" << endl;
                return true;
            }
            current = current->next;
        }
        cout << _n << " doesn't belong to this queue" << endl;
        return false;
    }
    void clear() {
        while (head) {
            dequeue();
        }
    }
    void print() {
        Node* current = head;
        while (current) {
            cout << current->n << " ";
            current = current->next;
        }
        cout << endl;
    }
};
int main()
{
    Queue queue;
    queue.enqueue(5);
    queue.enqueue(7);
    queue.enqueue(8);
    queue.enqueue(9);
    queue.print();
    while (true) {
        int option;
        cout << "Choose option: " << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Swap first and last elements" << endl;
        cout << "4. Reverse the queue" << endl;
        cout << "5. If element belong to the queue" << endl;
        cout << "6. Clear the queue" << endl;
        cin >> option;
        int number;
        switch (option) {
        case 1:
            cout << "Enter the number: " << endl;
            cin >> number;
            queue.enqueue(number);
            break;
        case 2:
            queue.dequeue();
            break;
        case 3:
            queue.swap();
            break;
        case 4:
            queue.reverse();
            break;
        case 5:
            cout << "Enter the number: " << endl;
            cin >> number;
            queue.ifBelongs(number);
            break;
        case 6:
            queue.clear();
            break;  
        }
        queue.print();

    }
    
}


