#include "Token.h"
#include "node.h"

#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

template <typename T>
class LinkedStack{
    Node<T>* topPtr;
    int count;

    public:
        LinkedStack(){
            topPtr = nullptr;
            count = 0;
        }

        LinkedStack(Node<T>* t, int c){
            topPtr = t;
            count = c;

            if(t == nullptr){
                count = 0;
                return;
            }

            topPtr = new Node<T>(t->getData());
            Node<T>* currentNew = topPtr;
            Node<T>* currentOld = t->getNext();

            while (currentOld != nullptr){
                Node<T>* newNode = new Node<T>(currentOld->getData());
                currentNew->setNext(newNode);
                currentNew = newNode;
                currentOld = currentOld->getNext();
            }
        }

        LinkedStack(const LinkedStack<T>& rhs){ 
            topPtr = nullptr;
            count = rhs.count;

            if(rhs.topPtr == nullptr){
                count = 0;
                return;
            }

            topPtr = new Node<T>(rhs.topPtr->getData());
            Node<T>* currentNew = topPtr;
            Node<T>* currentOld = rhs.topPtr->getNext();

            while (currentOld != nullptr){
                Node<T>* newNode = new Node<T>(currentOld->getData());
                currentNew->setNext(newNode);
                currentNew = newNode;
                currentOld = currentOld->getNext();
            }
        }

        LinkedStack<T>& operator=(const LinkedStack<T>& rhs){
            if (this != &rhs){
                clear();

                count = rhs.count;
                if(rhs.topPtr == nullptr){
                    topPtr = nullptr;
                    return *this;
                }

                topPtr = new Node<T>(rhs.topPtr->getData());
                Node<T>* currentNew = topPtr;
                Node<T>* currentOld = rhs.topPtr->getNext();

                while (currentOld != nullptr){
                    Node<T>* newNode = new Node<T>(currentOld->getData());
                    currentNew->setNext(newNode);
                    currentNew = newNode;
                    currentOld = currentOld->getNext();
                }
            }
            return *this;
        }
        
        ~LinkedStack(){ //should be finished
            clear();
        }

        void push(const T& val){
            Node<T>* newNode = new Node<T>(val);
            newNode->setNext(topPtr);
            topPtr = newNode;
            count++;
        }

        T pop(){
            if(!isEmpty()){ //maybe?
                T tempData = topPtr->getData();
                Node<T>* temp = topPtr;
                topPtr = topPtr->getNext();
                delete temp;
                count--;

                return tempData;
            }
            else{
                return T();
            }
        }
        
        bool isEmpty() const{ // should be working
            if(topPtr == nullptr){
                return true;
            }
            
            return false;
        }

        int size() const{
            return count;
        }

        void clear(){
            while(!isEmpty()){
                pop();
            }
        }

};
#endif