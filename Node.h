/* -----------------------------------------------------------------------------
 *
 * File Name: Node.h
 * Author: Caleb Bennetts
 * Assignment:   EECS-268 Lab03
 * Description: Header file for the node class that is TEMPLATED
 * Date: 03/06/2021
 *
 ---------------------------------------------------------------------------- */
#ifndef NODE_H
#define NODE_H


template <typename T>
class Node{

    private:
        T m_entry;
        Node<T>* m_next;

    public:
        Node (T entry);
        T getEntry() const;
        void setEntry(T entry);
        Node<T>* getNext() const;
        void setNext(Node<T>* next);

};
#endif