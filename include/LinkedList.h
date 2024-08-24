#pragma once
#include "node.h"
#include <iostream>

namespace jordan{
template<typename T>
class LinkedList{
    private:
        int max = -1;
        node<T> *head;
        node<T> *tail;
    protected:
        int size = 0;
    public:
        LinkedList(){
            this->head = new node<T>();
            this->head->value = -1;
            this->head->next= this->tail;
            tail = head;
        }

        ~LinkedList(){
            //delete head;
            if(!this->isEmpty()){
                //node<T> *tempHead = myself.head;
                //for (int i = 0; i < myself.size;i++){
                //    delete &tempHead;
                //    tempHead= tempHead->next;
               // }
                //delete tempHead;
            }

        }

        T get(const int& idx){
            if(this->size>0 && idx < this->size){
                node<T> *tempHead = this->head;
                tempHead= tempHead->next;

                for (int i = 0; i <= idx;i++){
                    if(i == idx){
                        int retVal = tempHead->value;
                        tempHead=NULL;
                        delete tempHead;
                        return(retVal);
                    }
                    tempHead= tempHead->next;
                }
                delete tempHead;
            }
            return -1;
        }

        void insert(const int &value){
            if(!this->isFull()){
                tail->next = new node<T>();
                tail = tail->next;
                tail->value = value;
                this->size++;
            }
        }

        void remove(const int &value){
             if(this->size>0){
                node<T> *tempHead = this->head;
                for (int i = 0; i < this->size;i++){
                    if(tempHead->next->value == value){
                        DeleteNext(tempHead);
                        tempHead=NULL;
                        break;
                    }
                    tempHead= tempHead->next;
                }
                delete tempHead;
                
            }

        }

        void removeAt(const int &value){
             if(this->size>0 && value <= this->size){
                node<T> *tempHead = this->head;
                for (int i = 0; i <= value;i++){
                    if(i == value){
                        DeleteNext(tempHead);
                        tempHead=NULL;
                        break;
                    }
                    tempHead= tempHead->next;
                }
                delete tempHead;
            }
        }

        void replace(const int &idx, const T &value){
            if(this->size>0 && value <= this->size){
                node<T> *tempHead = this->head->next;
                for (int i = 0; i <= idx;i++){
                    if(i == idx){
                        tempHead->value = value;
                        tempHead=NULL;
                        break;
                    }
                    tempHead= tempHead->next;
                }
                delete tempHead;
            }    
        }

        

        int length(){
            return this->size;
        }

        bool isEmpty(){
            return this->size==0;
        }
        
        bool isFull(){
            if(this->max != -1){
                return (this->size == this->max);
            }else{
                return false;
            }
        }

        friend std::ostream & operator<<(std::ostream &os,const LinkedList<T> &myself){
            os << "linkedlist size "<<myself.size<<"values";
            if(myself.size>0){
                node<T> *tempHead = myself.head;
                tempHead= tempHead->next;
                for (int i = 1; i < myself.size+1;i++){
                    //start with head
                    os << tempHead->value;
                    tempHead= tempHead->next;
                }
                tempHead = NULL;
                delete tempHead;
            }
            return os;
        }


    private:

        void DeleteNext(node<T> *node_before){
            node<T> *temp = node_before->next;
            node_before->next = node_before->next->next;
            delete temp;
            this->size --;
        }
       

};

}