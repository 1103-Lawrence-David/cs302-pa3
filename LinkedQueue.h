#include "Token.h"
#include "node.h"

#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

template <typename T>
class LinkedQueue{
    Node<T>* frontPtr;
    Node<T>* backPtr;
    int count;

    public:
        LinkedQueue(){
            frontPtr = nullptr;
            backPtr = nullptr;
            count = 0;
        }

        LinkedQueue(Node<T>* f, Node<T>* b, int c){
            frontPtr = nullptr;
            backPtr = nullptr;
            count = c;

            Node<T>* current = f;
            while(current != nullptr){
                enqueue(current->getData());

                if(current == b){
                    break;
                }
                current = current->getNext();
            }
        }

        LinkedQueue(const LinkedQueue<T>& rhs){
            frontPtr = nullptr;
            backPtr = nullptr;
            count = rhs.count;

            Node<T>* current = rhs.frontPtr;
            while(current != nullptr){
                enqueue(current->getData());
                current = current->getNext();
            }
        }

        LinkedQueue<T>& operator =(const LinkedQueue<T>& rhs){
            if(this != &rhs){
                clear();
                
                Node<T>* current = rhs.frontPtr;
                while(current != nullptr){
                    enqueue(current->getData());
                    current = current->getNext();
                }
            }
            return *this;
        }

        ~LinkedQueue(){ //should be working
            clear();
        }

        void enqueue(const T& val){
            Node<T>* newNode = new Node<T>(val);

            if(isEmpty()){
                frontPtr = backPtr = newNode;
            }
            else{
                backPtr->setNext(newNode);
                backPtr = newNode;
            }
            count++;
        }

        T dequeue(){
            if(!isEmpty()){
                T tempData = frontPtr->getData();
                Node<T>* tempNode = frontPtr;
                frontPtr = frontPtr->getNext();
                

                if(frontPtr == nullptr){
                    backPtr = nullptr;
                }

                delete tempNode;
                count--;

                return tempData;
            }
            return T();
        }

        bool isEmpty() const{ //maybe works???
            if(frontPtr == nullptr){
                return true;
            }
            return false;
        }

        int size() const{
            return count;
        }

        void clear(){
            while(!isEmpty()){
                dequeue();
            }
        }
};
#endif