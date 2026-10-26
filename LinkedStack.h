#include "Token.h"
#include "node.h"

#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

template <typename T>
class LinkedStack{
    Node<T>* topPtr;
    int count;
//2440 1886
    public:
        LinkedStack(){
            topPtr = nullptr;
            count = 0;
        }

        LinkedStack(Node<T>* t, int c){
            topPtr = t;
            count = c;
        }

        LinkedStack(const LinkedStack<T>& rhs){ //finish later
            topPtr = nullptr;
            count = 0;

            if(rhs.topPtr == nullptr){
                return ;
            }

            Node<T>* cRhs = rhs.topPtr;

        }

        LinkedStack<T>& operator=(const LinkedStack<T>& rhs){}
        
        ~LinkedStack(){ //should be finished
            clear();
        }

        void push(const T& val){
            Node<T>* newNode = new Node<T>(val);
            newNode->setNext(topPtr);
            topPtr = newNode;
            count++;
        }

        void pop(){
            if(!isEmpty()){ //maybe?
                Node<T>* temp = topPtr;
                topPtr = topPtr->getNext();
                delete temp;
                count--;
            }
        }
        
        bool isEmpty() const{ // should be working
            if(topPtr == nullptr && count = 0){
                return true;
            }
            
            return false;
        }

        int size() const{
            return count;
        }

        void clear(){
            while (!isEmpty()){
                pop();
            }
        }

};
#endif