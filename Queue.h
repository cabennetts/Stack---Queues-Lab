/* -----------------------------------------------------------------------------
 *
 * File Name: Queue.h
 * Author: Caleb Bennetts
 * Assignment:   EECS-268 Lab03
 * Description: Header file for queue class that is TEMPLATED
 * Date: 03/06/2021
 *
 ---------------------------------------------------------------------------- */
 #ifndef QUEUE_H
 #define QUEUE_H
 #include <stdexcept>
 #include <string>
 #include "Node.h"

template <typename T> 
class Queue{

    private:
        Node<T>* m_front;
        Node<T>* m_back;

    public:
         /**
		* @pre 
		* @post sets m_front to nullptr, makes m_back point to m_front
		* @param 
		* @throw 
		**/
        Queue();

        /**
		* @pre 
		* @post existing stack is copied to new one
		* @param 
		* @throw 
		**/
        Queue(const Queue<T>& orig);

        void operator= (const Queue<T>& rhs);

        /**
		* @pre 
		* @post adds element to back of queue
		* @param entry, element added to queue
		* @throw 
		**/
        void enqueue(T entry);
        
        /**
		* @pre queue has at least one element 
		* @post element is removed from front of queue
		* @param 
		* @throw if attempted on empty stack
		**/
        void dequeue();
        
        /**
		* @pre 
		* @post return whats in m_front
		* @param 
		* @throw when peekFront attempted on empty stack
		**/
        T peekFront() const;

        /**
		* @pre 
		* @post returns true if queue empty, false if not empty
		* @param 
		* @throw 
		**/
        bool isEmpty() const; 
};
#endif