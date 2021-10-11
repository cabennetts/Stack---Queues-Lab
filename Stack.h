/* -----------------------------------------------------------------------------
 *
 * File Name: Stack.h
 * Author: Caleb Bennetts
 * Assignment:   EECS-268 Lab03
 * Description: Header file for the stack class that is TEMPLATED
 * Date: 03/06/2021
 *
 ---------------------------------------------------------------------------- */
 #ifndef STACK_H
 #define STACK_H
 #include <stdexcept>
 #include "Node.h"

template <typename T>
 class Stack{

     private:
        Node<T>* m_top; 

     public:
        /**
		* @pre 
		* @post Sets m_top = to nullptr
		* @param 
		* @throw 
		**/
        Stack(); //Constructor to construct Stack

        /**
		* @pre 
		* @post new stack is copied to existing stack
		* @param orig, stack going to be copied
		* @throw 
		**/
        Stack(const Stack<T>& orig);

        /**
		* @pre 
		* @post overloads assignment operator so it can take values from front/back
		* @param 
		* @throw 
		**/
        void operator=(const Stack<T>& rhs);

        /**
		* @pre 
		* @post entry added to top of stack
		* @param entry, element that will be added to stack
		* @throw 
		**/
        void push(T entry); //takes in a value (entry) and pushes (adds) onto top of stack

        /**
		* @pre stack contains at least one element 
		* @post top element removed from stack 
		* @param 
		* @throw when pop attempted on empty stack ( m_top = nullptr)
		**/
        void pop(); //removes top value from stack

        /**
		* @pre stack contains at least one element
		* @post reurns top element of stack
		* @param 
		* @throw when peek attempted on empty stack ( m_top = nullptr )
		**/
        T peek() const; //looks to see value on top of stack

        /**
		* @pre 
		* @post returns if stack is empty or not
		* @param 
		* @throw 
		**/
        bool isEmpty() const; //checks to see if stack is empty and returns bool(true/false)
 };
 #endif