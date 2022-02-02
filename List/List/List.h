#pragma once
template<typename Type = int> class List {

    struct Node {
        Node* pNext;
        Type data;

        Node(Type data = Type(), Node* pNext = nullptr) {
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
    void push_front(Type data);

    void pop_front();
    void pop_back();

    void clear();
    void insert(Type value, int index);
    void removeAt(int index);

    Type& operator[] (const int index);
    int GetSize();
};

template<typename Type> List<Type>::List() {
    size = 0;
    head = nullptr;
}

template<typename Type> List<Type>::~List() {
    clear();
}

template<typename Type>
inline void List<Type>::push_back(Type data) {
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
inline void List<Type>::push_front(Type data) {
    head = new Node(data);
    size++;
}

template<typename Type>
inline int List<Type>::GetSize() {
    return size;
}

template<typename Type>
inline Type& List<Type>::operator[](const int index) {
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
inline void List<Type>::pop_front() {
    Node* temp = head;
    head = head->pNext;

    delete temp;
    size--;
}

template<typename Type>
inline void List<Type>::pop_back()
{
    removeAt(size - 1);
}


template<typename Type>
inline void List<Type>::clear() {
    while (size) {
        pop_front();
    }
}

template<typename Type>
inline void List<Type>::insert(Type value, int index)
{
    Node* current = head;
    for (size_t i = 0; i < size; i++)
    {
        if (i == index) {
            current->data = value;
        }
        current = current->pNext;
    }
}

template<typename Type>
inline void List<Type>::removeAt(int index) {
    if (index == 0) {
        pop_front();
    }
    else {
        Node* current = head;
        for (size_t i = 0; i < index - 1; i++)
        {
            current = current->pNext;
        }
        Node* toDelete = current->pNext;

        current->pNext = toDelete->pNext;
        delete toDelete;

        size--;
    }
}