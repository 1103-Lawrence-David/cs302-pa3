#ifndef NODE_H
#define NODE_H

template <typename T>
class Node{
    T data;
    Node<T>* next;

    public:
        Node(){
            data = T();
            next = nullptr;
        }

        Node(T d, Node<T>* n = nullptr){
            data = d;
            next = n; 
        }

        Node(const Node<T>& rhs){
            data = rhs.data;
            next = nullptr;
        }

        T getData(){
            return data;
        }

        void setData(T d){
            data = d;
        }

        Node<T>* getNext(){
            return next;
        }

        void setNext(Node<T>* n){
            next = n;
        }    
};

#endif