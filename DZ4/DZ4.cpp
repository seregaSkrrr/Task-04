#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;
    int size;

public:
    Stack() : top(nullptr), size(0) {}

    int push(int data) {
        if (size == 0) {
            top = new Node;
            top->data = data;
            top->next = nullptr;
            size++;
        }
        else {
            Node* temp = new Node;
            temp->data = data;
            temp->next = top;
            top = temp;
            size++;
        }
        return data;
    }

    int pop() {
        if (size == 0) {
            throw std::runtime_error("Stack Underflow");
        }

        int data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
        return data;
    }

    int peek() {
        if (size == 0) {
            throw std::runtime_error("Stack Underflow");
        }

        return top->data;
    }

    bool isEmpty() {
        return size == 0;
    }
};

class List {
private:
    Node* head;

public:
    List() : head(nullptr) {}

    void push(int data) {
        Node* temp = new Node;
        temp->data = data;
        temp->next = head;
        head = temp;
    }

    List* clone() {
        List* cloneList = new List;
        Node* current = head;

        while (current != nullptr) {
            cloneList->push(current->data);
            current = current->next;
        }

        return cloneList;
    }

    List* operator+(List& other) {
        List* newList = new List;
        Node* current1 = head;
        Node* current2 = other.head;

        while (current1 != nullptr) {
            newList->push(current1->data);
            current1 = current1->next;
        }

        while (current2 != nullptr) {
            newList->push(current2->data);
            current2 = current2->next;
        }

        return newList;
    }

    List* operator*(List& other) {
        List* newList = new List;
        Node* current1 = head;
        Node* current2 = other.head;

        while (current1 != nullptr) {
            while (current2 != nullptr) {
                if (current1->data == current2->data) {
                    newList->push(current1->data);
                    break;
                }
                current2 = current2->next;
            }
            current2 = other.head;
            current1 = current1->next;
        }

        return newList;
    }
};

int main() {
    Stack stack;
    cout << "Added: " << stack.push(1) << endl;
    cout << "Added: " << stack.push(2) << endl;
    cout << "Added: " << stack.push(3) << endl;

    cout << "Popped element: " << stack.pop() << endl;
    cout << "Top element: " << stack.peek() << endl;

    List list1;
    list1.push(1);
    list1.push(2);
    list1.push(3);

    List list2;
    list2.push(2);
    list2.push(3);
    list2.push(4);

    List* cloneList = list1.clone();
    List* listSum = list1 + list2;
    List* listMultiply = list1 * list2;

    return 0;
}