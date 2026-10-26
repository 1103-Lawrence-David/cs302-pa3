#include "Token.h"
#include "node.h"

#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

template <typename T>
class LinkedQueue{
    Node<T>* frontptr;
    Node<T>* backPtr;
    int count;

    public:
        LinkedQueue(){}
        LinkedQueue(const LinkedQueue<T>& rhs){}
        LinkedQueue<T>& operator =(const LinkedQueue<T>& rhs){}

        ~LinkedQueue(){ //should be working
            clear();
        }

        void enqueue(const T& value){}

        void dequeue(){}

        bool isEmpty() const{ //maybe works???
            if(frontPtr == backPtr && frontPtr == nullptr){
                return true;
            }
            return false;
        }

        int size() const{}

        void clear(){
            
        }
};
#endif