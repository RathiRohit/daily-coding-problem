#include <iostream>

#define ll long long
#define ull unsigned long long

using namespace std;

template <typename T>
class Node {
    public:
        T n;
        Node<T> *both;

        Node(T n) {
            this->n = n;
            this->both = NULL;
        }
};

template <typename T>
class XORDoublyLinkedList {
    private:
        Node<T> *head;

        Node<T>* getLastNode() {
            Node<T> *prevNode = NULL;
            Node<T> *currentNode = this->head;
            while(currentNode != NULL) {
                Node<T> *nextNode = (Node<T> *)((uintptr_t)(currentNode->both) ^ (uintptr_t)prevNode);
                prevNode = currentNode;
                currentNode = nextNode;
            }
            return prevNode;
        }

    public:
        XORDoublyLinkedList() {
            this->head = NULL;
        }

        void addToEnd(T value) {
            Node<T> *newNode = new Node<T>(value);
            Node<T> *lastNode = getLastNode();
            if(lastNode == NULL) {
                this->head = newNode;
                return;
            }
            lastNode->both = (Node<T> *)((uintptr_t)(lastNode->both) ^ (uintptr_t)newNode);
            newNode->both = (Node<T> *)((uintptr_t)lastNode ^ (uintptr_t)NULL);
        }

        T get(int index) {
            int currentIndex = 0;
            Node<T> *prevNode = NULL;
            Node<T> *currentNode = this->head;
            while(currentNode != NULL) {
                if(currentIndex == index) {
                    return currentNode->n;
                }
                Node<T> *nextNode = (Node<T> *)((uintptr_t)(currentNode->both) ^ (uintptr_t)prevNode);
                prevNode = currentNode;
                currentNode = nextNode;
                currentIndex++;
            }
            throw "ERROR: Index out of bound.";
        }

        void print() {
            if(this->head == NULL) {
                cout<<"List is empty."<<endl;
                return;
            }

            cout<<"List:"<<endl;
            Node<T> *prevNode = NULL;
            Node<T> *currentNode = this->head;
            while(currentNode != NULL) {
                if(prevNode != NULL) {
                    cout<<" <=> ";
                }
                cout<<currentNode->n;
                Node<T> *nextNode = (Node<T> *)((uintptr_t)(currentNode->both) ^ (uintptr_t)prevNode);
                prevNode = currentNode;
                currentNode = nextNode;
            }
            cout<<endl;
        }
};

int main() {
    XORDoublyLinkedList<int> dList;

    dList.print();
    dList.addToEnd(1);
    dList.print();
    dList.addToEnd(2);
    dList.print();
    dList.addToEnd(3);
    dList.addToEnd(4);
    dList.print();

    cout<<"Element at 0: "<<dList.get(0)<<endl;
    cout<<"Element at 1: "<<dList.get(1)<<endl;
    cout<<"Element at 2: "<<dList.get(2)<<endl;
    cout<<"Element at 3: "<<dList.get(3)<<endl;
    try {
        cout<<"Element at 4: "<<dList.get(4)<<endl;
    } catch (const char *e) {
        cout<<e<<endl;
    }
	return 0;
}
