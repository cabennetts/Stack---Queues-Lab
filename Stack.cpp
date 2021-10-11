/* -----------------------------------------------------------------------------
 *
 * File Name: Stack.cpp
 * Author: Caleb Bennetts
 * Assignment:   EECS-268 Lab03
 * Description: holds definitions for functions defined in stack class
 * Date: 03/06/2021
 *
 ---------------------------------------------------------------------------- */
 #include "Stack.h"
 #include "Node.h"
 #include <iostream>


 /*
 * constructor Sets ptrs to null
 */
 template <typename T>
 Stack<T>::Stack(){
     m_top = nullptr;
 }

 /*
 * copy constructor copies stack to a new stack
 */
 template <typename T>
 Stack<T>::Stack(const Stack<T>& orig){
     m_top = orig.m_top;
 }

 /*
 * overloads assignment operator
 */
 template <typename T>
 void Stack<T>::operator=(const Stack<T>& rhs){
    m_top = rhs.m_top;   
 }

 /*
 * pushes a value onto top of stack
 */
 template <typename T>
 void Stack<T>::push(T entry){
     Node<T>* temp = new Node<T>(entry);
     temp->setNext(m_top);
     m_top = temp;
 }

 /*
 * removes a value from top of stack
 */
 template <typename T>
 void Stack<T>::pop(){

     if(m_top == nullptr){
         throw std::runtime_error("Attempted pop on empty stack");
     }
     Node<T>* n = m_top;
     m_top = m_top->getNext();
     delete n;
     
 }

 /*
 * returns the value that is at top of stack
 */
 template <typename T>
 T Stack<T>::peek() const{
     if(!isEmpty()){
         return(m_top->getEntry());
     }
     else{
         throw(std::runtime_error("Peek called on an empty stack"));
     }
 }

 /*
 * verifies that stack is empty
 */
template <typename T>
bool Stack<T>::isEmpty() const{
     if(m_top == nullptr){
         return(true);
     }
     else{
         return(false);
     }
 }