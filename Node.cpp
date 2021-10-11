/* -----------------------------------------------------------------------------
 *
 * File Name: Node.cpp
 * Author: Caleb Bennetts
 * Assignment:   EECS-268 Lab03
 * Description: holds the functions definitions for the node class 
 * Date: 03/06/2021
 *
 ---------------------------------------------------------------------------- */
 #include "Node.h"

 template <typename T>
 Node<T>::Node(T entry){

     m_entry = entry;
     m_next = nullptr;
 }

 template <typename T>
 T Node<T>::getEntry() const{

     return(m_entry);
 }

template <typename T>
void Node<T>::setEntry(T entry){

    m_entry = entry;
}

template <typename T>
Node<T>* Node<T>::getNext() const{

    return(m_next);
}

template <typename T>
void Node<T>::setNext(Node<T>* next){
    
    m_next = next;
}
