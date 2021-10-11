/* -----------------------------------------------------------------------------
 *
 * File Name: Queue.cpp
 * Author: Caleb Bennetts
 * Assignment:   EECS-268 Lab03
 * Description: holds definitions for functions defined in Queue class
 * Date: 03/06/2021
 *
 ---------------------------------------------------------------------------- */
 #include "Queue.h"
 #include "Node.h"
 #include <iostream>

 /*
 * constructor Sets ptrs to null
 */
 template <typename T>
 Queue<T>::Queue(){
 
    m_front = nullptr;
    m_back = nullptr;
 }

 /*
 * copy constructor copies queue to a new stack
 */
 template <typename T>
 Queue<T>::Queue(const Queue<T>& orig){
 
     m_back = orig.m_back;
     m_front = orig.m_front;
 }

 /*
 * overloads assignment operator so it can take values from front/back
 */
 template <typename T>
 void Queue<T>::operator=(const Queue<T>& rhs){
 
     m_back = rhs.m_back;
     m_front = rhs.m_front;
 }
 
 /*
 * adds entry to back of queue
 */
 template <typename T>
 void Queue<T>::enqueue(T entry){

    Node<T>* temp = new Node<T>(entry);
    temp->setNext(nullptr);

    if(m_front == nullptr){
        m_front = temp;
        m_back = temp;
    }
    else{
        m_back->setNext(temp);
        m_back = temp;
    }
 }

/*
* removes entry from front of queue
*/
 template <typename T>
 void Queue<T>::dequeue(){
 
     if(isEmpty()){
         throw std::runtime_error("Attempted dequeue on empty stack");
     }
     else if(m_front == m_back){
         Node<T>* temp = m_front;
         m_front = nullptr;
         m_back = nullptr;
         delete temp;
     }
     else{
         Node<T>* temp = m_front;
         m_front = m_front->getNext();
         delete temp;
     }
 }

 /*
* returns value from front of queue
*/
template <typename T>
T Queue<T>::peekFront() const{

    return(m_front->getEntry());
}

/*
* verifies queue is empty
*/
template <typename T>
bool Queue<T>::isEmpty() const{

    if((m_back == m_front) && (m_front == nullptr)){
        return(true);
    }
    else{
        return(false);
    }

}

