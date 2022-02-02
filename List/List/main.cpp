#include <iostream>

template<typename Type = int> class List {

    struct Node {
        Node* pNext;
        Type data;

        Node(Type data, Node* pNext = nullptr) {
            this->data = data;
            this->pNext = pNext;
        }
    };

    int size = -1;
    Node* head;
public:
    List();
    ~List();

    void push_back(Type data);
    void pop_front();

    Type& operator[] (const int index);
    int GetSize();
};

template<typename Type> List<Type>::List() {
    size = 0;
    head = nullptr;
}

template<typename Type> List<Type>::~List() {
    while (size) {
        pop_front();
    }
}

template<typename Type>
void List<Type>::push_back(Type data) {
    if (head == nullptr) {
        head = new Node(data);
    }
    else {
        Node* current = head;
        while (current->pNext != nullptr) {
            current = current->pNext;
        }
        current->pNext = new Node(data);
    }
    size++;
}

template<typename Type>
int List<Type>::GetSize() {
    return size;
}

template<typename Type>
Type& List<Type>::operator[](const int index) {
    int counter = 0;
    Node* current = head;

    while (current != nullptr) {
        if (counter == index) {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
}

template<typename Type>
void List<Type>::pop_front() {
    Node* temp = head;
    head = head->pNext;

    delete temp;
    size--;
}

int main() {

    List<int> list;

    list.push_back(72);
    list.push_back(32);

    for (size_t i = 0; i < list.GetSize(); i++) {
        std::cout << list[i] << std::endl;
    }

    list.push_back(7454);
    list.push_back(365);
    std::cout << "After #1" << std::endl;

    for (size_t i = 0; i < list.GetSize(); i++) {
        std::cout << list[i] << std::endl;
    }

    list.pop_front();
    std::cout << "After #2" << std::endl;

    for (size_t i = 0; i < list.GetSize(); i++) {
        std::cout << list[i] << std::endl;
    }

    return 0;
}
