#include <iostream>
using namespace std;


template<typename T>
class Node{
public:
    T data;
    Node<T>* next;
    Node<T>* prev;
    
    Node(T val) : data(val), next(nullptr), prev(nullptr){};
};

template<typename T>
class LinkedList{
private:
    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    void add(T value){
        Node<T>* newNode = new Node<T>(value);
        if(!head){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    int GetSize(){
        Node<T>* current = head;
        int res = 0;
        while(current){
            res++;
            current = current->next;
        }
        return res;
    }

    bool IsEmpty(){
        return head == nullptr;
    }

    void removeAll(){
        Node<T>* current = head;
        while(current){
            Node<T>* tmp = current;
            current = current->next;
            delete tmp;
        }
        head = nullptr;
        tail = nullptr;
    }

    Node<T>* GetAt(int index){
        Node<T>* current = head;
        for(int i=0; current && i<GetSize(); i++){
            if(i == index) return current;
            current = current->next;
        }
        return nullptr;
    }

    void SetAt(int index, Node<T>* other){
        Node<T>* current = GetAt(index);
        if(current) current->data = other->data;
    }

    LinkedList Append(const LinkedList& other) const {
        LinkedList result;
        Node<T>* current = head;
        while(current){
            result.add(current->data);
            current = current->next;
        }
        current = other.head;
        while(current){
            result.add(current->data);
            current = current->next;
        }
        return result;
    }

    LinkedList& operator=(const LinkedList& other){
        if(this == &other) return *this;
        removeAll();
        Node<T>* current = other.head;
        while(current){
            add(current->data);
            current = current->next;
        }
        return *this;
    }

    Node<T>* GetHead(){ return head; }
    Node<T>* GetTail(){ return tail; }

    void InsertAt(int pos, T value){
        Node<T>* newNode = new Node<T>(value);

        if(pos <= 0){
            newNode->next = head;
            if(head) head->prev = newNode;
            head = newNode;
            if(!tail) tail = newNode;
            return;
        }

        Node<T>* current = head;
        int index = 0;
        while(current && index < pos){
            current = current->next;
            index++;
        }

        if(!current){
            add(value);
        } else {
            newNode->next = current;
            newNode->prev = current->prev;
            if(current->prev) current->prev->next = newNode;
            current->prev = newNode;
        }
    }

    void RemoveAt(int pos){
        if(IsEmpty() || pos < 0) return;

        Node<T>* current = head;
        int index = 0;
        while(current && index < pos){
            current = current->next;
            index++;
        }

        if(!current) return;

        if(current->prev) current->prev->next = current->next;
        else head = current->next;

        if(current->next) current->next->prev = current->prev;
        else tail = current->prev;

        delete current;
    }

    int GetUpperBound(){ return GetSize() - 1; }
    
    void SetSize(int size, T defaultValue = T()){
        int currentSize = GetSize();

        if(size > currentSize){
            for(int i = currentSize; i < size; i++){
                add(defaultValue);
            }
        } else if(size < currentSize){
            Node<T>* current = head;
            int index = 0;
            while(current && index < size){
                current = current->next;
                index++;
            }

            if(current){
                tail = current->prev;
                if(tail) tail->next = nullptr;

                while(current){
                    Node<T>* tmp = current;
                    current = current->next;
                    delete tmp;
                }
            }
        }
    }


    ~LinkedList(){
        removeAll()();
    }
};


int main(){
    
    return 0;
}

